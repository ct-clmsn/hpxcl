# Copyright (c)    2015 Patrick Diehl
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
##############################################################################
# - Try to find the Cuda NVRTC library
# Once done this will define
# LIBNVRTC_FOUND - System has LibNVRTC
# LIBNVRTC_LIBRARY_DIR - The NVRTC libraries dir
# CUDA_NVRTC_LIB - The NVRTC lib
##############################################################################
find_package(PkgConfig)

find_library(CUDA_NVRTC_LIB libnvrtc.so HINTS LIBNVRTC_LIBRARY_DIR /usr/local/lib64)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LibNVRTC DEFAULT_MSG CUDA_NVRTC_LIB)

mark_as_advanced(CUDA_NVRTC_LIB)

if(NOT LIBNVRTC_FOUND)
message(FATAL_ERROR "Cuda NVRTC Library not found: Specify the LIBNVRTC_LIBRARY_DIR where libnvrtc.so is located") 
endif()
