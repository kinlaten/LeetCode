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
class Solution
{
public:
    // fast = slow x 2; when fast reachs end, slow reachs mid
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;

        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                // Attach temp to current min node
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                // Attach temp to current min node
                temp->next = right;
                temp = right;
                // Move right forward 1 position
                right = right->next;
            }
        }

        while (left)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        return dummy->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *mid = getMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = nullptr;

        // Recusion
        left = sortList(left);
        right = sortList(right);

        ListNode *result = merge(left, right);

        return result;
    }
};