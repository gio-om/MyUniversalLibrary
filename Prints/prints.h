#ifndef PRINTS_H
#define PRINTS_H

#include <vector>
#include <iostream>

using namespace std;

template<class T>
void print(vector<T> &v) {
    for (auto el : v) {
        cout << el << " ";
    }
    cout << endl;
}

#endif //PRINTS_H
