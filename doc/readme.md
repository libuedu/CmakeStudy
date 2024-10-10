# 嵌入式软件&算法应用开发实战（C/C++、CMake、QT、ROS1/ROS2）

* **QT、ROS、OPenCV、XXXLIB... ======>>> C/C++调用的库**
* **CMake可以用于管理复杂的项目构建过程**
* 项目实战，设计模式，编程优化技巧...
* 使得所有流程可以可视化跟踪调试
* 

**课程环境**：ubuntu20.04、C++17、CMake3.16、QT5、ROS-Noetic

    VSCODE、QtCreator

## 1 现代CMake项目实战基础

### 1.1 CMake编译一个样例程序

### 1.2 CMake编译一个动态库/静态库

### 1.3 CMake C/C++ & QT 联合编程

### 1.4 CMake C/C++ & QT & ROS 联合编程（常用库的添加 OPenCV、PCL、Eigen、Sophus、Ceres\...）

## 2 现代CMake项目实战——串口网口工具

### 2.1 单元测试

### 2.2 单例模式

### 2.3 QT串口编程

### 2.4 QT网络编程

### 2.5 QT UI布局

### 2.6 ROS消息订阅与发布

## 3 Ceres求解工程问题

### 3.1 直线

### 3.2 平面

### 3.3 曲线

### 3.4 位姿优化

### 3.5 IMU、相机、激光雷达等传感器联合标定求解

## 4 从零开始搭建一套SLAM（激光雷达+IMU+相机+编码器......）

## 5 嵌入式软件集成深度模型与大模型接入

## 6 嵌入式SoC体系架构

## 7 人工智能硬件产品

# 1、CMakeLists.txt基本指令

CMake是一个跨平台的自动化构建系统，它使用配置文件（CMakeLists.txt）来生成标准的构建文件。CMake非常灵活，可以用于管理复杂的项目构建过程，支持多种编译器和开发环境。

#### 三种不同的编译器：

1. G++:是GNU编译器集合（GCC）的一部分，专门用于编译C++程序
2. Clang:支持C、C++、Objective-C等语言，编译快
3. MinGW:windows环境

Ninja ：小型的构建系统，专注于速度，可与CMake配合使用

```cmake
#*************************
# 声明cmake最低的版本号
#************************
cmake_minimum_required(VERSION 3.16)

#*************************
# 项目名称
#************************
project(serialNetTools)

#*************************
# 设置编译类型
#************************
# set(DEFAULT_BUILD_TYPE "Release")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

#*************************
# 指定C++标准 
#************************
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 确保编译器支持所选标准

#************************
# 设置优化等级
#************************
set(CMAKE_CXX_FLAGS "-w")# 忽略警告信息
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb ${CMAKE_CXX_FLAGS}")# 设置DEBUG模式的编译选项
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g -ggdb ${CMAKE_CXX_FLAGS}")# 设置RELEASE模式的编译选项

#*************************
# 添加头文件
#************************
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#*************************
# 生成可执行文件
#************************
add_executable(${PROJECT_NAME}_test main_test.cpp)

# target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
```

```
set(VAL "a")    	# VAL 内容为 1 个值：a
set(VAL "a" b)  	# VAL 内容为 2 个值：a;b
set(VAL a;b)    	# VAL 内容为 2 个值：a;b
set(VAL a;b c)  	# VAL 内容为 3 个值：a;b;c
```

```
message(STATUS "C = ${C}")
```

逻辑、条件、循环等运算

```
if(xxx)
...
elseif(yyy)
...
else()
...
endif()
```

```
NOT>AND>OR
```

```
foreach while
```

```
function(my_func)
  # function
endfunction()
```

```
macro(myFun xx)
  # macro
endmacro()

调用
cmake_language(CALL myFun xx)
```

```
find_package(OpenGL 3.0 REQUIRED) #包名字 版本号 REQUIRED：表示一定要找到包,否则终止CMake过程 / QUIT:如果查找失败不会在屏幕输出
find_package(Qt5 COMPONENTS Widgets Core REQUIRED) #COMPONENTS：与REQUIRED类似，查找多个，查不到一个就失败
```

```cmake

add_library(mylib SHARED ${SOURCES}) #STATIC

target_link_libraries()
```

```
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
```

```cmake
# 安装目标
install(
  TARGETS my_executable my_library
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  EXPORT MyModules
)

# 安装导出集，这样其他项目可以使用find_package来找到my_library
install(EXPORT MyModules DESTINATION cmake)
```

```
<pre><div class="language-bash"><code class="language-bash"><span class="token">git</span><span> clone https://github.com/google/glog</span></code></div></pre>
```

```
cd glog
mkdir build && cd build
cmake ..
make
sudo make install
sudo ldconfig`
```



安装到指定目录 cmake -DCMAKE_INSTALL_PREFIX=/home/wzh/00_project/install_test .

```
export LD_LIBRARY_PATH=/home/wzh/00_project/02_mylesson/00_MyLesson/install/lib:$LD_LIBRARY_PATH
```


**使用 `patchelf`或 `chrpath`** ：
在安装后，可以使用 `patchelf`或 `chrpath`工具来修改已安装的可执行文件的RPATH：

patchelf --set-rpath '$ORIGIN/../lib' /path/to/installed/my_executable

如果使用CMake构建的项目，`make install` 会在构建目录中生成一个 `install_manifest.txt` 文件，其中列出了所有安装的文件。你可以使用这个文件来帮助找到并删除这些文件

```
cat install_manifest.txt | xargs sudo rm
```
