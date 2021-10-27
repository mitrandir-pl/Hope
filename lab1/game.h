#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Game
{
private:
	vector< vector<int> > field; /*
		   *  0 - nothing
		   *  1 - cross
		   *  2 - zero
		   */
	int size;
	int player_num = 1;
	pair<int, int> cur_pos = {0, 0};

public:
	Game(int);
	bool set();
	int get(int, int);
	bool is_empty(int, int);
	void show();
	void show_matrix();
	void cur_pos_out(int);
	void move(char);
	void get_diraction();
};

