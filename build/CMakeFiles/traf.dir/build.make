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
CMAKE_SOURCE_DIR = /home/recall/Desktop/Github_pro/FileTransfer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/recall/Desktop/Github_pro/FileTransfer/build

# Include any dependencies generated for this target.
include CMakeFiles/traf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/traf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/traf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/traf.dir/flags.make

CMakeFiles/traf.dir/src/Client_main.cpp.o: CMakeFiles/traf.dir/flags.make
CMakeFiles/traf.dir/src/Client_main.cpp.o: ../src/Client_main.cpp
CMakeFiles/traf.dir/src/Client_main.cpp.o: CMakeFiles/traf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recall/Desktop/Github_pro/FileTransfer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/traf.dir/src/Client_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/traf.dir/src/Client_main.cpp.o -MF CMakeFiles/traf.dir/src/Client_main.cpp.o.d -o CMakeFiles/traf.dir/src/Client_main.cpp.o -c /home/recall/Desktop/Github_pro/FileTransfer/src/Client_main.cpp

CMakeFiles/traf.dir/src/Client_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traf.dir/src/Client_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recall/Desktop/Github_pro/FileTransfer/src/Client_main.cpp > CMakeFiles/traf.dir/src/Client_main.cpp.i

CMakeFiles/traf.dir/src/Client_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traf.dir/src/Client_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recall/Desktop/Github_pro/FileTransfer/src/Client_main.cpp -o CMakeFiles/traf.dir/src/Client_main.cpp.s

CMakeFiles/traf.dir/src/parse_arguments.cpp.o: CMakeFiles/traf.dir/flags.make
CMakeFiles/traf.dir/src/parse_arguments.cpp.o: ../src/parse_arguments.cpp
CMakeFiles/traf.dir/src/parse_arguments.cpp.o: CMakeFiles/traf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recall/Desktop/Github_pro/FileTransfer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/traf.dir/src/parse_arguments.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/traf.dir/src/parse_arguments.cpp.o -MF CMakeFiles/traf.dir/src/parse_arguments.cpp.o.d -o CMakeFiles/traf.dir/src/parse_arguments.cpp.o -c /home/recall/Desktop/Github_pro/FileTransfer/src/parse_arguments.cpp

CMakeFiles/traf.dir/src/parse_arguments.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traf.dir/src/parse_arguments.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recall/Desktop/Github_pro/FileTransfer/src/parse_arguments.cpp > CMakeFiles/traf.dir/src/parse_arguments.cpp.i

CMakeFiles/traf.dir/src/parse_arguments.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traf.dir/src/parse_arguments.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recall/Desktop/Github_pro/FileTransfer/src/parse_arguments.cpp -o CMakeFiles/traf.dir/src/parse_arguments.cpp.s

CMakeFiles/traf.dir/src/client.cpp.o: CMakeFiles/traf.dir/flags.make
CMakeFiles/traf.dir/src/client.cpp.o: ../src/client.cpp
CMakeFiles/traf.dir/src/client.cpp.o: CMakeFiles/traf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recall/Desktop/Github_pro/FileTransfer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/traf.dir/src/client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/traf.dir/src/client.cpp.o -MF CMakeFiles/traf.dir/src/client.cpp.o.d -o CMakeFiles/traf.dir/src/client.cpp.o -c /home/recall/Desktop/Github_pro/FileTransfer/src/client.cpp

CMakeFiles/traf.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traf.dir/src/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recall/Desktop/Github_pro/FileTransfer/src/client.cpp > CMakeFiles/traf.dir/src/client.cpp.i

CMakeFiles/traf.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traf.dir/src/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recall/Desktop/Github_pro/FileTransfer/src/client.cpp -o CMakeFiles/traf.dir/src/client.cpp.s

# Object files for target traf
traf_OBJECTS = \
"CMakeFiles/traf.dir/src/Client_main.cpp.o" \
"CMakeFiles/traf.dir/src/parse_arguments.cpp.o" \
"CMakeFiles/traf.dir/src/client.cpp.o"

# External object files for target traf
traf_EXTERNAL_OBJECTS =

traf: CMakeFiles/traf.dir/src/Client_main.cpp.o
traf: CMakeFiles/traf.dir/src/parse_arguments.cpp.o
traf: CMakeFiles/traf.dir/src/client.cpp.o
traf: CMakeFiles/traf.dir/build.make
traf: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
traf: CMakeFiles/traf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/recall/Desktop/Github_pro/FileTransfer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable traf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/traf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/traf.dir/build: traf
.PHONY : CMakeFiles/traf.dir/build

CMakeFiles/traf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/traf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/traf.dir/clean

CMakeFiles/traf.dir/depend:
	cd /home/recall/Desktop/Github_pro/FileTransfer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/recall/Desktop/Github_pro/FileTransfer /home/recall/Desktop/Github_pro/FileTransfer /home/recall/Desktop/Github_pro/FileTransfer/build /home/recall/Desktop/Github_pro/FileTransfer/build /home/recall/Desktop/Github_pro/FileTransfer/build/CMakeFiles/traf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/traf.dir/depend

