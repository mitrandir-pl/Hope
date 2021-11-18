#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <conio.h>
#include "cell.h"


using namespace std;

class Game
{
private:
	vector< vector<Cell> > field;
	int size = 3;
	int player_number = 1;
	pair<int, int> cur_pos = {0, 0};
	int win_number;
	int symb_number = 0;
public:
	Game();
	vector<Cell> operator [] (int);
	int get_player_number();
	void set_win_num(int);
	bool is_empty(int, int);
	void show();
	void show_matrix();
	void cur_pos_out(int);
	void move();
	char get_diraction();
	int win_check();
	void start_game();
	void end_game(int);
	void error_sound();
};

