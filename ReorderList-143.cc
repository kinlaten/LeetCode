/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  void reorderList(ListNode *head) {
    // Find middle Node
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse latter half
    ListNode *second = slow->next;
    slow->next = nullptr; // break down 2 arr
    ListNode *prev = nullptr;
    ListNode *nextNode = nullptr;
    int n = 0;
    while (second != nullptr) {
      nextNode = second->next;
      second->next = prev;
      prev = second;
      second = nextNode;
      n++;
    }

    // Merge
    ListNode *first = head;
    second = prev;

    while (second) {
      ListNode *temp1 = first->next;
      ListNode *temp2 = second->next;
      first->next = second;
      second->next = temp1;
      first = temp1;
      second = temp2;
    }
  }
};
