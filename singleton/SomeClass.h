
#include <iostream>

class SomeClass
{
public:
	SomeClass()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		counter++;
	}
	
	~SomeClass()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		counter--;
	}
	
	void printCounter()
	{
		std::cout << "counter: " << counter << std::endl;
	}
	
	void printThis()
	{
		std::cout << "this: " << this << std::endl;
	}
private:
	static int counter;
};
int SomeClass::counter = 0;