/******************************************************************************
// Name         : Kruskal_algo.cpp.
//  Author      : Ayub Shaikh
//  Roll Number : CS21M515
//  Copyright   : @2022 IIT Madras Lab Assignment-1
//  Description : KRUSKAL'S ALGORITHM
//       Date   :   20-APRIL-2022
*******************************************************************************/
#include <iostream>

#include <algorithm>

#include<vector>

using namespace std;


class EdgeOfGraph{

    public:

    int source;

    int desti;

    int weight;

    EdgeOfGraph(){


    }

    EdgeOfGraph(int src,int des,int wei){

    	source=src;

    	desti=des;

    	weight=wei;

    }

};


bool compare(EdgeOfGraph e1,EdgeOfGraph e2){

    return e1.weight<e2.weight;

}


int findparent(int i,int* parent ){

    if(parent[i]==i)

        return i;

    return findparent(parent[i],parent);

}


class KrushkalMinSpanningTree{

    public:

    int edges,nodes;

    EdgeOfGraph* edgesOf;


    KrushkalMinSpanningTree(int nd,int edg){

        this->nodes=nd;

        this->edges=edg;

        edgesOf=new EdgeOfGraph[edg];

        cout<<"\t ENTER VERTICES AND WEIGHT OF EDGE SEPERATED BY SPACE- EXAMPLE LIKE THIS 0 1 2 (0 --> 1 vERICES  AND 2 IS WEIGHT) \n";
        for(int i=0;i<edg;i++)

        {

            int x,y,w;

            cout<<"\t ENTER VERTICES AND WEIGHT OF EDGE "<<i+1<<" :	";

            cin>>x>>y>>w;

            EdgeOfGraph e(x,y,w);

            edgesOf[i]=e;

        }

    }


    EdgeOfGraph* unionfind(){

        int* parent=new int[nodes];

        for(int i=0;i<nodes;i++){

            parent[i]=i;

        }

        sort(edgesOf, edgesOf+edges,compare);



        EdgeOfGraph* output;

        output=new EdgeOfGraph[nodes-1];

        int count=0,i=0;

        while(count!=nodes-1){

        	EdgeOfGraph c=edgesOf[i];

            int sourceparent=findparent(edgesOf[i].source,parent);

            int desparent=findparent(edgesOf[i].desti,parent);

            if(sourceparent!=desparent){

                output[count]=c;

                parent[sourceparent]=desparent;

                count++;

            }

            i++;

        }

        int sum=0;

        cout<<endl<<"\t -------(KRUSKAL) MINIMUM SPANNING TREE-------\n";

       for(int index=0;index <nodes-1; index++){

           cout<<"\t  "<<output[index].source<<"	"<<output[index].desti<<"	"<<output[index].weight<<endl;

           sum+=output[index].weight;

       }

       cout<<"\n \t WEIGHT OF MINIMUM SPANNING TREE IS=> "<<sum;

       return output;

    }

};


int main(){

    int nodes,edges;


      cout << "-----------------------------------------------------------------" << endl;
      cout << "------------     LAB Programming Assignment-3 ----------------------" << endl;
      cout << "             Submitted by => Ayub Shaikh,  Roll number: CS21M515  " << endl;
      cout << "           KRUSKAL'S ALGORITHM in C++ "  << endl;
      cout << "--------------------------------------------------------------" << endl;
      cout<<"\t KRUSKAL'S ALGORITHM\n \t ENTER NUMBER OF VERTICES :	";

    cin>>nodes;

    cout<<"\t ENTER NUMBER OF EDGEES :	";

    cin>>edges;

    KrushkalMinSpanningTree kruskalGraph(nodes,edges);

    EdgeOfGraph* mst=kruskalGraph.unionfind();

    cout << "\n---------------------------------------------------- ------" << endl;
       cout << "-------------------------END Thank You!-----------------------" << endl;
       cout << "-----------------------------------------------------------" << endl;
    int exit;
    cout << "\t press any number to exit: ";
    cin >> exit;
    if(exit>0){
        return 0;
    }

}

