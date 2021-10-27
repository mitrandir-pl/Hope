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
bool Game::set() {
	if (!is_empty(this->cur_pos.first, this->cur_pos.second)) {
		return 0;
	}
	field[this->cur_pos.first][this->cur_pos.second] = this->player_num;
	this->player_num = this->player_num ^ 3;
}
int Game::get(int x, int y) {
	if (x >= this->size || y >= this->size) {
		return -1;
	}
	return field[x][y];
}
bool Game::is_empty(int x, int y) { //if cell is empty - 1, else - 0
	if (get(x, y) == 0) {
		return 1;
	}
	return 0;
}