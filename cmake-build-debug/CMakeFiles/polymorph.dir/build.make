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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kevin/dev/cpp/hackerrank

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kevin/dev/cpp/hackerrank/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/polymorph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/polymorph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/polymorph.dir/flags.make

CMakeFiles/polymorph.dir/polymorphism.cpp.o: CMakeFiles/polymorph.dir/flags.make
CMakeFiles/polymorph.dir/polymorphism.cpp.o: ../polymorphism.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kevin/dev/cpp/hackerrank/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/polymorph.dir/polymorphism.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/polymorph.dir/polymorphism.cpp.o -c /Users/kevin/dev/cpp/hackerrank/polymorphism.cpp

CMakeFiles/polymorph.dir/polymorphism.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/polymorph.dir/polymorphism.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kevin/dev/cpp/hackerrank/polymorphism.cpp > CMakeFiles/polymorph.dir/polymorphism.cpp.i

CMakeFiles/polymorph.dir/polymorphism.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/polymorph.dir/polymorphism.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kevin/dev/cpp/hackerrank/polymorphism.cpp -o CMakeFiles/polymorph.dir/polymorphism.cpp.s

# Object files for target polymorph
polymorph_OBJECTS = \
"CMakeFiles/polymorph.dir/polymorphism.cpp.o"

# External object files for target polymorph
polymorph_EXTERNAL_OBJECTS =

polymorph: CMakeFiles/polymorph.dir/polymorphism.cpp.o
polymorph: CMakeFiles/polymorph.dir/build.make
polymorph: CMakeFiles/polymorph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kevin/dev/cpp/hackerrank/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable polymorph"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/polymorph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/polymorph.dir/build: polymorph

.PHONY : CMakeFiles/polymorph.dir/build

CMakeFiles/polymorph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/polymorph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/polymorph.dir/clean

CMakeFiles/polymorph.dir/depend:
	cd /Users/kevin/dev/cpp/hackerrank/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kevin/dev/cpp/hackerrank /Users/kevin/dev/cpp/hackerrank /Users/kevin/dev/cpp/hackerrank/cmake-build-debug /Users/kevin/dev/cpp/hackerrank/cmake-build-debug /Users/kevin/dev/cpp/hackerrank/cmake-build-debug/CMakeFiles/polymorph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/polymorph.dir/depend

