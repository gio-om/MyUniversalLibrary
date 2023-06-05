#include "MyVector.h"
#include <cstring>

void MyVector::resize() {
    char** new_pdata = new char* [maxsize];
    for (int i = 0; i < size; ++i) {
        new_pdata[i] = new char[strlen(pdata[i])];
        strcpy(new_pdata[i], pdata[i]);
        delete[] pdata[i];
    }
    delete[] pdata;
    pdata = new_pdata;
}

MyVector::MyVector(char *el, int maxsz) {
    maxsize = maxsz;
    if (el == nullptr) {
        size = 0;
        pdata = new char* [maxsize];
    } else {
        size = 1;
        pdata = new char* [maxsize];
        pdata[0] = new char [strlen(el)];
        strcpy(pdata[0], el);
    }
}

MyVector::~MyVector() {
    for (int i = 0; i < size; ++i) {
        if (pdata[i] != nullptr) {
            delete[] pdata[i];
            pdata[i] = nullptr;
        }
    }
    delete[] pdata;
    pdata = nullptr;
}

MyVector::MyVector(const MyVector &v) {
    this->maxsize = v.maxsize;
    this->size = v.size;
    this->pdata = new char* [maxsize];
    for (int i = 0; i < size; ++i) {
        this->pdata[i] = new char[strlen(v.pdata[i])];
        strcpy(this->pdata[i], v.pdata[i]);
    }
}

void MyVector::add_element(char *el) {
    pdata[size] = new char[strlen(el)];
    strcpy(pdata[size++], el);
    if (size == maxsize) {
        maxsize *= 2;
        resize();
    }
}

bool MyVector::delete_element(int index) {
    if (index >= size || index < 0) {
        return false;
    }

    for (int i = index + 1; i < size; ++i) {
        strcpy(pdata[i - 1], pdata[i]);
    }
    delete pdata[size - 1];
    pdata[(size--) - 1] = nullptr;
    if (size * 2 < maxsize) {
        maxsize /= 2;
        resize();
    }
    return true;
}

char* MyVector::operator[](int i) {
    return pdata[i];
}

void MyVector::sort() {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(pdata[j], pdata[j + 1]) > 0) {
                swapped = true;
                std::swap(pdata[j], pdata[j + 1]);
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int MyVector::find(char *el) {
    if (size == 0) {
        return -1;
    }
    int l = 0;
    int r = size - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if(strcmp(pdata[mid], el) < 0) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (strcmp(pdata[l], el) == 0) {
        return l;
    } else if (strcmp(pdata[r], el) == 0) {
        return r;
    } else {
        return -1;
    }
}


MyVector& MyVector::operator=(const MyVector& v) {
    if(this == &v) {
        return *this;
    }

    for (int i = 0; i < this->size; ++i) {
        delete[] pdata[i];
        pdata[i] = nullptr;
    }
    delete[] pdata;
    pdata = nullptr;

    this->maxsize = v.maxsize;
    this->size = v.size;
    this->pdata = new char* [v.maxsize];
    for (int i = 0; i < size; ++i) {
        this->pdata[i] = new char[strlen(v.pdata[i])];
        strcpy(this->pdata[i], v.pdata[i]);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const MyVector &v) {
    for (int i = 0; i < v.size; ++i) {
        std::cout << v.pdata[i] << ' ';
    }
    return out;
}


