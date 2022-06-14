#include <iostream>
#include <cmath>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>  

void task1();

void task2();
int* task2_gen_arr(int size);
void task2_display_arr(int* arr, int size, int num = -1);

void task3();

void task4();

void task5();

int main()
{
    //task1();
    //task2();
    //task3();
    //task4();
    task5();
}

void task1() 
{
    std::cout << "Task1" << std::endl;
    std::cout << "Enter power of 2" << std::endl;
    int power = 0;
    std::cin >> power;
    if (power < 0) 
    {
        std::cout << "Only positive values are available" << std::endl;
        return;
    }

    power++;
    int* arr = new int[power];

    for (int i = 0; i < power; i++) 
    {
        *(arr + i) = pow(2, i);
        std::cout << *(arr + i) << " ";
    }
    
    delete[] arr;
    std::cout << std::endl;
}

void task2() {
    const int matrix_size = 4;
    std::cout << "Task1" << std::endl;
    int** arr = new int*[matrix_size];

    for (int i = 0; i < matrix_size; i++)
    {
        *(arr + i) = task2_gen_arr(matrix_size);
        task2_display_arr(*(arr + i), matrix_size, i);
    }


    for (int i = 0; i < matrix_size; i++) 
    {
        delete[] *(arr + i);
    }

    delete[] arr;
}

int* task2_gen_arr(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++) 
    {
        *(arr + i) = rand();
    }

    return arr;
}

void task2_display_arr(int* arr, int size, int num) 
{
    if (num > -1) 
    {
        std::cout << "arr #" << num << std::endl;
    }
    else 
    {
        std::cout << std::endl;
    }

    for (int i = 0; i < size; i++) {
        
        std::cout << *(arr + i) << " ";
    }

    std::cout << std::endl;
}


void task3() {
    std::cout << "Task 3" << std::endl;
    const std::string default_text = "Hello CPP fellas!";
    std::string file1, file2;

    std::cout << "Enter name for file1" << std::endl;
    std::cin >> file1;

    std::cout << "Enter name for file2" << std::endl;
    std::cin >> file2;

    std::ofstream fs1(file1.c_str());
    if (!fs1.is_open()) {
        std::cout << "Couldn't open file " << file1;
        return;
    }

    fs1 << default_text << std::endl << file1;
    fs1.close();

    std::ofstream fs2(file2.c_str());
    if (!fs2.is_open()) {
        std::cout << "Couldn't open file " << file2;
        return;
    }
    fs2 << default_text << std::endl << file2;
    fs2.close();
}

void task4() {
    std::cout << "Task 4" 
        << std::endl;
    std::string target, appendix1, appendix2;

    std::cout << "Enter full path to appendix1 file" 
        << std::endl;
    std::cin >> appendix1;

    std::cout << "Enter full path to appendix2 file" 
        << std::endl;
    std::cin >> appendix2;

    std::cout << "Enter full path to target file"
        << std::endl;
    std::cin >> target;

    std::ofstream target_fs(target);
    if (target_fs.is_open()) 
    {
        std::ifstream appendix_fs1(appendix1);
        if (!appendix_fs1.is_open())
        {
            std::cout << "Failed to open file \"" 
                << appendix1 
                << "\"" 
                << std::endl;
            return;
        }

        std::ifstream appendix_fs2(appendix2);
        if (!appendix_fs2.is_open())
        {
            std::cout << "Failed to open file \"" 
                << appendix2 
                << "\"" 
                << std::endl;
            return;
        }

        std::string buff;
        while (appendix_fs1) {
            getline(appendix_fs1, buff);
            target_fs << buff << std::endl;
            buff = "";
        }

        appendix_fs1.close();

        while (appendix_fs2) {
            getline(appendix_fs2, buff);
            target_fs << buff << std::endl;
            buff = "";
        }

        appendix_fs1.close();

        target_fs << "Appendix1: " 
            << appendix1 
            << std::endl 
            << "Appendix2: "
            << appendix2;
    }
    else 
    {
        std::cout << "Failed to open file \"" << target << "\"" << std::endl;
    }

    target_fs.close();
}

void task5() {
    std::cout << "Task 4"
        << std::endl;
    std::string target, word;

    std::cout << "Enter full path to target file"
        << std::endl;
    std::cin >> target;

    std::cout << "Enter word to find"
        << std::endl;
    std::cin >> word;

    std::ifstream target_fs(target);
    if (target_fs.is_open())
    {
        int inner_ind = 0;
        char symb;
        while (target_fs) 
        {
            if (inner_ind == word.length() - 1) {
                break;
            }

            symb = target_fs.get();
            if (symb == word[inner_ind]) {
                inner_ind++;
            }
            else {
                inner_ind = 0;
            }
        }

        std::cout << (inner_ind == word.length() - 1
            ? "Exists"
            : "Not exists");
    }
    else 
    {
        std::cout << "Failed to open file \"" << target << "\"" << std::endl;
    }

    target_fs.close();
}