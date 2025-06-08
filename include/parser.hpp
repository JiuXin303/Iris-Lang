/*
 *--------------------------------------------------------------------------------
 *文件名: parser.hpp
 *创建时间: 2025-06-09 00:59:54 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 03:50:03 Mon
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

#include "expr.hpp"

#include <vector>

namespace IrisLang
{
	class Parser
	{
		public:

		Parser() = default;

		/**
		* @brief 构造函数
		* @param text 要分析的源代码字符串
		*/
		Parser(std::string text);

		/**
		* @brief 解析二元表达式
		* @return std::vector<ExprNode*> 解析生成的表达式节点列表
		*/
		std::vector<ExprNode*> parseBinaryExpr();

		~Parser()
		{
			for (auto expr: m_exprChildrens) delete expr;
		}

		/**
		* @brief 获取解析后的令牌序列
		* @return std::vector<Token> 令牌序列
		*/
		std::vector<Token> getTokens() const { return m_tokens; }

		private:

		/**
		* @brief 匹配指定类型的令牌
		* @param type 要匹配的令牌类型
		* @return Token 匹配到的令牌
		*/
		Token match(TokenType type);

		/**
		* @brief 解析基本表达式
		* @param type 期望的令牌类型
		* @return ExprNode* 解析生成的表达式节点
		*/
		ExprNode* parsePrimaryExpr(TokenType type);

		int m_position = 0;								///< 当前解析位置
		std::vector<Token> m_tokens = {};				///< 令牌序列
		std::vector<ExprNode*> m_exprChildrens = {};	///< 表达式节点列表
	};
}	 // namespace IrisLang
