#include "Set.h"
#include <iostream>
#include <string>
#include <utility>

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

    return 0;
}