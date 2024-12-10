#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

// Classe pour le tas binaire minimum
template <typename T>
class MinHeap {
private:
   
    std::vector<T> heap; // Conteneur pour stocker les �l�ments du tas

    // R�organise le tas en remontant un �l�ment
    void heapMontant(int index);

    // R�organise le tas en descendant un �l�ment
    void heapDescendant(int index);

public:
    MinHeap(); // Constructeur

    // Ins�re une valeur dans le tas
    void insert(T value);

    // Supprime et renvoie la valeur minimale
    T extractMin();

    // Renvoie la valeur minimale  sans la supprimer
    T getMin() const;

    // Affiche le contenu du tas
    void print() const;

    // V�rifie si le tas est vide
    bool isEmpty() const;
};


