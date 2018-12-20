
#include "Registry.h"

#include <iostream>

static void my_func(const std::string& string)
{
	std::cout << __PRETTY_FUNCTION__ << " --> " << string << std::endl;
}

static void other_func(const std::string& string)
{
	std::cout << __PRETTY_FUNCTION__ << " --> " << string << std::endl;
}

int main()
{
	/**
	 * create registry with:
	 * Key:  std::string
	 * Func: void(const std::string&)
	 */
	Registry<std::string, void(const std::string&)> s_registry;

	/* register some functions */
	s_registry.registerFunction("my_func", &my_func);
	s_registry.registerFunction("other_func", &other_func);

	/* call function */
	s_registry["my_func"]("TEST(my_func)");
	s_registry["other_func"]("TEST(other_func)");

	/* check if 'my_func' is registered */
	if (s_registry.isRegistered("my_func"))
	{
		std::cout << "my_func is registered" << std::endl;
	}

	/* try to create an instance of an unknown function ('unknown') */
	try
	{
		s_registry["unknown_func"]("SHOULD FAIL");
	}
	catch (const UndefinedKeyException<std::string>& e)
	{
		std::cout << "Exception: " << e.what() << ": '" << e.key() << "'" << std::endl;
	}

	/* clear registry */
	s_registry.clear();

	return 0;
}
