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



option(Build-test "Build test" ON)
if(Build-test)
	# 日志测试
	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    	add_definitions(-DUSE_LOGGER)
	endif()

	add_executable(iris-logger ${CMAKE_SOURCE_DIR}/test/logger.cpp)
	target_include_directories(iris-logger PUBLIC ${CMAKE_SOURCE_DIR}/include)
	target_compile_features(iris-logger PUBLIC cxx_std_23)
endif()

# Iris编译器
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    	add_definitions(-DUSE_LOGGER)
endif()
add_executable(iris-compiler ${iris-compiler_SRCS})
target_compile_features(iris-compiler PUBLIC cxx_std_23)
target_include_directories(iris-compiler PUBLIC ${CMAKE_SOURCE_DIR}/include)

