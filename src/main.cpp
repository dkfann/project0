#include <iostream>
#include "ArrayList.hpp"

int main()
{
    ArrayList array_list;
    array_list.push_back("A")
              .push_back("B")
              .push_back("C");
    for (int i = 0; i < array_list.size(); i++)
    {
        std::cout << array_list.at(i) << std::endl;
    }


    return 0;
}

