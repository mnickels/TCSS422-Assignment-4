# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /cygdrive/c/Users/User/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/User/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TCSS422-Assignment-4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TCSS422-Assignment-4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TCSS422-Assignment-4.dir/flags.make

CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o: CMakeFiles/TCSS422-Assignment-4.dir/flags.make
CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o: ../OS.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o   -c /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/OS.c

CMakeFiles/TCSS422-Assignment-4.dir/OS.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TCSS422-Assignment-4.dir/OS.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/OS.c > CMakeFiles/TCSS422-Assignment-4.dir/OS.c.i

CMakeFiles/TCSS422-Assignment-4.dir/OS.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TCSS422-Assignment-4.dir/OS.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/OS.c -o CMakeFiles/TCSS422-Assignment-4.dir/OS.c.s

CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o.requires:

.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o.requires

CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o.provides: CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o.requires
	$(MAKE) -f CMakeFiles/TCSS422-Assignment-4.dir/build.make CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o.provides.build
.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o.provides

CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o.provides.build: CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o


CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o: CMakeFiles/TCSS422-Assignment-4.dir/flags.make
CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o: ../fifo_queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o   -c /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/fifo_queue.c

CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/fifo_queue.c > CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.i

CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/fifo_queue.c -o CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.s

CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o.requires:

.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o.requires

CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o.provides: CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o.requires
	$(MAKE) -f CMakeFiles/TCSS422-Assignment-4.dir/build.make CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o.provides.build
.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o.provides

CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o.provides.build: CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o


CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o: CMakeFiles/TCSS422-Assignment-4.dir/flags.make
CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o: ../pcb.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o   -c /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/pcb.c

CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/pcb.c > CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.i

CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/pcb.c -o CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.s

CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o.requires:

.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o.requires

CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o.provides: CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o.requires
	$(MAKE) -f CMakeFiles/TCSS422-Assignment-4.dir/build.make CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o.provides.build
.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o.provides

CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o.provides.build: CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o


CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o: CMakeFiles/TCSS422-Assignment-4.dir/flags.make
CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o: ../PriorityQ.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o   -c /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/PriorityQ.c

CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/PriorityQ.c > CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.i

CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/PriorityQ.c -o CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.s

CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o.requires:

.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o.requires

CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o.provides: CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o.requires
	$(MAKE) -f CMakeFiles/TCSS422-Assignment-4.dir/build.make CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o.provides.build
.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o.provides

CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o.provides.build: CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o


# Object files for target TCSS422-Assignment-4
TCSS422__Assignment__4_OBJECTS = \
"CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o" \
"CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o" \
"CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o" \
"CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o"

# External object files for target TCSS422-Assignment-4
TCSS422__Assignment__4_EXTERNAL_OBJECTS =

TCSS422-Assignment-4.exe: CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o
TCSS422-Assignment-4.exe: CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o
TCSS422-Assignment-4.exe: CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o
TCSS422-Assignment-4.exe: CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o
TCSS422-Assignment-4.exe: CMakeFiles/TCSS422-Assignment-4.dir/build.make
TCSS422-Assignment-4.exe: CMakeFiles/TCSS422-Assignment-4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable TCSS422-Assignment-4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TCSS422-Assignment-4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TCSS422-Assignment-4.dir/build: TCSS422-Assignment-4.exe

.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/build

CMakeFiles/TCSS422-Assignment-4.dir/requires: CMakeFiles/TCSS422-Assignment-4.dir/OS.c.o.requires
CMakeFiles/TCSS422-Assignment-4.dir/requires: CMakeFiles/TCSS422-Assignment-4.dir/fifo_queue.c.o.requires
CMakeFiles/TCSS422-Assignment-4.dir/requires: CMakeFiles/TCSS422-Assignment-4.dir/pcb.c.o.requires
CMakeFiles/TCSS422-Assignment-4.dir/requires: CMakeFiles/TCSS422-Assignment-4.dir/PriorityQ.c.o.requires

.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/requires

CMakeFiles/TCSS422-Assignment-4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TCSS422-Assignment-4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/clean

CMakeFiles/TCSS422-Assignment-4.dir/depend:
	cd /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4 /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4 /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug /cygdrive/c/Users/User/CLionProjects/TCSS422-Assignment-4/cmake-build-debug/CMakeFiles/TCSS422-Assignment-4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TCSS422-Assignment-4.dir/depend
