# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jose/Tesis/MyThesis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jose/Tesis/MyThesis/build

# Include any dependencies generated for this target.
include application/CMakeFiles/AGS.dir/depend.make

# Include the progress variables for this target.
include application/CMakeFiles/AGS.dir/progress.make

# Include the compile flags for this target's objects.
include application/CMakeFiles/AGS.dir/flags.make

application/CMakeFiles/AGS.dir/AGS.cpp.o: application/CMakeFiles/AGS.dir/flags.make
application/CMakeFiles/AGS.dir/AGS.cpp.o: ../application/AGS.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jose/Tesis/MyThesis/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object application/CMakeFiles/AGS.dir/AGS.cpp.o"
	cd /home/jose/Tesis/MyThesis/build/application && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AGS.dir/AGS.cpp.o -c /home/jose/Tesis/MyThesis/application/AGS.cpp

application/CMakeFiles/AGS.dir/AGS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AGS.dir/AGS.cpp.i"
	cd /home/jose/Tesis/MyThesis/build/application && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jose/Tesis/MyThesis/application/AGS.cpp > CMakeFiles/AGS.dir/AGS.cpp.i

application/CMakeFiles/AGS.dir/AGS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AGS.dir/AGS.cpp.s"
	cd /home/jose/Tesis/MyThesis/build/application && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jose/Tesis/MyThesis/application/AGS.cpp -o CMakeFiles/AGS.dir/AGS.cpp.s

application/CMakeFiles/AGS.dir/AGS.cpp.o.requires:
.PHONY : application/CMakeFiles/AGS.dir/AGS.cpp.o.requires

application/CMakeFiles/AGS.dir/AGS.cpp.o.provides: application/CMakeFiles/AGS.dir/AGS.cpp.o.requires
	$(MAKE) -f application/CMakeFiles/AGS.dir/build.make application/CMakeFiles/AGS.dir/AGS.cpp.o.provides.build
.PHONY : application/CMakeFiles/AGS.dir/AGS.cpp.o.provides

application/CMakeFiles/AGS.dir/AGS.cpp.o.provides.build: application/CMakeFiles/AGS.dir/AGS.cpp.o

# Object files for target AGS
AGS_OBJECTS = \
"CMakeFiles/AGS.dir/AGS.cpp.o"

# External object files for target AGS
AGS_EXTERNAL_OBJECTS =

application/AGS: application/CMakeFiles/AGS.dir/AGS.cpp.o
application/AGS: application/CMakeFiles/AGS.dir/build.make
application/AGS: /home/jose/Tesis/paradiseo/build/lib/libeoutils.a
application/AGS: /home/jose/Tesis/paradiseo/build/lib/libeo.a
application/AGS: /home/jose/Tesis/paradiseo/build/lib/libsmp.a
application/AGS: lib/liblDiscovery.a
application/AGS: application/CMakeFiles/AGS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable AGS"
	cd /home/jose/Tesis/MyThesis/build/application && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AGS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/CMakeFiles/AGS.dir/build: application/AGS
.PHONY : application/CMakeFiles/AGS.dir/build

application/CMakeFiles/AGS.dir/requires: application/CMakeFiles/AGS.dir/AGS.cpp.o.requires
.PHONY : application/CMakeFiles/AGS.dir/requires

application/CMakeFiles/AGS.dir/clean:
	cd /home/jose/Tesis/MyThesis/build/application && $(CMAKE_COMMAND) -P CMakeFiles/AGS.dir/cmake_clean.cmake
.PHONY : application/CMakeFiles/AGS.dir/clean

application/CMakeFiles/AGS.dir/depend:
	cd /home/jose/Tesis/MyThesis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jose/Tesis/MyThesis /home/jose/Tesis/MyThesis/application /home/jose/Tesis/MyThesis/build /home/jose/Tesis/MyThesis/build/application /home/jose/Tesis/MyThesis/build/application/CMakeFiles/AGS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : application/CMakeFiles/AGS.dir/depend

