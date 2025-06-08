/*
 *--------------------------------------------------------------------------------
 *文件名: lexer.cpp
 *创建时间: 2025-06-06 16:56:34 Fri
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 21:38:29 Sun
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#include <cctype>
#include <lexer.hpp>
#include <logger.hpp>

using namespace IrisLang;

Token Lexer::GetNextToken(void)
{
	if (_position >= _text.length()) return Token(EndOfFileToken, _position, "\0");

	// 判断字符是否为数字
	if (std::isdigit(GetCharCurrent()))
	{
		int start = _position;
		while (std::isdigit(GetCharCurrent())) GetNextChar();
		return Token(NumberToken, start, _text.substr(start, _position - start));
	}

	// 判断字符是否为空格
	if (std::isspace(GetCharCurrent()))
	{
		int start = _position;
		while (std::isspace(GetCharCurrent())) GetNextChar();
		return Token(WhiteSpaceToken, _position, _text.substr(start, _position - start));
	}

	// 判断字符符号
	switch (GetCharCurrent())
	{
	case '+':
		// position先赋值在+1
		return Token(PlusToken, _position++, "+");
		break;
	case '-': return Token(MinusToken, _position++, "-"); break;
	case '*': return Token(MultiplyToken, _position++, "*"); break;
	case '/': return Token(DivideToken, _position++, "/"); break;
	case '(': return Token(LeftParenthesisToken, _position++, "("); break;
	case ')': return Token(RightParenthesisToken, _position++, ")");
	default: break;
	}

	// 未知字符
	int prevPosition = _position++;
	LOG_WARNING("Lexer", "Unknown token: " + _text.substr(prevPosition, 1));
	return Token(UnknownToken, prevPosition, _text.substr(prevPosition, 1));
}
