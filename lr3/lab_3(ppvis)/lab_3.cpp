#include "starter.h"
#include <time.h>

using namespace ocean;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	Starter::start("ocean2.txt", 10);

	return 0;
}