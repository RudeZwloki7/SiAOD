#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

// Ребро графа
class Edge {
public:
    int src, dest, weight;
    void setValues(int src, int dest, int weight);
};

// Граф
class Graph {
public:

    // V - количество вершин, E - количество ребер
    int V, E;

    Edge* edge;
   
};

// Создать граф с V вершинами и E ребрами
Graph* createGraph(int V, int E);


// Подмоножество для реализации функции поиска
class subset {
public:
    int parent;
    int rank;
};

// Функция поиска множества для элемента i
int find(subset subsets[], int i);

// Функция, объединяющая два множества x и y
void Union(subset subsets[], int x, int y);


// Сравнивает два ребра по весу
int myComp(const void* a, const void* b);


// Создание минимального остовного дерева по алгоритму Краскала 
void KruskalMST(Graph* graph);

