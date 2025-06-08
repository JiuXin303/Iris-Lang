/*
 *--------------------------------------------------------------------------------
 *文件名: parser.cpp
 *创建时间: 2025-06-09 01:00:38 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 04:46:46 Mon
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---
 *------------------------------------------------------
 */

#include <lexer.hpp>
#include <logger.hpp>
#include <parser.hpp>

using namespace IrisLang;

Parser::Parser(std::string text)
{
	Lexer lexer(text);
	for (Token token = lexer.getNextToken(); token.getType() != TokenType::END_OF_FILE_TOKEN;
		 token = lexer.getNextToken())
	{
		if (token.getType() == TokenType::WHITE_SPACE_TOKEN || token.getType() == TokenType::UNKNOWN_TOKEN) continue;
		m_tokens.push_back(token);
	}
}

Token Parser::match(TokenType type)
{
	if (m_position >= m_tokens.size())
	{
		LOG_WARNING("Parser", "SyntaxError: Unexpected end of file at position " + std::to_string(m_position) + ".");
		return Token(TokenType::END_OF_FILE_TOKEN, "");
	}
	if (m_tokens[m_position].getType() == type) return m_tokens[m_position++];

	LOG_WARNING("Parser", "SyntaxError: Unexpected token '" + m_tokens[m_position].getText() + "' at position " +
							  std::to_string(m_position) + ". Expected " + tokenTypeToString(type) + ".");
	m_position++;
	return Token(TokenType::UNKNOWN_TOKEN, "");
}

std::vector<ExprNode*> Parser::parseBinaryExpr()
{

	auto left = parsePrimaryExpr(TokenType::NUMBER_TOKEN);
	if (left) m_exprChildrens.push_back(left);
	while (m_position < m_tokens.size() && (m_tokens[m_position].getType() == TokenType::PLUS_TOKEN ||
											m_tokens[m_position].getType() == TokenType::MINUS_TOKEN))
	{
		auto op = parsePrimaryExpr(m_tokens[m_position].getType());
		if (op)
		{
			m_exprChildrens.push_back(op);
			auto right = parsePrimaryExpr(TokenType::NUMBER_TOKEN);
			if (right)
			{
				m_exprChildrens.push_back(right);
				if (left) m_exprChildrens.push_back(BinaryExprSyntax(*left, *op, *right).clone());
				left = m_exprChildrens.back();
			}
		}
	}
	return m_exprChildrens;
}

ExprNode* Parser::parsePrimaryExpr(TokenType type)
{
	if (type == TokenType::NUMBER_TOKEN)
	{
		Token token = match(type);
		if (token.getType() == TokenType::NUMBER_TOKEN) return new ExprNode(token.getText(), ExprType::NUMBER_EXPR);
	}
	else if (type == TokenType::PLUS_TOKEN || type == TokenType::MINUS_TOKEN)
	{
		Token token = match(type);
		if (token.getType() == TokenType::PLUS_TOKEN || token.getType() == TokenType::MINUS_TOKEN)
			return new ExprNode(token.getText(), ExprType::OPERATOR_EXPR);
	}
	return nullptr;
}
