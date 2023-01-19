#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include "System.h"

using namespace std;
using namespace sf;

int main()
{
	srand(time(NULL));

	System sys;

	sys.Run();

	return 0;
}