# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/theo/EPITECH_CPE/GITHUB/MyECS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/theo/EPITECH_CPE/GITHUB/MyECS

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/theo/EPITECH_CPE/GITHUB/MyECS/CMakeFiles /home/theo/EPITECH_CPE/GITHUB/MyECS/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/theo/EPITECH_CPE/GITHUB/MyECS/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named myecs

# Build rule for target.
myecs: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 myecs
.PHONY : myecs

# fast build rule for target.
myecs/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/build
.PHONY : myecs/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/main.cpp.s
.PHONY : main.cpp.s

src/ecs/engine/Engine.o: src/ecs/engine/Engine.cpp.o

.PHONY : src/ecs/engine/Engine.o

# target to build an object file
src/ecs/engine/Engine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/ecs/engine/Engine.cpp.o
.PHONY : src/ecs/engine/Engine.cpp.o

src/ecs/engine/Engine.i: src/ecs/engine/Engine.cpp.i

.PHONY : src/ecs/engine/Engine.i

# target to preprocess a source file
src/ecs/engine/Engine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/ecs/engine/Engine.cpp.i
.PHONY : src/ecs/engine/Engine.cpp.i

src/ecs/engine/Engine.s: src/ecs/engine/Engine.cpp.s

.PHONY : src/ecs/engine/Engine.s

# target to generate assembly for a file
src/ecs/engine/Engine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/ecs/engine/Engine.cpp.s
.PHONY : src/ecs/engine/Engine.cpp.s

src/ecs/entities/Entity.o: src/ecs/entities/Entity.cpp.o

.PHONY : src/ecs/entities/Entity.o

# target to build an object file
src/ecs/entities/Entity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/ecs/entities/Entity.cpp.o
.PHONY : src/ecs/entities/Entity.cpp.o

src/ecs/entities/Entity.i: src/ecs/entities/Entity.cpp.i

.PHONY : src/ecs/entities/Entity.i

# target to preprocess a source file
src/ecs/entities/Entity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/ecs/entities/Entity.cpp.i
.PHONY : src/ecs/entities/Entity.cpp.i

src/ecs/entities/Entity.s: src/ecs/entities/Entity.cpp.s

.PHONY : src/ecs/entities/Entity.s

# target to generate assembly for a file
src/ecs/entities/Entity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/ecs/entities/Entity.cpp.s
.PHONY : src/ecs/entities/Entity.cpp.s

src/ecs/systems/System.o: src/ecs/systems/System.cpp.o

.PHONY : src/ecs/systems/System.o

# target to build an object file
src/ecs/systems/System.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/ecs/systems/System.cpp.o
.PHONY : src/ecs/systems/System.cpp.o

src/ecs/systems/System.i: src/ecs/systems/System.cpp.i

.PHONY : src/ecs/systems/System.i

# target to preprocess a source file
src/ecs/systems/System.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/ecs/systems/System.cpp.i
.PHONY : src/ecs/systems/System.cpp.i

src/ecs/systems/System.s: src/ecs/systems/System.cpp.s

.PHONY : src/ecs/systems/System.s

# target to generate assembly for a file
src/ecs/systems/System.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/ecs/systems/System.cpp.s
.PHONY : src/ecs/systems/System.cpp.s

src/systems/TestSystem.o: src/systems/TestSystem.cpp.o

.PHONY : src/systems/TestSystem.o

# target to build an object file
src/systems/TestSystem.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/systems/TestSystem.cpp.o
.PHONY : src/systems/TestSystem.cpp.o

src/systems/TestSystem.i: src/systems/TestSystem.cpp.i

.PHONY : src/systems/TestSystem.i

# target to preprocess a source file
src/systems/TestSystem.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/systems/TestSystem.cpp.i
.PHONY : src/systems/TestSystem.cpp.i

src/systems/TestSystem.s: src/systems/TestSystem.cpp.s

.PHONY : src/systems/TestSystem.s

# target to generate assembly for a file
src/systems/TestSystem.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myecs.dir/build.make CMakeFiles/myecs.dir/src/systems/TestSystem.cpp.s
.PHONY : src/systems/TestSystem.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... myecs"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/ecs/engine/Engine.o"
	@echo "... src/ecs/engine/Engine.i"
	@echo "... src/ecs/engine/Engine.s"
	@echo "... src/ecs/entities/Entity.o"
	@echo "... src/ecs/entities/Entity.i"
	@echo "... src/ecs/entities/Entity.s"
	@echo "... src/ecs/systems/System.o"
	@echo "... src/ecs/systems/System.i"
	@echo "... src/ecs/systems/System.s"
	@echo "... src/systems/TestSystem.o"
	@echo "... src/systems/TestSystem.i"
	@echo "... src/systems/TestSystem.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
