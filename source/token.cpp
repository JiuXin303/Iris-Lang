/*
 *--------------------------------------------------------------------------------
 *文件名: token.cpp
 *创建时间: 2025-06-09 00:58:14 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 03:23:41 Mon
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---
 *------------------------------------------------------
 */

#include <token.hpp>

using namespace IrisLang;

std::string IrisLang::tokenTypeToString(TokenType type)
{
	switch (type)
	{
	case TokenType::NONE_TOKEN: return "NONE_TOKEN";
	case TokenType::END_OF_FILE_TOKEN: return "END_OF_FILE_TOKEN";
	case TokenType::UNKNOWN_TOKEN: return "UNKNOWN_TOKEN";
	case TokenType::NUMBER_TOKEN: return "NUMBER_TOKEN";
	case TokenType::WHITE_SPACE_TOKEN: return "WHITE_SPACE_TOKEN";
	case TokenType::PLUS_TOKEN: return "PLUS_TOKEN";
	case TokenType::MINUS_TOKEN: return "MINUS_TOKEN";
	case TokenType::MULTIPLY_TOKEN: return "MULTIPLY_TOKEN";
	case TokenType::DIVIDE_TOKEN: return "DIVIDE_TOKEN";
	case TokenType::LEFT_PARENTHESIS_TOKEN: return "LEFT_PARENTHESIS_TOKEN";
	case TokenType::RIGHT_PARENTHESIS_TOKEN: return "RIGHT_PARENTHESIS_TOKEN";
	default: return "UNKNOWN_TOKEN_TYPE";
	}
}
