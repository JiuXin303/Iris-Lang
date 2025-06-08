/*
 *--------------------------------------------------------------------------------
 *文件名: expr.hpp
 *创建时间: 2025-06-09 00:55:58 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 04:40:41 Mon
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

#include <logger.hpp>

namespace IrisLang
{
	enum class ExprType
	{
		NONE_EXPR,		  ///< 空表达式
		NUMBER_EXPR,	  ///< 数字表达式
		OPERATOR_EXPR,	  ///< 运算符表达式
		BINARY_EXPR,	  ///< 二元表达式
		UNKNOW_EXPR,	  ///< 未知表达式
	};

	/**
	* @brief 将类型转换为字符串
	* @param type 表达式类型
	* @return std::string 类型字符串
	*/
	std::string exprTypeToString(IrisLang::ExprType type);

	class ExprNode
	{
		public:

		ExprNode() = default;
		virtual ~ExprNode() = default;

		/**
		* @brief 构造函数
		* @param value 表达式的值
		* @param type 表达式的类型
		*/
		ExprNode(std::string value, ExprType type): m_value(value), m_type(type) {}

		std::string m_value = "";				  ///< 表达式的值
		ExprType m_type = ExprType::NONE_EXPR;	  ///< 表达式类型
	};

	class NumberExprSyntax: public ExprNode
	{
		public:

		NumberExprSyntax() = default;

		/**
		* @brief 构造函数
		* @param number 数字令牌
		*/
		NumberExprSyntax(Token number)
		{
			ExprNode::m_value = number.getText();
			ExprNode::m_type = ExprType::NUMBER_EXPR;
		}
	};

	class BinaryExprSyntax: public ExprNode
	{
		public:

		BinaryExprSyntax() {}

		/**
		* @brief 构造函数
		* @param left 左子表达式
		* @param op 运算符令牌
		* @param right 右子表达式
		*/
		BinaryExprSyntax(ExprNode left, ExprNode op, ExprNode right)
		{
			try
			{
				if (left.m_value.empty() || right.m_value.empty())
					throw std::runtime_error("BinaryExprSyntax: left or right is null");
			}
			catch (const std::exception& e)
			{
				LOG_ERROR("Expr", e.what());
			}
			ExprNode::m_value = left.m_value + op.m_value + right.m_value;
			ExprNode::m_type = ExprType::BINARY_EXPR;
		}

		ExprNode* clone() { return new ExprNode(ExprNode::m_value, ExprNode::m_type); }
	};
}	 // namespace IrisLang
