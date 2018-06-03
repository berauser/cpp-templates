
#include <iostream>
#include "Subject.h"

void print()
{
	std::cout << __FUNCTION__ << ": no payload" << std::endl;
}

void print_string(const std::string& s)
{
	std::cout << __FUNCTION__ << ": " << s << std::endl;
}

void pretty_print_string(const std::string& s)
{
	std::cout << __PRETTY_FUNCTION__ << ": " << s << std::endl;
}

int main()
{
	std::cout << std::endl
			  << "-------- Subject<int,void> ---------------------" << std::endl;
	/*
	 * Subject without return value and without params
	 * event type:   int
	 * return value: void
	 * params:       -
	 */
	Subject<int, void> subject1;

	// register callback function for event 1 and 2
	subject1.registerObserver(1, std::bind(&print));
	subject1.registerObserver(2, std::bind(&print_string, ""));
	// notify all callbacks for event 1 and 2
	subject1.notify(1);
	subject1.notify(2);

	std::cout << std::endl
			  << "-------- Subject<int, void, std::string> -------" << std::endl;
	/*
	 * Subject without return value and string as param
	 * event tyoe:   int
	 * return value: void
	 * params:       std::string
	 */
	Subject<int, void, std::string> subject2;

	// register callback function for event 1 and 2
	subject2.registerObserver(1, std::bind(&print_string, std::placeholders::_1));
	subject2.registerObserver(1, std::bind(&pretty_print_string, std::placeholders::_1));
	subject2.registerObserver(2, std::bind(&pretty_print_string, std::placeholders::_1));
	// notify all callbacks for event 1 and 2
	subject2.notify(1, "call event number 1");
	subject2.notify(2, "call event number 2");

	std::cout << std::endl
			  << "-------- Subject<std::string, void, std::string>" << std::endl;
	/*
	 * Subject without return value and string as param
	 * event tyoe:   int
	 * return value: void
	 * params:       std::string
	 */
	Subject<std::string, void, std::string> subject3;

	// register callback function for event 1 and 2
	subject3.registerObserver("On", std::bind(&print_string, std::placeholders::_1));
	subject3.registerObserver("On", std::bind(&pretty_print_string, std::placeholders::_1));
	subject3.registerObserver("Off", std::bind(&pretty_print_string, std::placeholders::_1));
	// notify all callbacks for event 1 and 2
	subject3.notify("On", "call on");
	subject3.notify("Off", "call off");

	// remove all keys
	subject3.unregisterAll("On");
	subject3.notify("On", "call nobody");

	return 0;
}
