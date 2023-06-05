#include <iostream>

#include "Structures/BinaryTree.h"

using namespace std;

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(-1);
    tree.insert(0);
    tree.insert(15);
    tree.insert(54);

    tree.display();
    return 0;
}
