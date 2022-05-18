// CPP_HW_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Task 2
enum GameSymbols : char {
    X = 'X',
    O = 'O'
};

// Task4
struct GameField {
    int x;
    int y;
    GameSymbols symbol;
};

//Task 5
union MyVariant {
    int int_val;
    float float_val;
    char char_val;
};

int main()
{
    // Task 1
    short short_16 = 0;
    int int_32 = 0;
    long long long_64 = 0;
    char char_8 = 'a';
    bool bool_8 = 0;
    float float_32 = 1.0f;
    double double_64 = 1.0;

    //Task 3
    GameSymbols gameSymblos[9];

    //Task 5

    MyVariant variant;
    bool is_int = false, is_float = false, is_char = false;

    variant.int_val = 10;
    is_int = true;

    std::cout << "int val (stored): " << variant.int_val << std::endl;
    std::cout << "float val: " << variant.float_val << std::endl;
    std::cout << "char val: " << variant.char_val << std::endl;

    variant.float_val = 11.0f;
    is_int = false;
    is_float = true;

    std::cout << "int val: " << variant.int_val << std::endl;
    std::cout << "float val (stored): " << variant.float_val << std::endl;
    std::cout << "char val: " << variant.char_val << std::endl << std::endl;

    variant.char_val = 'G';
    is_char = true;
    is_float = false;

    std::cout << "int val: " << variant.int_val << std::endl;
    std::cout << "float val: " << variant.float_val << std::endl;
    std::cout << "char val (stored): " << variant.char_val << std::endl;
}
