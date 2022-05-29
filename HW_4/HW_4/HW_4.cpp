#include <iostream>
#include <string.h>
#include <cmath>

void task1();
void task2();
void task3(int upperBound);
void task4(int val);
void task5(int val);

const int const_a = 1;
const int const_b = 9;

int main()
{
    task1();
    task2();
    task3(50);
    task4(3559);
    task5(1600);
}

void task1() {
    int a, b;

    std::cin >> a >> b;

    std::string str = a + b >= 20
        ? "true"
        : "false";

    std::cout << str << std::endl;;
}

void task2() {
    if ((const_a == 10 && const_a == const_b) || const_a + const_b == 10) 
    {
        std::cout << "true" << std::endl;
    }
    else 
    {
        std::cout << "false" << std::endl;

    }

}

void task3(int upperBound) {
    if (upperBound < 2) 
    {
        std::cout << "task3 failed coz [upperBound] " 
            << upperBound 
            << " less than 2";
    }

    for (int i = 0; i <= upperBound; i++) 
    {
        if (i % 2 == 1) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}

void task4(int val) {

    bool isPrime = true;
    for (int i = 2; i < std::abs(val / 2); i++) 
    {
        if (val % i == 0) 
        {
            isPrime = false;
            break;
        }
    }

    std::cout << val 
        << " is " 
        << (isPrime ? "prime" : "not prime")
        << std::endl;
}

void task5(int val) {
    if (val < 1 || val > 3000)
    {
        std::cout << "task5 failed, year must be between 1 and 3000";
    }

    if (val % 400 == 0 || (val % 4 == 0 && val % 100 != 0)) 
    {
       std:: cout << "leap year";
    }
    else {
        std::cout << "not leap year";
    }

    std::cout << std::endl;
}
