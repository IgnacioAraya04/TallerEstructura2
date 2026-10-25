#include "Queue.h"

Queue::Queue() {
    this->inicio = nullptr;
}

void Queue::push(Node* nodo) {
    if (nodo == nullptr) {
        return;
    }

    if (this -> inicio == nullptr) {
        this -> inicio = nodo;
    } else {
        Node* actual = this -> inicio;
        while (actual->getNext() != nullptr) {
            actual = actual->getNext();
        }
        actual->setNext(nodo);
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

