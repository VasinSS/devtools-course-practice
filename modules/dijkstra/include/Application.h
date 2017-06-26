// Copyright 2017 Kozlov Ilya

#ifndef MODULES_DIJKSTRA_INCLUDE_APPLICATION_H_
#define MODULES_DIJKSTRA_INCLUDE_APPLICATION_H_

#include <string>
#include "include/Graph.h"


class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    int parseInt(const char* arg);
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int start_node_;
        int size_;
        int connected_nodes_;
    } Arguments;
    typedef struct {
        int weight_;
        int start_;
        int end_;
    } Connection;
};
#endif  // #ifndef MODULES_DIJKSTRA_INCLUDE_APPLICATION_H_


