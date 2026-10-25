#pragma once
#include "Node.h"

class Queue {
    private:
        Node* inicio;
    public:
        Queue();
        void push(Node* paciente);
        void pop();
        Node* front();
        Node* takeFront();

        int size();
        bool isEmpty();
        void clear();
        ~Queue();
};