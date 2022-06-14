#include <iostream>
#include <string>
#include <fstream>

namespace homework
{
    #define TASK2_IN_RANGE(val, maxBound) (val >= 0 && val < maxBound);
    #define TASK3_ARR_SIZE 10;
    #define TASK3_SWAP(a,b) { \
        *a = *a + *b; \
        *b = *a - *b; \
        *a = *a - *b; \
    };

    void task2()
    {
        std::cout << "Task2" << std::endl;
        int val = 10;
        bool ans2 = TASK2_IN_RANGE(val, 9);
        std::cout << (ans2 ? "True" : "False") << "\n";
    }

    void task3_buble_sort(int* arr, int size) {
        for (int j = 0; j < size; j++) {
            for (int i = 1; i < size; i++) {
                if (*(arr + i - 1) > *(arr + i)) {
                    TASK3_SWAP((arr + i - 1), (arr + i))
                    i--;
                }
            }
        }
    }

    void task3_display_arr(int* arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << *(arr + i) << " ";
        }
        std::cout << "\n";
    }

    void task3() {
        std::cout << "Task3" << std::endl;
        int size = TASK3_ARR_SIZE;
        int* arr = new int[size];

        for (int i = 0; i < size; i++) {
            std::cout << "Enter an element #" 
                << (i + 1) 
                << "(" 
                << "of " 
                << size 
                << ")\n";
            std::cin >> *(arr + i);
        }

        task3_display_arr(arr, size);
        task3_buble_sort(arr, size);
        task3_display_arr(arr, size);
    }

    #pragma pack(push, 1)
    struct employee {
        int age;
        float salary;
        std::string name;
        char category;
    };
    #pragma pack(pop)


    void task4() {
        employee* empl = new employee{24, 250000, "Mishanya Torpeda", 'A'};
        std::cout << "Byte alignment structure takes " << sizeof(*empl) << " bytes in memory";
        std::ofstream fs1("employee.txt");
        fs1 << "Age: " << empl->age << "\n"
            << "Salary: " << empl->salary << "\n"
            << "Name: " << empl->name << "\n"
            << "Category: " << empl->name << "\n";
        fs1.close();
    }
}