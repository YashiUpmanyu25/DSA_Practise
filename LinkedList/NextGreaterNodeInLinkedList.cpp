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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        // Step 1: Convert linked list to array
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        int n = values.size();
        vector<int> result(n, 0);
        stack<int> st; // stores indices

        // Step 2: Monotonic decreasing stack
        for (int i = 0; i < n; i++) {
            while (!st.empty() && values[i] > values[st.top()]) {
                result[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};
