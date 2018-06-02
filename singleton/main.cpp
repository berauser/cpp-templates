
#include "Singleton.h"
#include "SomeClass.h"

void printSingleton();

int main()
{
	// First singleton object
	Singleton<SomeClass> singleton;
	singleton->printCounter();
	singleton->printThis();
	
	
	{
		// Second singleton object;
		Singleton<SomeClass> s;
		s->printCounter();
		s->printThis();
	}
	
	// Third singleton object
	printSingleton();
	
	return 0;
}

void printSingleton()
{
	Singleton<SomeClass> singleton;
	singleton->printCounter();
	singleton->printThis();
}
