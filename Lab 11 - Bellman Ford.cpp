#include <iostream>
#include <limits.h>
using namespace std;

int vertices, edges, temp1, temp2, weight;

struct Edge{
	int u, v, w;
};

struct Graph{
	int V, E; //v = vertex e = edge
	struct Edge *edge; 
};

void print(int arr[], int size, bool boolean){
	int i = 0;
	if(boolean){
		cout << "TRUE" << endl;
		while(i < size){
			switch(arr[i]){
			case INT_MAX:
				cout << "INFINITY" << endl;
			break;
				
			default:
				cout << arr[i] << endl;
			break;
			}
			i++;
		}
	}
}

void bellman(struct Graph *graph, int s){
	bool boolean = true;
	int totalvertices = graph->V;
	int totaledges = graph->E;
	int distance[totalvertices];
	int u, v, w;
	
	int i = 0;
	while(i < totalvertices){
		distance[i] = INT_MAX;
		i++;
	}
	
	distance[s] = 0;

	i = 1;
	while(i <= (totalvertices - 1)){
		int j = 0;
		while(j < totaledges){
			u = graph->edge[j].u;
			v = graph->edge[j].v;
			w = graph->edge[j].w;
			if(distance[u] != INT_MAX && distance[v] > distance[u] + w){
				distance[v] = distance[u] + w;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	while(i < totaledges){
		u = graph->edge[i].u;
		v = graph->edge[i].v;
		w = graph->edge[i].w;
		if(distance[u] != INT_MAX && distance[v] > distance[u] + w) {
			cout << "FALSE" << endl;
			boolean = false;
			return;
		}
		i++;
	}
	
	print(distance, totalvertices, boolean);
}

int main(){
	struct Graph* graph = new Graph();
	
	cin >> vertices >> edges;
	
	graph->V = vertices;
	graph->E = edges;
	graph->edge = new Edge[edges];
	
	int i = 0;
	
	while(i < edges){
		cin >> temp1 >> temp2 >> weight;
		
		graph->edge[i].u = temp1;
		graph->edge[i].v = temp2;
		graph->edge[i].w = weight;

		i++;
	}
	
	bellman(graph, 0);
	
	return 0;
}
