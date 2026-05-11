#include <bits/stdc++.h>
using namespace std;

class AllOne {
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    unordered_map<string, int> keyCount;
    unordered_map<int, Node*> countNode;

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        int cnt = keyCount[key]++;
        int newCnt = cnt + 1;

        Node* curr = (cnt == 0) ? nullptr : countNode[cnt];
        Node* nextNode;

        if (countNode.find(newCnt) == countNode.end()) {
            nextNode = new Node(newCnt);
            countNode[newCnt] = nextNode;
            insertAfter((cnt == 0) ? head : curr, nextNode);
        } else {
            nextNode = countNode[newCnt];
        }

        nextNode->keys.insert(key);

        if (curr) {
            curr->keys.erase(key);
            if (curr->keys.empty()) removeNode(curr);
        }
    }
    
    void dec(string key) {
        if (keyCount.find(key) == keyCount.end()) return;

        int cnt = keyCount[key];
        Node* curr = countNode[cnt];
        curr->keys.erase(key);

        if (cnt == 1) {
            keyCount.erase(key);
        } else {
            int newCnt = cnt - 1;
            Node* prevNode;
            if (countNode.find(newCnt) == countNode.end()) {
                prevNode = new Node(newCnt);
                countNode[newCnt] = prevNode;
                insertBefore(curr, prevNode);
            } else {
                prevNode = countNode[newCnt];
            }
            prevNode->keys.insert(key);
            keyCount[key]--;
        }

        if (curr->keys.empty()) removeNode(curr);
    }
    
    string getMaxKey() {
        return (tail->prev == head || tail->prev->keys.empty()) ? "" : *tail->prev->keys.begin();
    }
    
    string getMinKey() {
        return (head->next == tail || head->next->keys.empty()) ? "" : *head->next->keys.begin();
    }

private:
    void insertAfter(Node* a, Node* b) {
        b->next = a->next;
        b->prev = a;
        a->next->prev = b;
        a->next = b;
    }

    void insertBefore(Node* a, Node* b) {
        b->prev = a->prev;
        b->next = a;
        a->prev->next = b;
        a->prev = b;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        countNode.erase(node->count);
        delete node;
    }
};
