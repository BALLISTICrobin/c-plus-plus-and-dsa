#include <iostream>
#include <set>

int main() {
    std::set<int> mySet;

    // Insert elements
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(4);

    // Iterate and print elements (they will be in increasing order)
    for (int elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
