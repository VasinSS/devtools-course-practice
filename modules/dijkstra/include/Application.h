// Copyright 2017 Kozlov Ilya

#ifndef MODULES_DIJKSTRA_INCLUDE_APPLICATION_H_
#define MODULES_DIJKSTRA_INCLUDE_APPLICATION_H_

#include <string>
#include <vector>
#include "include/Graph.h"


class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    vector<vector<unsigned int>> ParseGraph(const int argc, const char** argv);
    int ParseInt(const char* arg);
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int size_;
        int start_node_;
        std::vector <std::vector<unsigned int>> gm_;
    } Arguments;
};
#endif  // MODULES_DIJKSTRA_INCLUDE_APPLICATION_H_
