# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/retr0/Documents/ComputerGraphics/Proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/retr0/Documents/ComputerGraphics/Proj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Proj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Proj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proj.dir/flags.make

CMakeFiles/Proj.dir/main.cpp.o: CMakeFiles/Proj.dir/flags.make
CMakeFiles/Proj.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/retr0/Documents/ComputerGraphics/Proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Proj.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proj.dir/main.cpp.o -c /home/retr0/Documents/ComputerGraphics/Proj/main.cpp

CMakeFiles/Proj.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proj.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/retr0/Documents/ComputerGraphics/Proj/main.cpp > CMakeFiles/Proj.dir/main.cpp.i

CMakeFiles/Proj.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proj.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/retr0/Documents/ComputerGraphics/Proj/main.cpp -o CMakeFiles/Proj.dir/main.cpp.s

CMakeFiles/Proj.dir/openglwindow.cpp.o: CMakeFiles/Proj.dir/flags.make
CMakeFiles/Proj.dir/openglwindow.cpp.o: ../openglwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/retr0/Documents/ComputerGraphics/Proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Proj.dir/openglwindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proj.dir/openglwindow.cpp.o -c /home/retr0/Documents/ComputerGraphics/Proj/openglwindow.cpp

CMakeFiles/Proj.dir/openglwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proj.dir/openglwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/retr0/Documents/ComputerGraphics/Proj/openglwindow.cpp > CMakeFiles/Proj.dir/openglwindow.cpp.i

CMakeFiles/Proj.dir/openglwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proj.dir/openglwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/retr0/Documents/ComputerGraphics/Proj/openglwindow.cpp -o CMakeFiles/Proj.dir/openglwindow.cpp.s

# Object files for target Proj
Proj_OBJECTS = \
"CMakeFiles/Proj.dir/main.cpp.o" \
"CMakeFiles/Proj.dir/openglwindow.cpp.o"

# External object files for target Proj
Proj_EXTERNAL_OBJECTS =

Proj: CMakeFiles/Proj.dir/main.cpp.o
Proj: CMakeFiles/Proj.dir/openglwindow.cpp.o
Proj: CMakeFiles/Proj.dir/build.make
Proj: CMakeFiles/Proj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/retr0/Documents/ComputerGraphics/Proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Proj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Proj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proj.dir/build: Proj

.PHONY : CMakeFiles/Proj.dir/build

CMakeFiles/Proj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Proj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Proj.dir/clean

CMakeFiles/Proj.dir/depend:
	cd /home/retr0/Documents/ComputerGraphics/Proj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/retr0/Documents/ComputerGraphics/Proj /home/retr0/Documents/ComputerGraphics/Proj /home/retr0/Documents/ComputerGraphics/Proj/cmake-build-debug /home/retr0/Documents/ComputerGraphics/Proj/cmake-build-debug /home/retr0/Documents/ComputerGraphics/Proj/cmake-build-debug/CMakeFiles/Proj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Proj.dir/depend

