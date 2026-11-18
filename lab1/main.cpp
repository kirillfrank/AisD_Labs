#include "Set.h"
#include <iostream>
#include <string>
#include <utility>

template <typename T>
bool is_subset(const T* arr1, int size1, const T* arr2, int size2) {
    Set<T> set1(arr1, size1);
    Set<T> set2(arr2, size2);
    return (set1 - set2) == Set<T>();
}

int main() {
    std::cout << "=== int ===\n";
    Set<int> s1(5, 1, 10);
    std::cout << "Random set: " << s1 << "\n";
    s1 += 55;
    std::cout << "After += 55: " << s1 << "\n";
    s1 -= 55;
    std::cout << "After -= 55: " << s1 << "\n";

    std::cout << "\n=== float ===\n";
    Set<float> s_float(3, 1.0f, 5.0f);
    std::cout << "Set: " << s_float << "\n";

    std::cout << "\n=== string ===\n";
    std::string words[] = { "apple", "banana", "apple" };
    Set<std::string> s_str(words, 3);
    std::cout << "Set: " << s_str << "\n";

    std::cout << "\n=== pair ===\n";
    std::pair<int, double> pairs[] = { {1, 1.5}, {2, 2.5} };
    Set<std::pair<int, double>> s_pair(pairs, 2);
    std::cout << "Set: " << s_pair << "\n";

    std::cout << "\n=== exception ===\n";
    try {
        std::cout << s1[100] << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    std::cout << "\n=== Task ===\n";
    int a1[] = { 1, 2, 3 };
    int a2[] = { 3, 1, 2, 4, 5 };
    int a3[] = { 1, 2, 6 };

    std::cout << "Is {1,2,3} in {3,1,2,4,5}? " << (is_subset(a1, 3, a2, 5) ? "Yes" : "No") << "\n";
    std::cout << "Is {1,2,3} in {1,2,6}? " << (is_subset(a1, 3, a3, 3) ? "Yes" : "No") << "\n";

    return 0;
}