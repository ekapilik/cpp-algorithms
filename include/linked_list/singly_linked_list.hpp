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
  void push_back(int data);
  void push_back(Node* node);
  void push_front(int data);
  void push_front(Node* node);
  Node* pop_back();
  Node* pop_front();
  Node* front() const;
  bool empty() const;
  int size() const;
  void clear();
  void sort();
private:
  void split(SinglyLinkedList& list_a, SinglyLinkedList& list_b);
  void merge_sort(SinglyLinkedList& list);
  void sorted_merge();
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

}  // namespace linked_list
#endif  // LINKED_LIST_SINGLY_LINKED_LIST_HPP_
