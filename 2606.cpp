#include <bits/stdc++.h>

using namespace std;

int computers, connected;
bool isVisit[200];
bool MAP[200][200];
queue<int> q;
int counter = 0;

void BFS(int node){

	isVisit[node] = true;	
	q.push(node);
	

	while(!q.empty()){
		int current = q.front();
		q.pop();

		for(int j=1; j<=computers; j++){
			if((!isVisit[j] && MAP[current][j]) == 1){
				isVisit[j] = true;
				q.push(j);
				counter++;
			}
		}
		
	}

}

int main(){

	int u, v;
	cin >> computers >> connected;
	
	for(int i=0; i<connected; i++){
		cin >> u >> v;
		MAP[u][v] = MAP[v][u] = true;
	} 


			BFS(1);
	
	cout << counter;
}
