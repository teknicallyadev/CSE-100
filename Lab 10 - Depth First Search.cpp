#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//dfs from textbook

vector<int> component, order;

void DFS(vector<int> graph[], int n, bool visit[], int switcher) {
	int i;
	visit[n] = true;
	for(i = 0; i < graph[n].size(); i++){
		if (!visit[graph[n][i]]) {
			DFS(graph, graph[n][i], visit, switcher);
		}
		switch(switcher){
		case 0:
			order.push_back(n);
			break;
			
		default:
			component.push_back(n);
			break;
		}
	}
}

int main() {
	int i, j, k, tmp1, tmp2, switcher, value, vertices, edges;
	cin >> vertices >> edges;

	vector<int> vect;
	vector<int> adjverts[9]; //adjacent vertices
	vector<int> reverse[9]; 

	vector<vector<int>> scc;

	bool visit[9] = {false};

	for(i = 0; i < vertices; i++){
		vect.push_back(i);
	}

	for(i = 0; i < edges; i++){
		cin >> tmp1 >> tmp2;
		adjverts[tmp1].push_back(tmp2);
	}

	switcher = 0;
	for(i = 0; i < vertices; i++){
		if(!visit[i]){
			DFS(adjverts, i, visit, switcher);
		}
	}

	for(i = 0; i < vertices; i++){
		for(j = 0; j <adjverts[i].size(); j++){
			reverse[adjverts[i][j]].push_back(i);
		}
	}

	for(i = 0; i < vertices; i++){
		visit[i] = false;
	}

	vector<int> rvect(order.rbegin(), order.rend()); //reverser
	order.swap(rvect);

	switcher = 1;
	for(i = 0; i < order.size();i++){
		if(!visit[order[i]]){
			component.clear();
			DFS(reverse, order[i], visit, switcher);
			scc.push_back(component);
		}
	}
	
	//tried for loop but gave seg fault for some reason
	i = 0;
	while(i < scc.size()) {
		j = 0;
		while(j < scc[i].size()) {
			value = scc[i][j];
			k = 0;
			while(k < vertices) {
				if(vect[k] == value) {
					vect[k] = *min_element(scc[i].begin(), scc[i].end());
				}
				k++;
			}
			j++;
		}
		i++;
	}
	
	for(i = 0;i < vertices; i++){
		cout << vect[i] << endl;
	}

	return 0;
}
