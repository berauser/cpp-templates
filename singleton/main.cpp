
#include "Singleton.h"
#include "SomeClass.h"

void printSingleton();

int main()
{
	// ------------- singleton is created before main ----------
	std::cout << __PRETTY_FUNCTION__ << std::endl;

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
	}

	// Fourth singleton object
	Singleton<SomeClass> singleton;
	singleton->printCounter();
	singleton->printThis();

	std::cout << __PRETTY_FUNCTION__ << std::endl;
	// ------------- singleton is deleted after main -----------
	return 0;
}

void printSingleton()
{
	Singleton<SomeClass> singleton;
	singleton->printCounter();
	singleton->printThis();
}
