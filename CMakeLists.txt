cmake_minimum_required(VERSION 3.20)
project(Algorithm)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

if (MSVC)
    # add_compile_options("/source-charset:utf-8")
    add_compile_options(/utf-8)
endif ()

# 添加子目录
add_subdirectory(src)
add_subdirectory(tests)
# 如果通过FetchContent安装googletest失败,则自己下载googletest文件夹
# add_subdirectory(googletest的文件位置) 