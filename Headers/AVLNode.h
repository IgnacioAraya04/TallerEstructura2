#ifndef AVLNODE_H
#define AVLNODE_H

#include <iostream>
#include "Node.h"
using namespace std;

class AVLNode {
    private:
        Node* paciente;
        AVLNode* left;
        AVLNode* right;
        int height;
    public:
        AVLNode(Node* paciente){
            this->paciente = paciente;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 1;
        }
    
        AVLNode* getLeft() {
            return left;
        }

        AVLNode* getRight() {
            return right;
        }

        void setLeft(AVLNode* left) {
            this->left = left;
        }

        void setRight(AVLNode* right) {
            this->right = right;
        }

        Node* getPaciente() {
            return paciente;
        }

        int getHeight() {
            return height;
        }

        void setHeight(int height) {
            this->height = height;
        }

        string toString() {
            return "T: " + to_string(paciente->getPaciente()->getTemperatura()) + "° | D: "+to_string(paciente->getPaciente()->getDolor())+ " | TD: "+ paciente->getPaciente()->getTipoDolor() + " | Tr: " +to_string(paciente->getPaciente()->getTrauma()) + " | SN: " + to_string(paciente->getPaciente()->getSintomasNeurologicos()) + " | RC: " + to_string(paciente->getPaciente()->getCirugia()) + " | DH: " + to_string(paciente->getPaciente()->getDiasHospitalizado());
        }
};

#endif
