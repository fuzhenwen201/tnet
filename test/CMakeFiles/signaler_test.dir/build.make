# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/kevin/thirdparty/clion-2018.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kevin/thirdparty/clion-2018.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kevin/thirdparty/libtnet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kevin/thirdparty/libtnet

# Include any dependencies generated for this target.
include test/CMakeFiles/signaler_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/signaler_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/signaler_test.dir/flags.make

test/CMakeFiles/signaler_test.dir/signaler_test.cpp.o: test/CMakeFiles/signaler_test.dir/flags.make
test/CMakeFiles/signaler_test.dir/signaler_test.cpp.o: test/signaler_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevin/thirdparty/libtnet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/signaler_test.dir/signaler_test.cpp.o"
	cd /home/kevin/thirdparty/libtnet/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/signaler_test.dir/signaler_test.cpp.o -c /home/kevin/thirdparty/libtnet/test/signaler_test.cpp

test/CMakeFiles/signaler_test.dir/signaler_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/signaler_test.dir/signaler_test.cpp.i"
	cd /home/kevin/thirdparty/libtnet/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevin/thirdparty/libtnet/test/signaler_test.cpp > CMakeFiles/signaler_test.dir/signaler_test.cpp.i

test/CMakeFiles/signaler_test.dir/signaler_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/signaler_test.dir/signaler_test.cpp.s"
	cd /home/kevin/thirdparty/libtnet/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevin/thirdparty/libtnet/test/signaler_test.cpp -o CMakeFiles/signaler_test.dir/signaler_test.cpp.s

# Object files for target signaler_test
signaler_test_OBJECTS = \
"CMakeFiles/signaler_test.dir/signaler_test.cpp.o"

# External object files for target signaler_test
signaler_test_EXTERNAL_OBJECTS =

bin/signaler_test: test/CMakeFiles/signaler_test.dir/signaler_test.cpp.o
bin/signaler_test: test/CMakeFiles/signaler_test.dir/build.make
bin/signaler_test: lib/libtnet.a
bin/signaler_test: test/CMakeFiles/signaler_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kevin/thirdparty/libtnet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/signaler_test"
	cd /home/kevin/thirdparty/libtnet/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/signaler_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/signaler_test.dir/build: bin/signaler_test

.PHONY : test/CMakeFiles/signaler_test.dir/build

test/CMakeFiles/signaler_test.dir/clean:
	cd /home/kevin/thirdparty/libtnet/test && $(CMAKE_COMMAND) -P CMakeFiles/signaler_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/signaler_test.dir/clean

test/CMakeFiles/signaler_test.dir/depend:
	cd /home/kevin/thirdparty/libtnet && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kevin/thirdparty/libtnet /home/kevin/thirdparty/libtnet/test /home/kevin/thirdparty/libtnet /home/kevin/thirdparty/libtnet/test /home/kevin/thirdparty/libtnet/test/CMakeFiles/signaler_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/signaler_test.dir/depend

