#include "Ejercicio02.h"

Node<char>* reverseList(Node<char>* head, int k) {
    Node<char>* prev = nullptr;
    Node<char>* current = head;
    Node<char>* next = nullptr;
    while (current != nullptr && k > 0) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        k--;
    }
    return prev;
}

bool hasKNodes(Node<char>* head, int k) {
    int count = 0;
    while (head != nullptr && count < k) {
        head = head->next;
        count++;
    }
    return count == k;
}

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k) {
    if (head == nullptr || k == 1) {
        return head;
    }

    Node<char>* dummy = new Node<char>();
    dummy->next = head;
    Node<char>* prevGroupEnd = dummy;
    Node<char>* current = head;

    while (hasKNodes(current, k)) {
        Node<char>* groupStart = current;
        for (int i = 0; i < k; i++) {
            current = current->next;
        }

        prevGroupEnd->next = reverseList(groupStart, k);
        groupStart->next = current;
        prevGroupEnd = groupStart;
    }

    Node<char>* newHead = dummy->next;
    delete dummy;
    return newHead;
}
