#include "Heap.h"
#include "Heap.cpp"

int main() {
    MinHeap<int> minHeap;
    std::vector<int>v;
    srand(time(0));
    for (int i = 0; i < 100000000; i++)  v.push_back(rand() % 100);

    for (auto it = v.begin(); it != v.end(); it++) minHeap.insert(*it);

    std::cout << "MinHeap content: ";
    minHeap.print();

    std::cout << "Extracted Min: " << minHeap.extractMin() << std::endl;

    std::cout << "MinHeap after extraction: ";
    minHeap.print();

    return 0;
}
