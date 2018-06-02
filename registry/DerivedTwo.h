
#ifndef _SRC_DERIVEDTWO_H_
#define _SRC_DERIVEDTWO_H_

#include "Base.h"

class DerivedTwo : public Base
{
public:
	DerivedTwo() : Base()
	{
		std::cout << "DerivedTwo::DerivedTwo()" << std::endl;
	}

	DerivedTwo(int var_arg) : Base(var_arg)
	{
		std::cout << "DerivedTwo::DerivedTwo(" << _var << ")" << std::endl;
	}

	virtual ~DerivedTwo()
	{
	}

	virtual void print(int i)
	{
		std::cout << "DerivedTwo(" << _var << ") : " << i << std::endl;
	}
};

#endif /* _SRC_DERIVEDTWO_H_ */
