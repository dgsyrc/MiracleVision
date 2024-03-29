# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/ccong/MiracleVision

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ccong/MiracleVision

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ccong/MiracleVision/CMakeFiles /home/ccong/MiracleVision//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ccong/MiracleVision/CMakeFiles 0
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
# Target rules for targets named mv-video-capture

# Build rule for target.
mv-video-capture: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-video-capture
.PHONY : mv-video-capture

# fast build rule for target.
mv-video-capture/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-video-capture.dir/build.make CMakeFiles/mv-video-capture.dir/build
.PHONY : mv-video-capture/fast

#=============================================================================
# Target rules for targets named mv-uart-serial

# Build rule for target.
mv-uart-serial: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-uart-serial
.PHONY : mv-uart-serial

# fast build rule for target.
mv-uart-serial/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-uart-serial.dir/build.make CMakeFiles/mv-uart-serial.dir/build
.PHONY : mv-uart-serial/fast

#=============================================================================
# Target rules for targets named mv-basic-pnp

# Build rule for target.
mv-basic-pnp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-basic-pnp
.PHONY : mv-basic-pnp

# fast build rule for target.
mv-basic-pnp/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-pnp.dir/build.make CMakeFiles/mv-basic-pnp.dir/build
.PHONY : mv-basic-pnp/fast

#=============================================================================
# Target rules for targets named mv-angle-solve

# Build rule for target.
mv-angle-solve: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-angle-solve
.PHONY : mv-angle-solve

# fast build rule for target.
mv-angle-solve/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-angle-solve.dir/build.make CMakeFiles/mv-angle-solve.dir/build
.PHONY : mv-angle-solve/fast

#=============================================================================
# Target rules for targets named mv-new-buff

# Build rule for target.
mv-new-buff: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-new-buff
.PHONY : mv-new-buff

# fast build rule for target.
mv-new-buff/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-new-buff.dir/build.make CMakeFiles/mv-new-buff.dir/build
.PHONY : mv-new-buff/fast

#=============================================================================
# Target rules for targets named mv-basic-armor

# Build rule for target.
mv-basic-armor: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-basic-armor
.PHONY : mv-basic-armor

# fast build rule for target.
mv-basic-armor/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-armor.dir/build.make CMakeFiles/mv-basic-armor.dir/build
.PHONY : mv-basic-armor/fast

#=============================================================================
# Target rules for targets named mv-fan-armor

# Build rule for target.
mv-fan-armor: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-fan-armor
.PHONY : mv-fan-armor

# fast build rule for target.
mv-fan-armor/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-fan-armor.dir/build.make CMakeFiles/mv-fan-armor.dir/build
.PHONY : mv-fan-armor/fast

#=============================================================================
# Target rules for targets named mv-dnn-armor

# Build rule for target.
mv-dnn-armor: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-dnn-armor
.PHONY : mv-dnn-armor

# fast build rule for target.
mv-dnn-armor/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-dnn-armor.dir/build.make CMakeFiles/mv-dnn-armor.dir/build
.PHONY : mv-dnn-armor/fast

#=============================================================================
# Target rules for targets named mv-basic-buff

# Build rule for target.
mv-basic-buff: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-basic-buff
.PHONY : mv-basic-buff

# fast build rule for target.
mv-basic-buff/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-buff.dir/build.make CMakeFiles/mv-basic-buff.dir/build
.PHONY : mv-basic-buff/fast

#=============================================================================
# Target rules for targets named mv-basic-kalman

# Build rule for target.
mv-basic-kalman: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-basic-kalman
.PHONY : mv-basic-kalman

# fast build rule for target.
mv-basic-kalman/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-kalman.dir/build.make CMakeFiles/mv-basic-kalman.dir/build
.PHONY : mv-basic-kalman/fast

#=============================================================================
# Target rules for targets named mv-video-record

# Build rule for target.
mv-video-record: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-video-record
.PHONY : mv-video-record

# fast build rule for target.
mv-video-record/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-video-record.dir/build.make CMakeFiles/mv-video-record.dir/build
.PHONY : mv-video-record/fast

#=============================================================================
# Target rules for targets named mv-onnx-inferring

# Build rule for target.
mv-onnx-inferring: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-onnx-inferring
.PHONY : mv-onnx-inferring

# fast build rule for target.
mv-onnx-inferring/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-onnx-inferring.dir/build.make CMakeFiles/mv-onnx-inferring.dir/build
.PHONY : mv-onnx-inferring/fast

#=============================================================================
# Target rules for targets named mv-basic-roi

# Build rule for target.
mv-basic-roi: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-basic-roi
.PHONY : mv-basic-roi

# fast build rule for target.
mv-basic-roi/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-roi.dir/build.make CMakeFiles/mv-basic-roi.dir/build
.PHONY : mv-basic-roi/fast

#=============================================================================
# Target rules for targets named mv-camera-calibration

# Build rule for target.
mv-camera-calibration: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mv-camera-calibration
.PHONY : mv-camera-calibration

# fast build rule for target.
mv-camera-calibration/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-camera-calibration.dir/build.make CMakeFiles/mv-camera-calibration.dir/build
.PHONY : mv-camera-calibration/fast

#=============================================================================
# Target rules for targets named MiracleVision

# Build rule for target.
MiracleVision: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MiracleVision
.PHONY : MiracleVision

# fast build rule for target.
MiracleVision/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MiracleVision.dir/build.make CMakeFiles/MiracleVision.dir/build
.PHONY : MiracleVision/fast

#=============================================================================
# Target rules for targets named fmt

# Build rule for target.
fmt: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 fmt
.PHONY : fmt

# fast build rule for target.
fmt/fast:
	$(MAKE) $(MAKESILENT) -f 3rdparty/fmt/CMakeFiles/fmt.dir/build.make 3rdparty/fmt/CMakeFiles/fmt.dir/build
.PHONY : fmt/fast

base/MiracleVision.o: base/MiracleVision.cpp.o
.PHONY : base/MiracleVision.o

# target to build an object file
base/MiracleVision.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MiracleVision.dir/build.make CMakeFiles/MiracleVision.dir/base/MiracleVision.cpp.o
.PHONY : base/MiracleVision.cpp.o

base/MiracleVision.i: base/MiracleVision.cpp.i
.PHONY : base/MiracleVision.i

# target to preprocess a source file
base/MiracleVision.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MiracleVision.dir/build.make CMakeFiles/MiracleVision.dir/base/MiracleVision.cpp.i
.PHONY : base/MiracleVision.cpp.i

base/MiracleVision.s: base/MiracleVision.cpp.s
.PHONY : base/MiracleVision.s

# target to generate assembly for a file
base/MiracleVision.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MiracleVision.dir/build.make CMakeFiles/MiracleVision.dir/base/MiracleVision.cpp.s
.PHONY : base/MiracleVision.cpp.s

devices/camera/mv_video_capture.o: devices/camera/mv_video_capture.cpp.o
.PHONY : devices/camera/mv_video_capture.o

# target to build an object file
devices/camera/mv_video_capture.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-video-capture.dir/build.make CMakeFiles/mv-video-capture.dir/devices/camera/mv_video_capture.cpp.o
.PHONY : devices/camera/mv_video_capture.cpp.o

devices/camera/mv_video_capture.i: devices/camera/mv_video_capture.cpp.i
.PHONY : devices/camera/mv_video_capture.i

# target to preprocess a source file
devices/camera/mv_video_capture.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-video-capture.dir/build.make CMakeFiles/mv-video-capture.dir/devices/camera/mv_video_capture.cpp.i
.PHONY : devices/camera/mv_video_capture.cpp.i

devices/camera/mv_video_capture.s: devices/camera/mv_video_capture.cpp.s
.PHONY : devices/camera/mv_video_capture.s

# target to generate assembly for a file
devices/camera/mv_video_capture.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-video-capture.dir/build.make CMakeFiles/mv-video-capture.dir/devices/camera/mv_video_capture.cpp.s
.PHONY : devices/camera/mv_video_capture.cpp.s

devices/serial/uart_serial.o: devices/serial/uart_serial.cpp.o
.PHONY : devices/serial/uart_serial.o

# target to build an object file
devices/serial/uart_serial.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-uart-serial.dir/build.make CMakeFiles/mv-uart-serial.dir/devices/serial/uart_serial.cpp.o
.PHONY : devices/serial/uart_serial.cpp.o

devices/serial/uart_serial.i: devices/serial/uart_serial.cpp.i
.PHONY : devices/serial/uart_serial.i

# target to preprocess a source file
devices/serial/uart_serial.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-uart-serial.dir/build.make CMakeFiles/mv-uart-serial.dir/devices/serial/uart_serial.cpp.i
.PHONY : devices/serial/uart_serial.cpp.i

devices/serial/uart_serial.s: devices/serial/uart_serial.cpp.s
.PHONY : devices/serial/uart_serial.s

# target to generate assembly for a file
devices/serial/uart_serial.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-uart-serial.dir/build.make CMakeFiles/mv-uart-serial.dir/devices/serial/uart_serial.cpp.s
.PHONY : devices/serial/uart_serial.cpp.s

module/angle_solve/angle_solve.o: module/angle_solve/angle_solve.cpp.o
.PHONY : module/angle_solve/angle_solve.o

# target to build an object file
module/angle_solve/angle_solve.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-angle-solve.dir/build.make CMakeFiles/mv-angle-solve.dir/module/angle_solve/angle_solve.cpp.o
.PHONY : module/angle_solve/angle_solve.cpp.o

module/angle_solve/angle_solve.i: module/angle_solve/angle_solve.cpp.i
.PHONY : module/angle_solve/angle_solve.i

# target to preprocess a source file
module/angle_solve/angle_solve.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-angle-solve.dir/build.make CMakeFiles/mv-angle-solve.dir/module/angle_solve/angle_solve.cpp.i
.PHONY : module/angle_solve/angle_solve.cpp.i

module/angle_solve/angle_solve.s: module/angle_solve/angle_solve.cpp.s
.PHONY : module/angle_solve/angle_solve.s

# target to generate assembly for a file
module/angle_solve/angle_solve.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-angle-solve.dir/build.make CMakeFiles/mv-angle-solve.dir/module/angle_solve/angle_solve.cpp.s
.PHONY : module/angle_solve/angle_solve.cpp.s

module/angle_solve/basic_pnp.o: module/angle_solve/basic_pnp.cpp.o
.PHONY : module/angle_solve/basic_pnp.o

# target to build an object file
module/angle_solve/basic_pnp.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-pnp.dir/build.make CMakeFiles/mv-basic-pnp.dir/module/angle_solve/basic_pnp.cpp.o
.PHONY : module/angle_solve/basic_pnp.cpp.o

module/angle_solve/basic_pnp.i: module/angle_solve/basic_pnp.cpp.i
.PHONY : module/angle_solve/basic_pnp.i

# target to preprocess a source file
module/angle_solve/basic_pnp.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-pnp.dir/build.make CMakeFiles/mv-basic-pnp.dir/module/angle_solve/basic_pnp.cpp.i
.PHONY : module/angle_solve/basic_pnp.cpp.i

module/angle_solve/basic_pnp.s: module/angle_solve/basic_pnp.cpp.s
.PHONY : module/angle_solve/basic_pnp.s

# target to generate assembly for a file
module/angle_solve/basic_pnp.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-pnp.dir/build.make CMakeFiles/mv-basic-pnp.dir/module/angle_solve/basic_pnp.cpp.s
.PHONY : module/angle_solve/basic_pnp.cpp.s

module/armor/DNN_armor.o: module/armor/DNN_armor.cpp.o
.PHONY : module/armor/DNN_armor.o

# target to build an object file
module/armor/DNN_armor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-dnn-armor.dir/build.make CMakeFiles/mv-dnn-armor.dir/module/armor/DNN_armor.cpp.o
.PHONY : module/armor/DNN_armor.cpp.o

module/armor/DNN_armor.i: module/armor/DNN_armor.cpp.i
.PHONY : module/armor/DNN_armor.i

# target to preprocess a source file
module/armor/DNN_armor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-dnn-armor.dir/build.make CMakeFiles/mv-dnn-armor.dir/module/armor/DNN_armor.cpp.i
.PHONY : module/armor/DNN_armor.cpp.i

module/armor/DNN_armor.s: module/armor/DNN_armor.cpp.s
.PHONY : module/armor/DNN_armor.s

# target to generate assembly for a file
module/armor/DNN_armor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-dnn-armor.dir/build.make CMakeFiles/mv-dnn-armor.dir/module/armor/DNN_armor.cpp.s
.PHONY : module/armor/DNN_armor.cpp.s

module/armor/basic_armor.o: module/armor/basic_armor.cpp.o
.PHONY : module/armor/basic_armor.o

# target to build an object file
module/armor/basic_armor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-armor.dir/build.make CMakeFiles/mv-basic-armor.dir/module/armor/basic_armor.cpp.o
.PHONY : module/armor/basic_armor.cpp.o

module/armor/basic_armor.i: module/armor/basic_armor.cpp.i
.PHONY : module/armor/basic_armor.i

# target to preprocess a source file
module/armor/basic_armor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-armor.dir/build.make CMakeFiles/mv-basic-armor.dir/module/armor/basic_armor.cpp.i
.PHONY : module/armor/basic_armor.cpp.i

module/armor/basic_armor.s: module/armor/basic_armor.cpp.s
.PHONY : module/armor/basic_armor.s

# target to generate assembly for a file
module/armor/basic_armor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-armor.dir/build.make CMakeFiles/mv-basic-armor.dir/module/armor/basic_armor.cpp.s
.PHONY : module/armor/basic_armor.cpp.s

module/armor/fan_armor.o: module/armor/fan_armor.cpp.o
.PHONY : module/armor/fan_armor.o

# target to build an object file
module/armor/fan_armor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-fan-armor.dir/build.make CMakeFiles/mv-fan-armor.dir/module/armor/fan_armor.cpp.o
.PHONY : module/armor/fan_armor.cpp.o

module/armor/fan_armor.i: module/armor/fan_armor.cpp.i
.PHONY : module/armor/fan_armor.i

# target to preprocess a source file
module/armor/fan_armor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-fan-armor.dir/build.make CMakeFiles/mv-fan-armor.dir/module/armor/fan_armor.cpp.i
.PHONY : module/armor/fan_armor.cpp.i

module/armor/fan_armor.s: module/armor/fan_armor.cpp.s
.PHONY : module/armor/fan_armor.s

# target to generate assembly for a file
module/armor/fan_armor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-fan-armor.dir/build.make CMakeFiles/mv-fan-armor.dir/module/armor/fan_armor.cpp.s
.PHONY : module/armor/fan_armor.cpp.s

module/buff/basic_buff.o: module/buff/basic_buff.cpp.o
.PHONY : module/buff/basic_buff.o

# target to build an object file
module/buff/basic_buff.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-buff.dir/build.make CMakeFiles/mv-basic-buff.dir/module/buff/basic_buff.cpp.o
.PHONY : module/buff/basic_buff.cpp.o

module/buff/basic_buff.i: module/buff/basic_buff.cpp.i
.PHONY : module/buff/basic_buff.i

# target to preprocess a source file
module/buff/basic_buff.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-buff.dir/build.make CMakeFiles/mv-basic-buff.dir/module/buff/basic_buff.cpp.i
.PHONY : module/buff/basic_buff.cpp.i

module/buff/basic_buff.s: module/buff/basic_buff.cpp.s
.PHONY : module/buff/basic_buff.s

# target to generate assembly for a file
module/buff/basic_buff.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-buff.dir/build.make CMakeFiles/mv-basic-buff.dir/module/buff/basic_buff.cpp.s
.PHONY : module/buff/basic_buff.cpp.s

module/buff/new_buff.o: module/buff/new_buff.cpp.o
.PHONY : module/buff/new_buff.o

# target to build an object file
module/buff/new_buff.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-new-buff.dir/build.make CMakeFiles/mv-new-buff.dir/module/buff/new_buff.cpp.o
.PHONY : module/buff/new_buff.cpp.o

module/buff/new_buff.i: module/buff/new_buff.cpp.i
.PHONY : module/buff/new_buff.i

# target to preprocess a source file
module/buff/new_buff.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-new-buff.dir/build.make CMakeFiles/mv-new-buff.dir/module/buff/new_buff.cpp.i
.PHONY : module/buff/new_buff.cpp.i

module/buff/new_buff.s: module/buff/new_buff.cpp.s
.PHONY : module/buff/new_buff.s

# target to generate assembly for a file
module/buff/new_buff.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-new-buff.dir/build.make CMakeFiles/mv-new-buff.dir/module/buff/new_buff.cpp.s
.PHONY : module/buff/new_buff.cpp.s

module/camera/camera_calibration.o: module/camera/camera_calibration.cpp.o
.PHONY : module/camera/camera_calibration.o

# target to build an object file
module/camera/camera_calibration.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-camera-calibration.dir/build.make CMakeFiles/mv-camera-calibration.dir/module/camera/camera_calibration.cpp.o
.PHONY : module/camera/camera_calibration.cpp.o

module/camera/camera_calibration.i: module/camera/camera_calibration.cpp.i
.PHONY : module/camera/camera_calibration.i

# target to preprocess a source file
module/camera/camera_calibration.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-camera-calibration.dir/build.make CMakeFiles/mv-camera-calibration.dir/module/camera/camera_calibration.cpp.i
.PHONY : module/camera/camera_calibration.cpp.i

module/camera/camera_calibration.s: module/camera/camera_calibration.cpp.s
.PHONY : module/camera/camera_calibration.s

# target to generate assembly for a file
module/camera/camera_calibration.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-camera-calibration.dir/build.make CMakeFiles/mv-camera-calibration.dir/module/camera/camera_calibration.cpp.s
.PHONY : module/camera/camera_calibration.cpp.s

module/filter/basic_kalman.o: module/filter/basic_kalman.cpp.o
.PHONY : module/filter/basic_kalman.o

# target to build an object file
module/filter/basic_kalman.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-kalman.dir/build.make CMakeFiles/mv-basic-kalman.dir/module/filter/basic_kalman.cpp.o
.PHONY : module/filter/basic_kalman.cpp.o

module/filter/basic_kalman.i: module/filter/basic_kalman.cpp.i
.PHONY : module/filter/basic_kalman.i

# target to preprocess a source file
module/filter/basic_kalman.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-kalman.dir/build.make CMakeFiles/mv-basic-kalman.dir/module/filter/basic_kalman.cpp.i
.PHONY : module/filter/basic_kalman.cpp.i

module/filter/basic_kalman.s: module/filter/basic_kalman.cpp.s
.PHONY : module/filter/basic_kalman.s

# target to generate assembly for a file
module/filter/basic_kalman.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-kalman.dir/build.make CMakeFiles/mv-basic-kalman.dir/module/filter/basic_kalman.cpp.s
.PHONY : module/filter/basic_kalman.cpp.s

module/ml/onnx_inferring.o: module/ml/onnx_inferring.cpp.o
.PHONY : module/ml/onnx_inferring.o

# target to build an object file
module/ml/onnx_inferring.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-onnx-inferring.dir/build.make CMakeFiles/mv-onnx-inferring.dir/module/ml/onnx_inferring.cpp.o
.PHONY : module/ml/onnx_inferring.cpp.o

module/ml/onnx_inferring.i: module/ml/onnx_inferring.cpp.i
.PHONY : module/ml/onnx_inferring.i

# target to preprocess a source file
module/ml/onnx_inferring.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-onnx-inferring.dir/build.make CMakeFiles/mv-onnx-inferring.dir/module/ml/onnx_inferring.cpp.i
.PHONY : module/ml/onnx_inferring.cpp.i

module/ml/onnx_inferring.s: module/ml/onnx_inferring.cpp.s
.PHONY : module/ml/onnx_inferring.s

# target to generate assembly for a file
module/ml/onnx_inferring.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-onnx-inferring.dir/build.make CMakeFiles/mv-onnx-inferring.dir/module/ml/onnx_inferring.cpp.s
.PHONY : module/ml/onnx_inferring.cpp.s

module/record/record.o: module/record/record.cpp.o
.PHONY : module/record/record.o

# target to build an object file
module/record/record.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-video-record.dir/build.make CMakeFiles/mv-video-record.dir/module/record/record.cpp.o
.PHONY : module/record/record.cpp.o

module/record/record.i: module/record/record.cpp.i
.PHONY : module/record/record.i

# target to preprocess a source file
module/record/record.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-video-record.dir/build.make CMakeFiles/mv-video-record.dir/module/record/record.cpp.i
.PHONY : module/record/record.cpp.i

module/record/record.s: module/record/record.cpp.s
.PHONY : module/record/record.s

# target to generate assembly for a file
module/record/record.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-video-record.dir/build.make CMakeFiles/mv-video-record.dir/module/record/record.cpp.s
.PHONY : module/record/record.cpp.s

module/roi/basic_roi.o: module/roi/basic_roi.cpp.o
.PHONY : module/roi/basic_roi.o

# target to build an object file
module/roi/basic_roi.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-roi.dir/build.make CMakeFiles/mv-basic-roi.dir/module/roi/basic_roi.cpp.o
.PHONY : module/roi/basic_roi.cpp.o

module/roi/basic_roi.i: module/roi/basic_roi.cpp.i
.PHONY : module/roi/basic_roi.i

# target to preprocess a source file
module/roi/basic_roi.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-roi.dir/build.make CMakeFiles/mv-basic-roi.dir/module/roi/basic_roi.cpp.i
.PHONY : module/roi/basic_roi.cpp.i

module/roi/basic_roi.s: module/roi/basic_roi.cpp.s
.PHONY : module/roi/basic_roi.s

# target to generate assembly for a file
module/roi/basic_roi.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mv-basic-roi.dir/build.make CMakeFiles/mv-basic-roi.dir/module/roi/basic_roi.cpp.s
.PHONY : module/roi/basic_roi.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... MiracleVision"
	@echo "... fmt"
	@echo "... mv-angle-solve"
	@echo "... mv-basic-armor"
	@echo "... mv-basic-buff"
	@echo "... mv-basic-kalman"
	@echo "... mv-basic-pnp"
	@echo "... mv-basic-roi"
	@echo "... mv-camera-calibration"
	@echo "... mv-dnn-armor"
	@echo "... mv-fan-armor"
	@echo "... mv-new-buff"
	@echo "... mv-onnx-inferring"
	@echo "... mv-uart-serial"
	@echo "... mv-video-capture"
	@echo "... mv-video-record"
	@echo "... base/MiracleVision.o"
	@echo "... base/MiracleVision.i"
	@echo "... base/MiracleVision.s"
	@echo "... devices/camera/mv_video_capture.o"
	@echo "... devices/camera/mv_video_capture.i"
	@echo "... devices/camera/mv_video_capture.s"
	@echo "... devices/serial/uart_serial.o"
	@echo "... devices/serial/uart_serial.i"
	@echo "... devices/serial/uart_serial.s"
	@echo "... module/angle_solve/angle_solve.o"
	@echo "... module/angle_solve/angle_solve.i"
	@echo "... module/angle_solve/angle_solve.s"
	@echo "... module/angle_solve/basic_pnp.o"
	@echo "... module/angle_solve/basic_pnp.i"
	@echo "... module/angle_solve/basic_pnp.s"
	@echo "... module/armor/DNN_armor.o"
	@echo "... module/armor/DNN_armor.i"
	@echo "... module/armor/DNN_armor.s"
	@echo "... module/armor/basic_armor.o"
	@echo "... module/armor/basic_armor.i"
	@echo "... module/armor/basic_armor.s"
	@echo "... module/armor/fan_armor.o"
	@echo "... module/armor/fan_armor.i"
	@echo "... module/armor/fan_armor.s"
	@echo "... module/buff/basic_buff.o"
	@echo "... module/buff/basic_buff.i"
	@echo "... module/buff/basic_buff.s"
	@echo "... module/buff/new_buff.o"
	@echo "... module/buff/new_buff.i"
	@echo "... module/buff/new_buff.s"
	@echo "... module/camera/camera_calibration.o"
	@echo "... module/camera/camera_calibration.i"
	@echo "... module/camera/camera_calibration.s"
	@echo "... module/filter/basic_kalman.o"
	@echo "... module/filter/basic_kalman.i"
	@echo "... module/filter/basic_kalman.s"
	@echo "... module/ml/onnx_inferring.o"
	@echo "... module/ml/onnx_inferring.i"
	@echo "... module/ml/onnx_inferring.s"
	@echo "... module/record/record.o"
	@echo "... module/record/record.i"
	@echo "... module/record/record.s"
	@echo "... module/roi/basic_roi.o"
	@echo "... module/roi/basic_roi.i"
	@echo "... module/roi/basic_roi.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

