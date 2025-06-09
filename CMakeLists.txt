cmake_minimum_required(VERSION 3.15)
project(iris-lang)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(iris-compiler_SRCS)
list(APPEND iris-compiler_SRCS ${CMAKE_SOURCE_DIR}/main.cpp)
list(APPEND iris-compiler_SRCS ${CMAKE_SOURCE_DIR}/source/token.cpp)
list(APPEND iris-compiler_SRCS ${CMAKE_SOURCE_DIR}/source/lexer.cpp)
list(APPEND iris-compiler_SRCS ${CMAKE_SOURCE_DIR}/source/parser.cpp)
list(APPEND iris-compiler_SRCS ${CMAKE_SOURCE_DIR}/source/expr.cpp)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	# Debug 配置开启 ASAN
	if(NOT (CMAKE_SYSTEM_NAME STREQUAL "Windows"))
		set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -fsanitize=address")
		set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-fsanitize=address")
	endif()
	
	add_custom_target(
	run_asan
	COMMAND ASAN_OPTIONS=detect_leaks=1 ./${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	DEPENDS iris-compiler)
endif()


if(BUILD-TEST)
	# 日志测试
	add_executable(iris-logger ${CMAKE_SOURCE_DIR}/test/logger.cpp)
	target_include_directories(iris-logger PUBLIC ${CMAKE_SOURCE_DIR}/include)
	target_compile_features(iris-logger PUBLIC cxx_std_23)
	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
		target_compile_definitions(iris-logger PUBLIC USE_LOGGER)
	endif()
endif()

# Iris编译器

add_executable(iris-compiler ${iris-compiler_SRCS})
target_compile_features(iris-compiler PUBLIC cxx_std_23)
target_include_directories(iris-compiler PUBLIC ${CMAKE_SOURCE_DIR}/include)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(iris-compiler PUBLIC USE_LOGGER)
endif()
