// HW8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include "GameField.h"

void runGame();
int getUserInput(int size);
int getAIInput(int size);

static int turn;

int main()
{
    runGame();
}

void runGame() 
{
    auto gameField = GameField();
    gameField.render();

    while (gameField.is_valid()) {

        if (turn % 2 == 0)
        {
            auto coord = getUserInput(gameField.get_size());
            while (!gameField.set_symb(coord, Symbol::X)) {
                std::cout << "Wrong input, please, try again" << "\n";
                auto coord = getUserInput(gameField.get_size());
            }
        }
        else
        {
            gameField.set_symb(gameField.GetFreeCells()[0], Symbol::O);
        }

        turn++;
        gameField.render();
    }

    auto winner = gameField.get_winner();
    switch (winner) 
    {
        case Symbol::None:
            std::cout << "Draw";
            break;
        case Symbol::X:
            std::cout << "Player won!";
            break;
        case Symbol::O:
            std::cout << "AI won!";
            break;
    }
}

int getUserInput(int size) 
{
    auto coord = -1;
    while (coord < 0 || coord >= size * size) {
        coord = -1;
        int row = -1, col = -1;
        std::cout << "Choose row from " << 0 << " to " << size - 1 << "\n";
        std::cin >> row;
        std::cout << "Choose column from " << 0 << " to " << size - 1 << "\n";
        std::cin >> col;
        coord = row * size + col;
    }

    return coord;
}
