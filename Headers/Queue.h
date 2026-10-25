#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
    private:
        Node* inicio;
    public:
        Queue();
        void push(Node* nodo);
        void pop();
        Node* front();
        Node* takeFront();

        int size();
        bool isEmpty();
        void clear();
        ~Queue();
};

#endif