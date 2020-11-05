// n05-practice 13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "BuildGraph.h"

using namespace std;

int main()
{
   
    int V; // Number of vertices in graph
    int E; // Number of edges in graph
    cout << "Enter the number of VERTICES and EDGES in graph:" << endl;
    cin >> V >> E;
    Graph* graph = createGraph(V, E);

    cout << "Enter the source, destination and weigth of every edge:" << endl;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph->edge[i].setValues(a - 1, b - 1, c);
    }
 
    /* TEST DATA
    
    graph->edge[0].setValues(0, 1, 7);
    graph->edge[1].setValues(0, 3, 2);
    graph->edge[2].setValues(0, 5, 4);
    graph->edge[3].setValues(1, 2, 1);
    graph->edge[4].setValues(1, 3, 2);
    graph->edge[5].setValues(2, 3, 2);
    graph->edge[6].setValues(2, 4, 3);
    graph->edge[7].setValues(3, 4, 6);
    graph->edge[8].setValues(3, 5, 1);
    graph->edge[9].setValues(4, 5, 8);
    
    */
    


    // Function call

    KruskalMST(graph);

    return 0;
}
