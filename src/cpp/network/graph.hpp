#include "nodes.hpp"
#include<iostream>
#include <algorithm>
#include <map>
#include <list>
#include<stack>
#include "../routing/Dijikstra.hpp"
#include "../logs/log.hpp"
#ifndef GRAPH
#define GRAPH
using namespace std;


class Graph
{
    public:
    int vertex;
    map<int ,map<int,int>> adjList; //use extern
     //int->current node, int ->nextHope

    Node *individual_Nodes; //It contains all the information about each nodes


    Graph(int v) :vertex {v}
    {
        //this->vertex=v;
        individual_Nodes=new Node[v]; //Here all individual nodes created
        for(int i=0;i<v;i++)
        {
            individual_Nodes[i].Node_id=i;
        }

    }

    void addEdge(int src,int des,int wt) //Let graph is bidirectional
    {
        adjList[src][des]=wt;
        adjList[des][src]=wt;

       // info[src].Node_id=src;

    }

    
    void printList()
    {

        for(auto x:adjList)

        {
            cout<<x.first<<" ->: ";
            log::out<<x.first<<" ->: ";
            for(auto y:adjList[x.first])
            {
            	log:: out <<"( "<<y.first<<", "<<y.second<<")";
                cout<<"( "<<y.first<<", "<<y.second<<")";
            }
            cout<<endl;
            log::out<<endl;
        }
    }
	
	int findCost(int u,int v)
	{
		return adjList[u][v];
	}
    //here routing table is genrated


};


#endif
