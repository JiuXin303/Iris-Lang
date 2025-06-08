/*
 *--------------------------------------------------------------------------------
 *文件名: logger.hpp
 *创建时间: 2025-06-08 19:32:44 Sun
 *说明:
 *作者: 九新
 *主机: LAPTOP-VAKT0BRG
 *--------------------------------------------------------------------------------
 *最后编辑作者: 九新
 *最后修改时间: 2025-06-08 21:41:02 Sun
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

#include <iomanip>
#include <iostream>
#include <map>

namespace IrisLang
{
	/**
	* @brief 日志级别枚举
	* @details 定义不同级别的日志类型
	*/
	enum class LogLevel
	{
		Trace,		///< 跟踪级别日志
		Info,		///< 信息级别日志
		Debug,		///< 调试级别日志
		Warning,	///< 警告级别日志
		Error,		///< 错误级别日志
		Fatal		///< 致命错误级别日志
	};

	// ANSI 颜色代码
	const std::string ColorTrace = "\033[37m";		///< 白色
	const std::string ColorInfo = "\033[32m";		///< 绿色
	const std::string ColorDebug = "\033[36m";		///< 青色
	const std::string ColorWarning = "\033[33m";	///< 黄色
	const std::string ColorError = "\033[31m";		///< 红色
	const std::string ColorFatal = "\033[35m";		///< 紫色
	const std::string ColorReset = "\033[0m";		///< 重置颜色

	/**
	* @brief 日志记录器类
	* @details 提供多级别、带颜色的日志记录功能
	*/
	class Logger
	{
		public:

		/**
		* @brief 默认构造函数
		*/
		Logger() = default;

		/**
		* @brief 构造函数，创建指定名称和级别的日志记录器
		* @param[in] name 日志记录器名称
		* @param[in] level 日志级别
		*/
		explicit Logger(std::string name, LogLevel level) { m_logs[name] = std::make_pair("", level); }

		/**
		* @brief 打印日志
		* @param[in] name 日志记录器名称
		* @param[in] message 日志消息
		* @param[in] level 日志级别
		*/
		static void PrintLog(std::string name, std::string message, LogLevel level)
		{
			Logger(name, level).PrimaryPrintLog(name, message, level);
		}

		/**
		* @brief 添加新的日志记录器
		* @param[in] name 日志记录器名称
		* @param[in] level 日志级别
		*/
		void AddLogger(std::string name, LogLevel level)
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
		* @param[in] name 日志记录器名称
		* @param[in] level 新的日志级别
		*/
		void SetLogLevel(std::string name, LogLevel level)
		{
			if (m_logs.find(name) != m_logs.end()) m_logs[name].second = level;
			else std::cout << "Logger not found: " << name << std::endl;
		}

		/**
		* @brief 记录跟踪级别日志
		* @param[in] name 日志记录器名称
		* @param[in] message 日志消息
		*/
		void Trace(std::string name, std::string message) { PrintLog(name, message, LogLevel::Trace); }

		/**
		* @brief 记录信息级别日志
		* @param[in] name 日志记录器名称
		* @param[in] message 日志消息
		*/
		void Info(std::string name, std::string message) { PrintLog(name, message, LogLevel::Info); }

		/**
		* @brief 记录调试级别日志
		* @param[in] name 日志记录器名称
		* @param[in] message 日志消息
		*/
		void Debug(std::string name, std::string message) { PrintLog(name, message, LogLevel::Debug); }

		/**
		* @brief 记录警告级别日志
		* @param[in] name 日志记录器名称
		* @param[in] message 日志消息
		*/
		void Warning(std::string name, std::string message) { PrintLog(name, message, LogLevel::Warning); }

		/**
		* @brief 记录错误级别日志
		* @param[in] name 日志记录器名称
		* @param[in] message 日志消息
		*/
		void Error(std::string name, std::string message) { PrintLog(name, message, LogLevel::Error); }

		/**
		* @brief 记录致命错误级别日志
		* @param[in] name 日志记录器名称
		* @param[in] message 日志消息
		*/
		void Fatal(std::string name, std::string message) { PrintLog(name, message, LogLevel::Fatal); }

		/**
		* @brief 显示指定日志记录器的所有日志
		* @param[in] name 日志记录器名称
		*/
		void ShowAllLogs(std::string name)
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
		* @param[in] level 日志级别
		* @return 对应的字符串表示
		*/
		std::string_view LevelToString(LogLevel level)
		{
			switch (level)
			{
			case LogLevel::Trace: return "TRACE";
			case LogLevel::Info: return "INFO";
			case LogLevel::Debug: return "DEBUG";
			case LogLevel::Warning: return "WARNING";
			case LogLevel::Error: return "ERROR";
			case LogLevel::Fatal: return "FATAL";
			default: return "UNKNOWN";
			}
		}

		/**
		* @brief 获取指定日志级别对应的颜色代码
		* @param[in] level 日志级别
		* @return 对应的ANSI颜色代码
		*/
		std::string GetColor(LogLevel level)
		{
			switch (level)
			{
			case LogLevel::Trace: return ColorTrace;
			case LogLevel::Info: return ColorInfo;
			case LogLevel::Debug: return ColorDebug;
			case LogLevel::Warning: return ColorWarning;
			case LogLevel::Error: return ColorError;
			case LogLevel::Fatal: return ColorFatal;
			default: return ColorReset;
			}
		}

#ifdef USE_LOGGER
		/**
		* @brief 打印日志
		* @param[in] name 日志记录器名称
		* @param[in] message 日志消息
		* @param[in] level 日志级别(默认为Info)
		*/
		void PrimaryPrintLog(std::string name, std::string message, LogLevel level = LogLevel::Info)
		{
			if (m_logs.find(name) != m_logs.end() && level >= m_logs[name].second)
			{
				std::string levelStr = std::string(LevelToString(level));
				std::string color = GetColor(level);
				std::ostringstream oss;
				oss << color << "[" << std::left << std::setw(7) << levelStr << " " << name << "]" << message
					<< ColorReset << "\n";
				std::string logEntry = oss.str();
				std::cout << logEntry;
				m_logs[name].first += logEntry;
			}
		}
#else
		void PrimaryPrintLog(std::string name, std::string message, LogLevel level = LogLevel::Info) {}
#endif

		std::map<std::string, std::pair<std::string, LogLevel>> m_logs;	   ///< 日志记录器存储
	};
}	 // namespace IrisLang

#define LOG_TRACE(name, message)   IrisLang::Logger::PrintLog(name, message, IrisLang::LogLevel::Trace)
#define LOG_INFO(name, message)	   IrisLang::Logger::PrintLog(name, message, IrisLang::LogLevel::Info)
#define LOG_DEBUG(name, message)   IrisLang::Logger::PrintLog(name, message, IrisLang::LogLevel::Debug)
#define LOG_WARNING(name, message) IrisLang::Logger::PrintLog(name, message, IrisLang::LogLevel::Warning)
#define LOG_ERROR(name, message)   IrisLang::Logger::PrintLog(name, message, IrisLang::LogLevel::Error)
#define LOG_FATAL(name, message)   IrisLang::Logger::PrintLog(name, message, IrisLang::LogLevel::Fatal)
