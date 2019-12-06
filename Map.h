//
// Created by 罗咏佳 on 2019/12/5.
//

#ifndef DIGKSTRA_MAP_H
#define DIGKSTRA_MAP_H

#include <iostream>
#include "node.h"
using namespace std;


class Map{
private:
    unsigned int sumOfNode;     //总共顶点数量
    unsigned int countCity;     //已输入顶点
    node* nodes;                //存储所有的顶点
    unsigned int *feeMatrix;    //存储所有顶点之间费用
    unsigned int *distanceMatrix;   //存储所有顶点之间距离
    int startCityIndex;             //起点城市标号
    int endCityIndex;

public:
    Map(unsigned int numOfNode);
    ~Map();
    bool addNode(node *pNode);
    bool creatEdge(int node1, int node2, unsigned int fee, unsigned int distance);
    void showNodes();
    void reset();
    bool getStartIndex(string name);
    bool getEndIndex(string name);
    void Digkstra();
    void printAns(string name);

};

#endif //DIGKSTRA_MAP_H
