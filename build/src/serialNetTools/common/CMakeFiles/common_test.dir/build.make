# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/u/Desktop/cmakeproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/u/Desktop/cmakeproject/build

# Include any dependencies generated for this target.
include src/serialNetTools/common/CMakeFiles/common_test.dir/depend.make

# Include the progress variables for this target.
include src/serialNetTools/common/CMakeFiles/common_test.dir/progress.make

# Include the compile flags for this target's objects.
include src/serialNetTools/common/CMakeFiles/common_test.dir/flags.make

src/serialNetTools/common/CMakeFiles/common_test.dir/main_common_test.cpp.o: src/serialNetTools/common/CMakeFiles/common_test.dir/flags.make
src/serialNetTools/common/CMakeFiles/common_test.dir/main_common_test.cpp.o: ../src/serialNetTools/common/main_common_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/Desktop/cmakeproject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/serialNetTools/common/CMakeFiles/common_test.dir/main_common_test.cpp.o"
	cd /home/u/Desktop/cmakeproject/build/src/serialNetTools/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common_test.dir/main_common_test.cpp.o -c /home/u/Desktop/cmakeproject/src/serialNetTools/common/main_common_test.cpp

src/serialNetTools/common/CMakeFiles/common_test.dir/main_common_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common_test.dir/main_common_test.cpp.i"
	cd /home/u/Desktop/cmakeproject/build/src/serialNetTools/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/Desktop/cmakeproject/src/serialNetTools/common/main_common_test.cpp > CMakeFiles/common_test.dir/main_common_test.cpp.i

src/serialNetTools/common/CMakeFiles/common_test.dir/main_common_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common_test.dir/main_common_test.cpp.s"
	cd /home/u/Desktop/cmakeproject/build/src/serialNetTools/common && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/Desktop/cmakeproject/src/serialNetTools/common/main_common_test.cpp -o CMakeFiles/common_test.dir/main_common_test.cpp.s

# Object files for target common_test
common_test_OBJECTS = \
"CMakeFiles/common_test.dir/main_common_test.cpp.o"

# External object files for target common_test
common_test_EXTERNAL_OBJECTS =

../bin/common_test: src/serialNetTools/common/CMakeFiles/common_test.dir/main_common_test.cpp.o
../bin/common_test: src/serialNetTools/common/CMakeFiles/common_test.dir/build.make
../bin/common_test: ../lib/libcommon.so
../bin/common_test: src/serialNetTools/common/CMakeFiles/common_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/u/Desktop/cmakeproject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../bin/common_test"
	cd /home/u/Desktop/cmakeproject/build/src/serialNetTools/common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/serialNetTools/common/CMakeFiles/common_test.dir/build: ../bin/common_test

.PHONY : src/serialNetTools/common/CMakeFiles/common_test.dir/build

src/serialNetTools/common/CMakeFiles/common_test.dir/clean:
	cd /home/u/Desktop/cmakeproject/build/src/serialNetTools/common && $(CMAKE_COMMAND) -P CMakeFiles/common_test.dir/cmake_clean.cmake
.PHONY : src/serialNetTools/common/CMakeFiles/common_test.dir/clean

src/serialNetTools/common/CMakeFiles/common_test.dir/depend:
	cd /home/u/Desktop/cmakeproject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/u/Desktop/cmakeproject /home/u/Desktop/cmakeproject/src/serialNetTools/common /home/u/Desktop/cmakeproject/build /home/u/Desktop/cmakeproject/build/src/serialNetTools/common /home/u/Desktop/cmakeproject/build/src/serialNetTools/common/CMakeFiles/common_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/serialNetTools/common/CMakeFiles/common_test.dir/depend

