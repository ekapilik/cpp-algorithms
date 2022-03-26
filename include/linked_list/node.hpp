/**
 * @file node.hpp
 * @author Eric Kapilik (erickapilik@gmail.com)
 * @brief Node class to be used by all linked list implementations.
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef LINKED_LIST_NODE_HPP_
#define LINKED_LIST_NODE_HPP_
namespace linked_list
{
class Node
{
public:
  Node();
  //~Node();
  int get_data();
  void set_data(int data);
  Node* get_next();
  void set_next(Node* node);
private:
  int data_;
  Node* next_;
};
}  // namespace linked_list
#endif  // LINKED_LIST_NODE_HPP_
