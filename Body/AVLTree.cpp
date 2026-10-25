#include "AVLTree.h"

AVLTree::AVLTree() {
    this->root = nullptr;
}

bool AVLTree::isEmpty() const {
    return root == nullptr;
}

AVLNode* AVLTree::getRoot() const {
    return root;
}

int AVLTree::height(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->getHeight();
}

int AVLTree::balanceFactor(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->getLeft()) - height(node->getRight());
}

AVLNode* AVLTree::rotateRight(AVLNode* node) {
    AVLNode* newRoot = node->getLeft();
    node->setLeft(newRoot->getRight());
    newRoot->setRight(node);

    node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);
    newRoot->setHeight(max(height(newRoot->getLeft()), height(newRoot->getRight())) + 1);

    return newRoot;
}

AVLNode* AVLTree::rotateLeft(AVLNode* node) {
    AVLNode* newRoot = node->getRight();
    node->setRight(newRoot->getLeft());
    newRoot->setLeft(node);

    node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);
    newRoot->setHeight(max(height(newRoot->getLeft()), height(newRoot->getRight())) + 1);

    return newRoot;
}

AVLNode* AVLTree::rotateLeftRight(AVLNode* node) {
    node->setLeft(rotateLeft(node->getLeft()));
    return rotateRight(node);
}

AVLNode* AVLTree::rotateRightLeft(AVLNode* node) {
    node->setRight(rotateRight(node->getRight()));
    return rotateLeft(node);
}

AVLNode* AVLTree::insertNode(AVLNode* node, Node* paciente) {
    if (node == nullptr) {
        return new AVLNode(paciente);
    }

    if (paciente->getPaciente()->getID() < node->getPaciente()->getPaciente()->getID()) {
        node->setLeft(insertNode(node->getLeft(), paciente));
    } else if (paciente->getPaciente()->getID() > node->getPaciente()->getPaciente()->getID()) {
        node->setRight(insertNode(node->getRight(), paciente));
    } else {
        return node;
    }

    node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));
    int balance = balanceFactor(node);

    if (balance > 1) {
        if (balanceFactor(node->getLeft()) >= 0) {
            return rotateRight(node);
        } else {
            node->setLeft(rotateLeft(node->getLeft()));
            return rotateRight(node);
        }
    }
    if (balance < -1) {
        if (balanceFactor(node->getRight()) <= 0) {
            return rotateLeft(node);
        } else {
            node->setRight(rotateRight(node->getRight()));
            return rotateLeft(node);
        }
    }

    return node;
}

void AVLTree::insert(Node* paciente) {
    if (paciente == nullptr) {
        return;
    }
    root = insertNode(root, paciente);
}

AVLNode* AVLTree::search(int ID) {
    AVLNode* current = root;
    while (current != nullptr) {
        if (ID == current->getPaciente()->getPaciente()->getID()) {
            return current;
        } else if (ID < current->getPaciente()->getPaciente()->getID()) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }
    return nullptr;
}

void AVLTree::inOrder(AVLNode* root) {
    if (root != nullptr) {
        inOrder(root->getLeft());
        cout << "ID: " << root->getPaciente()->getPaciente()->getID() << ", Nombre: " << root->getPaciente()->getPaciente()->getNombre() << endl;
        inOrder(root->getRight());
    }
}

void AVLTree::preOrder(AVLNode* root) {
    if (root != nullptr) {
        cout << "ID: " << root->getPaciente()->getPaciente()->getID() << ", Nombre: " << root->getPaciente()->getPaciente()->getNombre() << endl;
        preOrder(root->getLeft());
        preOrder(root->getRight());
    }
}

void AVLTree::postOrder(AVLNode* root) {
    if (root != nullptr) {
        postOrder(root->getLeft());
        postOrder(root->getRight());
        cout << "ID: " << root->getPaciente()->getPaciente()->getID() << ", Nombre: " << root->getPaciente()->getPaciente()->getNombre() << endl;
    }
}