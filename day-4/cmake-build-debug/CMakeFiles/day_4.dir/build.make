# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hazelque/Desktop/advent-of-code/day-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hazelque/Desktop/advent-of-code/day-4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/day_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/day_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/day_4.dir/flags.make

CMakeFiles/day_4.dir/main.cpp.o: CMakeFiles/day_4.dir/flags.make
CMakeFiles/day_4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hazelque/Desktop/advent-of-code/day-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/day_4.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/day_4.dir/main.cpp.o -c /Users/hazelque/Desktop/advent-of-code/day-4/main.cpp

CMakeFiles/day_4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/day_4.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hazelque/Desktop/advent-of-code/day-4/main.cpp > CMakeFiles/day_4.dir/main.cpp.i

CMakeFiles/day_4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/day_4.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hazelque/Desktop/advent-of-code/day-4/main.cpp -o CMakeFiles/day_4.dir/main.cpp.s

# Object files for target day_4
day_4_OBJECTS = \
"CMakeFiles/day_4.dir/main.cpp.o"

# External object files for target day_4
day_4_EXTERNAL_OBJECTS =

day_4: CMakeFiles/day_4.dir/main.cpp.o
day_4: CMakeFiles/day_4.dir/build.make
day_4: CMakeFiles/day_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hazelque/Desktop/advent-of-code/day-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable day_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/day_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/day_4.dir/build: day_4

.PHONY : CMakeFiles/day_4.dir/build

CMakeFiles/day_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/day_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/day_4.dir/clean

CMakeFiles/day_4.dir/depend:
	cd /Users/hazelque/Desktop/advent-of-code/day-4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hazelque/Desktop/advent-of-code/day-4 /Users/hazelque/Desktop/advent-of-code/day-4 /Users/hazelque/Desktop/advent-of-code/day-4/cmake-build-debug /Users/hazelque/Desktop/advent-of-code/day-4/cmake-build-debug /Users/hazelque/Desktop/advent-of-code/day-4/cmake-build-debug/CMakeFiles/day_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/day_4.dir/depend

