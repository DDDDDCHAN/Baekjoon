//Using DFS with recursion
//Adjacency matrix
//Getting No. of Connected Components
#include <bits/stdc++.h> //사용시 map이란 이름의 array 생성시 오류 남! 

using namespace std;


int N, M;
int MAP[1001][1001];
bool isVisit[1001];


void DFS(int node){
	
	isVisit[node] =  true;
	
	for(int i=1; i<=N; i++){    // Node No. N starts from 1
		if( MAP[node][i] && !isVisit[i] == 1)
			DFS(i);
	}	
}


int main(){
	
	int u, v;
	int count = 0;  // No. of connected components
	
	cin >> N >> M;
	memset(isVisit, 0, sizeof(isVisit));  //initialize arrays
	memset(MAP, 0, sizeof(MAP));
	
	
	
	for(int i = 0; i<M; i++){               //get M no. different edges
		cin >> u >> v;                      //get adjacency matrix
		MAP[u][v] = MAP[v][u] = 1; 
	}
	
	for(int j=1; j<=N; j++){
		if(isVisit[j] == 0){
			DFS(j);
			count++;
		}
	}
	
	cout << count;
}
