# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/build

# Include any dependencies generated for this target.
include CMakeFiles/../bin/Neuron.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/../bin/Neuron.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/../bin/Neuron.dir/flags.make

CMakeFiles/../bin/Neuron.dir/neuron.cpp.o: CMakeFiles/../bin/Neuron.dir/flags.make
CMakeFiles/../bin/Neuron.dir/neuron.cpp.o: /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/../bin/Neuron.dir/neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/../bin/Neuron.dir/neuron.cpp.o -c /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/neuron.cpp

CMakeFiles/../bin/Neuron.dir/neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/../bin/Neuron.dir/neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/neuron.cpp > CMakeFiles/../bin/Neuron.dir/neuron.cpp.i

CMakeFiles/../bin/Neuron.dir/neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/../bin/Neuron.dir/neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/neuron.cpp -o CMakeFiles/../bin/Neuron.dir/neuron.cpp.s

CMakeFiles/../bin/Neuron.dir/neuron.cpp.o.requires:
.PHONY : CMakeFiles/../bin/Neuron.dir/neuron.cpp.o.requires

CMakeFiles/../bin/Neuron.dir/neuron.cpp.o.provides: CMakeFiles/../bin/Neuron.dir/neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/../bin/Neuron.dir/build.make CMakeFiles/../bin/Neuron.dir/neuron.cpp.o.provides.build
.PHONY : CMakeFiles/../bin/Neuron.dir/neuron.cpp.o.provides

CMakeFiles/../bin/Neuron.dir/neuron.cpp.o.provides.build: CMakeFiles/../bin/Neuron.dir/neuron.cpp.o

CMakeFiles/../bin/Neuron.dir/main.cpp.o: CMakeFiles/../bin/Neuron.dir/flags.make
CMakeFiles/../bin/Neuron.dir/main.cpp.o: /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/../bin/Neuron.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/../bin/Neuron.dir/main.cpp.o -c /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/main.cpp

CMakeFiles/../bin/Neuron.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/../bin/Neuron.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/main.cpp > CMakeFiles/../bin/Neuron.dir/main.cpp.i

CMakeFiles/../bin/Neuron.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/../bin/Neuron.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/main.cpp -o CMakeFiles/../bin/Neuron.dir/main.cpp.s

CMakeFiles/../bin/Neuron.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/../bin/Neuron.dir/main.cpp.o.requires

CMakeFiles/../bin/Neuron.dir/main.cpp.o.provides: CMakeFiles/../bin/Neuron.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/../bin/Neuron.dir/build.make CMakeFiles/../bin/Neuron.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/../bin/Neuron.dir/main.cpp.o.provides

CMakeFiles/../bin/Neuron.dir/main.cpp.o.provides.build: CMakeFiles/../bin/Neuron.dir/main.cpp.o

CMakeFiles/../bin/Neuron.dir/network.cpp.o: CMakeFiles/../bin/Neuron.dir/flags.make
CMakeFiles/../bin/Neuron.dir/network.cpp.o: /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/../bin/Neuron.dir/network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/../bin/Neuron.dir/network.cpp.o -c /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/network.cpp

CMakeFiles/../bin/Neuron.dir/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/../bin/Neuron.dir/network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/network.cpp > CMakeFiles/../bin/Neuron.dir/network.cpp.i

CMakeFiles/../bin/Neuron.dir/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/../bin/Neuron.dir/network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src/network.cpp -o CMakeFiles/../bin/Neuron.dir/network.cpp.s

CMakeFiles/../bin/Neuron.dir/network.cpp.o.requires:
.PHONY : CMakeFiles/../bin/Neuron.dir/network.cpp.o.requires

CMakeFiles/../bin/Neuron.dir/network.cpp.o.provides: CMakeFiles/../bin/Neuron.dir/network.cpp.o.requires
	$(MAKE) -f CMakeFiles/../bin/Neuron.dir/build.make CMakeFiles/../bin/Neuron.dir/network.cpp.o.provides.build
.PHONY : CMakeFiles/../bin/Neuron.dir/network.cpp.o.provides

CMakeFiles/../bin/Neuron.dir/network.cpp.o.provides.build: CMakeFiles/../bin/Neuron.dir/network.cpp.o

# Object files for target ../bin/Neuron
__/bin/Neuron_OBJECTS = \
"CMakeFiles/../bin/Neuron.dir/neuron.cpp.o" \
"CMakeFiles/../bin/Neuron.dir/main.cpp.o" \
"CMakeFiles/../bin/Neuron.dir/network.cpp.o"

# External object files for target ../bin/Neuron
__/bin/Neuron_EXTERNAL_OBJECTS =

../bin/Neuron: CMakeFiles/../bin/Neuron.dir/neuron.cpp.o
../bin/Neuron: CMakeFiles/../bin/Neuron.dir/main.cpp.o
../bin/Neuron: CMakeFiles/../bin/Neuron.dir/network.cpp.o
../bin/Neuron: CMakeFiles/../bin/Neuron.dir/build.make
../bin/Neuron: CMakeFiles/../bin/Neuron.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/Neuron"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/../bin/Neuron.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/../bin/Neuron.dir/build: ../bin/Neuron
.PHONY : CMakeFiles/../bin/Neuron.dir/build

CMakeFiles/../bin/Neuron.dir/requires: CMakeFiles/../bin/Neuron.dir/neuron.cpp.o.requires
CMakeFiles/../bin/Neuron.dir/requires: CMakeFiles/../bin/Neuron.dir/main.cpp.o.requires
CMakeFiles/../bin/Neuron.dir/requires: CMakeFiles/../bin/Neuron.dir/network.cpp.o.requires
.PHONY : CMakeFiles/../bin/Neuron.dir/requires

CMakeFiles/../bin/Neuron.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/../bin/Neuron.dir/cmake_clean.cmake
.PHONY : CMakeFiles/../bin/Neuron.dir/clean

CMakeFiles/../bin/Neuron.dir/depend:
	cd /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/src /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/build /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/build /home/INTRANET/eduperre/myfiles/2017/cs116-2017-Eliane-Duperrex/Neuron/Part2/build/bin/Neuron.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/../bin/Neuron.dir/depend

