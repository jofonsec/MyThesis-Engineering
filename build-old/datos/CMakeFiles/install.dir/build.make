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

# Utility rule file for install.

# Include the progress variables for this target.
include datos/CMakeFiles/install.dir/progress.make

datos/CMakeFiles/install: ../datos/AGMEsmp.param
datos/CMakeFiles/install: ../datos/AGisland.param
datos/CMakeFiles/install: ../datos/AGisland-2islas.param
datos/CMakeFiles/install: ../datos/AGS.param
datos/CMakeFiles/install: ../datos/Anclas.txt
datos/CMakeFiles/install: ../datos/Allposition.txt
datos/CMakeFiles/install: ../datos/generarES.param
datos/CMakeFiles/install: ../datos/graficarError.param
datos/CMakeFiles/install: ../datos/Matriz1.txt
datos/CMakeFiles/install: ../datos/Matriz2.txt
datos/CMakeFiles/install: ../datos/Matriz3.txt
datos/CMakeFiles/install: ../datos/Matriz4.txt
datos/CMakeFiles/install: ../datos

install: datos/CMakeFiles/install
install: datos/CMakeFiles/install.dir/build.make
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/AGMEsmp.param /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/AGS.param /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/AGisland.param /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/AGisland-2islas.param /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/Anclas.txt /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/Allposition.txt /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/generarES.param /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/graficarError.param /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/Matriz1.txt /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/Matriz2.txt /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/Matriz3.txt /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake -E copy_if_different /home/jose/Tesis/MyThesis/datos/Matriz4.txt /home/jose/Tesis/MyThesis/build/application
	cd /home/jose/Tesis/MyThesis/build/datos && /usr/bin/cmake
.PHONY : install

# Rule to build all files generated by this target.
datos/CMakeFiles/install.dir/build: install
.PHONY : datos/CMakeFiles/install.dir/build

datos/CMakeFiles/install.dir/clean:
	cd /home/jose/Tesis/MyThesis/build/datos && $(CMAKE_COMMAND) -P CMakeFiles/install.dir/cmake_clean.cmake
.PHONY : datos/CMakeFiles/install.dir/clean

datos/CMakeFiles/install.dir/depend:
	cd /home/jose/Tesis/MyThesis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jose/Tesis/MyThesis /home/jose/Tesis/MyThesis/datos /home/jose/Tesis/MyThesis/build /home/jose/Tesis/MyThesis/build/datos /home/jose/Tesis/MyThesis/build/datos/CMakeFiles/install.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : datos/CMakeFiles/install.dir/depend

