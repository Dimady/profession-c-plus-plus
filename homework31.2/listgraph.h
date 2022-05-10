#pragma once
#include <string>
#include <map>
#include "igraph.h"
#include "matrixgraph.h"

class ListGraph : public IGraph
{
private:
    int vertices = 0;
    std::string type = "List";
    std::map<int, std::vector<int>> grph;

public:
    ListGraph();

    ListGraph(IGraph *_oth);

    virtual ~ListGraph();

    std::string getType();

    void AddEdge(int from, int to); // Метод принимает вершины начала и конца ребра и добавляет ребро

    int VerticesCount() const; // Метод должен считать текущее количество вершин

    void GetNextVertices(int vertex, std::vector<int> &vertices) const; // Для конкретной вершины метод выводит в вектор “вершины”
                                                                                    // все вершины, в которые можно дойти по ребру из данной

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const; // Для конкретной вершины метод выводит в вектор “вершины”
                                                                                    // все вершины, из которых можно дойти по ребру в данную
};
