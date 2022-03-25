/**
 * @file singly_linked_list.hpp
 * @author Eric Kapilik (erickapilik@gmail.com)
 * @brief Implement a singly linked list.
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LINKED_LIST_SINGLY_LINKED_LIST_HPP_
#define LINKED_LIST_SINGLY_LINKED_LIST_HPP_

#include <ostream>
#include "linked_list/node.hpp"


namespace linked_list
{
class SinglyLinkedList
{
public:
  SinglyLinkedList();
//  ~singly_linked_list();
  void push_back(int data);
  Node* front() const;
private:
  Node* head_;
  Node* current_;
};

std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& sll)
{
  os << "[";
  Node* current = sll.front();
  while (current != NULL){
    os << current->get_data() << " ";
    current = current->get_next();
  }
  os << "]";
  return os;
}

}  // linked_list
#endif  // LINKED_LIST_SINGLY_LINKED_LIST_HPP_
