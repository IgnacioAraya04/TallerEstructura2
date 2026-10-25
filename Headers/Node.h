#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include "Paciente.h"
using namespace std;

class Node {
    private:
        Paciente* paciente;
        Node* next;
    public:
        Node(Paciente* paciente);
        Paciente* getPaciente();
        Node* getNext();
        void setNext(Node* next);
        ~Node();
};

#endif