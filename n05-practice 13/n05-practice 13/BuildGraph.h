#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

// ����� �����
class Edge {
public:
    int src, dest, weight;
    void setValues(int src, int dest, int weight);
};

// ����
class Graph {
public:

    // V - ���������� ������, E - ���������� �����
    int V, E;

    Edge* edge;
   
};

// ������� ���� � V ��������� � E �������
Graph* createGraph(int V, int E);


// ������������� ��� ���������� ������� ������
class subset {
public:
    int parent;
    int rank;
};

// ������� ������ ��������� ��� �������� i
int find(subset subsets[], int i);

// �������, ������������ ��� ��������� x � y
void Union(subset subsets[], int x, int y);


// ���������� ��� ����� �� ����
int myComp(const void* a, const void* b);


// �������� ������������ ��������� ������ �� ��������� �������� 
void KruskalMST(Graph* graph);

