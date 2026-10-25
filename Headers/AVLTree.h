#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"

class AVLTree {
    private:
        AVLNode* root;
        AVLNode* insertNode(AVLNode* node, Node* paciente);
    public:
        AVLTree();

        bool isEmpty() const;
        AVLNode* getRoot() const;
        int height(AVLNode* node);
        int balanceFactor(AVLNode* node);
        AVLNode* rotateRight(AVLNode* node);
        AVLNode* rotateLeft(AVLNode* node);
        AVLNode* rotateLeftRight(AVLNode* node);
        AVLNode* rotateRightLeft(AVLNode* node);
        void insert(Node* paciente);
        AVLNode* search(int ID);
        void inOrder(AVLNode* root);
        void preOrder(AVLNode* root);
        void postOrder(AVLNode* root);
};

#endif