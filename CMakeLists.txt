cmake_minimum_required(VERSION 3.23)
project(CPPTemplateTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(cmake/BuildType.cmake)

# 查找 PCL 包
find_package(PCL 1.12 REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE INCLUDE "include/*.h" "include/*.hpp")
message(STATUS "INCLUDE: ${INCLUDE}")
list(REMOVE_DUPLICATES src_files)

message(STATUS "cmake module path : ${CMAKE_MODULE_PATH}")
include(CMakePrintHelpers)
cmake_print_variables(SOURCES)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDE}) 

# 链接 PCL 库
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES})

# 包含 PCL 头文件
target_include_directories(${PROJECT_NAME} PUBLIC ${PCL_INCLUDE_DIRS} ${CMAKE_CURRENT_LIST_DIR}/include)

# 定义编译选项（防止 PCL 中的警告被视为错误）
target_compile_definitions(${PROJECT_NAME} PUBLIC ${PCL_DEFINITIONS})

include(cmake/GitCommitHash.cmake)
get_git_info(PACKAGE_GIT_VERSION PACKAGE_COMMIT_HASH PACKAGE_BRANCH_NAME)
message(STATUS "PACKAGE_GIT_VERSION: ${PACKAGE_COMMIT_HASH}")
