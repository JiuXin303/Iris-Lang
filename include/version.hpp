/*
 *--------------------------------------------------------------------------------
 *文件名: version.hpp
 *创建时间: 2025-06-06 17:40:47 Fri
 *说明: 
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-06 18:22:57 Fri
 *--------------------------------------------------------------------------------
 *Copyright (c) 2025 九新
 *--------------------------------------------------------------------------------
 *更新历史:
 *--------------------------------------------------------------------------------
 *时间      		作者		信息
 *----------		---		------------------------------------------------------
 */

#pragma once

#define IRIS_VERSION_MAJOR	0
#define IRIS_VERSION_MINOR	1
#define IRIS_VERSION_PATCH	0
#define IRIS_VERSION_STRING "0.1.0"

#if defined(_WIN32) || defined(_WIN64)
	#define IRIS_PLATFORM_WINDOWS
	#define IRIS_PLATFORM_STRING "Windows"
#elif defined(__linux__)
	#define IRIS_PLATFORM_LINUX
	#define IRIS_PLATFORM_STRING "Linux"
#elif defined(__APPLE__)
	#define IRIS_PLATFORM_MACOS
	#define IRIS_PLATFORM_STRING "MacOS"
#else
	#error "Unsupported platform"
#endif
