//
// Created by 罗咏佳 on 2019/12/5.
//

#ifndef DIGKSTRA_NODE_H
#define DIGKSTRA_NODE_H
#define INFINITE 0xFFFFFFFF

#include <string>
using namespace std;
class node {
public:
    node(string name = "0");
    unsigned int minFee;
    unsigned int minDistance;
    string name;
};


#endif //DIGKSTRA_NODE_H
