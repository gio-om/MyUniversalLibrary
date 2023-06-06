#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <cstring>

const int MAX_SIZE = 4;

template<typename T>
class MyVector {
public:
    explicit MyVector(T el, int maxsz = MAX_SIZE);

    MyVector(const MyVector<T> &v);

    ~MyVector();

    virtual void add_element(T el);

    bool delete_element(int index);

    T operator[](int i);

    void sort();

    [[nodiscard]] int Size() const { return size; }

    [[nodiscard]] int Maxsize() const { return maxsize; }

    int find(T el);

    MyVector<T>& operator=(const MyVector<T>& v);

    template<class U>
    friend std::ostream &operator<<(std::ostream &out, const MyVector<U> &v);

protected:
    int maxsize;
    int size;
    T *pdata;
private:
    void resize();
};

template<typename T>
void MyVector<T>::resize() {
    T* new_pdata = new T[maxsize];
    for (int i = 0; i < size; ++i) {
        new_pdata[i] = pdata[i];
    }
    delete[] pdata;
    pdata = new_pdata;
}

template<typename T>
MyVector<T>::MyVector(T el, int maxsz) {
    maxsize = maxsz;
    size = 1;
    pdata = new T[maxsize];
    pdata[0] = el;
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] pdata;
    pdata = nullptr;
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T> &v) {
    this->maxsize = v.maxsize;
    this->size = v.size;
    this->pdata = new T[maxsize];
    for (int i = 0; i < size; ++i) {
        this->pdata[i] = v.pdata[i];
    }
}

template<typename T>
void MyVector<T>::add_element(T el) {
    pdata[size++] = el;
    if (size == maxsize) {
        maxsize *= 2;
        resize();
    }
}

template<typename T>
bool MyVector<T>::delete_element(int index) {
    if (index >= size || index < 0) {
        return false;
    }

    for (int i = index + 1; i < size; ++i) {
        pdata[i - 1] = pdata[i];
    }
    size--;
    if (size * 2 < maxsize) {
        maxsize /= 2;
        resize();
    }
    return true;
}

template<typename T>
T MyVector<T>::operator[](int i) {
    return pdata[i];
}

template<typename T>
void MyVector<T>::sort() {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (pdata[j] > pdata[j + 1]) {
                swapped = true;
                std::swap(pdata[j], pdata[j + 1]);
            }
        }
        if (!swapped) {
            break;
        }
    }
}

template<typename T>
int MyVector<T>::find(T el) {
    if (size == 0) {
        return -1;
    }
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (pdata[mid] == el) {
            return mid;
        } else if(pdata[mid] < el) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& v) {
    if(this == &v) {
        return *this;
    }

    for (int i = 0; i < this->size; ++i) {
        pdata[i] = 0;
    }
    delete[] pdata;
    pdata = nullptr;

    this->maxsize = v.maxsize;
    this->size = v.size;
    this->pdata = new T[v.maxsize];
    for (int i = 0; i < size; ++i) {
        this->pdata[i] = v.pdata[i];
    }
    return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const MyVector<T> &v) {
    for (int i = 0; i < v.size; ++i) {
        std::cout << v.pdata[i] << ' ';
    }
    return out;
}


#endif //MYVECTOR_H
