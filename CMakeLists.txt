cmake_minimum_required(VERSION 3.16)
project(my_tree)

find_package(behaviortree_cpp REQUIRED)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含目录
include_directories(
    include
    ${behaviortree_cpp_INCLUDE_DIRS}
)

# 创建可执行文件
add_executable(my_tree
    src/main.cpp
    src/behavior_tree_nodes.cpp
)

# 链接库
target_link_libraries(my_tree
    behaviortree_cpp
)