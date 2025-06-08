/*
 *--------------------------------------------------------------------------------
 *文件名: lexer.cpp
 *创建时间: 2025-06-09 00:59:17 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 02:14:48 Mon
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---
 *------------------------------------------------------
 */

#include <cctype>
#include <lexer.hpp>
#include <logger.hpp>

using namespace IrisLang;

Token Lexer::getNextToken()
{
	if (m_position >= m_text.length()) return Token(TokenType::END_OF_FILE_TOKEN, "\0");

	// 判断字符是否为数字
	if (std::isdigit(getCharCurrent()))
	{
		int start = m_position;
		while (std::isdigit(getCharCurrent())) getNextChar();
		return Token(TokenType::NUMBER_TOKEN, m_text.substr(start, m_position - start));
	}

	// 判断字符是否为空格
	if (std::isspace(getCharCurrent()))
	{
		int start = m_position;
		while (std::isspace(getCharCurrent())) getNextChar();
		return Token(TokenType::WHITE_SPACE_TOKEN, m_text.substr(start, m_position - start));
	}

	// 判断字符符号
	switch (getCharCurrent())
	{
	case '+': m_position++; return Token(TokenType::PLUS_TOKEN, "+");
	case '-': m_position++; return Token(TokenType::MINUS_TOKEN, "-");
	case '*': m_position++; return Token(TokenType::MULTIPLY_TOKEN, "*");
	case '/': m_position++; return Token(TokenType::DIVIDE_TOKEN, "/");
	case '(': m_position++; return Token(TokenType::LEFT_PARENTHESIS_TOKEN, "(");
	case ')': m_position++; return Token(TokenType::RIGHT_PARENTHESIS_TOKEN, ")");
	default: break;
	}

	// 未知字符
	int prevPosition = m_position++;
	LOG_WARNING("Lexer", "Unknown token: " + m_text.substr(prevPosition, 1));
	return Token(TokenType::UNKNOWN_TOKEN, m_text.substr(prevPosition, 1));
}
