/*
 *--------------------------------------------------------------------------------
 *文件名: parser.cpp
 *创建时间: 2025-06-09 01:00:38 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 19:41:09 Mon
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
		LOG_ERROR("Parser", "Unexpected end of file at position " + std::to_string(m_position) + ".");
		return Token(TokenType::END_OF_FILE_TOKEN, "");
	}
	if (m_tokens[m_position].getType() == type) return m_tokens[m_position++];

	LOG_WARNING("Parser", "Unexpected token '" + m_tokens[m_position].getText() + "' at position " +
							  std::to_string(m_position) + ". Expected " + tokenTypeToString(type) + ".");
	m_position++;
	return Token(TokenType::UNKNOWN_TOKEN, "");
}

std::vector<std::shared_ptr<ExprNode>> Parser::parseBinaryExpr()
{

	auto left = parsePrimaryExpr(TokenType::NUMBER_TOKEN);
	if (left) m_exprTree.push_back(left);
	while (m_position < m_tokens.size() && (m_tokens[m_position].getType() == TokenType::PLUS_TOKEN ||
											m_tokens[m_position].getType() == TokenType::MINUS_TOKEN ||
											m_tokens[m_position].getType() == TokenType::MULTIPLY_TOKEN ||
											m_tokens[m_position].getType() == TokenType::DIVIDE_TOKEN))
	{
		auto op = parsePrimaryExpr(m_tokens[m_position].getType());
		if (op)
		{
			m_exprTree.push_back(op);
			auto right = parsePrimaryExpr(TokenType::NUMBER_TOKEN);
			if (right)
			{
				m_exprTree.push_back(right);
				if (left) m_exprTree.push_back(BinaryExprSyntax(*left, *op, *right).clone());
				left = m_exprTree.back();
			}
		}
	}
	return m_exprTree;
}

std::shared_ptr<ExprNode> Parser::parsePrimaryExpr(TokenType type)
{
	if (type == TokenType::NUMBER_TOKEN)
	{
		Token token = match(type);
		if (token.getType() == TokenType::NUMBER_TOKEN) return NumberExprSyntax(token).clone();
	}
	else if (type == TokenType::PLUS_TOKEN || type == TokenType::MINUS_TOKEN || type == TokenType::MULTIPLY_TOKEN ||
			 type == TokenType::DIVIDE_TOKEN)
	{
		Token token = match(type);
		if (token.getType() == TokenType::PLUS_TOKEN || token.getType() == TokenType::MINUS_TOKEN ||
			token.getType() == TokenType::MULTIPLY_TOKEN || token.getType() == TokenType::DIVIDE_TOKEN)
		{
			return std::make_shared<ExprNode>(0, token.getText(), ExprType::OPERATOR_EXPR);
		}
	}
	return nullptr;
}
