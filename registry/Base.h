
#ifndef _SRC_BASE_H_
#define _SRC_BASE_H_

#include <iostream>

class Base
{
public:
	Base() : _var(-1)
	{
		std::cout << "Base::Base()" << std::endl;
	}

	Base(int var_arg) : _var(var_arg)
	{
		std::cout << "Base::Base(" << _var << ")" << std::endl;
	}

	virtual ~Base()
	{
	}

	virtual void print(int i)
	{
		std::cout << "Base(" << _var << ") : " << i << std::endl;
	}

protected:
	int _var;
};

#endif /* _SRC_BASE_H_ */
