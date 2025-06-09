/*
 *--------------------------------------------------------------------------------
 *文件名: evaluator.hpp
 *创建时间: 2025-06-09 18:28:31 Mon
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 19:07:21 Mon
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#pragma once

#include <logger.hpp>
#include <string>

namespace IrisLang
{
	template<typename T>
	class Evaluator
	{
		public:

		Evaluator<T>() = default;
		virtual ~Evaluator<T>() = default;

		T evaluate(T left, std::string op, T right)
		{
			if (op == "+")
			{
				return left + right;
			}
			else if (op == "-")
			{
				return left - right;
			}
			else if (op == "*")
			{
				return left * right;
			}
			else if (op == "/")
			{
				if (right == 0)
				{
					try
					{
						throw "division by zero";
					}
					catch (std::exception& e)
					{
						LOG_ERROR("Evaluator", e.what());
						return T();
					}
				}
				return left / right;
			}
			else
			{
				return T();
			}
		}
	};

}	 // namespace IrisLang
