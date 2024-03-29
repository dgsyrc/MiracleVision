# Remake on 2024-02-20 by dgsyrc
# For RoboMaster

# Create project
cmake_minimum_required(VERSION 3.10.0)
project(MiracleVision VERSION 2024.2.20 LANGUAGES CXX)

# Check system platform
if(NOT CMAKE_SYSTEM_NAME STREQUAL Linux)
    message(FATAL_ERROR "Not supported platform: ${CMAKE_SYSTEM_NAME}")
endif()

# Specialize CMake build flags for different build types
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-deprecated")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


# Use standard c++20
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add DEBUG/RELEASE marco to define if debug/release configured
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")
add_compile_options("$<$<CONFIG:RELEASE>:-DRELEASE>")

# Don't build test by default
set(BUILD_TEST False)

# Prefer posix threads
set(THREADS_PREFER_PTHREAD_FLAG True)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
find_package(Threads REQUIRED)

# Find and add opencv as required
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS})

#onnxruntime
set(ONNXRUNTIME_ROOT_PATH /usr/local)
set(ONNXRUNTIME_INCLUDE_DIRS ${ONNXRUNTIME_ROOT_PATH}/include/onnxruntime
                             ${ONNXRUNTIME_ROOT_PATH}/onnxruntime)
set(ONNXRUNTIME_LIB ${ONNXRUNTIME_ROOT_PATH}/lib/libonnxruntime.so)

# Add fmtlib directory
add_subdirectory(3rdparty/fmt)
# Add fmtlib include to EXTRA_INCLUDES
list(APPEND EXTRA_INCLUDES 3rdparty/fmt/include)

# Add mindvision-sdk directory and include path for target
add_library(MVSDK SHARED IMPORTED)
get_filename_component(MVSDK_PATH 3rdparty/mindvision/linux REALPATH)
# Check system architecture for mindvision-sdk library
execute_process(COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE)
message(STATUS "Checking platform architecture for MVSDK: ${ARCHITECTURE}")
if(${ARCHITECTURE} STREQUAL x86_64)
    set(MIMDVISION_SDK_LIBRARY ${MVSDK_PATH}/lib/x64/libMVSDK.so)
elseif(${ARCHITECTURE} STREQUAL x86)
    set(MIMDVISION_SDK_LIBRARY ${MVSDK_PATH}/lib/x86/libMVSDK.so)
elseif(${ARCHITECTURE} STREQUAL aarch64)
    set(MIMDVISION_SDK_LIBRARY ${MVSDK_PATH}/lib/arm64/libMVSDK.so)
elseif(${ARCHITECTURE} STREQUAL armv7)
    set(MIMDVISION_SDK_LIBRARY ${MVSDK_PATH}/lib/arm/libMVSDK.so)
else()
    message(FATAL_ERROR "Not supported architecture for MVSDK: ${ARCHITECTURE}")
endif()
set_property(TARGET MVSDK PROPERTY IMPORTED_LOCATION ${MIMDVISION_SDK_LIBRARY})
# Add mindvision lib to build target
list(APPEND EXTRA_LIBS MVSDK)
# Add mindvision include path
list(APPEND EXTRA_INCLUDES 3rdparty/mindvision/linux/include)

# Add project source dir to include
list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR})

# Add base src and header
list(APPEND EXTRA_INCLUDES base)

# Add device as shared library to build target
list(APPEND EXTRA_INCLUDES devices)

list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/devices/camera)
add_library(mv-video-capture SHARED devices/camera/mv_video_capture.cpp)
target_link_libraries(mv-video-capture
    PRIVATE
    MVSDK
)
list(APPEND MV_EXTRA_LIBS mv-video-capture)

list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/devices/serial)
add_library(mv-uart-serial SHARED devices/serial/uart_serial.cpp)
list(APPEND MV_EXTRA_LIBS mv-uart-serial)

# Add module as shared library to build target
list(APPEND EXTRA_INCLUDES module)

list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/module/angle_solve)
add_library(mv-basic-pnp SHARED module/angle_solve/basic_pnp.cpp)
list(APPEND MV_EXTRA_LIBS mv-basic-pnp)

list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/module/angle_solve)
add_library(mv-angle-solve SHARED module/angle_solve/angle_solve.cpp)
list(APPEND MV_EXTRA_LIBS mv-angle-solve)

list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/module/buff)
add_library(mv-new-buff SHARED module/buff/new_buff.cpp)
list(APPEND MV_EXTRA_LIBS mv-new-buff)


list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/module/armor)
add_library(mv-basic-armor SHARED module/armor/basic_armor.cpp)
list(APPEND MV_EXTRA_LIBS mv-basic-armor)
add_library(mv-fan-armor SHARED module/armor/fan_armor.cpp)
list(APPEND MV_EXTRA_LIBS mv-fan-armor)
add_library(mv-dnn-armor SHARED module/armor/DNN_armor.cpp)
list(APPEND MV_EXTRA_LIBS mv-dnn-armor)


list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/module/buff)
add_library(mv-basic-buff SHARED module/buff/basic_buff.cpp)
target_link_libraries(mv-basic-buff
    PRIVATE
    mv-fan-armor
    mv-new-buff
)
list(APPEND MV_EXTRA_LIBS mv-basic-buff)



list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/module/filter)
add_library(mv-basic-kalman SHARED module/filter/basic_kalman.cpp)
list(APPEND MV_EXTRA_LIBS mv-basic-kalman)

list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/module/ml)
add_library(mv-onnx-inferring SHARED module/ml/onnx_inferring.cpp)
list(APPEND MV_EXTRA_LIBS mv-onnx-inferring)

list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/module/roi)
add_library(mv-basic-roi SHARED module/roi/basic_roi.cpp)
list(APPEND MV_EXTRA_LIBS mv-basic-roi)

list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/module/camera)
add_library(mv-camera-calibration SHARED module/camera/camera_calibration.cpp)
list(APPEND MV_EXTRA_LIBS mv-camera-calibration)

# Add utils header
list(APPEND EXTRA_INCLUDES utils)

# Add EXTRA_INCLUDES to project includes
include_directories(${EXTRA_INCLUDES})

# Add base/MiracleVision to executable
add_executable(MiracleVision base/MiracleVision.cpp)

# Add shared library link to MiracleVision
target_link_libraries(MiracleVision
    PUBLIC
    Threads::Threads
    fmt::fmt
    ${OpenCV_LIBS}
    ${EXTRA_LIBS}
    ${ONNXRUNTIME_LIB}
    PRIVATE
    ${MV_EXTRA_LIBS}
)

# Set MiracleVision compile cxx_std features
target_compile_features(MiracleVision PUBLIC cxx_std_${CMAKE_CXX_STANDARD})

# Set MiracleVision linking time optimization to true
set_target_properties(MiracleVision PROPERTIES INTERPROCEDURAL_OPTIMIZATION True)

# Set built binary to ~/bin
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

# Set built library to ~/lib
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# Set configs folder absolute path
# define
set(CONFIG_FILE_PATH ${PROJECT_SOURCE_DIR}/configs)
set(SOURCE_PATH ${PROJECT_SOURCE_DIR})
set(SAVE_FILE_PATH ${PROJECT_SOURCE_DIR}/configs/camera)
target_compile_definitions(MiracleVision PRIVATE "CONFIG_FILE_PATH=\"${CONFIG_FILE_PATH}\"")
target_compile_definitions(MiracleVision PRIVATE "SOURCE_PATH=\"${SOURCE_PATH}\"")
target_compile_definitions(mv-basic-buff PRIVATE "CONFIG_FILE_PATH=\"${CONFIG_FILE_PATH}\"")
target_compile_definitions(mv-onnx-inferring PRIVATE "CONFIG_FILE_PATH=\"${CONFIG_FILE_PATH}\"")
target_compile_definitions(mv-camera-calibration PRIVATE "SAVE_FILE_PATH=\"${SAVE_FILE_PATH}\"")


# Add test_camera directory
if(BUILD_TEST)
    add_subdirectory(test/test_camera)
endif()
