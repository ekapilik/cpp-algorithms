/**
 * @file SinglyLinkedList.cpp
 * @author Eric Kapilik (erickapilik@gmail.com)
 * @brief Implement a singly linked list.
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstddef>
#include "linked_list/singly_linked_list.hpp"

namespace linked_list
{
SinglyLinkedList::SinglyLinkedList()
{
  head_ = NULL;
  current_ = NULL;
}

/*
SinglyLinkedList::~SinglyLinkedList()
{
  current_ = head_;
  Node* next = current_.get_next();
  while(current_ != NULL){

  }
}
*/

void SinglyLinkedList::push_back(int data)
{
  Node* new_node = new Node();
  new_node->set_data(data);

  if(head_ == NULL){  // head is empty
    head_ = new_node;
    return;
  }
  current_ = head_;
  while(current_->get_next() != NULL){
    current_ = current_->get_next();  // traverse linked list
  }
  current_->set_next(new_node);
}

Node* SinglyLinkedList::front() const
{
  return head_;
}
}
