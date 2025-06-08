/*
 *--------------------------------------------------------------------------------
 *文件名: lexer.hpp
 *创建时间: 2025-06-06 16:38:36 Fri
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 22:20:02 Sun
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#pragma once

#include "token.hpp"

namespace IrisLang
{
	class Lexer
	{

		public:

		Lexer() = default;

		/**
		* @brief 构造函数
		* @param[in] text 要解析的文本
		*/
		Lexer(std::string text): _text(text) {}

		/**
		* @brief 获取当前位置的字符
		* @return 返回当前位置的字符
		*/
		char GetCharCurrent(void)
		{
			if (_position >= _text.length()) return '\0';
			return _text[_position];
		}

		/**
		* @brief 移动到下一个字符
		*/
		void GetNextChar(void) { ++_position; }

		/**
		* @brief 解析一个令牌，自动移动到下一个令牌
		* @return 返回解析出的令牌
		*/
		Token GetNextToken(void);

		private:

		std::string _text = "";
		int _position = 0;
	};
}	 // namespace IrisLang
