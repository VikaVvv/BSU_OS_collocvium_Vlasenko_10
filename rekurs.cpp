#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseListRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;
}
