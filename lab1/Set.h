#ifndef SET_H
#define SET_H
#include <iostream>

template <typename T>
class Set {
private:
    T* data_;
    int size_;
    const int MAX_SIZE = 100;

public:
    Set() : size_(0) { data_ = new T[MAX_SIZE]; }

    ~Set() { delete[] data_; }

    Set(const Set& other) : size_(other.size_) {
        data_ = new T[MAX_SIZE];
        for (int i = 0; i < size_; ++i) data_[i] = other.data_[i];
    }

    Set& operator=(const Set& other) {
        if (this != &other) {
            size_ = other.size_;
            for (int i = 0; i < size_; ++i) data_[i] = other.data_[i];
        }
        return *this;
    }
};

#endif