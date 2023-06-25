#include "BinaryTree.h"
#include <iostream>

void BinaryTree::insert(int el) {
    Node* new_node = new Node(el);
    if (is_empty()) {
        root = new_node;
    } else {
        Node* ptr = root;
        Node* parent = nullptr;
        while (ptr != nullptr) {
            parent = ptr;
            if (el > ptr->data) {
                ptr = ptr->right;
            } else {
                ptr = ptr->left;
            }
        }

        if (el > parent->data) {
            parent->right = new_node;
        } else {
            parent->left = new_node;
        }
    }
}


void BinaryTree::print(Node* ptr) {
    if(ptr != nullptr) {
        print(ptr->left);
        std::cout << ptr->data << " ";
        print(ptr->right);
    }
}

void BinaryTree::display() {
    print(root);
}
