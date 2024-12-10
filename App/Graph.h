#pragma once
#include <vector>
#include <qpoint.h>

struct Edge {
    int first;
    int second;
    double weight;
};

struct Vertex {
    int id;
    int posX;
    int posY;
};

class Graph {

public:
    Graph();
    ~Graph();
    void buildGraph();
    bool isPointInsideCircle(const QPoint& point, const QPoint& center, int radius) const;
    bool isOverlappingWithExistingCircles(const QPoint& newCircle) const;
    int getVertexListLen();
    int getEdgeListLen();
    int getVisitedEdgeListLen();
    std::vector<Edge> getEdgeList() const;
    std::vector<Vertex> getVertexList() const;
    Edge getEdge(int id);
    Vertex getVertex(int id);
    int getStartEdge() const;
    int getEndEdge() const;
    void setStartEdge(int id);
    void setEndEdge(int id);


protected:
    void addVertex(int posX, int posY);
    void addEdge(int first, int second, double weight);
    void addEdge(Edge edge);
    void addEdgeToVisited(int id);
    double calcDistance(int first, int second);
    bool isVisitedEdge(int id);


private:
    std::vector<Vertex> vertexList;
    std::vector<Edge> edgeList;
    std::vector<int> visitedEdgeList;
    int startEdge;
    int endEdge;
};