#include "Ejercicio01.h"
#include <stack>

Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2) {
    std::stack<int> stack1, stack2;

    //para llenar las pilas 
    Node<int>* temp = l1;
    while (temp != nullptr) {
        stack1.push(temp->value);
        temp = temp->next;
    }
    temp = l2;
    while (temp != nullptr) {
        stack2.push(temp->value);
        temp = temp->next;
    }

    int sum = 0;
    Node<int>* result = nullptr;

    
    while (!stack1.empty() || !stack2.empty() || sum > 0) {
        if (!stack1.empty()) {
            sum += stack1.top();
            stack1.pop();
        }
        if (!stack2.empty()) {
            sum += stack2.top();
            stack2.pop();
        }

        Node<int>* node = new Node<int>();
        node->value = sum % 10;
        node->next = result;
        result = node;
        sum /= 10;
    }

    return result;
}
