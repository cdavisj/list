#include <iostream>

#include "List.h"

int main()
{
    List<int> list;

    for (int i = 1; i <= 10; i++)
    {
        list.push_back(i);
    }

    std::cout << "\nInitial list..\n";
    list.print();

    std::cout << "\nPushing 10 to front..\n";
    list.push_front(10);
    list.print();

    std::cout << "\nPushing 10 to back..\n";
    list.push_back(10);
    list.print();

    std::cout << "\nResizing down to half-sized..\n";
    list.resize(list.size() / 2);
    list.print();

    std::cout << "\nResizing up to 20 with 7's..\n";
    list.resize(20, 7);
    list.print();

    std::cout << "\nReversing..\n";
    list.reverse();
    list.print();


    std::cin.get();
    return 0;
}