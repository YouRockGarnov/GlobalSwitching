#include "headers\stdOperators.h"
#include "headers\StackMemoryManager.h"
#include <iostream>

using namespace std;

int main()
{
	int* intptr = new int(100);

	std::cout << *intptr;

	/*GlobalSwitcher::get_switcher().pushManager(new StackMemoryManager());

	int* lol = new int(500);
	std::cout << *intptr;*/

	system("pause");

	return 0;
}
