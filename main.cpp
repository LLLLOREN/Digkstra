#include <iostream>
#include "Map.h"
int main() {
    Map *Europe = new Map(22);
    node* node0 = new node("Lisbon");
    node* node1 = new node("Madrid");
    node* node2 = new node("Paris");
    node* node3 = new node("London");
    node* node4 = new node("Rome");
    node* node5 = new node("Bern");
    node* node6 = new node("Brussels");
    node* node7 = new node("Amsterdam");
    node* node8 = new node("Copenhagen");
    node* node9 = new node("Berlin");
    node* node10 = new node("Prague");
    node* node11 = new node("Warsaw");
    node* node12 = new node("Vienna");
    node* node13 = new node("Budapest");
    node* node14 = new node("Sarajevo");
    node* node15 = new node("Sofia");
    node* node16 = new node("Skopja");
    node* node17 = new node("Tirane");
    node* node18 = new node("Athens");
    node* node19 = new node("Bucharest");
    node* node20 = new node("Dublin");
    node* node21 = new node("Belfast");

    Europe->addNode(node0);
    Europe->addNode(node1);
    Europe->addNode(node2);
    Europe->addNode(node3);
    Europe->addNode(node4);
    Europe->addNode(node5);
    Europe->addNode(node6);
    Europe->addNode(node7);
    Europe->addNode(node8);
    Europe->addNode(node9);
    Europe->addNode(node10);
    Europe->addNode(node11);
    Europe->addNode(node12);
    Europe->addNode(node13);
    Europe->addNode(node14);
    Europe->addNode(node15);
    Europe->addNode(node16);
    Europe->addNode(node17);
    Europe->addNode(node18);
    Europe->addNode(node19);
    Europe->addNode(node20);
    Europe->addNode(node21);

    Europe->creatEdge(0, 1,75,450);
    Europe->creatEdge(1,0,55,450);
    Europe->creatEdge(1,2,100,1300);
    Europe->creatEdge(1,5,15,1500);
    Europe->creatEdge(2,3,110,450);
    Europe->creatEdge(2,5,35,600);
    Europe->creatEdge(2,12,75,1300);
    Europe->creatEdge(2,6,135,300);
    Europe->creatEdge(2,1,100,1300);
    Europe->creatEdge(3,2,110,450);
    Europe->creatEdge(4,5,75,900);
    Europe->creatEdge(5,4,74,900);
    Europe->creatEdge(5,2,15,600);
    Europe->creatEdge(5,14,25,1100);
    Europe->creatEdge(5,1,45,1500);
    Europe->creatEdge(6,2,225,300);
    Europe->creatEdge(6,7,185,200);
    Europe->creatEdge(6,9,65,800);
    Europe->creatEdge(7,6,125,200);
    Europe->creatEdge(7,8,45,800);
    Europe->creatEdge(7,9,45,700);
    Europe->creatEdge(8,7,45,800);
    Europe->creatEdge(9,7,75 ,700);
    Europe->creatEdge(9,6,35,800);
    Europe->creatEdge(9,10,45,350);
    Europe->creatEdge(9,11,35,900);
    Europe->creatEdge(10,9,55,350);
    Europe->creatEdge(10,12,45,300);
    Europe->creatEdge(10,11,35,850);
    Europe->creatEdge(11,9,35,900);
    Europe->creatEdge(11,19,25,1700);
    Europe->creatEdge(11,10,25,850);
    Europe->creatEdge(12,10,45,300);
    Europe->creatEdge(12,2,75,1300);
    Europe->creatEdge(12,13,45,300);
    Europe->creatEdge(13,12,25,300);
    Europe->creatEdge(13,19,25,900);
    Europe->creatEdge(13,14,15,600);
    Europe->creatEdge(14,5,25,1100);
    Europe->creatEdge(14,15,15,600);
    Europe->creatEdge(14,16,15,500);
    Europe->creatEdge(14,13,25,600);
    Europe->creatEdge(15,14,25,600);
    Europe->creatEdge(15,16,15,200);
    Europe->creatEdge(16,15,15,200);
    Europe->creatEdge(16,17,15,200);
    Europe->creatEdge(16,14,15,500);
    Europe->creatEdge(17,18,55,700);
    Europe->creatEdge(17,16,35,200);
    Europe->creatEdge(18,17,55,700);
    Europe->creatEdge(19,13,25,900);
    Europe->creatEdge(19,11,25,1700);
    Europe->creatEdge(20,21,25,167);
    Europe->creatEdge(21,20,25,167);

//    Europe->showNodes();

    string startCity, endCity;
    cout<<startCity<<endCity<<endl;
    while(1){
        cout<<"Enter a start and destination city: <'quit' to exit>"<<endl;
        cin>>startCity;
        if(startCity == "quit"){
            cout<<"END"<<endl;
            break;
        }
        cin>>endCity;
        if(endCity == "quit"){
            cout<<"END"<<endl;
            break;
        }
        if(!Europe->getStartIndex(startCity)||!Europe->getEndIndex(endCity))
            continue;
        Europe->getStartIndex(startCity);
        Europe->Digkstra();
        Europe->printAns(endCity);
    }
    return 0;
}