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

/**
 * @brief Expose protected members of class to test.
 * 
 */
class SinglyLinkedListTest : public linked_list::SinglyLinkedList
{
public:
  SinglyLinkedListTest() : linked_list::SinglyLinkedList()
  {
  }

  linked_list::Node* get_middle_node_test()
  {
    return get_middle_node();
  }
};

class SinglyLinkedListTestFixture : public ::testing::Test
{
protected:
  void SetUp() override
  {
    sll_ = SinglyLinkedListTest();
    sll_ptr_ = new SinglyLinkedListTest();
  }

  void TearDown() override
  {
    delete(sll_ptr_);
  }

  SinglyLinkedListTest sll_;
  SinglyLinkedListTest* sll_ptr_;
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
  sll_.push_back(2);
  sll_.push_back(3);
  linked_list::Node* current;
  current = sll_.pop_front();
  EXPECT_EQ(current->get_data(), 1);
  EXPECT_EQ(current->get_next(), nullptr);
  current = sll_.pop_front();
  EXPECT_EQ(current->get_data(), 2);
  EXPECT_EQ(current->get_next(), nullptr);
  current = sll_.pop_front();
  EXPECT_EQ(current->get_data(), 3);
  EXPECT_EQ(current->get_next(), nullptr);
  current = sll_.pop_front();
  EXPECT_EQ(current, nullptr);
}

TEST_F(SinglyLinkedListTestFixture, PushFrontPopBack)
{
  sll_.push_front(1);
  sll_.push_front(2);
  sll_.push_front(3);
  linked_list::Node* current;
  current = sll_.pop_back();
  EXPECT_EQ(current->get_data(), 1);
  EXPECT_EQ(current->get_next(), nullptr);
  current = sll_.pop_back();
  EXPECT_EQ(current->get_data(), 2);
  EXPECT_EQ(current->get_next(), nullptr);
  current = sll_.pop_back();
  EXPECT_EQ(current->get_data(), 3);
  EXPECT_EQ(current->get_next(), nullptr);
  current = sll_.pop_back();
  EXPECT_EQ(current, nullptr);
}

TEST_F(SinglyLinkedListTestFixture, PushFrontPopFront)
{
  sll_.push_front(1);
  sll_ptr_->push_front(new linked_list::Node(1));
  sll_.push_front(2);
  sll_ptr_->push_front(new linked_list::Node(2));
  sll_.push_front(3);
  sll_ptr_->push_front(new linked_list::Node(3));
  linked_list::Node* current;
  current = sll_.pop_front();
  EXPECT_EQ(current->get_data(), 3);
  EXPECT_EQ(current->get_next(), nullptr);
  current = sll_.pop_front();
  EXPECT_EQ(current->get_data(), 2);
  EXPECT_EQ(current->get_next(), nullptr);
  current = sll_.pop_front();
  EXPECT_EQ(current->get_data(), 1);
  EXPECT_EQ(current->get_next(), nullptr);
  current = sll_.pop_front();
  EXPECT_EQ(current, nullptr);
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

TEST_F(SinglyLinkedListTestFixture, DataAt)
{
  sll_.push_back(1);
  sll_.push_back(2);
  sll_.push_back(3);
  sll_.push_back(4);
  sll_.push_back(5);
  sll_.push_back(6);
  EXPECT_EQ(sll_.at(0), 1);
  EXPECT_EQ(sll_.at(1), 2);
  EXPECT_EQ(sll_.at(2), 3);
  EXPECT_EQ(sll_.at(3), 4);
  EXPECT_EQ(sll_.at(4), 5);
  EXPECT_EQ(sll_.at(5), 6);
}

TEST_F(SinglyLinkedListTestFixture, GetMiddleNode)
{
  sll_.push_back(1);
  sll_.push_back(2);
  sll_.push_back(3);
  sll_.push_back(4);
  sll_.push_back(5);

  linked_list::Node* middle_node = sll_.get_middle_node_test();
  EXPECT_EQ(middle_node->get_data(), 3);
  
  sll_.push_back(6);

  middle_node = sll_.get_middle_node_test();
  EXPECT_EQ(middle_node->get_data(), 3);
}

TEST_F(SinglyLinkedListTestFixture, MoveFrontNodeUtility)
{
  linked_list::SinglyLinkedList list_a, list_b;
  list_a.push_back(1);
  list_a.push_back(2);
  list_a.push_back(3);
  list_b.push_back(1);
  list_b.push_back(2);
  list_b.push_back(3);
  
  linked_list::move_front_node(list_a, list_b);

  ASSERT_EQ(list_a.size(), 2);
  EXPECT_EQ(list_a.at(0), 2);
  EXPECT_EQ(list_a.at(1), 3);

  ASSERT_EQ(list_b.size(), 4);
  EXPECT_EQ(list_b.at(0), 1);
  EXPECT_EQ(list_b.at(1), 1);
  EXPECT_EQ(list_b.at(2), 2);
  EXPECT_EQ(list_b.at(3), 3);
}

TEST_F(SinglyLinkedListTestFixture, MergeListsBintoA)
{
  linked_list::SinglyLinkedList list_a, list_b;
  list_a.push_back(1);
  list_a.push_back(3);
  list_a.push_back(5);
  list_b.push_back(2);
  list_b.push_back(4);
  list_b.push_back(6);

  list_a.merge(list_b);

  ASSERT_EQ(list_a.size(), 6);
  ASSERT_EQ(list_b.size(), 0);
  EXPECT_EQ(list_a.at(0), 1);
  EXPECT_EQ(list_a.at(1), 2);
  EXPECT_EQ(list_a.at(2), 3);
  EXPECT_EQ(list_a.at(3), 4);
  EXPECT_EQ(list_a.at(4), 5);
  EXPECT_EQ(list_a.at(5), 6);
  EXPECT_EQ(list_a.at(6), 0);
}

TEST_F(SinglyLinkedListTestFixture, MergeListsAintoB)
{
  linked_list::SinglyLinkedList list_a, list_b;
  list_a.push_back(1);
  list_a.push_back(3);
  list_a.push_back(5);
  list_b.push_back(2);
  list_b.push_back(4);
  list_b.push_back(6);
  list_b.merge(list_a);
  ASSERT_EQ(list_a.size(), 0);
  ASSERT_EQ(list_b.size(), 6);

  EXPECT_EQ(list_b.at(0), 1);
  EXPECT_EQ(list_b.at(1), 2);
  EXPECT_EQ(list_b.at(2), 3);
  EXPECT_EQ(list_b.at(3), 4);
  EXPECT_EQ(list_b.at(4), 5);
  EXPECT_EQ(list_b.at(5), 6);
  EXPECT_EQ(list_b.at(6), 0);
}


//TEST_F(SinglyLinkedListTestFixture, Sort)
//{
//  // [3] -> [2] -> [5] -> [1] -> [4] -> []
//  sll_.push_front(4);
//  sll_.push_front(1);
//  sll_.push_front(5);
//  sll_.push_front(2);
//  sll_.push_front(3);
//
//  sll_.sort();
//
//  // [1] -> [2] -> [3] -> [4] -> [5] -> []
//  EXPECT_EQ(sll_.pop_front()->get_data(), 1);
//  EXPECT_EQ(sll_.pop_front()->get_data(), 2);
//  EXPECT_EQ(sll_.pop_front()->get_data(), 3);
//  EXPECT_EQ(sll_.pop_front()->get_data(), 4);
//  EXPECT_EQ(sll_.pop_front()->get_data(), 5);
//  EXPECT_EQ(sll_.pop_front(), nullptr);
//}
