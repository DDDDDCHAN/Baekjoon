#include <bits/stdc++.h>

using namespace std;

bool MAP[100][100];
bool isVisit[100][100];
queue<pair<int,int> > q; // BFS에 사용 할 x, y의 queue(pair 이용 두 개)

// up, down , left, right
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int M, N, K;

void BFS(int node1, int node2){
	isVisit[node1][node2] = true;
	q.push(pair<int,int>(node1, node2));

	while(!q.empty()){
		int cx = q.front().first;  //current x and y
		int cy = q.front().second; //Used fisrt, second of pairs
		q.pop();

		for(int l=0; l<4; l++){
			int ax = cx + dx[l];
			int ay = cy + dy[l];
			if(!isVisit[ax][ay] && MAP[ax][ay] && ax>0 && ay>0 && ax<=M && ay<=N){
				isVisit[ax][ay] = true;
				q.push(pair<int,int>(ax,ay));
			}
		}
	}

} 

int main(){

	int TC;
	cin >> TC;

	for(int i=0; i<TC; i++){
		
		int u, v;
		int worm = 0;

		memset(isVisit, 0, sizeof(isVisit));
		memset(MAP, 0, sizeof(MAP));
		cin >> M >> N >> K;

		for(int j=0; j<K; j++){
			cin >> u >> v;
			MAP[u+1][v+1] = true;
		}

		for(int j=1; j<=M; j++){
			for(int k=1; k<=N; k++){
				if(!isVisit[j][k] && MAP[j][k]){
					BFS(j,k);
					worm++;
				}
			}
		}
		cout << worm << endl;
	}

}
