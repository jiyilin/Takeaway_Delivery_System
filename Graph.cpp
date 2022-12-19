#include "Graph.h"
#include <fstream>

using namespace std;

Graph::Graph(int V)
{
    this->vNum = V;
    edges = new list<iPair>[V];
}

Graph::~Graph() = default;

void Graph::insert_edge(int u, int v, int w)
{
    if (u >= 0 && u < vNum && v >= 0 && v < vNum)
    {

        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }
}

void Graph::shortest_path(int start)
{

    vector<unsigned char> visited(vNum, 0);
    vector<int> parent(vNum, -1);
    vector<int> distance(vNum, INT_MAX);

    distance[start] = 0;
    int v_curr = start;
    while (0 == visited[v_curr])
    {

        visited[v_curr] = 1;

        for (auto i = edges[v_curr].begin(); i != edges[v_curr].end(); i++)
        {
            int v_neighbor = (*i).first;
            int weight = (*i).second;

            if ((distance[v_curr] + weight) < distance[v_neighbor])
            {
                distance[v_neighbor] = distance[v_curr] + weight;
                parent[v_neighbor] = v_curr;
            }
        }

        int smallest_dist = INT_MAX;
        for (int i = 0; i < vNum; i++)
        {
            if (!visited[i] && (distance[i] < smallest_dist))
            {
                v_curr = i;
                smallest_dist = distance[i];
            }
        }
    }

    print_shortest_path(distance, parent, start);
}

void Graph::print_shortest_path(const vector<int> &distance, const vector<int> &parent, int start)
{
    for (auto u = distance.size() - 1; u != start && u != -1; u = parent[u])
    {
        key.push_back(u);
    }
    key.push_back(start);
}

void Graph::GainAnswer(std::string From, std::string To)
{
    this->ReadMapList();
    int from = 0;
    int to = 0;
    int flag = 0;
    for (int i = 0; i < map.size(); i++)
    {
        if (flag == 2)
        {
            break;
        }
        if (From == map[i])
        {
            from = i;
            flag++;
        }
        if (To == map[i])
        {
            to = i;
            flag++;
        }
    }
    this->GainList(from, to);
}

void Graph::ReadMapList()
{
    ifstream read;
    read.open("MapList.txt", ios_base::in);
    if (read.is_open() == false)
    {
        return;
    }
    string process;
    while (getline(read, process))
    {
        map.push_back(process);
    }
    read.close();
}

void Graph::GainList(int from, int to)
{
    int start = 0;
    int end = 0;
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] == from)
        {
            start = i;
        }
        else if (key[i] == to)
        {
            end = i;
        }
    }
    if (start < end)
    {
        for (; start <= end; start++)
        {
            answer.push_back(key[start]);
        }
    }
    else
    {
        for (; start >= end; start--)
        {
            answer.push_back(key[start]);
        }
    }
    this->Print();
}

void Graph::Print()
{
    auto search = answer.begin();
    while (search != answer.end())
    {
        // cout << map[*search-1] << endl;
        out.push_back(map[*search]);
        search++;
    }
}

std::list<std::string> MapInterface(std::string From, std::string To)
{
    auto data = ReadDataTxt();
    if (data == nullptr)
    {
        cout << "系统异常，无法启动地图" << std::endl;
    }
    else
    {
        data->shortest_path(0);
        data->GainAnswer(From, To);
        return data->out;
    }
    std::list<std::string> out;
    return out;
}

Graph *ReadDataTxt()
{
    ifstream read;
    read.open("Map.txt", ios_base::in);
    if (read.is_open() == false)
    {
        return nullptr;
    }
    int number;
    int numberLine;
    read >> number >> numberLine;
    auto *data = new Graph(number);
    int first = 0;
    int second = 0;
    int third = 0;
    for (int i = 0; i < numberLine; i++)
    {
        read >> first >> second >> third;
        data->insert_edge(first, second, third);
    }
    read.close();
    return data;
}
