#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "game.h"
#include <Windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

Game::Game() {
	this->size = 3;
	this->win_number = 3;
}

vector<Cell> Game::operator [] (int index) {
	return this->field[index];
}

void Game::cur_pos_out(int colour) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(colour));
	int code;
	if (this->player_number == 1){
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
	int win_check_res = this->win_check();
	if (win_check_res != 0) {
		this->end_game(win_check_res);
	}
	for (int i = 0; i < this->field.size(); i++) {
		for (int j = 0; j < this->field[i].size(); j++) {
			if (i == this->cur_pos.first && j == this->cur_pos.second) {
				if (!this->field[this->cur_pos.first][this->cur_pos.second].is_empty()) {
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
			if (this->field[i][j].get_value() == 0) {
				code = 250;
			}
			else if(this->field[i][j].get_value() == 1){
				code = 120;
			}
			else if (this->field[i][j].get_value() == 2) {
				code = 111;
			}
			cout << (char)code;
		}
		cout << endl;
	}
	cout << endl;
}

void Game::move() {
	switch (this->get_diraction()) //добавить звук, когда выходит за границы поля
	{
	case 'w':	//up
		if (this->cur_pos.first == 0) {
			break;
		}
		this->cur_pos.first -= 1;
		break;
	case 'a':	//left
		if (this->cur_pos.second == 0) {
			break;
		}
		this->cur_pos.second -= 1;
		break;
	case 's':	//down
		if (this->cur_pos.first == this->size - 1) {
			break;
		}
		this->cur_pos.first += 1;
		break;
	case 'd':	//right
		if (this->cur_pos.second == this->size - 1) {
			break;
		}
		this->cur_pos.second += 1;
		break;	
	case 13:
		if (this->field[this->cur_pos.first][this->cur_pos.second].is_empty()) {
			this->field[cur_pos.first][cur_pos.second].set_value(this->player_number);
			this->symb_number++;
			int win_check_res = this->win_check();
			if (win_check_res != 0) {
				this->end_game(win_check_res);
			}
			this->player_number ^= 3;
		}
	}
}

char Game::get_diraction() {
	char dir;
	dir = _getch();
	return dir;
}
	
int Game::win_check() {
	int n = this->size;
	int i = 0, j = 0; // первая диагональ
	i = this->cur_pos.first - min(this->cur_pos.first, this->cur_pos.second);
	j = this->cur_pos.second - min(this->cur_pos.first, this->cur_pos.second);
	int num = 0;
	while (i != n && j != n) {	
		if (this->field[i][j].get_value() != this->player_number) {
			num = 0;
		}
		else {
			num++;
			if (num == this->win_number) {
				return 1;
			}
		}
		i++;
		j++;
	}
	// вторая диагональ
	i = cur_pos.first - min(this->size - this->cur_pos.second - 1, this->cur_pos.first);
	j = this->cur_pos.second + min(this->size - this->cur_pos.second - 1, this->cur_pos.first);
	num = 0;
	while (i != n && j != -1) {
		if (this->field[i][j].get_value() != this->player_number) {
			num = 0;
		}
		else {
			num++;
			if (num == this->win_number) {
				return 1;
			}
		}
		i++;
		j--;
	}
	i = 0; // вертикаль
	j = this->cur_pos.second;
	num = 0;
	while (i != n) {
		if (this->field[i][j].get_value() != this->player_number) {
			num = 0;
		}
		else {
			num++;
			if (num == this->win_number) {
				return 1;
			}
		}
		i++;
	}
	i = this->cur_pos.first; // горизонталь
	j = 0;
	num = 0;
	while (j != n) {
		if (this->field[i][j].get_value() != this->player_number) {
			num = 0;
		}
		else {
			num++;
			if (num == this->win_number) {
				return 1;
			}
		}
		j++;
	}
	if(this->symb_number == this->size * this->size)
		return 2;
	return 0;
}

int Game::get_player_number() {
	return this->player_number;
}

void Game::set_win_num(int val) {
	this->win_number = val;
}

void Game::start_game() {
	system("cls");
	int n, num;
	cout << "Enter field size: ";
	cin >> n;
	cout << "Enter the length of the line required to win: ";
	cin >> num;
	this->win_number = num;
	this->size = n;
	this->field.resize(this->size);
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->field[i].push_back(*(new Cell()));
		}
	}
	cout << field[0][1].get_value() << endl;
	while (1) {
		this->show();
		this->move();
	}
}

void Game::end_game(int fl) {
	if (fl == 1) {
		cout << "Player #" << player_number << " won." << endl;
	} 
	else {
		cout << "Draw." << endl;
	}
	cout << "1. Start new game." << endl
		<< "2. Exit game." << endl;
	char f = _getch();
	if (f == 1) {
		this->start_game();
	}
	else {
		cout << "See you again soon" << endl;
		exit(0);
	}
}