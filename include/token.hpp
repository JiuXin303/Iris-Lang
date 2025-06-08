/*
 *--------------------------------------------------------------------------------
 *文件名: token.hpp
 *创建时间: 2025-06-09 00:57:46 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 03:21:53 Mon
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

#include <string>

namespace IrisLang
{
	enum class TokenType
	{
		NONE_TOKEN,				   ///< 空令牌
		END_OF_FILE_TOKEN,		   ///< 文件结束令牌
		UNKNOWN_TOKEN,			   ///< 未知令牌
		NUMBER_TOKEN,			   ///< 数字令牌
		WHITE_SPACE_TOKEN,		   ///< 空白字符令牌
		PLUS_TOKEN,				   ///< 加号令牌
		MINUS_TOKEN,			   ///< 减号令牌
		MULTIPLY_TOKEN,			   ///< 乘号令牌
		DIVIDE_TOKEN,			   ///< 除号令牌
		LEFT_PARENTHESIS_TOKEN,	   ///< 左括号令牌
		RIGHT_PARENTHESIS_TOKEN	   ///< 右括号令牌
	};

	/**
	* @brief 静态方法将TokenType转换为字符串
	* @param type 要转换的TokenType
	* @return std::string 类型对应的字符串表示
	*/
	std::string tokenTypeToString(TokenType type);

	class Token
	{
		public:

		Token() = default;

		/**
		* @brief 构造函数
		* @param type 令牌类型
		* @param position 令牌在源代码中的位置
		* @param text 令牌文本内容
		*/
		Token(TokenType type, std::string text): m_type(type), m_text(text) {}

		/**
		* @brief 获取令牌类型
		* @return TokenType 令牌类型
		*/
		TokenType getType() const { return m_type; }

		/**
		* @brief 获取令牌位置
		* @return int 令牌在源代码中的位置
		*/
		//int GetPosition() const { return m_position; }

		/**
		* @brief 获取令牌文本
		* @return std::string 令牌文本内容
		*/
		std::string getText() const { return m_text; }

		private:

		TokenType m_type = TokenType::NONE_TOKEN;	 ///< 令牌类型
		std::string m_text = "";					 ///< 令牌文本
	};

}	 // namespace IrisLang
