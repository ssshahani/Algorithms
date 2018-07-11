/*
 * Djkstras.cpp
 *
 *  Created on: 11-Jul-2018
 *      Author: Sahil S
 */

//Shortest Path
// The program is for adjacency matrix representation of the graph

#include <stdio.h>
#include <limits.h>
#include <cstdio>
using namespace std;

// Number of vertices in the graph
#define V 9

int minimumPath(int dist[], bool sptSET[]){
	int min = INT_MAX, min_idx;
	for(int v =0; v<V; v++){
		if((sptSET[v] == false) && dist[v] <= min)
			min = dist[v], min_idx = v;
	}
	return min_idx;
}

void printSolution(int dist[]){
	printf("Distance from Source 0 of all vertices: \n");
		for(int i = 1; i<V; i++){
			printf("\n Distance from Vertex %d  is %d",i, dist[i]);
		}
}
//Time Complexity: Quadratic O(n^2)
void dijkstra(int graph[V][V], int src){
	// array tp store if vertices are vistited or not
	bool sptSET[V];

	//array to maintain distances from source
	int dist[V];

	//Initializes all distances to INF, and sets all flags to false
	for(int i = 0; i< V; i++){
		dist[i] = INT_MAX,sptSET[i] = false;
	}

	//Setting the source distance
	dist[src] = 0;

	int count;
	for(count = 0; count < V-1; count++){

		// finds the minimum path which is untouched still
		int u = minimumPath(dist,sptSET);

		//sets the flag of the minimum vertex to true
		sptSET[u] = true;

		// sets the distance of new vertices adjacent to selected minimum vertex
		for(int v = 0; v<V; v++){
			if(!sptSET[v] && graph[u][v] && dist[u] != INT_MAX
											&& dist[u]+graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	//prints the solution
	printSolution(dist);
}



// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}



