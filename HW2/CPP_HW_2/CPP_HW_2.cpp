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
union InvariantVal {
    int int_val;
    float float_val;
    char char_val;
};


#define integer 1;
#define character 2;
#define floating 4;
struct InvariantValue {
private:
    InvariantVal value;
    unsigned char type;
public:
    void set_int(int val) {
        value.int_val = val;
        type = integer;
    }

    void set_float(float val) {
        value.float_val = val;
        type = floating;
    }

    void set_char(char val) {
        value.char_val = val;
        type = character;
    }

    char get_char() {
        return value.char_val;
    }

    int get_int() {
        return value.int_val;
    }

    float get_float() {
        return value.float_val;
    }

    int get_type() {
        return (int)type;
    }
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

    InvariantValue variant;

    variant.set_int(10);

    std::cout << "int val: " << variant.get_int() << std::endl;
    std::cout << "float val: " << variant.get_float() << std::endl;
    std::cout << "char val: " << variant.get_char() << std::endl;
    std::cout << "flag: " << variant.get_type() << std::endl << std::endl;

    variant.set_float(11.0f);

    std::cout << "int val: " << variant.get_int() << std::endl;
    std::cout << "float val: " << variant.get_float() << std::endl;
    std::cout << "char val: " << variant.get_char() << std::endl;
    std::cout << "flag: " << variant.get_type() << std::endl << std::endl;

    variant.set_char('G');

    std::cout << "int val: " << variant.get_int() << std::endl;
    std::cout << "float val: " << variant.get_float() << std::endl;
    std::cout << "char val: " << variant.get_char() << std::endl;
    std::cout << "flag: " << variant.get_type() << std::endl << std::endl;
}
