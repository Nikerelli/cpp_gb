#include "GameField.h"
#include <iostream>
#include <string.h>
#include <vector>

std::string as_string(Symbol c) {
	switch (c)
	{
	case Symbol::X:
		return "X";
	case Symbol::O:
		return "O";
	case Symbol::None:
		return "_";
	default:
		break;
	}
}

GameField::GameField() 
{
	_size = 3;
	_field = std::vector<Symbol>();
	_freeCells = std::vector<int>();
	for (auto i = 0; i < _size * _size; i++) 
	{
		_field.push_back(Symbol::None);
		_freeCells.push_back(i);
	}
}

int GameField::get_size() {
	return _size;
}

bool GameField::set_symb(int coord, Symbol s) {
	if (coord < 0 || coord > _size * _size) {
		return false;
	}

	if (_field[coord] != Symbol::None) {
		return false;
	}

	_field[coord] = s;
	auto iterator = remove(_freeCells.begin(), _freeCells.end(), coord);
	_freeCells.erase(iterator, _freeCells.end());
	_filled_cells_coutn++;
	return true;
}

std::vector<int> GameField::GetFreeCells()
{
	return _freeCells;
}


void GameField::render() {
	std::cout << "\n";
	for (int i = 0; i < _size; i++)
	{
		std::cout << "|";
		for (int j = 0; j < _size; j++)
		{
			std::cout << " " << as_string(_field[i * _size + j]) << " |";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

bool GameField::is_valid()
{
	if (_filled_cells_coutn == _size * _size) 
	{
		_winner = Symbol::None;
		return false;
	}

	return !find_winner();
}

Symbol GameField::get_winner() {
	return _winner;
}

bool GameField::find_winner() {
	for (auto check : _defaultChecks) {
		if (_field[check[0]] == _field[check[1]] && _field[check[2]] == _field[check[1]] && _field[check[2]] != Symbol::None) {
			_winner = _field[check[0]];
			return true;
		}
	}

	return false;
}