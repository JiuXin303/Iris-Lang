/*
 *--------------------------------------------------------------------------------
 *文件名: logger.cpp
 *创建时间: 2025-06-08 16:18:18 Sun
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 19:38:29 Sun
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#include "logger.hpp"

auto main() -> int
{
	IrisLang::Logger logger("main", IrisLang::LogLevel::Info);
	logger.Trace("main", ": Logger test Trace");
	logger.Info("main", ": Logger test Info");
	logger.Debug("main", ": Logger test Debug");
	logger.Warning("main", ": Logger test Warning");
	logger.Error("main", ": Logger test Error");
	logger.Fatal("main", ": Logger test Fatal");
	logger.ShowAllLogs("main");	   // 打印所有日志
	return 0;
}
