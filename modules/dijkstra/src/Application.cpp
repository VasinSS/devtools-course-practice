// Copyright 2017 Kozlov Ilya

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include "include/Application.h"
#include "include/Graph.h"

using std::vector;

Application::Application() {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an optimal way calculator application.\n\n" +
        "Pleaseprovide arguments in the following format:\n\n" +

        "  $ " + appname + "<size> <start_node_index>" +
        "<edge1> <edge2> ... <edgeN>\n" +
        "WHERE <edgeN> = <weightN> <nodeIndexA> <nodeIndexB>\n\n" +

        "ATTENTION:\n"
        "\n*All arguments should be unsingned integer values!" +
        "\n*The max value of any argument is " + std::to_string(INF) + "!" +
        "\n*If there is no edge between nodes, the result of optimal way" +
        "between them will be 'inf'" +
        "\n*The number of arguments should be > 2 " +
        "and 2 + n, where the 'n' is a multiple of 3!" +
        "\n*Carefully observe the format where typing the edges!";
}

int Application::ParseInt(const char* arg) {
    int val = std::stoi(arg);
    if ((unsigned int)val > INF) {
        throw(std::string)"ERROR: One of arguments is out of limit";
    }
    return val;
}

vector<vector<unsigned int>> Application::ParseGraph(const int argc,
                                                     const char** argv) {
    const int gr_size = (argc - 3) / 3;
    vector<vector<unsigned int>> res(gr_size);
    for (unsigned int i = 0; i < res.size(); i++) {
        res[i].resize(3);
    }
         int k = 0;
    for (int i = 1; i <= argc - 3; i++) {
        if (i % 3 == 0) {
            res[k][0] = ParseInt(argv[i]);
            res[k][1] = ParseInt(argv[i + 1]);
            res[k][2] = ParseInt(argv[i + 2]);
            k++;
        }
    }
    return res;
}

bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }

    if (argc >= 3 && (argc - 3) % 3 == 0) {
        return true;
    }

    Help(argv[0], "ERROR: Incorrect arguments num.\n\n");
    return false;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    vector<unsigned int> res;
    std::ostringstream stream;


    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.size_ = ParseInt(argv[1]);
        args.start_node_ = ParseInt(argv[2]);
        args.gm_ = ParseGraph(argc, argv);
    }
    catch (std::string& str) {
        return str;
    }
    Graph gr(args.size_);
    for (unsigned int i = 0; i < args.gm_.size(); i++) {
        try {
            gr.AddEdge(args.gm_[i][0], args.gm_[i][1], args.gm_[i][2]);
        }
        catch (std::string& str) {
            return str;
        }
    }
    res = gr.Dijkstra(args.start_node_);
    for (unsigned int i = 0; i < res.size(); i++) {
        if (res[i] == INF) {
            stream << "inf ";
        }
        if (res[i] != INF) {
            stream << res[i] << " ";
        }
        message_ = stream.str();
    }
    message_.pop_back();
    return message_;
}

