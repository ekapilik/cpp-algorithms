/**
 * @file singly_linked_list.cpp
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

void SinglyLinkedList::push_back(int data)
{
  Node* new_node = new Node(data);
  push_back(new_node);
}

void SinglyLinkedList::push_back(Node* node)
{
  if (head_ == NULL){  // head is empty
    head_ = node;
    return;
  }
  current_ = head_;
  while (current_->get_next() != NULL){
    current_ = current_->get_next();  // traverse linked list
  }
  current_->set_next(node);
}

void SinglyLinkedList::push_front(int data)
{
  Node* new_node = new Node(data);
  push_front(new_node);
}

void SinglyLinkedList::push_front(Node* node)
{
  current_ = head_;
  node->set_next(head_);
  head_ = node;
}

Node* SinglyLinkedList::pop_back()
{
  if (head_ == nullptr){
    return nullptr;
  } else if (head_->get_next() == nullptr) {
    Node* temp = head_;
    head_ = nullptr;
    return temp;
  }

  current_ = head_;
  Node* previous = current_;
  while (current_->get_next() != nullptr){
    previous = current_;
    current_ = current_->get_next();  // traverse linked list
  }
  previous->set_next(nullptr);
  return current_;
}

Node* SinglyLinkedList::pop_front()
{
  current_ = head_;
  if (current_ == nullptr){
    return nullptr;
  }
  head_ = current_->get_next();
  return current_;
}

Node* SinglyLinkedList::front() const
{
  return head_;
}

bool SinglyLinkedList::empty() const
{
  return head_ == nullptr;
}

int SinglyLinkedList::size() const
{
  Node* current = head_;
  int count = 0;
  while (current != nullptr){
    ++count;
    current = current->get_next();
  }
  return count;
}

void SinglyLinkedList::clear()
{
  current_ = head_;
  Node* previous_ = current_;
  while (current_ != nullptr){
    previous_ = current_;
    current_ = current_->get_next();
    delete(previous_);
  }
  head_ = nullptr;
}

void SinglyLinkedList::sort()
{

}


//void split(SinglyLinkedList& list_a, SinglyLinkedList& list_b)
//{
//  list_a.clear();
//  list_b.clear();
//  Node* slow = head_;
//  Node* fast = head_->get_next();
//
//  while (fast != nullptr){
//    fast = fast->get_next();
//    if (fast != nullptr){
//      slow = slow->get_next();
//      fast = fast->get_next();
//    }
//  }
//
//  list_a
//}
}  // namespace linked_list
