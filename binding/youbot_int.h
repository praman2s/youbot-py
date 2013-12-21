/****************************************************************
 *
 * Copyright (c) 2011
 * All rights reserved.
 * 
 * Locomotec GmBH
 * Hochschule Bonn-Rhein-Sieg
 * University of Applied Sciences
 * Computer Science Department
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Author:
 * Praveen Ramanujam
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * This sofware is published under a dual-license: GNU Lesser General Public 
 * License LGPL 2.1 and BSD license. The dual-license implies that users of this
 * code may choose which terms they prefer.
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Hochschule Bonn-Rhein-Sieg nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 2.1 of the
 * License, or (at your option) any later version or the BSD license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License LGPL and the BSD license for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL and BSD license along with this program.
 *
 ****************************************************************/

#include <boost/array.hpp>
#include <boost/multi_array.hpp>
#include <boost/python/numeric.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/format.hpp>
#include <boost/python.hpp>
#include <boost/assert.hpp>
#include <numpy/ndarrayobject.h> 
#include <boost/cstdint.hpp>
#include <numpy/ndarrayobject.h>
#include <vector>

// Contains all the required headers and the inline templates for python conversion

namespace YOUBOTPYTHON{
using namespace boost::python;

/* To Extract Array from Python Object */
template <typename T>
	inline std::vector<T> ExtractArray(const object& o)
	{
	    std::vector<T> v(len(o));
	    for(size_t i = 0; i < v.size(); ++i) {
		v[i] = extract<T>(o[i]);
	    }
	    return v;
	}

/* To convert std::vector<double> to python array*/
	inline object PyArray( std::vector<double> const& vec )
	{
      		npy_intp size = vec.size();  // Assumes that the vector size is never zero
		double * data = size ? const_cast<double *>(&vec[0]) : static_cast<double *>(NULL);
      		PyObject * pyObj = PyArray_SimpleNewFromData( 1, &size, NPY_DOUBLE, data );
      		boost::python::handle<> handle( pyObj );
      		boost::python::numeric::array arr( handle );
		return arr.copy();
  	};
}/*End of Namespace YOUBOTPYTHON*/



