// Copyright (c)    2013 Martin Stumpf
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#ifndef HPX_OPENCL_DEVICE_HPP_
#define HPX_OPENCL_DEVICE_HPP_

// Default includes
#include <hpx/hpx.hpp>
#include <hpx/config.hpp>

// Export definitions
#include "export_definitions.hpp"

// OpenCL
#include "cl_headers.hpp"

// Forward Declarations
#include "fwd_declarations.hpp"

// Dependencies
#include "detail/info_type.hpp"
#include "util/generic_buffer.hpp"

namespace hpx {
namespace opencl {

    /////////////////////////////////////////
    /// @brief An accelerator device.
    ///
    class HPX_OPENCL_EXPORT device
      : public hpx::components::client_base<device, server::device>
    {
    
        typedef hpx::components::client_base<device, server::device> base_type;

        public:
            device(){}

            device(hpx::shared_future<hpx::naming::id_type> const& gid)
              : base_type(gid)
            {}
            
            //////////////////////////////////////////
            // Exposed Component functionality
            // 

            /**
             *  @brief Creates an OpenCL buffer.
             *
             *  @param flags    Sets properties of the buffer.<BR>
             *                  Possible values are
             *                      - CL_MEM_READ_WRITE
             *                      - CL_MEM_WRITE_ONLY
             *                      - CL_MEM_READ_ONLY
             *                      - CL_MEM_HOST_WRITE_ONLY
             *                      - CL_MEM_HOST_READ_ONLY
             *                      - CL_MEM_HOST_NO_ACCESS
             *                      .
             *                  and combinations of them.<BR>
             *                  For further information, read the official
             *                  <A HREF="http://www.khronos.org/registry/cl/sdk/
             * 1.2/docs/man/xhtml/clCreateBuffer.html">
             *                  OpenCL Reference</A>.
             *  @param size     The size of the buffer, in bytes.
             *  @return         A new \ref buffer object.
             *  @see            buffer
             */
            hpx::opencl::buffer
            create_buffer(cl_mem_flags flags, std::size_t size) const;

            /**
             *  @brief Queries device infos.
             *  
             *         The template argument defines the type of information.
             *         A complete list can be found on the official
             *         <A HREF="http://www.khronos.org/registry/cl/
             * sdk/1.2/docs/man/xhtml/clGetDeviceInfo.html">
             *                      OpenCL Reference</A>.
             *  @return The requested information.
             */
            template<cl_device_info Name>
            hpx::future<typename detail::device_info<Name>::type>
            get_device_info() const {

                hpx::opencl::util::generic_buffer data = 
                    get_device_info_raw(Name);

                return static_cast<hpx::future<
                    typename detail::device_info<Name>::type> >(data);

            }

            /**
             *  @brief Queries platform infos.
             *  
             *         The template argument defines the type of information.
             *         A complete list can be found on the official
             *         <A HREF="http://www.khronos.org/registry/cl/
             * sdk/1.2/docs/man/xhtml/clGetPlatformInfo.html">
             *                      OpenCL Reference</A>.
             *  @return The requested information.
             */
            template<cl_platform_info Name>
            hpx::future<typename detail::platform_info<Name>::type>
            get_platform_info() const {

                hpx::opencl::util::generic_buffer data = 
                    get_platform_info_raw(Name);

                return static_cast<hpx::future<
                    typename detail::platform_info<Name>::type> >(data);

            }

        private:
            
            //////////////////////////////////////////
            // Internal Component functionality
            // 

            /**
             *  @brief Queries device infos.
             *  
             *  @param info_type    The type of information.<BR>
             *                      A complete list can be found on the official
             *                      <A HREF="http://www.khronos.org/registry/cl/
             * sdk/1.2/docs/man/xhtml/clGetDeviceInfo.html">
             *                      OpenCL Reference</A>.
             *  @return The info data as \ref hpx::opencl::info.<BR>
             *          It can be cast to several datatypes.
             */
            hpx::opencl::util::generic_buffer
            get_device_info_raw(cl_device_info info_type) const;

             /**
             *  @brief Queries platform infos.
             *  
             *  @param info_type    The type of information.<BR>
             *                      A complete list can be found on the official
             *                      <A HREF="http://www.khronos.org/registry/cl/
             * sdk/1.2/docs/man/xhtml/clGetPlatformInfo.html">
             *                      OpenCL Reference</A>.
             *  @return The info data as \ref hpx::opencl::info.<BR>
             *          It can be cast to several datatypes.
             */
            hpx::opencl::util::generic_buffer
            get_platform_info_raw(cl_platform_info info_type) const;


    };

}}


#endif// HPX_OPENCL_DEVICE_HPP_

            
