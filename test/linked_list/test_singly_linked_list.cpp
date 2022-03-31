/**
 * @file test_singly_linked_list.cpp
 * @author Eric Kapilik (erickapilik@gmail.com)
 * @brief Unit test the singly linked list
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "gtest/gtest.h"
#include "linked_list/singly_linked_list.hpp"

class SinglyLinkedListTestFixture : public ::testing::Test
{
protected:
  void SetUp() override
  {
    sll_ = linked_list::SinglyLinkedList();
    sll_ptr_ = new linked_list::SinglyLinkedList();
  }

  void TearDown() override
  {
    delete(sll_ptr_);
  }

  linked_list::SinglyLinkedList sll_;
  linked_list::SinglyLinkedList* sll_ptr_;
};

TEST_F(SinglyLinkedListTestFixture, IsEmptyInitially)
{
  EXPECT_EQ(sll_.front(), nullptr);
  EXPECT_EQ(sll_ptr_->front(), nullptr);
  EXPECT_TRUE(sll_.empty());
  EXPECT_TRUE(sll_ptr_->empty());
}

TEST_F(SinglyLinkedListTestFixture, PushBackSingleData)
{
  sll_.push_back(5);
  sll_ptr_->push_back(5);
  EXPECT_EQ(sll_.front()->get_data(), 5);
  EXPECT_EQ(sll_ptr_->front()->get_data(), 5);
}

TEST_F(SinglyLinkedListTestFixture, PushBackSingleNode)
{
  sll_.push_back(new linked_list::Node(5));
  EXPECT_EQ(sll_.front()->get_data(), 5);
}

TEST_F(SinglyLinkedListTestFixture, PushFrontSingleData)
{
  sll_.push_front(5);
  sll_ptr_->push_front(5);
  EXPECT_EQ(sll_.front()->get_data(), 5);
  EXPECT_EQ(sll_ptr_->front()->get_data(), 5);
}

TEST_F(SinglyLinkedListTestFixture, PushFrontSingleNode)
{
  sll_.push_front(new linked_list::Node(8));
  EXPECT_EQ(sll_.front()->get_data(), 8);
}

TEST_F(SinglyLinkedListTestFixture, PushBackPopBack)
{
  sll_.push_back(1);
  sll_ptr_->push_back(new linked_list::Node(1));
  sll_.push_back(2);
  sll_ptr_->push_back(new linked_list::Node(2));
  sll_.push_back(3);
  sll_ptr_->push_back(new linked_list::Node(3));
  EXPECT_EQ(sll_.pop_back()->get_data(), 3);
  EXPECT_EQ(sll_ptr_->pop_back()->get_data(), 3);
  EXPECT_EQ(sll_.pop_back()->get_data(), 2);
  EXPECT_EQ(sll_ptr_->pop_back()->get_data(), 2);
  EXPECT_EQ(sll_.pop_back()->get_data(), 1);
  EXPECT_EQ(sll_ptr_->pop_back()->get_data(), 1);
  EXPECT_EQ(sll_.pop_back(), nullptr);
  EXPECT_EQ(sll_ptr_->pop_back(), nullptr);
}

TEST_F(SinglyLinkedListTestFixture, PushBackPopFront)
{
  sll_.push_back(1);
  sll_ptr_->push_back(new linked_list::Node(1));
  sll_.push_back(2);
  sll_ptr_->push_back(new linked_list::Node(2));
  sll_.push_back(3);
  sll_ptr_->push_back(new linked_list::Node(3));
  EXPECT_EQ(sll_.pop_front()->get_data(), 1);
  EXPECT_EQ(sll_ptr_->pop_front()->get_data(), 1);
  EXPECT_EQ(sll_.pop_front()->get_data(), 2);
  EXPECT_EQ(sll_ptr_->pop_front()->get_data(), 2);
  EXPECT_EQ(sll_.pop_front()->get_data(), 3);
  EXPECT_EQ(sll_ptr_->pop_front()->get_data(), 3);
  EXPECT_EQ(sll_.pop_front(), nullptr);
  EXPECT_EQ(sll_ptr_->pop_front(), nullptr);
}

TEST_F(SinglyLinkedListTestFixture, PushFrontPopBack)
{
  sll_.push_front(1);
  sll_ptr_->push_front(new linked_list::Node(1));
  sll_.push_front(2);
  sll_ptr_->push_front(new linked_list::Node(2));
  sll_.push_front(3);
  sll_ptr_->push_front(new linked_list::Node(3));
  EXPECT_EQ(sll_.pop_back()->get_data(), 1);
  EXPECT_EQ(sll_ptr_->pop_back()->get_data(), 1);
  EXPECT_EQ(sll_.pop_back()->get_data(), 2);
  EXPECT_EQ(sll_ptr_->pop_back()->get_data(), 2);
  EXPECT_EQ(sll_.pop_back()->get_data(), 3);
  EXPECT_EQ(sll_ptr_->pop_back()->get_data(), 3);
  EXPECT_EQ(sll_.pop_back(), nullptr);
  EXPECT_EQ(sll_ptr_->pop_back(), nullptr);
}

TEST_F(SinglyLinkedListTestFixture, PushFrontPopFront)
{
  sll_.push_front(1);
  sll_ptr_->push_front(new linked_list::Node(1));
  sll_.push_front(2);
  sll_ptr_->push_front(new linked_list::Node(2));
  sll_.push_front(3);
  sll_ptr_->push_front(new linked_list::Node(3));
  EXPECT_EQ(sll_.pop_front()->get_data(), 3);
  EXPECT_EQ(sll_ptr_->pop_front()->get_data(), 3);
  EXPECT_EQ(sll_.pop_front()->get_data(), 2);
  EXPECT_EQ(sll_ptr_->pop_front()->get_data(), 2);
  EXPECT_EQ(sll_.pop_front()->get_data(), 1);
  EXPECT_EQ(sll_ptr_->pop_front()->get_data(), 1);
  EXPECT_EQ(sll_.pop_front(), nullptr);
  EXPECT_EQ(sll_ptr_->pop_front(), nullptr);
}

TEST_F(SinglyLinkedListTestFixture, Empty)
{
  EXPECT_TRUE(sll_.empty());
  sll_.push_front(1);
  EXPECT_FALSE(sll_.empty());
  sll_.pop_front();
  EXPECT_TRUE(sll_.empty());
  sll_.push_back(1);
  EXPECT_FALSE(sll_.empty());
  sll_.pop_back();
  EXPECT_TRUE(sll_.empty());
}

TEST_F(SinglyLinkedListTestFixture, Size)
{
  EXPECT_EQ(sll_.size(), 0);
  sll_.push_back(1);
  EXPECT_EQ(sll_.size(), 1);
  sll_.push_back(2);
  EXPECT_EQ(sll_.size(), 2);
  sll_.push_back(3);
  EXPECT_EQ(sll_.size(), 3);
  sll_.pop_back();
  EXPECT_EQ(sll_.size(), 2);
  sll_.pop_back();
  EXPECT_EQ(sll_.size(), 1);
  sll_.pop_back();
  EXPECT_EQ(sll_.size(), 0);
}

TEST_F(SinglyLinkedListTestFixture, Clear)
{
  sll_.push_back(1);
  sll_.push_back(2);
  sll_.push_back(3);
  sll_.clear();
  EXPECT_EQ(sll_.size(), 0);
  EXPECT_TRUE(sll_.empty());
}

TEST_F(SinglyLinkedListTestFixture, Sort)
{
  // [3] -> [2] -> [5] -> [1] -> [4] -> []
  sll_.push_front(4);
  sll_.push_front(1);
  sll_.push_front(5);
  sll_.push_front(2);
  sll_.push_front(3);

  sll_.sort();

  // [1] -> [2] -> [3] -> [4] -> [5] -> []
  EXPECT_EQ(sll_.pop_front()->get_data(), 1);
  EXPECT_EQ(sll_.pop_front()->get_data(), 2);
  EXPECT_EQ(sll_.pop_front()->get_data(), 3);
  EXPECT_EQ(sll_.pop_front()->get_data(), 4);
  EXPECT_EQ(sll_.pop_front()->get_data(), 5);
  EXPECT_EQ(sll_.pop_front(), nullptr);
}
