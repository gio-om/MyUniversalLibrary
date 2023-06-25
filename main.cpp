#include <iostream>

#include "Structures/BinaryTree.h"
#include "Structures/MyVector.h"

using namespace std;

int main() {
    MyVector<int> a(5);
    a.add_element(6);
    a.add_element(2);
    a.add_element(1);
    a.add_element(1);
    a.add_element(1);

    cout << a << endl;
    return 0;
}
