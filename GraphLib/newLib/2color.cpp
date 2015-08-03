/*
 * C++ Program to Check whether Graph is a Bipartite using 2 Color Algorithm
 */
#include <iostream>
#include <cstdio>
#define V 4
using namespace std;
/* 
 * A utility function to check if the current color assignment
 * is safe for vertex v  
 */
bool isSafe (int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}
 
/* 
 * A recursive utility function to solve m coloring problem 
 */
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil (graph, m, color, v+1) == true)
                return true;
           color[v] = 0;
        }
    }
    return false;
}
 
/* 
 * This function solves the m Coloring problem using Backtracking.
 */
bool graphColoring(bool graph[V][V], int m) {
    int *color = new int[V];
    for (int i = 0; i < V; i++)
       color[i] = 0;
    if (graphColoringUtil(graph, m, color, 0) == false)
        return false;
    return true;
}
 
/* 
 * Main Contains Menu 
*/
int main() {
    bool graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    bool gr[V][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 2;
    if (graphColoring (graph, m))
        cout<<"The graph 1 is Bipartite"<<endl;
    else
        cout<<"The graph 1 is not Bipartite"<<endl;
    if (graphColoring (gr, m))
        cout<<"The graph 2 is Bipartite"<<endl;
    else
        cout<<"The graph 2 is not Bipartite"<<endl;
    return 0;
}
