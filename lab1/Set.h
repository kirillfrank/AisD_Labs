#ifndef SET_H
#define SET_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <random>
#include <string>
#include <utility>

template <typename T>
class Set {
private:
    T* data_;
    int size_;
    const int MAX_SIZE = 100;
    static constexpr double EPSILON = 1e-6;

    bool is_equal(const T& a, const T& b) const { return a == b; }

public:
    Set() : size_(0) { data_ = new T[MAX_SIZE]; }

    Set(const T* arr, int arr_size) : Set() {
        for (int i = 0; i < arr_size; ++i) add(arr[i]);
    }

    Set(int count, T min_val, T max_val) : Set() {
        std::mt19937 gen(42);
        for (int i = 0; i < count; ++i) {
            if constexpr (std::is_integral<T>::value) {
                std::uniform_int_distribution<int> dist(static_cast<int>(min_val), static_cast<int>(max_val));
                add(static_cast<T>(dist(gen)));
            }
            else {
                std::uniform_real_distribution<double> dist(static_cast<double>(min_val), static_cast<double>(max_val));
                add(static_cast<T>(dist(gen)));
            }
        }
    }

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

    T operator[](int index) const {
        if (index < 0 || index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    bool contains(const T& value) const {
        for (int i = 0; i < size_; ++i) if (is_equal(data_[i], value)) return true;
        return false;
    }

    void add(const T& value) {
        if (!contains(value) && size_ < MAX_SIZE) data_[size_++] = value;
    }

    void remove(const T& value) {
        for (int i = 0; i < size_; ++i) {
            if (is_equal(data_[i], value)) {
                for (int j = i; j < size_ - 1; ++j) data_[j] = data_[j + 1];
                size_--; return;
            }
        }
    }

    Set& operator+=(const T& value) { add(value); return *this; }
    Set operator+(const T& value) const { Set res = *this; res += value; return res; }

    Set& operator-=(const T& value) { remove(value); return *this; }
    Set operator-(const T& value) const { Set res = *this; res -= value; return res; }

    Set operator+(const Set& other) const {
        Set res = *this;
        for (int i = 0; i < other.size_; ++i) res += other.data_[i];
        return res;
    }

    Set operator-(const Set& other) const {
        Set res = *this;
        for (int i = 0; i < other.size_; ++i) res -= other.data_[i];
        return res;
    }

    Set intersection(const Set& other) const {
        Set res = *this;
        for (int i = 0; i < size_; ++i) if (!other.contains(data_[i])) res -= data_[i];
        return res;
    }

    bool operator==(const Set& other) const {
        if (size_ != other.size_) return false;
        for (int i = 0; i < size_; ++i) if (!other.contains(data_[i])) return false;
        return true;
    }

    bool operator!=(const Set& other) const { return !(*this == other); }

    friend std::ostream& operator<<(std::ostream& os, const Set& s) {
        os << "{";
        for (int i = 0; i < s.size_; ++i) {
            os << s.data_[i];
            if (i < s.size_ - 1) os << ", ";
        }
        os << "}";
        return os;
    }
};

// Вспомогательные функции для сравнения вещественных чисел и вывода пар
template <typename T> bool check_equal(const T& a, const T& b) { return a == b; }
inline bool check_equal(const float& a, const float& b) { return std::abs(a - b) < 1e-6f; }
inline bool check_equal(const double& a, const double& b) { return std::abs(a - b) < 1e-6; }
template <typename T1, typename T2> std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

#endif