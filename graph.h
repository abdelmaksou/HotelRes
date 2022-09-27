#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include "reservation.h"

using namespace std;

class graph
{
   private:
    vector<vector <double>> map;
   public:
    string result;
    graph();
    const char *cities[5] = {"Paris", "Barcelona", "Cairo", "Berlin", "London"};
    void setMap(vector<vector <double>> map);
    void dijkstra(int src, int dst);
    void printPath(int parent[], int j);
    void printSolution(int src, double dist[], int d, int parent[]);
    double minDistance(double dist[], bool sptSet[]);
};

#endif // GRAPH_H

