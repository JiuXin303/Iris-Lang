/*
 *--------------------------------------------------------------------------------
 *文件名: lexer.hpp
 *创建时间: 2025-06-09 00:58:42 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 01:10:22 Mon
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---
 *------------------------------------------------------
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
		* @param text 要分析的源代码字符串
		*/
		Lexer(std::string text): m_text(text) {}

		/**
		* @brief 获取当前位置的字符
		* @return char 当前字符，如果到达结尾则返回'\0'
		*/
		char getCharCurrent()
		{
			if (m_position >= m_text.length()) return '\0';
			return m_text[m_position];
		}

		/**
		* @brief 移动到下一个字符
		*/
		void getNextChar() { ++m_position; }

		/**
		* @brief 解析并返回下一个令牌
		* @return Token 解析出的令牌对象
		*/
		Token getNextToken();

		private:

		std::string m_text = "";	///< 要分析的源代码文本
		int m_position = 0;			///< 当前分析位置
	};
}	 // namespace IrisLang
