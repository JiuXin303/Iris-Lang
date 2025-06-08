/*
 *--------------------------------------------------------------------------------
 *文件名: parser.hpp
 *创建时间: 2025-06-06 19:00:30 Fri
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 22:25:37 Sun
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#pragma once
#include "expr.hpp"

#include <stdexcept>
#include <vector>

namespace IrisLang
{
	class Parser
	{
		public:

		Parser() = default;

		/**
		* @brief 构造函数
		* @param[in] text 待解析的文本
		*/
		Parser(std::string text);

		/**
		* @brief 解析二元表达式
		* @return 表达式节点的向量
		*/
		std::vector<ExprNode*> ParseBinaryExpr();

		~Parser()
		{
			for (auto expr: _ExprChildrens) delete expr;
		}

		/**
		* @brief 获取解析后的表达式节点
		* @return 表达式节点的向量
		*/
		std::vector<Token> GetTokens() const { return _tokens; }

		private:

		/**
		* @brief 获取当前令牌，自动移动位置
		* @return 当前令牌
		*/
		Token GetNextToken()
		{
			if (_position >= _tokens.size()) throw std::out_of_range("GetNextToken: position out of range");
			return _tokens[_position++];
		}

		/**
		* @brief 匹配指定类型令牌
		* @param[in] type 要匹配的令牌类型
		* @return 匹配到的令牌
		*/
		Token Match(TokenType type);

		/**
		* @brief 解析一个表达式
		* @return 表达式节点
		*/
		ExprNode* ParserPrimaryExpr(TokenType type);

		int _position = 0;
		std::vector<Token> _tokens = {};
		std::vector<ExprNode*> _ExprChildrens = {};
	};
}	 // namespace IrisLang
