// Copyright (c)       2013 Martin Stumpf
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// The class header file
#include "generic_buffer.hpp"

using hpx::opencl::util::generic_buffer;

hpx::serialization::serialize_buffer<char>
generic_buffer::raw()
{
    return data.get();
}


generic_buffer::operator hpx::future<std::string>()
{
    return data.then(
        [] (data_type && data)
        {
            hpx::serialization::serialize_buffer<char> char_array =
                data.get();

            // Calculate length of string. Cut short if it has a 0-Termination
            // (Some queries like CL_DEVICE_NAME always return a size of 64, but 
            // contain a 0-terminated string)
            std::size_t length = 0;
            while(length < char_array.size())
            {
                if(char_array[length] == '\0') break;
                length++;
            }

            return std::string(char_array.data(), char_array.data() + length);
        });
}


