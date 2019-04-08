/*
Copyright (C) 2019 Kedar R. Bhat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include "LinkedListSolutions/DeleteNodeAtPosition.hpp"
#include "LinkedListSolutions/InsertNodeAtHead.hpp"
#include "LinkedListSolutions/InsertNodeAtPosition.hpp"
#include "LinkedListSolutions/InsertNodeAtTail.hpp"
#include "LinkedListSolutions/PrintLinkedListElements.hpp"

namespace {
void DeleteLinkedList(linked_lists::detail::SinglyLinkedListNode *head) {
  while (head != nullptr) {
    auto *tmp = head->next_;
    delete head;
    head = tmp;
  }
}
}  // namespace

namespace {
TEST(TestLinkedListSolutions, PrintListedListElements) {
  auto *head = new linked_lists::detail::SinglyLinkedListNode(16);
  head->next_ = new linked_lists::detail::SinglyLinkedListNode(13);
  ASSERT_EQ(linked_lists::PrintLinkedList(head), std::string("16 13"));
  DeleteLinkedList(head);
}

TEST(TestLinkedListSolutions, InsertNodeAtTail) {
  linked_lists::detail::SinglyLinkedListNode *head = nullptr;
  for (auto i : {141, 302, 164, 530, 474}) {
    head = linked_lists::InsertNodeAtTail(head, i);
  }

  for (auto i : {141, 302, 164, 530, 474}) {
    ASSERT_FALSE(head == nullptr);
    ASSERT_EQ(head->data_,
              i);  // NOLINT(clang-analyzer-core.NonNullParamChecker)
    head = head->next_;
  }
  DeleteLinkedList(head);
}

TEST(TestLinkedListSolutions, InsertNodeAtHead) {
  linked_lists::detail::SinglyLinkedListNode *head = nullptr;
  for (auto i : {383, 484, 392, 975, 321}) {
    head = linked_lists::insertNodeAtHead(head, i);
  }

  for (auto i : {321, 975, 392, 484, 383}) {
    ASSERT_FALSE(head == nullptr);
    ASSERT_EQ(head->data_,
              i);  // NOLINT(clang-analyzer-core.NonNullParamChecker)
    head = head->next_;
  }
  DeleteLinkedList(head);
}

TEST(TestLinkedListSolutions, InsertNodeAtPosition) {
  linked_lists::detail::SinglyLinkedListNode *head = nullptr;
  for (auto i : {16, 13, 7}) {
    head = linked_lists::InsertNodeAtTail(head, i);
  }

  head = linked_lists::insertNodeAtPosition(head, 1, 2);

  for (auto i : {16, 13, 1, 7}) {
    ASSERT_FALSE(head == nullptr);
    ASSERT_EQ(head->data_,
              i);  // NOLINT(clang-analyzer-core.NonNullParamChecker)
    head = head->next_;
  }
  DeleteLinkedList(head);
}

TEST(TestLinkedListSolutions, DeleteNodeAtPosition) {
  linked_lists::detail::SinglyLinkedListNode *head = nullptr;
  for (auto i : {20, 6, 2, 19, 7, 4, 15, 9}) {
    head = linked_lists::InsertNodeAtTail(head, i);
  }

  head = linked_lists::deleteNode(head, 3);

  for (auto i : {20, 6, 2, 7, 4, 15, 9}) {
    ASSERT_FALSE(head == nullptr);
    ASSERT_EQ(head->data_,
              i);  // NOLINT(clang-analyzer-core.NonNullParamChecker)
    head = head->next_;
  }
  DeleteLinkedList(head);
}


}  // namespace