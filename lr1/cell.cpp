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

Cell::Cell() {
	this->value = 0;
}

Cell::Cell(const Cell &other) {
	this->value = other.value;
}

Cell::~Cell() {
	//деструкор :)
}

int Cell::get_value() {
	return this->value;
}


void Cell::set_value(int val) {
	if (!this->is_empty()) {
		return;
	}
	this->value = val;
}

bool Cell::is_empty() { //if cell is empty - 1, else - 0 
	if (this->get_value() == 0) {
		return 1;
	}
	return 0;
}

Cell& Cell::operator=(const Cell& other) {
	this->value = other.value;
	return *this;
}

Cell& Cell::operator++() {
	this->value++;
	return *this;
}

Cell& Cell::operator++(int value) {
	Cell temp(*this);
	this->value++;
	return temp;
}

Cell& Cell::operator--() {
	this->value--;
	return *this;
}

Cell& Cell::operator--(int value) {
	Cell temp(*this);
	this->value--;
	return temp;
}

bool Cell::operator==(const Cell& other) {
	return this->value == other.value;
}

bool Cell::operator!=(const Cell& other) {
	return this->value != other.value;
}

bool Cell::operator<(const Cell& other)
{
	return this->value < other.value;
}

bool Cell::operator>(const Cell& other)
{
	return this->value > other.value;
}

bool Cell::operator<=(const Cell& other)
{
	return this->value <= other.value;
}

bool Cell::operator>=(const Cell& other)
{
	return this->value >= other.value;
}

Cell Cell::operator+(const Cell& other)
{
	Cell temp;
	temp.value = this->value + other.value;
	return temp;
}

Cell Cell::operator-(const Cell& other)
{
	Cell temp;
	temp.value = this->value - other.value;
	return temp;
}

Cell Cell::operator*(const Cell& other)
{
	Cell temp;
	temp.value = this->value * other.value;
	return temp;
}

Cell Cell::operator/(const Cell& other)
{
	Cell temp;
	temp.value = this->value / other.value;
	return temp;
}

Cell& Cell::operator+=(const Cell& other) {
	this->value += other.value;
	return *this;
}

Cell& Cell::operator-=(const Cell& other) {
	this->value -= other.value;
	return *this;
}

Cell& Cell::operator*=(const Cell& other) {
	this->value *= other.value;
	return *this;
}

Cell& Cell::operator/=(const Cell& other) {
	this->value /= other.value;
	return *this;
}

ostream& operator << (ostream& out, Cell& cell) {
	out << cell.get_value();
	return out;
}