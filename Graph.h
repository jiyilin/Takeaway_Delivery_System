#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

using iPair = pair<int, int>;

class Graph
{
public:
    std::list<std::string> out;
    Graph(int V);
    ~Graph();
    void insert_edge(int x, int y, int weight);
    void shortest_path(int start);
    void print_shortest_path(const vector<int> &distance, const vector<int> &parent, int start);
    void GainAnswer(std::string From, std::string To);
    void ReadMapList();
    void GainList(int from, int to);
    void Print();

private:
    int vNum;
    list<iPair> *edges;
    vector<long long> key;
    vector<string> map;
    list<long long> answer;
};

std::list<std::string> MapInterface(std::string From, std::string To);
Graph *ReadDataTxt();

#endif // !GRAPH_H
