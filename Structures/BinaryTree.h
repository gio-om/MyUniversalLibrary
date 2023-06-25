#ifndef BINARYTREE_H
#define BINARYTREE_H

class Node {
public:
    Node* left;
    Node* right;
    int data;

    explicit Node(int d) {
        left = nullptr;
        right = nullptr;
        data = d;
    }
};

class BinaryTree {
    Node* root;

public:
    BinaryTree() { root = nullptr; }

    bool is_empty() { return root == nullptr; }

    void insert(int el);

    void print(Node* ptr);

    void display();
};

#endif //BINARYTREE_H
