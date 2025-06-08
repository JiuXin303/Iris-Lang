/*
 *--------------------------------------------------------------------------------
 *文件名: logger.cpp
 *创建时间: 2025-06-09 01:01:11 Mon
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 02:54:02 Mon
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---
 *------------------------------------------------------
 */

#include <logger.hpp>

int main()
{
	// 创建日志记录器实例
	IrisLang::Logger logger("main", IrisLang::LogLevel::INFO_LEVEL);

	// 测试各种日志级别
	logger.trace("main", "Logger test trace");
	logger.info("main", "Logger test info");
	logger.debug("main", "Logger test debug");
	logger.warning("main", "Logger test warning");
	logger.error("main", "Logger test error");
	logger.fatal("main", "Logger test fatal");

	// 显示所有记录的日志
	logger.showAllLogs("main");

	return 0;
}
