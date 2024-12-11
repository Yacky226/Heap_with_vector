#include "Heap.h"
#include "Heap.cpp"
#include <chrono>
int main() {
    MinHeap<int> minHeap;
    std::vector<int>v;
    srand(time(0));
    // Capture le temps au début
    auto debut = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++)  v.push_back(rand() % 100);
    for (auto it = v.begin(); it != v.end(); it++) minHeap.insert(*it);
    // Capture le temps à la fin
    auto fin = std::chrono::high_resolution_clock::now();

    // Calcul de la durée en secondes
    auto duree = std::chrono::duration_cast<std::chrono::seconds>(fin - debut);

    std::cout << "Temps d'execution : " << duree.count() << " seconds" << std::endl;
    
   

    minHeap.chercherValue(5);
    minHeap.print();

    std::cout << "Extracted Min: " << minHeap.extractMin() << std::endl;



    return 0;
}
