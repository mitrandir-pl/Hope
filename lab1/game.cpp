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

void Game::cur_pos_out(int colour) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(colour));
	int code;
	if (this->player_num == 1) {
		code = 120;
	}
	else {
		code = 111;
	}
	cout << (char)code;
	SetConsoleTextAttribute(hStdOut, (WORD)(15));
}


void Game::show_matrix() {
	for (int i = 0; i < this->field.size(); i++) {
		for (auto j = 0; j < this->field[i].size(); j++) {
			cout << this->field[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Game::show() {
	system("cls");
	for (int i = 0; i < this->field.size(); i++) {
		for (auto j = 0; j < this->field[i].size(); j++) {
			if (i == this->cur_pos.first && j == this->cur_pos.second) {
				if (!this->is_empty(this->cur_pos.first, this->cur_pos.second)) {
					cur_pos_out(12);
				}
				else {
					cur_pos_out(10);
				}
				//			if (j == (this->size - 1)) {
				//				cout << endl;
				//			}
				continue;
			}
			int code;
			switch (this->field[i][j]) {
			case 0:
				code = 250;
				break;
			case 1:
				code = 120;
				break;
			case 2:
				code = 111;
				break;
			}
			cout << (char)code;
		}
		cout << endl;
	}
	cout << endl;
}

