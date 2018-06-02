
#include "Registry.h"

#include "Base.h"
#include "DerivedOne.h"
#include "DerivedTwo.h"

int main()
{
	/**
	 * create registry with:
	 * Base: Base
	 * Key:  std::string
	 * Args: int
	 */
	Registry<Base, std::string, int> s_registry;

	/* register some classes */
	s_registry.registerClass<DerivedOne>("DerivedOne");
	s_registry.registerClass<DerivedTwo>("DerivedTwo");

	/* create an instance of 'DerivedOne' */
	std::shared_ptr<Base> s_derivedOne = s_registry.get("DerivedOne", 100);
	s_derivedOne->print(1);

	/* check if 'DerivedTwo' is registered */
	if (s_registry.isRegisteredClass("DerivedTwo"))
	{
		std::cout << "DerivedTwo is registered" << std::endl;
	}

	/* try to create an instance of an unknown class ('DerivedThree') */
	try
	{
		std::shared_ptr<Base> s_derivedThree = s_registry.get("DerivedThree", 200);
	}
	catch (const UndefinedKeyException<std::string>& e)
	{
		std::cout << "Exception: " << e.what() << ": '" << e.key() << "'" << std::endl;
	}

	/* clear registry */
	s_registry.clear();

	/*********************** another example *******************************
	 * crate another registry with:
	 * Base: Base
	 * Key:  unsigned int
	 * Args: - no arguments -
	 */
	Registry<Base, unsigned int> i_registry;

	/* register some classes */
	i_registry.registerClass<DerivedOne>(1);
	i_registry.registerClass<DerivedTwo>(2);

	/* create an instance of 'DerivedOne' */
	std::shared_ptr<Base> i_derivedTwo = i_registry.get(2);
	i_derivedTwo->print(2);

	/* unregister both */
	i_registry.unregisterClass(1);
	i_registry.unregisterClass(2);

	return 0;
}
