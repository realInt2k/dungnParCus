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

# Utility rule file for install-aibar.

# Include the progress variables for this target.
include aibar_rt/aibar/CMakeFiles/install-aibar.dir/progress.make

aibar_rt/aibar/CMakeFiles/install-aibar:
	cd /parmesan/llvm_mode/build/aibar_rt/aibar && /usr/bin/cmake -DCMAKE_INSTALL_COMPONENT=aibar -P /parmesan/llvm_mode/build/cmake_install.cmake

install-aibar: aibar_rt/aibar/CMakeFiles/install-aibar
install-aibar: aibar_rt/aibar/CMakeFiles/install-aibar.dir/build.make

.PHONY : install-aibar

# Rule to build all files generated by this target.
aibar_rt/aibar/CMakeFiles/install-aibar.dir/build: install-aibar

.PHONY : aibar_rt/aibar/CMakeFiles/install-aibar.dir/build

aibar_rt/aibar/CMakeFiles/install-aibar.dir/clean:
	cd /parmesan/llvm_mode/build/aibar_rt/aibar && $(CMAKE_COMMAND) -P CMakeFiles/install-aibar.dir/cmake_clean.cmake
.PHONY : aibar_rt/aibar/CMakeFiles/install-aibar.dir/clean

aibar_rt/aibar/CMakeFiles/install-aibar.dir/depend:
	cd /parmesan/llvm_mode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /parmesan/llvm_mode /parmesan/llvm_mode/aibar_rt/aibar /parmesan/llvm_mode/build /parmesan/llvm_mode/build/aibar_rt/aibar /parmesan/llvm_mode/build/aibar_rt/aibar/CMakeFiles/install-aibar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : aibar_rt/aibar/CMakeFiles/install-aibar.dir/depend
