#include "AVLNode.h"

class AVLTree {
    private:
        AVLNode* root;
    public:
        AVLTree();

        int height(AVLNode* node);
        int balanceFactor(AVLNode* node);
        AVLNode* rotateRight(AVLNode* node);
        AVLNode* rotateLeft(AVLNode* node);
        AVLNode* rotateLeftRight(AVLNode* node);
        AVLNode* rotateRightLeft(AVLNode* node);
        AVLNode* insert(AVLNode* node, Node* paciente);
        AVLNode* search(int ID);
        void inOrder(AVLNode* root);
        void preOrder(AVLNode* root);
        void postOrder(AVLNode* root);
};