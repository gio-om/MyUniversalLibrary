#include <iostream>

#include "Structures/MyVector.h"

using namespace std;

int main() {
    char test_str[] = "test";
    MyVector v(test_str);
    v.add_element(test_str);
    cout << v << endl;
    cout << 5;
    return 0;
}
