// Copyright (c)       2017 Madhavan Seshadri
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//###########################################################################
//Kernels
//###########################################################################

__kernel void partition(size_t offset, TYPE* in) {
	int threadIdX = get_local_id(0);
	int workGroupSize = get_global_size(0);
	size_t i = offset + threadIdX + workGroupSize;
	
	TYPE x = (TYPE) i;
	TYPE s = sinf(x);
	TYPE c = cosf(x);
	in[i] = in[i] + sqrt(s*s+c*c);

}