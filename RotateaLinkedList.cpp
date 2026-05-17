class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Find length and tail
        Node* tail = head;
        int len = 1;
        
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        k = k % len;
        if (k == 0) return head;
        
        // Find kth node
        Node* curr = head;
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }
        
        Node* newHead = curr->next;
        curr->next = NULL;   // break list
        tail->next = head;   // connect tail to old head
        
        return newHead;
    }
};