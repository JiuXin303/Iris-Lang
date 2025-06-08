/*
 *--------------------------------------------------------------------------------
 *文件名: expr.hpp
 *创建时间: 2025-06-06 19:55:01 Fri
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 22:11:29 Sun
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

#include <logger.hpp>

namespace IrisLang
{
	/**
	* @brief 表达式类型
	*/
	enum ExprType
	{
		NoneExpr,		 ///< 空表达式
		NumberExpr,		 ///< 数字表达式
		OperatorExpr,	 ///< 运算符表达式
		BinaryExpr,		 ///< 二元表达式
		UnknowExpr,		 ///< 未知表达式
	};

	/**
	* @brief 表达式节点
	*/
	typedef struct ExprNode
	{
		public:

		ExprNode() = default;

		/**
		* @brief 构造函数
		* @param[in] value 表达式的值
		* @param[in] type 表达式的类型
		*/
		ExprNode(std::string value, ExprType type): _Value(value), _Type(type) {}

		/**
		* @brief 将类型转换为字符串
		* @return 类型字符串
		*/
		std::string TypeToString() const;

		/**
		* @brief 克隆节点
		* @return 克隆的节点
		*/
		virtual ExprNode* Clone() const { return new ExprNode(_Value, _Type); }

		std::string _Value = "";

		ExprType _Type = NoneExpr;

	} ExprNode;

	/**
	* @brief 数字表达式
	*/
	class NumberExprSyntax: public ExprNode
	{
		public:

		NumberExprSyntax() = default;

		/**
		* @brief 构造函数
		* @param[in] number 数字令牌
		*/
		NumberExprSyntax(Token number)
		{
			ExprNode::_Value = number.GetText();
			ExprNode::_Type = NumberExpr;
		}

		/**
		* @brief 克隆节点
		* @return 克隆的节点
		*/
		ExprNode* Clone() const override { return new NumberExprSyntax(*this); }
	};

	/**
	* @brief 二元表达式
	*/
	class BinaryExprSyntax: public ExprNode
	{
		public:

		BinaryExprSyntax() {}

		/**
		* @brief 构造函数
		* @param[in] left 左子表达式
		* @param[in] op 运算符
		* @param[in] right 右子表达式
		*/
		BinaryExprSyntax(ExprNode* left, Token op, ExprNode* right): _Left(left), _Op(op), _Right(right)
		{
			try
			{
				if (left == nullptr || right == nullptr) throw std::runtime_error(": left or right is null");
			}
			catch (const std::exception& e)
			{
				LOG_ERROR("BinaryExprSyntax", e.what());
			}
			ExprNode::_Value = _Left->_Value + _Op.GetText() + _Right->_Value;
			ExprNode::_Type = BinaryExpr;
		}

		~BinaryExprSyntax()
		{
			if (_Left) delete _Left;
			if (_Right) delete _Right;
		}

		/**
		* @brief 获取左子表达式
		* @return 左子表达式
		*/
		Token GetOp() const { return _Op; }

		/**
		* @brief 获取左子表达式
		* @return 左子表达式
		*/
		ExprNode* GetLeft() const { return _Left; }

		/**
		* @brief 获取右子表达式
		* @return 右子表达式
		*/
		ExprNode* GetRight() const { return _Right; }

		/**
		* @brief 克隆节点
		* @return 克隆的节点
		*/
		ExprNode* Clone() const override { return new BinaryExprSyntax(_Left->Clone(), _Op, _Right->Clone()); }

		private:

		ExprNode* _Left = {};
		Token _Op;
		ExprNode* _Right = {};
	};
}	 // namespace IrisLang
