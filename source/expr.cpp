/*
 *--------------------------------------------------------------------------------
 *文件名: expr.cpp
 *创建时间: 2025-06-07 14:42:27 Sat
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 21:52:56 Sun
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#include <expr.hpp>

using namespace IrisLang;

std::string ExprNode::TypeToString() const
{
	switch (_Type)
	{
	case NoneExpr: return "NoneExpr"; break;
	case NumberExpr: return "NumberExpr"; break;
	case BinaryExpr: return "BinaryExpr"; break;
	case OperatorExpr: return "OperatorExpr"; break;
	default: return "UnknownExpr"; break;
	}
}
