/*
 *--------------------------------------------------------------------------------
 *文件名: token.hpp
 *创建时间: 2025-06-06 16:23:21 Fri
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 22:27:08 Sun
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#pragma once

#include <string>

namespace IrisLang
{
	enum TokenType
	{
		NoneToken,
		EndOfFileToken,
		UnknownToken,
		NumberToken,
		WhiteSpaceToken,
		PlusToken,
		MinusToken,
		MultiplyToken,
		DivideToken,
		LeftParenthesisToken,
		RightParenthesisToken
	};

	class Token
	{
		public:

		Token() = default;

		/**
		* @brief 构造函数
		* @param[in] type: 令牌类型
		* @param[in] position: 令牌位置
		* @param[in] text: 令牌文本
		*/
		Token(TokenType type, int position, std::string text): _type(type), _position(position), _text(text) {}

		/**
		* @brief 获取令牌类型
		* @return 返回令牌类型
		*/
		TokenType GetType() const { return _type; }

		/**
		* @brief 获取令牌位置
		* @return 返回令牌位置
		*/
		int GetPosition() const { return _position; }

		/**
		* @brief 获取令牌文本
		* @return 返回令牌文本
		*/
		std::string GetText() const { return _text; }

		/**
		* @brief 将令牌类型转换为字符串
		* @return 返回一个字符串
		*/
		std::string TypeToString() const;

		protected:

		TokenType _type = NoneToken;
		int _position = 0;
		std::string _text = "";
	};
}	 // namespace IrisLang
