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
CMAKE_COMMAND = /app/extra/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /app/extra/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Furniture.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Furniture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Furniture.dir/flags.make

CMakeFiles/Furniture.dir/main.cpp.o: CMakeFiles/Furniture.dir/flags.make
CMakeFiles/Furniture.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Furniture.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Furniture.dir/main.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/main.cpp

CMakeFiles/Furniture.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Furniture.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/main.cpp > CMakeFiles/Furniture.dir/main.cpp.i

CMakeFiles/Furniture.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Furniture.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/main.cpp -o CMakeFiles/Furniture.dir/main.cpp.s

CMakeFiles/Furniture.dir/Sources/Furniture.cpp.o: CMakeFiles/Furniture.dir/flags.make
CMakeFiles/Furniture.dir/Sources/Furniture.cpp.o: ../Sources/Furniture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Furniture.dir/Sources/Furniture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Furniture.dir/Sources/Furniture.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Furniture.cpp

CMakeFiles/Furniture.dir/Sources/Furniture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Furniture.dir/Sources/Furniture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Furniture.cpp > CMakeFiles/Furniture.dir/Sources/Furniture.cpp.i

CMakeFiles/Furniture.dir/Sources/Furniture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Furniture.dir/Sources/Furniture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Furniture.cpp -o CMakeFiles/Furniture.dir/Sources/Furniture.cpp.s

CMakeFiles/Furniture.dir/Sources/Table.cpp.o: CMakeFiles/Furniture.dir/flags.make
CMakeFiles/Furniture.dir/Sources/Table.cpp.o: ../Sources/Table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Furniture.dir/Sources/Table.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Furniture.dir/Sources/Table.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Table.cpp

CMakeFiles/Furniture.dir/Sources/Table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Furniture.dir/Sources/Table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Table.cpp > CMakeFiles/Furniture.dir/Sources/Table.cpp.i

CMakeFiles/Furniture.dir/Sources/Table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Furniture.dir/Sources/Table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Table.cpp -o CMakeFiles/Furniture.dir/Sources/Table.cpp.s

CMakeFiles/Furniture.dir/Sources/Chair.cpp.o: CMakeFiles/Furniture.dir/flags.make
CMakeFiles/Furniture.dir/Sources/Chair.cpp.o: ../Sources/Chair.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Furniture.dir/Sources/Chair.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Furniture.dir/Sources/Chair.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Chair.cpp

CMakeFiles/Furniture.dir/Sources/Chair.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Furniture.dir/Sources/Chair.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Chair.cpp > CMakeFiles/Furniture.dir/Sources/Chair.cpp.i

CMakeFiles/Furniture.dir/Sources/Chair.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Furniture.dir/Sources/Chair.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Chair.cpp -o CMakeFiles/Furniture.dir/Sources/Chair.cpp.s

CMakeFiles/Furniture.dir/Sources/Bed.cpp.o: CMakeFiles/Furniture.dir/flags.make
CMakeFiles/Furniture.dir/Sources/Bed.cpp.o: ../Sources/Bed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Furniture.dir/Sources/Bed.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Furniture.dir/Sources/Bed.cpp.o -c /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Bed.cpp

CMakeFiles/Furniture.dir/Sources/Bed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Furniture.dir/Sources/Bed.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Bed.cpp > CMakeFiles/Furniture.dir/Sources/Bed.cpp.i

CMakeFiles/Furniture.dir/Sources/Bed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Furniture.dir/Sources/Bed.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/Sources/Bed.cpp -o CMakeFiles/Furniture.dir/Sources/Bed.cpp.s

# Object files for target Furniture
Furniture_OBJECTS = \
"CMakeFiles/Furniture.dir/main.cpp.o" \
"CMakeFiles/Furniture.dir/Sources/Furniture.cpp.o" \
"CMakeFiles/Furniture.dir/Sources/Table.cpp.o" \
"CMakeFiles/Furniture.dir/Sources/Chair.cpp.o" \
"CMakeFiles/Furniture.dir/Sources/Bed.cpp.o"

# External object files for target Furniture
Furniture_EXTERNAL_OBJECTS =

Furniture: CMakeFiles/Furniture.dir/main.cpp.o
Furniture: CMakeFiles/Furniture.dir/Sources/Furniture.cpp.o
Furniture: CMakeFiles/Furniture.dir/Sources/Table.cpp.o
Furniture: CMakeFiles/Furniture.dir/Sources/Chair.cpp.o
Furniture: CMakeFiles/Furniture.dir/Sources/Bed.cpp.o
Furniture: CMakeFiles/Furniture.dir/build.make
Furniture: CMakeFiles/Furniture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Furniture"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Furniture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Furniture.dir/build: Furniture

.PHONY : CMakeFiles/Furniture.dir/build

CMakeFiles/Furniture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Furniture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Furniture.dir/clean

CMakeFiles/Furniture.dir/depend:
	cd /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug /home/petko/workspace/oop-2020-21/cs-2-practical/14-virtual-destructors-and-exercise/Furniture/cmake-build-debug/CMakeFiles/Furniture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Furniture.dir/depend

