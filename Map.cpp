//
// Created by 罗咏佳 on 2019/12/5.
//

#include "Map.h"
Map::Map(unsigned int numOfNode) {
    sumOfNode = numOfNode;
    countCity = 0;
    nodes = new node[sumOfNode];
    feeMatrix = new unsigned int[sumOfNode*sumOfNode];
    distanceMatrix = new unsigned int[sumOfNode*sumOfNode];
    startCityIndex = -1;
    endCityIndex = -1;
    //数组初始化
    for(int i = 0; i < sumOfNode*sumOfNode; i++){
        feeMatrix[i] = INFINITE;
        distanceMatrix[i] = INFINITE;
    }
}
Map::~Map() {
    delete[] nodes;
    delete[] feeMatrix;
    delete[] distanceMatrix;
}

bool Map::addNode(node *pNode) {
    nodes[countCity].name = pNode->name;
    nodes[countCity].minFee = pNode->minFee;
    nodes[countCity].minDistance = pNode->minDistance;
    countCity++;

    return true;
}

bool Map::creatEdge(int node1, int node2, unsigned int fee, unsigned int distance) {
    feeMatrix[node1*sumOfNode + node2] = fee;
    distanceMatrix[node1*sumOfNode + node2] = distance;

    return true;
}

void Map::showNodes() {
    cout<<"All the cities in this county:"<<endl;
    for(int i = 0; i < sumOfNode; i++){
        cout<<nodes[i].name<<" ";
    }
    cout<<"fee"<<endl;
    for(int i = 0; i < sumOfNode; i++){
        for(int j = 0; j < sumOfNode; j++){
            if(feeMatrix[i*sumOfNode+j] == INFINITE)
                cout<<"Inf"<<" ";
            else
                cout<<feeMatrix[i*sumOfNode+j]<<" ";
        }
        cout<<endl;
    }
    cout<<"distance:"<<endl;
    for(int i = 0; i < sumOfNode; i++){
        for(int j = 0; j < sumOfNode; j++){
            if(distanceMatrix[i*sumOfNode+j] == INFINITE)
                cout<<"Inf"<<" ";
            else
                cout<<distanceMatrix[i*sumOfNode+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Map::reset() {
    for(int i = 0; i < sumOfNode; i++){
        nodes[i].minDistance = INFINITE;
        nodes[i].minFee = INFINITE;
    }
}
bool Map::getStartIndex(string name) {
    for(int i = 0; i < sumOfNode; i++){
        if(nodes[i].name == name){
            startCityIndex = i;
            return true;
        }
    }
    if(startCityIndex == -1){
        cout<<"Wrong start city."<<endl;
        return false;
    }
}
bool Map::getEndIndex(string name) {
    for(int i = 0; i < sumOfNode; i++){
        if(nodes[i].name == name){
            endCityIndex = i;
            return true;
        }
    }
    if(endCityIndex == -1){
        cout<<"Wrong destination city."<<endl;
        return false;
    }
}
void Map::Digkstra(){
    reset();

    bool* vis = new bool[sumOfNode];
    for(int i = 0; i < sumOfNode; i++){
        vis[i] = false;
    }

    nodes[startCityIndex].minFee = 0;
    nodes[startCityIndex].minDistance = 0;
    vis[startCityIndex] = true;

    for(int i = 0; i < sumOfNode; i++){
        nodes[i].minFee = feeMatrix[startCityIndex * sumOfNode + i];
        nodes[i].minDistance = distanceMatrix[startCityIndex*sumOfNode+i];
    }
    //fee
    for(int i = 1; i < sumOfNode; i++){
        int minIndex = -1;
        unsigned int MIN = INFINITE;
        for(int j = 0; j < sumOfNode; j++){
            if(!vis[j] && nodes[j].minFee<MIN){
                minIndex = j;
                MIN = nodes[j].minFee;
            }
        }
        //如果没有，跳出
        if(minIndex == -1)
            break;

        vis[minIndex] = true;

        for(int v = 0; v < sumOfNode; v++){
            if((feeMatrix[minIndex*sumOfNode + v]!=INFINITE)&&(MIN + feeMatrix[minIndex*sumOfNode + v]) < nodes[v].minFee) {
                nodes[v].minFee = MIN + feeMatrix[minIndex * sumOfNode + v];
                nodes[v].minDistance = nodes[minIndex].minDistance + distanceMatrix[minIndex * sumOfNode + v];
            }
        }
    }

// //   dis
//    for(int i = 0; i < sumOfNode; i++){
//        vis[i] = false;
//    }
//    vis[startCityIndex] = true;
//    for(int i = 0; i < sumOfNode; i++){
//        int minIndex = -1;
//        unsigned int MIN = INFINITE;
//        for(int j = 0; j < sumOfNode; j++){
//            if(!vis[j] && nodes[j].minDistance<MIN){
//                minIndex = j;
//                MIN = nodes[j].minDistance;
//            }
//        }
//
//        cout<<minIndex<<endl;
//        if(minIndex == -1)
//            return;
//
//        vis[minIndex] = true;
//
//        for(int v = 0; v < sumOfNode; v++){
//            if((distanceMatrix[minIndex*sumOfNode + v]!=INFINITE)&&(MIN + distanceMatrix[minIndex*sumOfNode + v]) < nodes[v].minDistance){
//                nodes[v].minDistance = MIN + distanceMatrix[minIndex*sumOfNode+v];
//                nodes[v].minFee = nodes[minIndex].minFee + feeMatrix[minIndex*sumOfNode+v];
//             }
//        }
//    }
}

void Map::printAns(string name) {
    if(endCityIndex == -1){
        cout<<"Wrong input"<<endl;
        return;
    }else{
        if(nodes[endCityIndex].minFee!=INFINITE){
            cout<<"The cheapest route from "<<nodes[startCityIndex].name<<" to "<<nodes[endCityIndex].name<<endl;
            cout<<"costs "<<nodes[endCityIndex].minFee<<" euros and spans "<<nodes[endCityIndex].minDistance<<" kilometers"<<endl;
        }else{
            cout<<"There is no route from "<<nodes[startCityIndex].name<<"to "<<nodes[endCityIndex].name<<"."<<endl;
        }
        //dis first
//    if(nodes[endCityIndex].minFee!=INFINITE){
//        cout<<"distance first"<<endl;
//        cout<<nodes[endCityIndex].minFee<<" dis "<<nodes[endCityIndex].minDistance<<endl;
//    }else{
//        cout<<"There is no route from Rome to Dublin."<<endl;
//    }
    }

}