# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /var/lib/snapd/snap/clion/149/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/149/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/Tests/main.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Tests/main.cpp.o: ../Tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/Tests/main.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/Tests/main.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Tests/main.cpp

CMakeFiles/test.dir/Tests/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Tests/main.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Tests/main.cpp > CMakeFiles/test.dir/Tests/main.cpp.i

CMakeFiles/test.dir/Tests/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Tests/main.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Tests/main.cpp -o CMakeFiles/test.dir/Tests/main.cpp.s

CMakeFiles/test.dir/Catch2/catch2.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Catch2/catch2.cpp.o: ../Catch2/catch2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/Catch2/catch2.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/Catch2/catch2.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Catch2/catch2.cpp

CMakeFiles/test.dir/Catch2/catch2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Catch2/catch2.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Catch2/catch2.cpp > CMakeFiles/test.dir/Catch2/catch2.cpp.i

CMakeFiles/test.dir/Catch2/catch2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Catch2/catch2.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Catch2/catch2.cpp -o CMakeFiles/test.dir/Catch2/catch2.cpp.s

CMakeFiles/test.dir/Sources/AnimalFamily.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Sources/AnimalFamily.cpp.o: ../Sources/AnimalFamily.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/Sources/AnimalFamily.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/Sources/AnimalFamily.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/AnimalFamily.cpp

CMakeFiles/test.dir/Sources/AnimalFamily.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Sources/AnimalFamily.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/AnimalFamily.cpp > CMakeFiles/test.dir/Sources/AnimalFamily.cpp.i

CMakeFiles/test.dir/Sources/AnimalFamily.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Sources/AnimalFamily.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/AnimalFamily.cpp -o CMakeFiles/test.dir/Sources/AnimalFamily.cpp.s

CMakeFiles/test.dir/Sources/Fauna.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Sources/Fauna.cpp.o: ../Sources/Fauna.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.dir/Sources/Fauna.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/Sources/Fauna.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/Fauna.cpp

CMakeFiles/test.dir/Sources/Fauna.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Sources/Fauna.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/Fauna.cpp > CMakeFiles/test.dir/Sources/Fauna.cpp.i

CMakeFiles/test.dir/Sources/Fauna.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Sources/Fauna.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/Fauna.cpp -o CMakeFiles/test.dir/Sources/Fauna.cpp.s

CMakeFiles/test.dir/Sources/Planet.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Sources/Planet.cpp.o: ../Sources/Planet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test.dir/Sources/Planet.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/Sources/Planet.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/Planet.cpp

CMakeFiles/test.dir/Sources/Planet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Sources/Planet.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/Planet.cpp > CMakeFiles/test.dir/Sources/Planet.cpp.i

CMakeFiles/test.dir/Sources/Planet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Sources/Planet.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/Planet.cpp -o CMakeFiles/test.dir/Sources/Planet.cpp.s

CMakeFiles/test.dir/Sources/Zoo.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/Sources/Zoo.cpp.o: ../Sources/Zoo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/test.dir/Sources/Zoo.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/Sources/Zoo.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/Zoo.cpp

CMakeFiles/test.dir/Sources/Zoo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/Sources/Zoo.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/Zoo.cpp > CMakeFiles/test.dir/Sources/Zoo.cpp.i

CMakeFiles/test.dir/Sources/Zoo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/Sources/Zoo.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/Sources/Zoo.cpp -o CMakeFiles/test.dir/Sources/Zoo.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/Tests/main.cpp.o" \
"CMakeFiles/test.dir/Catch2/catch2.cpp.o" \
"CMakeFiles/test.dir/Sources/AnimalFamily.cpp.o" \
"CMakeFiles/test.dir/Sources/Fauna.cpp.o" \
"CMakeFiles/test.dir/Sources/Planet.cpp.o" \
"CMakeFiles/test.dir/Sources/Zoo.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/Tests/main.cpp.o
test: CMakeFiles/test.dir/Catch2/catch2.cpp.o
test: CMakeFiles/test.dir/Sources/AnimalFamily.cpp.o
test: CMakeFiles/test.dir/Sources/Fauna.cpp.o
test: CMakeFiles/test.dir/Sources/Planet.cpp.o
test: CMakeFiles/test.dir/Sources/Zoo.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug /home/petko/workspace/oop-2020-21/cs-2-practical/08-Animals/cmake-build-debug/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend
