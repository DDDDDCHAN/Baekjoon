#include <bits/stdc++.h>

using namespace std;

int N, M, V;
bool MAP[1002][1002];
bool DFSVisit[1002];
bool BFSVisit[1002];
queue<int> q;

void DFSwithPRINT(int node){
	
	DFSVisit[node] = true;
	printf("%d ", node);
	for(int j=1; j<=N; j++){
		if( (!DFSVisit[j] && MAP[node][j]) ==1 ) {

			DFSwithPRINT(j);
		}
	}

}

void BFSwithPRINT(int node){
	
	BFSVisit[node] = true;
	q.push(node);
	printf("%d ", node);
	while(!q.empty()){   // if q is empty, return 1
		int current = q.front();
		q.pop(); // pop을 안하면 위의 while을 빠져나가지 못함.
		for(int j=1; j<=N; j++){
			if( (!BFSVisit[j] && MAP[current][j]) == 1){
				BFSVisit[j] = true;
				printf("%d ", j); // recursion이 아니므로 함수 선언부 바로 밑의 print는 한 번만 나온다.
				q.push(j);
			}
		}
	}


}

int main(){

	int u, v;

	cin >> N >> M >> V;

	memset(MAP, 0, sizeof(MAP));
	memset(DFSVisit, 0, sizeof(DFSVisit));
	memset(BFSVisit, 0, sizeof(BFSVisit));

	for(int i=0; i<M; i++){
		cin >> u >> v;
		MAP[u][v] = MAP[v][u] = true;
	}

	   // DFS part
	if(!DFSVisit[V])
		DFSwithPRINT(V);
	
	printf("\n");
	

	   // BFS part
	if(!BFSVisit[V])
		BFSwithPRINT(V);

}
