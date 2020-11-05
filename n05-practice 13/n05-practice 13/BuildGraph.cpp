#include "BuildGraph.h"
using namespace std;

void Edge::setValues(int src, int dest, int weight) {
    this->src = src;
    this->dest = dest;
    this->weight = weight;
}

Graph* createGraph(int V, int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

int find(subset subsets[], int i){
    // поиск корня и его установка как родителя для i
    if (subsets[i].parent != i)
        subsets[i].parent
        = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Прикрепление дерева меньшего ранга под корень дерева высшего ранга
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // Если ранги совпадают, пометить один как корневой и увеличить на 1
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b){
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight - b1->weight;
}

void KruskalMST(Graph* graph){
    int V = graph->V;
    Edge* result = new Edge[V]; // Хранит результат создания древа
    int e = 0; // Индекс для result[]
    int i = 0; // Индекс для сортированных ребер

    //Шаг 1: Сортирует все ребра по неубыванию по весу
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
        myComp);

    subset* subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        // Шаг 2: Выбор наименьшего ребра
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }


    cout << "Following are the edges in the constructed "
        "MST\n";
    int minimumCost = 0;
    for (int j = 0; j < e; ++j)
    {
        cout << result[j].src + 1 << " -- " << result[j].dest  + 1
            << " == " << result[j].weight << endl;
        minimumCost = minimumCost + result[j].weight;
    }
    cout << "Minimum Cost Spanning Tree: " << minimumCost
        << endl;
}