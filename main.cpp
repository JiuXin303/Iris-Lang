/*
 *--------------------------------------------------------------------------------
 *文件名: main.cpp
 *创建时间: 2025-06-06 16:04:47 Fri
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 23:51:44 Sun
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#include <chrono>
#include <iostream>
#include <parser.hpp>
#include <version.hpp>
using namespace std;

// 打印表达式树
void PrettyPrint(IrisLang::ExprNode node, std::string indent = "")
{
	cout << indent;
	cout << "Type: " << node.TypeToString();
	if (node._Value.length() != 0) cout << " Value: " << node._Value << endl;
}

auto main(int argc, char* argv[]) -> int
{
	string input = "";
	bool is_running = true;

	// 打印基本信息
	cout << "Iris Lang v" << IRIS_VERSION_STRING << "." << endl;
	cout << "Platfrom: " << IRIS_PLATFORM_STRING << "." << endl;
	cout << "Input 'exit()' to exit." << endl;

	while (is_running)
	{
		cout << ">> ";
		getline(cin, input);
		if (input == "exit()")
		{
			is_running = false;
			break;
		}
		auto start_time = chrono::system_clock::now();

		// 解析表达式
		IrisLang::Parser parser(input);
		auto expr = parser.ParseBinaryExpr();
		std::string indent = "";
		for (auto expr_it = expr.rbegin(); expr_it != expr.rend(); expr_it++)
		{
			IrisLang::ExprNode node = **expr_it;
			if (node._Type == IrisLang::BinaryExpr)
			{
				PrettyPrint(node, indent);
				indent += "|————";
			}
			else
			{
				PrettyPrint(node, indent);
			}
		};

		// 打印运行时间
		auto end_time = chrono::system_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
		time_t end_time_t = chrono::system_clock::to_time_t(end_time);
		tm* timeinfo = localtime(&end_time_t);
		cout << "Now Time:" << timeinfo->tm_hour << ":" << timeinfo->tm_min << ":" << timeinfo->tm_sec << " "
			 << "Used Time: " << duration.count() << "us" << endl;
	}

	return 0;
}
