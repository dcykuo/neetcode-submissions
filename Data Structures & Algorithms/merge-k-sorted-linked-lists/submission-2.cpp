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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min Heap: smallest node on top
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        }

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype(cmp)
        > minHeap(cmp);

        // Push the first node of each list
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {

            // Get the smallest node
            ListNode* node = minHeap.top();
            minHeap.pop();

            // Append it to the result
            tail->next = node;
            tail = tail->next;

            // Push the next node if it exists
            if (node->next != nullptr) {
                minHeap.push(node->next);
            }
        }
        
        return dummy.next;
    }
};
