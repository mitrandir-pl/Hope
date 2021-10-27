#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "game.h"
#include <Windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

Game::Game(int n) {
	this->size = n;
	this->field.resize(this->size);
	for (int i = 0; i < this->size; i++) {
		this->field[i].resize(this->size, 0);
	}
}