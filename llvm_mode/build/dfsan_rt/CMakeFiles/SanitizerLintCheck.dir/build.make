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

# Utility rule file for SanitizerLintCheck.

# Include the progress variables for this target.
include dfsan_rt/CMakeFiles/SanitizerLintCheck.dir/progress.make

dfsan_rt/CMakeFiles/SanitizerLintCheck: ../dfsan_rt/sanitizer_common/scripts/check_lint.sh
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/parmesan/llvm_mode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running lint check for sanitizer sources..."
	cd /parmesan/llvm_mode/build/dfsan_rt && env LLVM_CHECKOUT= SILENT=1 TMPDIR= PYTHON_EXECUTABLE= COMPILER_RT=/parmesan/llvm_mode/dfsan_rt /parmesan/llvm_mode/dfsan_rt/sanitizer_common/scripts/check_lint.sh

SanitizerLintCheck: dfsan_rt/CMakeFiles/SanitizerLintCheck
SanitizerLintCheck: dfsan_rt/CMakeFiles/SanitizerLintCheck.dir/build.make

.PHONY : SanitizerLintCheck

# Rule to build all files generated by this target.
dfsan_rt/CMakeFiles/SanitizerLintCheck.dir/build: SanitizerLintCheck

.PHONY : dfsan_rt/CMakeFiles/SanitizerLintCheck.dir/build

dfsan_rt/CMakeFiles/SanitizerLintCheck.dir/clean:
	cd /parmesan/llvm_mode/build/dfsan_rt && $(CMAKE_COMMAND) -P CMakeFiles/SanitizerLintCheck.dir/cmake_clean.cmake
.PHONY : dfsan_rt/CMakeFiles/SanitizerLintCheck.dir/clean

dfsan_rt/CMakeFiles/SanitizerLintCheck.dir/depend:
	cd /parmesan/llvm_mode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /parmesan/llvm_mode /parmesan/llvm_mode/dfsan_rt /parmesan/llvm_mode/build /parmesan/llvm_mode/build/dfsan_rt /parmesan/llvm_mode/build/dfsan_rt/CMakeFiles/SanitizerLintCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dfsan_rt/CMakeFiles/SanitizerLintCheck.dir/depend

