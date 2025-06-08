/*
 *--------------------------------------------------------------------------------
 *文件名: expr.cpp
 *创建时间: 2025-06-09 00:57:05 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 03:23:32 Mon
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---
 *------------------------------------------------------
 */

/**
 * @file expr.cpp
 * @brief 表达式节点方法的实现
 */

#include <expr.hpp>

using namespace IrisLang;

std::string IrisLang::exprTypeToString(ExprType type)
{
	switch (type)
	{
	case ExprType::NONE_EXPR: return "NoneExpr"; break;
	case ExprType::NUMBER_EXPR: return "NumberExpr"; break;
	case ExprType::OPERATOR_EXPR: return "OperatorExpr"; break;
	case ExprType::BINARY_EXPR: return "BinaryExpr"; break;
	case ExprType::UNKNOW_EXPR: return "UnknowExpr"; break;
	default: return "UnknownExpr"; break;
	}
}
