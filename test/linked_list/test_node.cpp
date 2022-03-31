/**
 * @file test_node.cpp
 * @author Eric Kapilik (erickapilik@gmail.com)
 * @brief Unit test the node class
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "gtest/gtest.h"
#include "linked_list/node.hpp"

class NodeTestFixture : public ::testing::Test
{
protected:
  void SetUp() override
  {
    node_ = linked_list::Node();
    node_ptr_ = new linked_list::Node();
  }

  void TearDown() override
  {
    delete(node_ptr_);
  }

  linked_list::Node node_;
  linked_list::Node* node_ptr_;
};

TEST_F(NodeTestFixture, IsEmptyInitially)
{
  EXPECT_EQ(node_.get_data(), 0);
  EXPECT_EQ(node_.get_next(), nullptr);
  EXPECT_EQ(node_ptr_->get_data(), 0);
  EXPECT_EQ(node_ptr_->get_next(), nullptr);
}

TEST_F(NodeTestFixture, DataConstructor)
{
  linked_list::Node new_node = linked_list::Node(5);
  linked_list::Node* new_node_ptr = new linked_list::Node(8);
  EXPECT_EQ(new_node.get_data(), 5);
  EXPECT_EQ(new_node.get_next(), nullptr);
  EXPECT_EQ(new_node_ptr->get_data(), 8);
  EXPECT_EQ(new_node_ptr->get_next(), nullptr);
}

TEST_F(NodeTestFixture, SetData)
{
  node_.set_data(7 * 6);
  node_ptr_->set_data(7 + 6);
  EXPECT_EQ(node_.get_data(), 42);
  EXPECT_EQ(node_ptr_->get_data(), 13);
}

TEST_F(NodeTestFixture, SetNext)
{
  node_.set_next(node_ptr_);
  EXPECT_EQ(node_.get_next(), node_ptr_);
}

TEST_F(NodeTestFixture, DeconstructorDoesntDeleteNext)
{
  node_ptr_->set_data(5);
  {
    linked_list::Node scoped_node = linked_list::Node();
    scoped_node.set_next(node_ptr_);
  }
  EXPECT_EQ(node_ptr_->get_data(), 5);
}
