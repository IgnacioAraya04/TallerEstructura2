#include "Queue.h"

Queue::Queue() {
    this->inicio = nullptr;
}

void Queue::push(Paciente* paciente) {
    Node* nuevoNodo = new Node(paciente);
    if (this -> inicio == nullptr) {
        this -> inicio = nuevoNodo;
    } else {
        Node* actual = this -> inicio;
        while (actual->getNext() != nullptr) {
            actual = actual->getNext();
        }
        actual->setNext(nuevoNodo);
    }
}

void Queue::pop() {
    if (this->inicio != nullptr) {
        Node* nodoFrente = takeFront();
        delete nodoFrente;
    }
}

Node* Queue::takeFront() {
    if (this->inicio == nullptr) {
        return nullptr;
    } else {
        Node* nodoFrente = this->inicio;
        this->inicio = this->inicio->getNext();
        nodoFrente->setNext(nullptr);
        return nodoFrente;
    }
}

Node* Queue::front() {
    return this->inicio;
}

int Queue::size() {
    int count = 0;
    Node* actual = this->inicio;
    while (actual != nullptr) {
        count++;
        actual = actual->getNext();
    }
    return count;
}

bool Queue::isEmpty() {
    return this->inicio == nullptr;
}

void Queue::clear() {
    while (!isEmpty()) {
        pop();
    }
}

Queue::~Queue() {
    clear();
}

