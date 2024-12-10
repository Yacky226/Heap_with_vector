#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

// Classe pour le tas binaire minimum
template <typename T>
class MinHeap {
private:
   
    std::vector<T> heap; // Conteneur pour stocker les éléments du tas

    // Réorganise le tas en remontant un élément
    void heapMontant(int index);

    // Réorganise le tas en descendant un élément
    void heapDescendant(int index);

public:
    MinHeap(); // Constructeur

    // Insère une valeur dans le tas
    void insert(T value);

    // Supprime et renvoie la valeur minimale
    T extractMin();

    // Renvoie la valeur minimale  sans la supprimer
    T getMin() const;

    // Affiche le contenu du tas
    void print() const;

    // Vérifie si le tas est vide
    bool isEmpty() const;
};


