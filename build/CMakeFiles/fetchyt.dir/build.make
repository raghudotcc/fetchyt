# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sraghu/fetchyt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sraghu/fetchyt/build

# Include any dependencies generated for this target.
include CMakeFiles/fetchyt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fetchyt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fetchyt.dir/flags.make

CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o: CMakeFiles/fetchyt.dir/flags.make
CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o: ../src/fetchyt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sraghu/fetchyt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o -c /home/sraghu/fetchyt/src/fetchyt.cpp

CMakeFiles/fetchyt.dir/src/fetchyt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fetchyt.dir/src/fetchyt.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sraghu/fetchyt/src/fetchyt.cpp > CMakeFiles/fetchyt.dir/src/fetchyt.cpp.i

CMakeFiles/fetchyt.dir/src/fetchyt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fetchyt.dir/src/fetchyt.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sraghu/fetchyt/src/fetchyt.cpp -o CMakeFiles/fetchyt.dir/src/fetchyt.cpp.s

CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o.requires:

.PHONY : CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o.requires

CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o.provides: CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o.requires
	$(MAKE) -f CMakeFiles/fetchyt.dir/build.make CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o.provides.build
.PHONY : CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o.provides

CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o.provides.build: CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o


CMakeFiles/fetchyt.dir/src/main.cpp.o: CMakeFiles/fetchyt.dir/flags.make
CMakeFiles/fetchyt.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sraghu/fetchyt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fetchyt.dir/src/main.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fetchyt.dir/src/main.cpp.o -c /home/sraghu/fetchyt/src/main.cpp

CMakeFiles/fetchyt.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fetchyt.dir/src/main.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sraghu/fetchyt/src/main.cpp > CMakeFiles/fetchyt.dir/src/main.cpp.i

CMakeFiles/fetchyt.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fetchyt.dir/src/main.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sraghu/fetchyt/src/main.cpp -o CMakeFiles/fetchyt.dir/src/main.cpp.s

CMakeFiles/fetchyt.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/fetchyt.dir/src/main.cpp.o.requires

CMakeFiles/fetchyt.dir/src/main.cpp.o.provides: CMakeFiles/fetchyt.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/fetchyt.dir/build.make CMakeFiles/fetchyt.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/fetchyt.dir/src/main.cpp.o.provides

CMakeFiles/fetchyt.dir/src/main.cpp.o.provides.build: CMakeFiles/fetchyt.dir/src/main.cpp.o


CMakeFiles/fetchyt.dir/src/util.cpp.o: CMakeFiles/fetchyt.dir/flags.make
CMakeFiles/fetchyt.dir/src/util.cpp.o: ../src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sraghu/fetchyt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fetchyt.dir/src/util.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fetchyt.dir/src/util.cpp.o -c /home/sraghu/fetchyt/src/util.cpp

CMakeFiles/fetchyt.dir/src/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fetchyt.dir/src/util.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sraghu/fetchyt/src/util.cpp > CMakeFiles/fetchyt.dir/src/util.cpp.i

CMakeFiles/fetchyt.dir/src/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fetchyt.dir/src/util.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sraghu/fetchyt/src/util.cpp -o CMakeFiles/fetchyt.dir/src/util.cpp.s

CMakeFiles/fetchyt.dir/src/util.cpp.o.requires:

.PHONY : CMakeFiles/fetchyt.dir/src/util.cpp.o.requires

CMakeFiles/fetchyt.dir/src/util.cpp.o.provides: CMakeFiles/fetchyt.dir/src/util.cpp.o.requires
	$(MAKE) -f CMakeFiles/fetchyt.dir/build.make CMakeFiles/fetchyt.dir/src/util.cpp.o.provides.build
.PHONY : CMakeFiles/fetchyt.dir/src/util.cpp.o.provides

CMakeFiles/fetchyt.dir/src/util.cpp.o.provides.build: CMakeFiles/fetchyt.dir/src/util.cpp.o


# Object files for target fetchyt
fetchyt_OBJECTS = \
"CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o" \
"CMakeFiles/fetchyt.dir/src/main.cpp.o" \
"CMakeFiles/fetchyt.dir/src/util.cpp.o"

# External object files for target fetchyt
fetchyt_EXTERNAL_OBJECTS =

fetchyt.exe: CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o
fetchyt.exe: CMakeFiles/fetchyt.dir/src/main.cpp.o
fetchyt.exe: CMakeFiles/fetchyt.dir/src/util.cpp.o
fetchyt.exe: CMakeFiles/fetchyt.dir/build.make
fetchyt.exe: ../lib/libcurl.a
fetchyt.exe: CMakeFiles/fetchyt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sraghu/fetchyt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable fetchyt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fetchyt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fetchyt.dir/build: fetchyt.exe

.PHONY : CMakeFiles/fetchyt.dir/build

CMakeFiles/fetchyt.dir/requires: CMakeFiles/fetchyt.dir/src/fetchyt.cpp.o.requires
CMakeFiles/fetchyt.dir/requires: CMakeFiles/fetchyt.dir/src/main.cpp.o.requires
CMakeFiles/fetchyt.dir/requires: CMakeFiles/fetchyt.dir/src/util.cpp.o.requires

.PHONY : CMakeFiles/fetchyt.dir/requires

CMakeFiles/fetchyt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fetchyt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fetchyt.dir/clean

CMakeFiles/fetchyt.dir/depend:
	cd /home/sraghu/fetchyt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sraghu/fetchyt /home/sraghu/fetchyt /home/sraghu/fetchyt/build /home/sraghu/fetchyt/build /home/sraghu/fetchyt/build/CMakeFiles/fetchyt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fetchyt.dir/depend

