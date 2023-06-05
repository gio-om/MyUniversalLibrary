#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

const int MAX_SIZE = 4;

class MyVector {
public:
    explicit MyVector(char *el = nullptr, int maxsz = MAX_SIZE);

    MyVector(const MyVector &v);

    ~MyVector();

    virtual void add_element(char *el);

    bool delete_element(int index);

    char* operator[](int i);

    void sort();

    [[nodiscard]] int Size() const { return size; }

    [[nodiscard]] int Maxsize() const { return maxsize; }

    int find(char *el);

    MyVector& operator=(const MyVector& v);

    friend std::ostream &operator<<(std::ostream &out, const MyVector &v);

protected:
    int maxsize;
    int size;
    char **pdata;
private:
    void resize();
};



#endif //MYVECTOR_H
