//Using BFS with Queue
//Getting No. of Connected Components
#include <bits/stdc++.h>
using namespace std;

int N, M;
bool isVisit[1001];
bool MAP[1001][1001];
queue<int> q;

void BFS(int node){
	isVisit[node] = true;k
	q.push(node);

	while(!q.empty()){ // if empty, returns 1
		int current = q.front();
		q.pop();

		for(int j=1; j<=N; j++){
			if( (!isVisit[j] && MAP[current][j]) == 1 ){
				isVisit[j] = true;
				q.push(j);
			}
		}
	}
}

/*void BFS2(int node){

	isVisit[node] = true;
	int front = 0;
	int rear = 0;
	int pop;

	q[front] = node;
	rear++;

	while(front < rear){
		pop = q[front];
		front++;
		for(int j=1; j<=N; j++){
			if(!isVisit[j] && MAP[pop][j] == 1){
				isVisit[j] = true;
				rear++;
				q[front] = j;
			}				
		}
	}
}*/


int main(){

	int u, v;
	int count = 0;

	cin >> N >> M;	
	
	memset(isVisit, 0, sizeof(isVisit));
	memset(MAP, 0, sizeof(MAP));

	for(int i=0; i<M; i++){
		cin >> u >> v;
		MAP[u][v] = MAP[v][u] = true;
	}

	for(int i=1; i<=N; i++){
		if(!isVisit[i]){
			BFS(i);
			count++;
		}
	}
	
	cout << count;


}

