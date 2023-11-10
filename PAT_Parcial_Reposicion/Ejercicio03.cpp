#include "Ejercicio03.h"

Node<int>* Ejercicio03::detectCycle(Node<int>* head) {
    Node<int>* slow = head;
    Node<int>* fast = head;

    // encuentra el encuentro dentro del ciclo
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // encuetra el nodo de entrada al ciclo
            Node<int>* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    return nullptr;
}
