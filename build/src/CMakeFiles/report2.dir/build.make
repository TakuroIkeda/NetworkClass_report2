# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/local/src/dev/networks/report2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/local/src/dev/networks/report2/build

# Include any dependencies generated for this target.
include src/CMakeFiles/report2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/report2.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/report2.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/report2.dir/flags.make

src/CMakeFiles/report2.dir/simulate.c.o: src/CMakeFiles/report2.dir/flags.make
src/CMakeFiles/report2.dir/simulate.c.o: ../src/simulate.c
src/CMakeFiles/report2.dir/simulate.c.o: src/CMakeFiles/report2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/local/src/dev/networks/report2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/report2.dir/simulate.c.o"
	cd /usr/local/src/dev/networks/report2/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/report2.dir/simulate.c.o -MF CMakeFiles/report2.dir/simulate.c.o.d -o CMakeFiles/report2.dir/simulate.c.o -c /usr/local/src/dev/networks/report2/src/simulate.c

src/CMakeFiles/report2.dir/simulate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/report2.dir/simulate.c.i"
	cd /usr/local/src/dev/networks/report2/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /usr/local/src/dev/networks/report2/src/simulate.c > CMakeFiles/report2.dir/simulate.c.i

src/CMakeFiles/report2.dir/simulate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/report2.dir/simulate.c.s"
	cd /usr/local/src/dev/networks/report2/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /usr/local/src/dev/networks/report2/src/simulate.c -o CMakeFiles/report2.dir/simulate.c.s

# Object files for target report2
report2_OBJECTS = \
"CMakeFiles/report2.dir/simulate.c.o"

# External object files for target report2
report2_EXTERNAL_OBJECTS =

src/libreport2.so: src/CMakeFiles/report2.dir/simulate.c.o
src/libreport2.so: src/CMakeFiles/report2.dir/build.make
src/libreport2.so: src/CMakeFiles/report2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/local/src/dev/networks/report2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libreport2.so"
	cd /usr/local/src/dev/networks/report2/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/report2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/report2.dir/build: src/libreport2.so
.PHONY : src/CMakeFiles/report2.dir/build

src/CMakeFiles/report2.dir/clean:
	cd /usr/local/src/dev/networks/report2/build/src && $(CMAKE_COMMAND) -P CMakeFiles/report2.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/report2.dir/clean

src/CMakeFiles/report2.dir/depend:
	cd /usr/local/src/dev/networks/report2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/local/src/dev/networks/report2 /usr/local/src/dev/networks/report2/src /usr/local/src/dev/networks/report2/build /usr/local/src/dev/networks/report2/build/src /usr/local/src/dev/networks/report2/build/src/CMakeFiles/report2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/report2.dir/depend

