#include "Node.h"

Node::Node(Paciente* paciente) {
    this->paciente = paciente;
    this->next = nullptr;
}

Paciente* Node::getPaciente() {
    return paciente;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* next) {
    this->next = next;
}

Node::~Node() {
    delete paciente;
    delete next;
}
