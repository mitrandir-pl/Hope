#include <iostream>
#include <vector>
#include "game.h"
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <conio.h>


int main()
{
	int n;
	cin >> n;
	Game newGame(n);
	while (1) {
		newGame.show();
		newGame.get_diraction();
	}
}

