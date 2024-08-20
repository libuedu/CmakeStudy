#*************************
# 声明cmake最低的版本号
#************************
cmake_minimum_required(VERSION 3.16)

#*************************
# 项目名称
#************************
project(myLogTest)

#*************************
# 设置编译类型
#************************
# set(DEFAULT_BUILD_TYPE "Debug")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

#************************
# 设置优化等级
#************************
set(CMAKE_CXX_FLAGS "-w")# 忽略警告信息
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb ${CMAKE_CXX_FLAGS}")# 设置DEBUG模式的编译选项
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g -ggdb ${CMAKE_CXX_FLAGS}")# 设置RELEASE模式的编译选项

#*************************
# 添加头文件
#************************
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#*************************
# 添加库的路径
#************************
# set(CMAKE_MODULE_PATH "/home/wzh/00_project/02_mylesson/00_MyLesson/install")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../install)

message(STATUS "CMAKE_INCLUDE_PATH : ${CMAKE_MODULE_PATH}")

#*************************
# 寻找库
#************************
find_package(QtUi REQUIRED)

#*************************
# 添加库的头文件
#************************
set(QtUi_INCLUDE_DIRS ${CMAKE_MODULE_PATH}/include ${QtUi_INCLUDE_DIRS})
message(STATUS "QtUi_INCLUDE_DIRS : ${QtUi_INCLUDE_DIRS}")
include_directories(${QtUi_INCLUDE_DIRS})

#*************************
# 生成可执行文件
#************************
add_executable(${PROJECT_NAME}
                main.cpp
                )

#*************************
# 链接库
#************************
target_link_libraries(${PROJECT_NAME} common)               
