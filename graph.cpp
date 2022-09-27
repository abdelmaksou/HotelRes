#include "graph.h"
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

#define V 5

graph::graph()
{
    result = "";
    map = {{0, 8, 34.7, 11.7, 0}, {8, 0, 31, 16.3, 11.2}, {34.7, 31, 0, 0, 37.9}, {11.7, 16.3, 29.2, 0, 12.9}, {3.5, 11.2, 37.9, 12.9, 0}};
}

void graph::setMap(vector<vector <double>> map)
{
    this->map = map;
}


double graph::minDistance(double dist[],
                bool sptSet[])
{

    double min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false &&
                dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void graph::printPath(int parent[], int j)
{

    if (parent[j] == - 1)
    {
        return;
    }
    graph::printPath(parent, parent[j]);
    string r = string(cities[j]);
    result += " " + r;
    Reservation::details = "The flight will go through " + QString::fromStdString(result) ;

}

void graph::printSolution(int src, double dist[], int d, int parent[])
{
    ostringstream distt;
    distt << fixed;
    distt << setprecision(2);
    distt << dist[d];
    string disttt = distt.str();
    QString dddd = QString::fromStdString(disttt);
    Reservation::from = cities[src];
    Reservation::to=cities[d];
    Reservation::singleNO= dddd.toDouble()*111;
    Reservation::doubleNo= Reservation::singleNO+0.5*Reservation::singleNO;
    Reservation::tripleNO= Reservation::doubleNo+0.5*Reservation::doubleNo;
    result += string(cities[src]) + " -> " + string(cities[d]) + " " + disttt + " " + string(cities[src]);
    graph::printPath(parent, d);
}

void graph::dijkstra(int src, int dst)
{

    double dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;
    parent[src] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && map[u][v] &&
                dist[u] + map[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + map[u][v];
            }
    }
    graph::printSolution(src, dist, dst, parent);
}
