// Copyright 2017 Kalinin Vladimir & Kozlov Ilya

#include "include/Graph.h"
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using std::string;
using std::size_t;
using std::vector;
using std::pair;

Graph::Graph() :size_(0) {}

Graph::Graph(const size_t _size) : size_(_size) {
    if (size_ > INF) {
        throw(string)"ERROR: One of arguments is out of limit";
    }
    graph_.resize(size_);
    for (size_t i = 0; i < size_; i++) {
        graph_[i].resize(size_);
        for (size_t j = 0; j < size_; j++) {
            if (i != j) {
                graph_[i][j].weight = INF;
                graph_[i][j].connection = j;
            } else if (i == j) {
                    graph_[i][j].weight = 0;
                    graph_[i][j].connection = j;
            }
        }
    }
}

void Graph::AddEdge(const unsigned int _weight,
                    const size_t _node_A,
                    const size_t _node_B) {
    if (size_ <= _node_A) {
        throw(string)"ERROR: Forbidden index of node A";
    }
    if (size_ <= _node_B) {
        throw(string)"ERROR: Forbidden index of node B";
    }
    if (_node_A == _node_B) {
        throw(string)"ERROR: The graph is not able to have cycles";
    }
    if (INF < _node_A || INF < _node_B || INF < _weight) {
        throw(string)"ERROR: One of arguments is out of limit";
    }
    graph_[_node_A][_node_B].weight = _weight;
    graph_[_node_B][_node_A].weight = _weight;
}

bool Graph::IsConnect(const size_t _node_A, const size_t _node_B) {
    if (size_ <= _node_A) {
        throw(string)"ERROR: Forbidden index of node A";
    }
    if (size_ <= _node_B) {
        throw(string)"ERROR: Forbidden index of node B";
    }
    if (_node_A == _node_B) {
        throw(string)"ERROR: The graph is not able to have cycles";
    }
    if (graph_[_node_A][_node_B].weight == INF) {
        return 0;
    }
    return 1;
}

vector<unsigned int> Graph::Dijkstra(size_t _start_n) {
    if (_start_n >= size_) {
        throw(string)"ERROR: Forbidden index of start node";
    }

    const int selected = -1;
    const int s = _start_n;
    const int n = size_;
    vector<unsigned int> d(n, INF), p(n);
    vector<bool> u(n);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = selected;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == selected || d[j] < d[v])) {
                v = j;
            }
        }
        if (d[v] == INF) {
            break;
        }
        u[v] = true;
        for (size_t j = 0; j < size_; j++) {
            int to = graph_[v][j].connection,
                len = graph_[v][j].weight;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    return d;
}

size_t Graph::GetSize() {
    return size_;
}
