/*
 *--------------------------------------------------------------------------------
 *文件名: parser.cpp
 *创建时间: 2025-06-06 19:06:42 Fri
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 22:22:12 Sun
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#include <lexer.hpp>
#include <logger.hpp>
#include <parser.hpp>

using namespace IrisLang;

Parser::Parser(std::string text)
{
	Lexer lexer(text);
	for (Token token = lexer.GetNextToken(); token.GetType() != EndOfFileToken; token = lexer.GetNextToken())
	{
		if (token.GetType() == WhiteSpaceToken || token.GetType() == UnknownToken) continue;
		_tokens.push_back(token);
	}
}

Token Parser::Match(TokenType type)
{
	if (_position >= _tokens.size())
	{
		// 超出范围，返回一个特殊的 token
		LOG_WARNING("Parser", ": Match failed, unexpected end of file.");
		return Token(EndOfFileToken, _position, "");
	}
	if (_tokens[_position].GetType() == type) return _tokens[_position++];

	// 类型不匹配，跳过该 token 并返回一个特殊的 token
	LOG_WARNING("Parser", ": Match failed, unexpected token: " + _tokens[_position].GetText());
	_position++;
	return Token(UnknownToken, _position, "");
}

std::vector<ExprNode*> Parser::ParseBinaryExpr()
{
	try
	{
		// 解析二元表达式
		auto left = ParserPrimaryExpr(NumberToken);
		if (left) _ExprChildrens.push_back(left->Clone());
		while (_position < _tokens.size() &&
			   (_tokens[_position].GetType() == PlusToken || _tokens[_position].GetType() == MinusToken))
		{
			Token op = _tokens[_position++];
			_ExprChildrens.push_back(new ExprNode(op.GetText(), OperatorExpr));
			auto right = ParserPrimaryExpr(NumberToken);
			if (right)
			{
				_ExprChildrens.push_back(right->Clone());
				if (left)
				{
					_ExprChildrens.push_back(new BinaryExprSyntax(left->Clone(), op, right->Clone()));
					left = new BinaryExprSyntax(left, op, right);
				}
			}
		}
		return _ExprChildrens;
	}
	catch (...)
	{
		// 释放内存
		for (auto node: _ExprChildrens) delete node;
		throw;
	}
}

ExprNode* Parser::ParserPrimaryExpr(TokenType type)
{
	if (type == NumberToken)
	{
		Token token = Match(type);
		if (token.GetType() == NumberToken) return new NumberExprSyntax(token);
	}

	// 如果类型不匹配，返回 nullptr
	return nullptr;
}
