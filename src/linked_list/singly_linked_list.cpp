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
#include <cassert>
#include <iostream>
#include "linked_list/singly_linked_list.hpp"

namespace linked_list
{
SinglyLinkedList::SinglyLinkedList()
{
  head_ = NULL;
  current_ = NULL;
}

SinglyLinkedList::SinglyLinkedList(Node* node)
{
  head_ = node;
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
  if (empty()){
    return nullptr;
  }
  current_ = head_;
  head_ = current_->get_next();
  current_->set_next(nullptr);
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

int SinglyLinkedList::at(const int index) const
{
  int count = 0;
  Node* current = head_;
  while (count < index && current != nullptr){
    current = current->get_next();
    ++count;
  }
  if (current == nullptr){
    return 0;
  }
  else{
    return current->get_data();
  }
}

void SinglyLinkedList::sort()
{
  if(head_ == nullptr){
    return;
  }

  Node* mid = get_middle_node();
  Node* head2 = mid->get_next();
  mid->set_next(nullptr);
}

void SinglyLinkedList::merge(SinglyLinkedList& other)
{
  if (head_ == other.front()){
    // do nothing, can't merge with self.
    return;
  }
  SinglyLinkedList dummy_list;

  Node* current = pop_front();
  Node* other_current = other.pop_front();
  while(current != nullptr && other_current != nullptr){
    if(current->get_data() <= other_current->get_data()){
      dummy_list.push_back(current);
      current = pop_front();
    } else{
      dummy_list.push_back(other_current);
      other_current = other.pop_front();
    }
  }
  while(current != nullptr){
    // other must be empty because the above while loop ended
    dummy_list.push_back(current);
    current = pop_front();
  }
  while(other_current){
    // this must be empty because the above while loop ended
    dummy_list.push_back(other_current);
    other_current = other.pop_front();
  }
  head_ = dummy_list.front();
}

Node* SinglyLinkedList::get_middle_node()
{
  if(head_ == nullptr){
    return head_;  // early exit, avoid segmentation fault
  }
  Node* slow = head_;
  Node* fast = head_->get_next();

  while (fast != nullptr){
    fast = fast->get_next();
    if (fast != nullptr){
      slow = slow->get_next();
      fast = fast->get_next();
    }
  }
  return slow;
}

void move_front_node(linked_list::SinglyLinkedList& source, linked_list::SinglyLinkedList& destination)
{
  Node* node_to_move = source.pop_front();
  assert(node_to_move != nullptr);
  destination.push_front(node_to_move);
}
}  // namespace linked_list
