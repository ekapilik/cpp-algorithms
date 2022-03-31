/**
 * @file node.cpp
 * @author Eric Kapilik (erickapilik@gmail.com)
 * @brief Implement a node to be used in a linked list.
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstddef>
#include "linked_list/node.hpp"

namespace linked_list
{

Node::Node() : data_{0}, next_{nullptr}
{
}

Node::Node(int data) : data_{data}, next_{nullptr}
{
}

int Node::get_data()
{
  return data_;
}

void Node::set_data(int data)
{
  data_ = data;
}

Node* Node::get_next()
{
  return next_;
}

void Node::set_next(Node* node)
{
  next_ = node;
}

}  // namespace linked_list
