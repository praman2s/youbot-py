

#include "YouBotBase.hpp"
#include "YouBotManipulator.hpp"
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

namespace YOUBOTPYTHON{
using namespace boost::python;

template <typename T>
inline std::vector<T> ExtractArray(const object& o)
{
    std::vector<T> v(len(o));
    for(size_t i = 0; i < v.size(); ++i) {
        v[i] = extract<T>(o[i]);
    }
    return v;
}
class Robot {



private :
	
	
      
public:
	Robot();
	bool startcalib();
	bool SetArmJointValues(const object& o);
	object GetArmJointValues();
	object stdVecToNumpyArray( std::vector<double> const& vec )
	{
      		npy_intp size = vec.size();
		// const_cast is rather horrible but we need a writable pointer
      		double * data = size ? const_cast<double *>(&vec[0]) : static_cast<double *>(NULL);
    		// create a PyObject * from pointer and data 
      		PyObject * pyObj = PyArray_SimpleNewFromData( 1, &size, NPY_DOUBLE, data );
      		boost::python::handle<> handle( pyObj );
      		boost::python::numeric::array arr( handle );

   		 /* The problem of returning arr is twofold: firstly the user can modify
      		the data which will betray the const-correctness 
      		Secondly the lifetime of the data is managed by the C++ API and not the lifetime
      		of the numpy array whatsoever. But we have a simply solution..
     		*/
		return arr.copy(); // copy the object. numpy owns the copy now.
  	};
	bool SetBaseVelocity(const object& o);
	unsigned int nrofJoints;
	static bool instanceFlag;     // Instance Flag to check if the hardware was setup atleast once
	static Robot *single;
	static Robot* getInstance();  
	youbot::YouBotManipulator *youBotArm;  
	youbot::YouBotBase *youBotBase;       
	virtual ~Robot();
};

} /* namespace YOUBOTPYTHON */

