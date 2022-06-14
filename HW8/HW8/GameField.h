#pragma once

#include <vector>

enum class Symbol : char {
	X = 'X',
	O = 'O',
	None = '_',
};

class GameField {
	private:
		std::vector<Symbol> _field;
		int _size;
		int _filled_cells_coutn = 0;
		Symbol _winner;
		bool find_winner();
		std::vector<std::vector<int>> _defaultChecks = std::vector<std::vector<int>>
		{
			std::vector<int>{0,4,8},
			std::vector<int>{2,4,6},
			std::vector<int>{0,1,2},
			std::vector<int>{3,4,5},
			std::vector<int>{6,7,8},
			std::vector<int>{0,3,6},
			std::vector<int>{1,4,7},
			std::vector<int>{2,5,8},
		};

		std::vector<int> _freeCells;

	public:
		GameField();
		void render();
		bool is_valid();
		int get_size();
		Symbol get_winner();
		bool set_symb(int coord, Symbol s);
		std::vector<int> GetFreeCells();
};
