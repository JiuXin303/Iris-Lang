/*
 *--------------------------------------------------------------------------------
 *文件名: logger.hpp
 *创建时间: 2025-06-08 19:32:44 Sun
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-09 19:36:49 Mon
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

#include <chrono>
#include <iomanip>
#include <iostream>
#include <map>
#include <thread>

namespace IrisLang
{
	enum class LogLevel
	{
		TRACE_LEVEL,	  ///< 跟踪级别日志
		INFO_LEVEL,		  ///< 信息级别日志
		DEBUG_LEVEL,	  ///< 调试级别日志
		WARNING_LEVEL,	  ///< 警告级别日志
		ERROR_LEVEL,	  ///< 错误级别日志
		FATAL_LEVEL		  ///< 致命错误级别日志
	};

	// ANSI 颜色代码
	const std::string ColorTrace = "\033[37m";		///< 白色
	const std::string ColorInfo = "\033[32m";		///< 绿色
	const std::string ColorDebug = "\033[36m";		///< 青色
	const std::string ColorWarning = "\033[33m";	///< 黄色
	const std::string ColorError = "\033[31m";		///< 红色
	const std::string ColorFatal = "\033[35m";		///< 紫色
	const std::string ColorReset = "\033[0m";		///< 重置颜色

	class Logger
	{
		public:

		Logger() = default;

		/**
		* @brief 构造函数，创建指定名称和级别的日志记录器
		* @param name 日志记录器名称
		* @param level 日志级别
		*/
		explicit Logger(std::string name, LogLevel level) { m_logs[name] = std::make_pair("", level); }

		/**
		* @brief 打印日志
		* @param name 日志记录器名称
		* @param message 日志消息
		* @param level 日志级别
		*/
		static void printLog(std::string name, std::string message, LogLevel level)
		{
			Logger(name, level).printPrimaryLog(name, message, level);
		}

		/**
		* @brief 添加新的日志记录器
		* @param name 日志记录器名称
		* @param level 日志级别
		*/
		void addLogger(std::string name, LogLevel level)
		{
			if (m_logs.find(name) != m_logs.end())
			{
				std::cout << "Logger already exists: " << name << std::endl;
				return;
			}
			m_logs[name] = std::make_pair("", level);
		}

		/**
		* @brief 设置日志记录器的级别
		* @param name 日志记录器名称
		* @param level 新的日志级别
		*/
		void setLogLevel(std::string name, LogLevel level)
		{
			if (m_logs.find(name) != m_logs.end()) m_logs[name].second = level;
			else std::cout << "Logger not found: " << name << std::endl;
		}

		/**
		* @brief 记录跟踪级别日志
		* @param name 日志记录器名称
		* @param message 日志消息
		*/
		void trace(std::string name, std::string message) { printPrimaryLog(name, message, LogLevel::TRACE_LEVEL); }

		/**
		* @brief 记录信息级别日志
		* @param name 日志记录器名称
		* @param message 日志消息
		*/
		void info(std::string name, std::string message) { printPrimaryLog(name, message, LogLevel::INFO_LEVEL); }

		/**
		* @brief 记录调试级别日志
		* @param name 日志记录器名称
		* @param message 日志消息
		*/
		void debug(std::string name, std::string message) { printPrimaryLog(name, message, LogLevel::DEBUG_LEVEL); }

		/**
		* @brief 记录警告级别日志
		* @param name 日志记录器名称
		* @param message 日志消息
		*/
		void warning(std::string name, std::string message) { printPrimaryLog(name, message, LogLevel::WARNING_LEVEL); }

		/**
		* @brief 记录错误级别日志
		* @param name 日志记录器名称
		* @param message 日志消息
		*/
		void error(std::string name, std::string message) { printPrimaryLog(name, message, LogLevel::ERROR_LEVEL); }

		/**
		* @brief 记录致命错误级别日志
		* @param name 日志记录器名称
		* @param message 日志消息
		*/
		void fatal(std::string name, std::string message) { printPrimaryLog(name, message, LogLevel::FATAL_LEVEL); }

		/**
		* @brief 显示指定日志记录器的所有日志
		* @param name 日志记录器名称
		*/
		void showAllLogs(std::string name)
		{
#ifdef USE_LOGGER
			if (m_logs.find(name) != m_logs.end())
			{
				std::cout << "All logs of " << name << ":\n";
				std::cout << m_logs[name].first;
			}
			else
			{
				std::cout << "Logger not found: " << name << std::endl;
			}
#endif
		}

		private:

		/**
		* @brief 将日志级别转换为字符串
		* @param level 日志级别
		* @return std::string 对应的字符串表示
		*/
		std::string levelToString(LogLevel level)
		{
			switch (level)
			{
			case LogLevel::TRACE_LEVEL: return "TRACE";
			case LogLevel::INFO_LEVEL: return "INFO";
			case LogLevel::DEBUG_LEVEL: return "DEBUG";
			case LogLevel::WARNING_LEVEL: return "WARNING";
			case LogLevel::ERROR_LEVEL: return "ERROR";
			case LogLevel::FATAL_LEVEL: return "FATAL";
			default: return "UNKNOWN";
			}
		}

		/**
		* @brief 获取指定日志级别对应的颜色代码
		* @param level 日志级别
		* @return std::string 对应的ANSI颜色代码
		*/
		std::string getColor(LogLevel level)
		{
			switch (level)
			{
			case LogLevel::TRACE_LEVEL: return ColorTrace;
			case LogLevel::INFO_LEVEL: return ColorInfo;
			case LogLevel::DEBUG_LEVEL: return ColorDebug;
			case LogLevel::WARNING_LEVEL: return ColorWarning;
			case LogLevel::ERROR_LEVEL: return ColorError;
			case LogLevel::FATAL_LEVEL: return ColorFatal;
			default: return ColorReset;
			}
		}

#ifdef USE_LOGGER
		/**
		* @brief 打印日志
		* @param name 日志记录器名称
		* @param message 日志消息
		* @param level 日志级别(默认为Info)
		*/
		void printPrimaryLog(std::string name, std::string message, LogLevel level = LogLevel::INFO_LEVEL)
		{
			if (m_logs.find(name) != m_logs.end() && level >= m_logs[name].second)
			{
				// 获取当前时间
				auto now = std::chrono::system_clock::now();
				auto now_time = std::chrono::system_clock::to_time_t(now);
				auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

				// 格式化时间
				std::tm tm = *std::localtime(&now_time);
				std::ostringstream time_oss;
				time_oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << '.' << std::setfill('0') << std::setw(3)
						 << now_ms.count();

				// 获取线程ID
				std::thread::id thread_id = std::this_thread::get_id();

				std::string levelStr = levelToString(level);
				std::string color = getColor(level);
				std::ostringstream oss;
				oss << color << "[" << time_oss.str() << "]"				  // 时间戳
					<< "[" << std::left << std::setw(7) << levelStr << "]"	  // 日志级别
					<< "[" << thread_id << "]"								  // 线程ID
					<< "[" << name << "] "									  // 日志名称
					<< message << ColorReset << "\n";

				std::string logEntry = oss.str();
				std::cout << logEntry;
				m_logs[name].first += logEntry;
			}
		}
#else
		void printPrimaryLog(std::string name, std::string message, LogLevel level = LogLevel::INFO_LEVEL) {}
#endif

		std::map<std::string, std::pair<std::string, LogLevel>> m_logs;	   ///< 日志记录器存储
	};
}	 // namespace IrisLang

#define LOG_TRACE(name, message)   IrisLang::Logger::printLog(name, message, IrisLang::LogLevel::TRACE_LEVEL)
#define LOG_INFO(name, message)	   IrisLang::Logger::printLog(name, message, IrisLang::LogLevel::INFO_LEVEL)
#define LOG_DEBUG(name, message)   IrisLang::Logger::printLog(name, message, IrisLang::LogLevel::DEBUG_LEVEL)
#define LOG_WARNING(name, message) IrisLang::Logger::printLog(name, message, IrisLang::LogLevel::WARNING_LEVEL)
#define LOG_ERROR(name, message)   IrisLang::Logger::printLog(name, message, IrisLang::LogLevel::ERROR_LEVEL)
#define LOG_FATAL(name, message)   IrisLang::Logger::printLog(name, message, IrisLang::LogLevel::FATAL_LEVEL)
