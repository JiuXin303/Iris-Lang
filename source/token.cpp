/*
 *--------------------------------------------------------------------------------
 *文件名: token.cpp
 *创建时间: 2025-06-06 16:27:21 Fri
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 21:53:13 Sun
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#include <token.hpp>

using namespace IrisLang;

std::string Token::TypeToString() const
{
	switch (_type)
	{
	case TokenType::NoneToken: return "NoneToken"; break;
	case TokenType::EndOfFileToken: return "EndOfFileToken"; break;
	case TokenType::UnknownToken: return "UnknownToken"; break;
	case TokenType::NumberToken: return "NumberToken"; break;
	case TokenType::WhiteSpaceToken: return "WhiteSpaceToken"; break;
	case TokenType::PlusToken: return "PlusToken"; break;
	case TokenType::MinusToken: return "MinusToken"; break;
	case TokenType::MultiplyToken: return "MultiplyToken"; break;
	case TokenType::DivideToken: return "DivideToken"; break;
	case TokenType::LeftParenthesisToken: return "LeftParenthesisToken"; break;
	case TokenType::RightParenthesisToken: return "RightParenthesisToken"; break;
	default: return "InvalidToken"; break;
	}
}
