#include "Heap.h"
#include "Heap.cpp"

int main() {
    MinHeap<int> minHeap;

    // Insère des valeurs dans le tas
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(30);

    std::cout << "MinHeap content: ";
    minHeap.print();

    std::cout << "Extracted Min: " << minHeap.extractMin() << std::endl;

    std::cout << "MinHeap after extraction: ";
    minHeap.print();

    return 0;
}
