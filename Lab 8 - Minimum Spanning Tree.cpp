#include <iostream>
#include <vector>
#include <climits>

using namespace std;
//global variables
int vertices, edges, x, y, u, w, i, j;

int MinKey(int key[], bool boolean[]){
	int minValue = INT_MAX;
	int position = 0;
	int index = 0;
	
	while(index < vertices){
		if(!boolean[index] && key[index] < minValue){
			minValue = key[index];
			position = index;
		}
		index++;
	}

	return position;
}

void MST(){
	int weight[vertices], key[vertices]; //create arrays based off of amount of vertices
	bool boolean[vertices];
	
	vector<vector<int>> graph(vertices, vector<int>(vertices, 0));
	
	for(i = 0; i < vertices; i++){
		for(j = 0; j < vertices; j++){
			graph[i][j] = 0;
			key[i] = INT_MAX;
			boolean[i] = false;
		}
	}

	for(i = 0; i < edges; i++){
		cin >> x >> y >> w; //inputs stored into x, y, and w
		graph[y][x] = w;
		graph[x][y] = w;
	}

	for(i = 0; i < vertices-1; i++){
		u = MinKey(key, boolean); // u = position;
		boolean[u] = true; //boolean at index of position 
		for(j = 0; j < vertices; j++){
			if(graph[u][j] && !boolean[j] && (graph[u][j] < key[j])){
				weight[j] = u;
				key[j] = graph[u][j];
			}
		}
	}
	
	for(i = 1; i < vertices; i++){
		cout << weight[i] << endl;
	}

}

int main(){
	cin >> vertices >> edges; //inputs stored into vertices and edges
	MST();
	return 0;
}
