# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\skillbox\profession-c-plus-plus\homework18.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\skillbox\profession-c-plus-plus\homework18.1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/homework18_1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/homework18_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homework18_1.dir/flags.make

CMakeFiles/homework18_1.dir/main.cpp.obj: CMakeFiles/homework18_1.dir/flags.make
CMakeFiles/homework18_1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\skillbox\profession-c-plus-plus\homework18.1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/homework18_1.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\homework18_1.dir\main.cpp.obj -c C:\skillbox\profession-c-plus-plus\homework18.1\main.cpp

CMakeFiles/homework18_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework18_1.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\skillbox\profession-c-plus-plus\homework18.1\main.cpp > CMakeFiles\homework18_1.dir\main.cpp.i

CMakeFiles/homework18_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework18_1.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\skillbox\profession-c-plus-plus\homework18.1\main.cpp -o CMakeFiles\homework18_1.dir\main.cpp.s

# Object files for target homework18_1
homework18_1_OBJECTS = \
"CMakeFiles/homework18_1.dir/main.cpp.obj"

# External object files for target homework18_1
homework18_1_EXTERNAL_OBJECTS =

homework18_1.exe: CMakeFiles/homework18_1.dir/main.cpp.obj
homework18_1.exe: CMakeFiles/homework18_1.dir/build.make
homework18_1.exe: CMakeFiles/homework18_1.dir/linklibs.rsp
homework18_1.exe: CMakeFiles/homework18_1.dir/objects1.rsp
homework18_1.exe: CMakeFiles/homework18_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\skillbox\profession-c-plus-plus\homework18.1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable homework18_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\homework18_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homework18_1.dir/build: homework18_1.exe
.PHONY : CMakeFiles/homework18_1.dir/build

CMakeFiles/homework18_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\homework18_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/homework18_1.dir/clean

CMakeFiles/homework18_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\skillbox\profession-c-plus-plus\homework18.1 C:\skillbox\profession-c-plus-plus\homework18.1 C:\skillbox\profession-c-plus-plus\homework18.1\cmake-build-debug C:\skillbox\profession-c-plus-plus\homework18.1\cmake-build-debug C:\skillbox\profession-c-plus-plus\homework18.1\cmake-build-debug\CMakeFiles\homework18_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homework18_1.dir/depend

