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
CMAKE_SOURCE_DIR = /parmesan/llvm_mode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /parmesan/llvm_mode/build

# Include any dependencies generated for this target.
include dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/depend.make

# Include the progress variables for this target.
include dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/progress.make

# Include the compile flags for this target's objects.
include dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/flags.make

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.o: dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/flags.make
dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.o: ../dfsan_rt/interception/interception_linux.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/parmesan/llvm_mode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.o"
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.o -c /parmesan/llvm_mode/dfsan_rt/interception/interception_linux.cc

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.i"
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /parmesan/llvm_mode/dfsan_rt/interception/interception_linux.cc > CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.i

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.s"
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /parmesan/llvm_mode/dfsan_rt/interception/interception_linux.cc -o CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.s

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.o: dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/flags.make
dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.o: ../dfsan_rt/interception/interception_mac.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/parmesan/llvm_mode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.o"
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.o -c /parmesan/llvm_mode/dfsan_rt/interception/interception_mac.cc

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.i"
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /parmesan/llvm_mode/dfsan_rt/interception/interception_mac.cc > CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.i

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.s"
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /parmesan/llvm_mode/dfsan_rt/interception/interception_mac.cc -o CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.s

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.o: dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/flags.make
dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.o: ../dfsan_rt/interception/interception_win.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/parmesan/llvm_mode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.o"
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.o -c /parmesan/llvm_mode/dfsan_rt/interception/interception_win.cc

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.i"
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /parmesan/llvm_mode/dfsan_rt/interception/interception_win.cc > CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.i

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.s"
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /parmesan/llvm_mode/dfsan_rt/interception/interception_win.cc -o CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.s

RTInterception.x86_64: dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_linux.cc.o
RTInterception.x86_64: dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_mac.cc.o
RTInterception.x86_64: dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/interception_win.cc.o
RTInterception.x86_64: dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/build.make

.PHONY : RTInterception.x86_64

# Rule to build all files generated by this target.
dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/build: RTInterception.x86_64

.PHONY : dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/build

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/clean:
	cd /parmesan/llvm_mode/build/dfsan_rt/interception && $(CMAKE_COMMAND) -P CMakeFiles/RTInterception.x86_64.dir/cmake_clean.cmake
.PHONY : dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/clean

dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/depend:
	cd /parmesan/llvm_mode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /parmesan/llvm_mode /parmesan/llvm_mode/dfsan_rt/interception /parmesan/llvm_mode/build /parmesan/llvm_mode/build/dfsan_rt/interception /parmesan/llvm_mode/build/dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dfsan_rt/interception/CMakeFiles/RTInterception.x86_64.dir/depend

