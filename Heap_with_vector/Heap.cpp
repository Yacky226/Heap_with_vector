#include "Heap.h"

// Constructeur
template <typename T>
MinHeap<T>::MinHeap() = default;

// Réorganise le tas en remontant un élément
template <typename T>
void MinHeap<T>::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
        else {
            break;
        }
    }
}

// Réorganise le tas en descendant un élément.
template <typename T>
void MinHeap<T>::heapifyDown(int index) {
    int size = heap.size();
    while (index < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else {
            break;
        }
    }
}

// Insère une valeur dans le tas
template <typename T>
void MinHeap<T>::insert(T value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

// Supprime et renvoie la valeur minimale 
template <typename T>
T MinHeap<T>::extractMin() {
    if (heap.empty()) {
        throw std::out_of_range("Heap is empty");
    }

    T minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return minValue;
}

// Renvoie la valeur minimale sans la supprimer
template <typename T>
T MinHeap<T>::getMin() const {
    if (heap.empty()) {
        throw std::out_of_range("Heap is empty");
    }
    return heap[0];
}

// Affiche le contenu du tas
template <typename T>
void MinHeap<T>::print() const {
    for (const auto& value : heap) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

// Vérifie si le tas est vide
template <typename T>
bool MinHeap<T>::isEmpty() const {
    return heap.empty();
}
