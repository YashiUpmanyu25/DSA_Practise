class Solution {
public:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next; // store next node
            curr->next = prev;     // reverse link
            prev = curr;           // move prev ahead
            curr = nextNode;       // move curr ahead
        }

        return prev; // new head
    }
};