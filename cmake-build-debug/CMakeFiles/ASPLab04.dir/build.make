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
CMAKE_SOURCE_DIR = /Users/Tilliw/CLionProjects/ASPLab04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Tilliw/CLionProjects/ASPLab04/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ASPLab04.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ASPLab04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ASPLab04.dir/flags.make

CMakeFiles/ASPLab04.dir/main.c.o: CMakeFiles/ASPLab04.dir/flags.make
CMakeFiles/ASPLab04.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Tilliw/CLionProjects/ASPLab04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ASPLab04.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ASPLab04.dir/main.c.o   -c /Users/Tilliw/CLionProjects/ASPLab04/main.c

CMakeFiles/ASPLab04.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ASPLab04.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Tilliw/CLionProjects/ASPLab04/main.c > CMakeFiles/ASPLab04.dir/main.c.i

CMakeFiles/ASPLab04.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ASPLab04.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Tilliw/CLionProjects/ASPLab04/main.c -o CMakeFiles/ASPLab04.dir/main.c.s

# Object files for target ASPLab04
ASPLab04_OBJECTS = \
"CMakeFiles/ASPLab04.dir/main.c.o"

# External object files for target ASPLab04
ASPLab04_EXTERNAL_OBJECTS =

ASPLab04: CMakeFiles/ASPLab04.dir/main.c.o
ASPLab04: CMakeFiles/ASPLab04.dir/build.make
ASPLab04: CMakeFiles/ASPLab04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Tilliw/CLionProjects/ASPLab04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ASPLab04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ASPLab04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ASPLab04.dir/build: ASPLab04

.PHONY : CMakeFiles/ASPLab04.dir/build

CMakeFiles/ASPLab04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ASPLab04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ASPLab04.dir/clean

CMakeFiles/ASPLab04.dir/depend:
	cd /Users/Tilliw/CLionProjects/ASPLab04/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Tilliw/CLionProjects/ASPLab04 /Users/Tilliw/CLionProjects/ASPLab04 /Users/Tilliw/CLionProjects/ASPLab04/cmake-build-debug /Users/Tilliw/CLionProjects/ASPLab04/cmake-build-debug /Users/Tilliw/CLionProjects/ASPLab04/cmake-build-debug/CMakeFiles/ASPLab04.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ASPLab04.dir/depend

