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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vimsiin/Desktop/opengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vimsiin/Desktop/opengl/build

# Include any dependencies generated for this target.
include src/CMakeFiles/opengl.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/opengl.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/opengl.dir/flags.make

src/CMakeFiles/opengl.dir/main.cpp.o: src/CMakeFiles/opengl.dir/flags.make
src/CMakeFiles/opengl.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vimsiin/Desktop/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/opengl.dir/main.cpp.o"
	cd /home/vimsiin/Desktop/opengl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/main.cpp.o -c /home/vimsiin/Desktop/opengl/src/main.cpp

src/CMakeFiles/opengl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/main.cpp.i"
	cd /home/vimsiin/Desktop/opengl/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vimsiin/Desktop/opengl/src/main.cpp > CMakeFiles/opengl.dir/main.cpp.i

src/CMakeFiles/opengl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/main.cpp.s"
	cd /home/vimsiin/Desktop/opengl/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vimsiin/Desktop/opengl/src/main.cpp -o CMakeFiles/opengl.dir/main.cpp.s

src/CMakeFiles/opengl.dir/world.cpp.o: src/CMakeFiles/opengl.dir/flags.make
src/CMakeFiles/opengl.dir/world.cpp.o: ../src/world.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vimsiin/Desktop/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/opengl.dir/world.cpp.o"
	cd /home/vimsiin/Desktop/opengl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/world.cpp.o -c /home/vimsiin/Desktop/opengl/src/world.cpp

src/CMakeFiles/opengl.dir/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/world.cpp.i"
	cd /home/vimsiin/Desktop/opengl/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vimsiin/Desktop/opengl/src/world.cpp > CMakeFiles/opengl.dir/world.cpp.i

src/CMakeFiles/opengl.dir/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/world.cpp.s"
	cd /home/vimsiin/Desktop/opengl/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vimsiin/Desktop/opengl/src/world.cpp -o CMakeFiles/opengl.dir/world.cpp.s

src/CMakeFiles/opengl.dir/camera.cpp.o: src/CMakeFiles/opengl.dir/flags.make
src/CMakeFiles/opengl.dir/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vimsiin/Desktop/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/opengl.dir/camera.cpp.o"
	cd /home/vimsiin/Desktop/opengl/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl.dir/camera.cpp.o -c /home/vimsiin/Desktop/opengl/src/camera.cpp

src/CMakeFiles/opengl.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl.dir/camera.cpp.i"
	cd /home/vimsiin/Desktop/opengl/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vimsiin/Desktop/opengl/src/camera.cpp > CMakeFiles/opengl.dir/camera.cpp.i

src/CMakeFiles/opengl.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl.dir/camera.cpp.s"
	cd /home/vimsiin/Desktop/opengl/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vimsiin/Desktop/opengl/src/camera.cpp -o CMakeFiles/opengl.dir/camera.cpp.s

# Object files for target opengl
opengl_OBJECTS = \
"CMakeFiles/opengl.dir/main.cpp.o" \
"CMakeFiles/opengl.dir/world.cpp.o" \
"CMakeFiles/opengl.dir/camera.cpp.o"

# External object files for target opengl
opengl_EXTERNAL_OBJECTS =

src/opengl: src/CMakeFiles/opengl.dir/main.cpp.o
src/opengl: src/CMakeFiles/opengl.dir/world.cpp.o
src/opengl: src/CMakeFiles/opengl.dir/camera.cpp.o
src/opengl: src/CMakeFiles/opengl.dir/build.make
src/opengl: ../lib/libglfw3.a
src/opengl: src/gl3w/libgl3w.a
src/opengl: src/CMakeFiles/opengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vimsiin/Desktop/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable opengl"
	cd /home/vimsiin/Desktop/opengl/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/opengl.dir/build: src/opengl

.PHONY : src/CMakeFiles/opengl.dir/build

src/CMakeFiles/opengl.dir/clean:
	cd /home/vimsiin/Desktop/opengl/build/src && $(CMAKE_COMMAND) -P CMakeFiles/opengl.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/opengl.dir/clean

src/CMakeFiles/opengl.dir/depend:
	cd /home/vimsiin/Desktop/opengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vimsiin/Desktop/opengl /home/vimsiin/Desktop/opengl/src /home/vimsiin/Desktop/opengl/build /home/vimsiin/Desktop/opengl/build/src /home/vimsiin/Desktop/opengl/build/src/CMakeFiles/opengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/opengl.dir/depend

