//============================================================================
// Name        : Prims.cpp
// Author      : Ayub Shaikh - CS21M515
// Roll Number : CS21M515
// Copyright   : Lab Assignment - Your copyright notice- IITM
// Description : Prims Algo
// Date   :   19-APRIL-2022

//   			TIME COMPLEXITY: O(V^2)
//============================================================================
//
//#include <iostream>
//using namespace std;
//
//int main() {
//
//	return 0;
//}


#include<bits/stdc++.h>
using namespace std;

#define vertices 5		//No of vertices
#define vector1 6
#define vector2 6

//#define vertices 5		//No of vertices
#define vector3 5
#define vector4 5

int sumofWightMinSpanTree; //  Weight of Minimum Spanning Tree

int getVertexWithMinDistance(vector<int>& valueOfTree,vector<bool>& visitedMinSpanTree)
{
	int minimum = INT_MAX;
	int vertexOfGraph;
	for(int index =0; index <vertices; ++index)
	{
		if(visitedMinSpanTree[index]==false && valueOfTree[index] < minimum)
		{
			vertexOfGraph = index;
			minimum = valueOfTree[index];
		}
	}
	return vertexOfGraph;
}

void primsMinimumSpaningTree(int graph[vertices][vertices], int count)
{
	sumofWightMinSpanTree = 0;
	int parentMST[vertices];		//Stores MST
	vector<int> value(vertices,INT_MAX);	//Used for edge relaxation
	vector<bool> setMST(vertices,false);	// if TRUE -> Vertex is included in MST

	//Assuming start point as Node=> 0
	parentMST[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st


	for(int i=0;i<vertices-1;++i)
	{
		//Select best Vertex by applying greedy method
		int U = getVertexWithMinDistance(value,setMST);
		setMST[U] = true;	//Include new Vertex in MST

		//Relax adjacent vertices (not yet included in MST)
		for(int indx=0; indx < vertices; ++indx)
		{

			if(graph[U][indx]!=0 && setMST[indx]==false && graph[U][indx]<value[indx])
			{
				value[indx] = graph[U][indx];
				parentMST[indx] = U;
			}
		}
	}

	cout<<" FOr Adjecency Matrix:=> "<< count <<"      \n";
	cout<<"Vertex: "<<"  "<<" Edge     \n";
	// Here Printing the Minimum Spanning Tree
	for(int i=1;i < vertices ;++i){
		cout<<"U->Vertex: "<<parentMST[i]<<"->"<<i<<"  weight = "<<graph[parentMST[i]][i]<<"\n";


		 sumofWightMinSpanTree = sumofWightMinSpanTree + graph[parentMST[i]][i];

	}

	cout<<"Weight of Minimum Spanning Tree is: "<<"->"<< sumofWightMinSpanTree <<"\n";
	cout<<"----------------------------------------------------------------   \n";
}

int main()
{


	/*int graphforPrims[vector1][vector2] = { {0, 10, 6, 0, 0, 0},
						{100, 0, 6, 3, 10, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 10, 8, 2, 0, 7}
						{0, 0, 0, 3, 7, 0}};*/


	 // Adjecency Matrix:=> 1    ;
	int graphforPrims[vector3][vector4] =	{{0, 0, 3, 0, 0},
	                                {0, 0, 10, 4, 0},
	                                {3, 10, 0, 2, 6},
	                                {0, 4, 2, 0, 1},
	                                {0, 0, 6, 1, 0},
	                                };

	 // Adjecency Matrix:=> 2    ;
	int graph_2_forPrims[vector3][vector4] =	{{0, 10, 0, 30, 100},
	                                {10, 0, 50, 0, 0},
	                                {0, 50, 0, 20, 10},
	                                {30, 0, 20, 0, 60},
	                                {100, 0, 10, 60, 0},
	                                };
    cout << "-----------------------------------------------------------------" << endl;
    cout << "-------LAB Programming Assignment-1 ----------" << endl;
    cout << "        Submitted by => Ayub Shaikh,  Roll number: CS21M515  " << endl;
    cout << "------- Prims Minimum Spanning in C++ programm----------" << endl;
    cout << "-----------------------------------------------------------------" << endl;

	primsMinimumSpaningTree(graphforPrims, 1);

	primsMinimumSpaningTree(graph_2_forPrims, 2);




	 cout << "\n---------------------------------------------------- ------" << endl;
	    cout << "----------------------END Thank You!-----------------------" << endl;
	    cout << "-----------------------------------------------------------" << endl;
	int exit;
	     cout << "press any number to exit: ";
	     cin >> exit;
	     if(exit>0){
	        return 0;
	     }


}


