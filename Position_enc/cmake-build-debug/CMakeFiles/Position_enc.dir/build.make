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
CMAKE_COMMAND = /home/kadyrov_suleyman/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kadyrov_suleyman/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kadyrov_suleyman/Position_enc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kadyrov_suleyman/Position_enc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Position_enc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Position_enc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Position_enc.dir/flags.make

CMakeFiles/Position_enc.dir/main.cpp.o: CMakeFiles/Position_enc.dir/flags.make
CMakeFiles/Position_enc.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kadyrov_suleyman/Position_enc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Position_enc.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Position_enc.dir/main.cpp.o -c /home/kadyrov_suleyman/Position_enc/main.cpp

CMakeFiles/Position_enc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Position_enc.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kadyrov_suleyman/Position_enc/main.cpp > CMakeFiles/Position_enc.dir/main.cpp.i

CMakeFiles/Position_enc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Position_enc.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kadyrov_suleyman/Position_enc/main.cpp -o CMakeFiles/Position_enc.dir/main.cpp.s

CMakeFiles/Position_enc.dir/Position_from_enc.cpp.o: CMakeFiles/Position_enc.dir/flags.make
CMakeFiles/Position_enc.dir/Position_from_enc.cpp.o: ../Position_from_enc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kadyrov_suleyman/Position_enc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Position_enc.dir/Position_from_enc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Position_enc.dir/Position_from_enc.cpp.o -c /home/kadyrov_suleyman/Position_enc/Position_from_enc.cpp

CMakeFiles/Position_enc.dir/Position_from_enc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Position_enc.dir/Position_from_enc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kadyrov_suleyman/Position_enc/Position_from_enc.cpp > CMakeFiles/Position_enc.dir/Position_from_enc.cpp.i

CMakeFiles/Position_enc.dir/Position_from_enc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Position_enc.dir/Position_from_enc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kadyrov_suleyman/Position_enc/Position_from_enc.cpp -o CMakeFiles/Position_enc.dir/Position_from_enc.cpp.s

# Object files for target Position_enc
Position_enc_OBJECTS = \
"CMakeFiles/Position_enc.dir/main.cpp.o" \
"CMakeFiles/Position_enc.dir/Position_from_enc.cpp.o"

# External object files for target Position_enc
Position_enc_EXTERNAL_OBJECTS =

Position_enc: CMakeFiles/Position_enc.dir/main.cpp.o
Position_enc: CMakeFiles/Position_enc.dir/Position_from_enc.cpp.o
Position_enc: CMakeFiles/Position_enc.dir/build.make
Position_enc: CMakeFiles/Position_enc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kadyrov_suleyman/Position_enc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Position_enc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Position_enc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Position_enc.dir/build: Position_enc

.PHONY : CMakeFiles/Position_enc.dir/build

CMakeFiles/Position_enc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Position_enc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Position_enc.dir/clean

CMakeFiles/Position_enc.dir/depend:
	cd /home/kadyrov_suleyman/Position_enc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kadyrov_suleyman/Position_enc /home/kadyrov_suleyman/Position_enc /home/kadyrov_suleyman/Position_enc/cmake-build-debug /home/kadyrov_suleyman/Position_enc/cmake-build-debug /home/kadyrov_suleyman/Position_enc/cmake-build-debug/CMakeFiles/Position_enc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Position_enc.dir/depend

