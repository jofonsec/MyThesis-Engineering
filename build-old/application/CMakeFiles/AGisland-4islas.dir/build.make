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
include application/CMakeFiles/AGisland-4islas.dir/depend.make

# Include the progress variables for this target.
include application/CMakeFiles/AGisland-4islas.dir/progress.make

# Include the compile flags for this target's objects.
include application/CMakeFiles/AGisland-4islas.dir/flags.make

application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o: application/CMakeFiles/AGisland-4islas.dir/flags.make
application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o: ../application/AGisland.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jose/Tesis/MyThesis/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o"
	cd /home/jose/Tesis/MyThesis/build/application && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o -c /home/jose/Tesis/MyThesis/application/AGisland.cpp

application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AGisland-4islas.dir/AGisland.cpp.i"
	cd /home/jose/Tesis/MyThesis/build/application && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jose/Tesis/MyThesis/application/AGisland.cpp > CMakeFiles/AGisland-4islas.dir/AGisland.cpp.i

application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AGisland-4islas.dir/AGisland.cpp.s"
	cd /home/jose/Tesis/MyThesis/build/application && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jose/Tesis/MyThesis/application/AGisland.cpp -o CMakeFiles/AGisland-4islas.dir/AGisland.cpp.s

application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o.requires:
.PHONY : application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o.requires

application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o.provides: application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o.requires
	$(MAKE) -f application/CMakeFiles/AGisland-4islas.dir/build.make application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o.provides.build
.PHONY : application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o.provides

application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o.provides.build: application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o

# Object files for target AGisland-4islas
AGisland__4islas_OBJECTS = \
"CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o"

# External object files for target AGisland-4islas
AGisland__4islas_EXTERNAL_OBJECTS =

application/AGisland-4islas: application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o
application/AGisland-4islas: application/CMakeFiles/AGisland-4islas.dir/build.make
application/AGisland-4islas: /home/jose/Tesis/paradiseo/build/lib/libeoutils.a
application/AGisland-4islas: /home/jose/Tesis/paradiseo/build/lib/libeo.a
application/AGisland-4islas: /home/jose/Tesis/paradiseo/build/lib/libsmp.a
application/AGisland-4islas: lib/liblDiscovery.a
application/AGisland-4islas: application/CMakeFiles/AGisland-4islas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable AGisland-4islas"
	cd /home/jose/Tesis/MyThesis/build/application && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AGisland-4islas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/CMakeFiles/AGisland-4islas.dir/build: application/AGisland-4islas
.PHONY : application/CMakeFiles/AGisland-4islas.dir/build

application/CMakeFiles/AGisland-4islas.dir/requires: application/CMakeFiles/AGisland-4islas.dir/AGisland.cpp.o.requires
.PHONY : application/CMakeFiles/AGisland-4islas.dir/requires

application/CMakeFiles/AGisland-4islas.dir/clean:
	cd /home/jose/Tesis/MyThesis/build/application && $(CMAKE_COMMAND) -P CMakeFiles/AGisland-4islas.dir/cmake_clean.cmake
.PHONY : application/CMakeFiles/AGisland-4islas.dir/clean

application/CMakeFiles/AGisland-4islas.dir/depend:
	cd /home/jose/Tesis/MyThesis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jose/Tesis/MyThesis /home/jose/Tesis/MyThesis/application /home/jose/Tesis/MyThesis/build /home/jose/Tesis/MyThesis/build/application /home/jose/Tesis/MyThesis/build/application/CMakeFiles/AGisland-4islas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : application/CMakeFiles/AGisland-4islas.dir/depend

