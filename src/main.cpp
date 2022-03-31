/**
 * @file main.cpp
 * @author Eric Kapilik (erickapilik@gmail.com)
 * @brief The main program of entry for cpp-algorithms command line interface.
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

#include "linked_list/singly_linked_list.hpp"

int main(int argc, char * argv[]) {
    std::cout << "hello, world" << std::endl;

    linked_list::SinglyLinkedList sll;
    std::cout << sll << std::endl;
    for (int i = 0; i < 10; ++i){
        sll.push_back(i);
        std::cout << sll << std::endl;
    }
}
