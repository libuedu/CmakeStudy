#*************************
# 声明cmake最低的版本号
#************************
# cmake_minimum_required(VERSION 3.16)

#*************************
# 项目名称
#************************
project(qt_ui)

#*************************
# 设置编译类型
#************************
# set(DEFAULT_BUILD_TYPE "Release")
# if(NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE "Release")
# endif()

#*************************
# 指定C++标准 
#************************
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON) # 确保编译器支持所选标准

#************************
# 设置优化等级
#************************
# set(CMAKE_CXX_FLAGS "-w")# 忽略警告信息
# set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb ${CMAKE_CXX_FLAGS}")# 设置DEBUG模式的编译选项
# set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g -ggdb ${CMAKE_CXX_FLAGS}")# 设置RELEASE模式的编译选项


message(STATUS "PROJECT_NAME = ${PROJECT_NAME}")

#*************************
# 添加头文件
#************************
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../common)
# include_directories(/home/wzh/00_project/02_mylesson/00_MyLesson/007_lesson/src/common)


message(STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

# find_library(MY_LIBRARY NAMES common PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../common/build)
# 将库的路径添加到链接器的搜索路径
# link_directories(${MY_LIBRARY})

#************************
# 导入QT库
#************************
find_package(Qt5 COMPONENTS Widgets Core SerialPort REQUIRED)


#************************
# 添加源文件
#************************
# GLOB_RECURSE: 这个选项告诉CMake递归地搜索所有子目录，而不仅仅是当前目录。
# QT_SOURCES: 这是用来存储找到的文件路径的变量名。
# RELATIVE: 这个选项指定了文件路径应该是相对于 CMAKE_CURRENT_SOURCE_DIR 的相对路径，而不是绝对路径。
# ${CMAKE_CURRENT_SOURCE_DIR}: 这是CMake预定义的变量，代表当前正在处理的CMakeLists.txt文件所在的目录。
# FOLLOW_SYMLINKS: 这个选项指示CMake跟随符号链接并包含符号链接指向的文件。
# *.*: 这是搜索模式，用来匹配所有以 .* 结尾的文件。
file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS *.h)
# file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS *.cpp)
set(QT_SOURCES mainwindow.cpp)

#三个用于处理Qt特定资源和代码生成的命令
QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS}) #从 .ui 文件自动生成用户界面类的头文件和源文件
QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})#将 .qrc 资源文件转换成可编译的C++源文件
QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC}) #.h 文件（包含Qt对象的头文件）自动生成moc（元对象编译器）文件，这些文件是Qt信号和槽机制所必需的

#*************************
# 打印消息
#************************
message(STATUS "CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "QT_FORMS_HPP : ${QT_FORMS_HPP}")
message(STATUS "QT_RESOURCES_CPP : ${QT_RESOURCES_CPP}")
message(STATUS "QT_MOC_HPP : ${QT_MOC_HPP}")
message(STATUS "QT_SOURCES : ${QT_SOURCES}")

#*************************
# 生成动态库
#************************
add_library(${PROJECT_NAME} SHARED  ${QT_SOURCES} 
                                    ${QT_RESOURCES_CPP} 
                                    ${QT_FORMS_HPP} 
                                    ${QT_MOC_HPP})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets common Qt5::SerialPort)




#*************************
# 生成可执行文件
#************************
# add_executable(${PROJECT_NAME}_test main_test.cpp serialNetTools.cpp)
add_executable(${PROJECT_NAME}_test main.cpp)

# target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}_test 
                        ${PROJECT_NAME} 
                        # qt_ui
                        )

#*************************
# 项目和库的导出安装
#************************
#特定的目标设置RPATH 绝对路径
# set_target_properties(${PROJECT_NAME}_test PROPERTIES
#   INSTALL_RPATH ${MY_CMAKE_INSTALL_DIRECTORY}/lib
# )

# set_target_properties(${PROJECT_NAME} PROPERTIES
#   INSTALL_RPATH ${MY_CMAKE_INSTALL_DIRECTORY}/lib
# )

#相对路径
set_target_properties(${PROJECT_NAME}_test PROPERTIES
  INSTALL_RPATH "$ORIGIN/../lib")
set_target_properties(${PROJECT_NAME}  PROPERTIES
  INSTALL_RPATH "$ORIGIN/../lib")

# 安装目标
# install(
#   TARGETS ${PROJECT_NAME}_test ${PROJECT_NAME} common 
#   EXPORT FindQtUi
#   RUNTIME DESTINATION ${MY_CMAKE_INSTALL_DIRECTORY}/bin
#   LIBRARY DESTINATION ${MY_CMAKE_INSTALL_DIRECTORY}/lib
#   ARCHIVE DESTINATION ${MY_CMAKE_INSTALL_DIRECTORY}/lib
# )

# #头文件
# install(FILES mainwindow.h ../common/myLog.h ../common/common.h
#         DESTINATION ${MY_CMAKE_INSTALL_DIRECTORY}/include) # 对于头文件

# # 安装导出集，这样其他项目可以使用find_package来找到my_library
# install(EXPORT FindQtUi
#        FILE FindQtUi.cmake
#        DESTINATION ${MY_CMAKE_INSTALL_DIRECTORY})     