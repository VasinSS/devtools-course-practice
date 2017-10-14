// Copyright 2017 Kalinin Vladimir & Kozlov Ilya

#ifndef MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
#define MODULES_DIJKSTRA_INCLUDE_GRAPH_H_

#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using std::pair;
using std::vector;

const unsigned int INF = 1000000;

class Graph {
 public:
    Graph();
    explicit Graph(const size_t _size);
    void AddEdge(const unsigned int _weight,
        const size_t _node_A,
        const size_t _node_B);
    vector<unsigned int> Dijkstra(size_t _start_n);
    bool IsConnect(const size_t _node_A, const size_t _node_B);
    size_t GetSize();
 protected:
    class Edge :public pair<unsigned int, unsigned int> {
     public:
        unsigned int weight = first;
        unsigned int connection = second;
    };
    vector< vector<Edge>> graph_;
    size_t size_;
};

#endif  // MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
