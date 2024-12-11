#include "Heap.h"

// Constructeur
template <typename T>
MinHeap<T>::MinHeap() {
    
}

// Réorganise le tas en remontant un élément
template <typename T>
void MinHeap<T>::heapMontant(int index)
{
    while (index > 0) 
    {
        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex])
        {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
        else {
            break;
        }
    }
}



// Insère une valeur dans le tas
template <typename T>
void MinHeap<T>::insert(T value) 
{
    heap.push_back(value);
    heapMontant(heap.size() - 1);
}
// Réorganise le tas en descendant un élément.
template <typename T>
void MinHeap<T>::heapDescendant(int index)
{
    int size = heap.size();
    while (index < size) 
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) 
        {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest])
        {
            smallest = rightChild;
        }

        if (smallest != index) 
        {
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else 
        {
            break;
        }
    }
}
// Supprime et renvoie la valeur minimale 
template <typename T>
T MinHeap<T>::extractMin() 
{
    if (heap.empty()) {
        throw std::out_of_range("Heap est vide");
    }

    T minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapDescendant(0);

    return minValue;
}

template<typename T>
bool MinHeap<T>::recherher(T value,int index)
{
   
    if (index >= heap.size())
    {
        return false;
    }
  
    
    if (heap[index] > value)
    {
        return false;
    }
      
    if (heap[index] == value)
        return true;
  
        if(!recherher(value, 2 * index + 1)) 
            return recherher(value, 2 * index + 2);
        return true;
}

// Renvoie la valeur minimale sans la supprimer
template <typename T>
T MinHeap<T>::getMin() const
{
    if (heap.empty()) {
        throw std::out_of_range("Heap est vide");
    }
    return heap[0];
}

template<typename T>
void MinHeap<T>::chercherValue(T value)
{
    if (recherher(value, 0))
        std::cout << "la valeur " << value << " existe dans le tas" << std::endl;
    else
        std::cout << "la valeur " << value << " n'existe pas dans le tas" << std::endl;
}

// Affiche le contenu du tas
template <typename T>
void MinHeap<T>::print() const 
{
    for (const auto& value : heap) 
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

// Vérifie si le tas est vide
template <typename T>
bool MinHeap<T>::isEmpty() const {
    return heap.empty();
}
