# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.3.6/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.3.6/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/MPU6050_AND_SERIAL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MPU6050_AND_SERIAL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MPU6050_AND_SERIAL.dir/flags.make

CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.o: CMakeFiles/MPU6050_AND_SERIAL.dir/flags.make
CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.o -c "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/main.cpp"

CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/main.cpp" > CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.i

CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/main.cpp" -o CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.s

CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.o: CMakeFiles/MPU6050_AND_SERIAL.dir/flags.make
CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.o: ../MPU6050.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.o -c "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/MPU6050.cpp"

CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/MPU6050.cpp" > CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.i

CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/MPU6050.cpp" -o CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.s

# Object files for target MPU6050_AND_SERIAL
MPU6050_AND_SERIAL_OBJECTS = \
"CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.o" \
"CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.o"

# External object files for target MPU6050_AND_SERIAL
MPU6050_AND_SERIAL_EXTERNAL_OBJECTS =

MPU6050_AND_SERIAL: CMakeFiles/MPU6050_AND_SERIAL.dir/main.cpp.o
MPU6050_AND_SERIAL: CMakeFiles/MPU6050_AND_SERIAL.dir/MPU6050.cpp.o
MPU6050_AND_SERIAL: CMakeFiles/MPU6050_AND_SERIAL.dir/build.make
MPU6050_AND_SERIAL: CMakeFiles/MPU6050_AND_SERIAL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MPU6050_AND_SERIAL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MPU6050_AND_SERIAL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MPU6050_AND_SERIAL.dir/build: MPU6050_AND_SERIAL

.PHONY : CMakeFiles/MPU6050_AND_SERIAL.dir/build

CMakeFiles/MPU6050_AND_SERIAL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MPU6050_AND_SERIAL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MPU6050_AND_SERIAL.dir/clean

CMakeFiles/MPU6050_AND_SERIAL.dir/depend:
	cd "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL" "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL" "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/cmake-build-debug" "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/cmake-build-debug" "/home/ilya/Рабочий стол/Технопарк/gyroscope/MPU6050_AND_SERIAL/cmake-build-debug/CMakeFiles/MPU6050_AND_SERIAL.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MPU6050_AND_SERIAL.dir/depend
