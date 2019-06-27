#include <bits/stdc++.h>

using namespace std;

int N;
bool isVisit[30][30];
bool MAP[30][30];
//up, down, left, right
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int apartCount[900];
int complexCount = 0;
queue<pair<int,int> > q;

void BFS(int node1, int node2){
	isVisit[node1][node2] = true;
	q.push(pair<int,int>(node1, node2));

	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(unsigned int i=0; i<4; i++){
			int ax = cx + dx[i];
			int ay = cy + dy[i];
			if( !isVisit[ax][ay] && MAP[ax][ay] && ax>=0 && ay>=0 && ax<N && ay<N ){
				isVisit[ax][ay] = true;
				apartCount[complexCount]++;
				q.push(pair<int,int>(ax,ay));				
			}
		}
	}
}

int main(){
	cin >> N;

	char input[30];
	memset(input, 0, sizeof(input));
	memset(isVisit, 0, sizeof(isVisit));
	memset(MAP, 0, sizeof(MAP));
	memset(apartCount, 0, sizeof(apartCount));
	for(unsigned int i=0; i<N; i++){
		for(unsigned int j=0; j<N; j++){
			cin >> input[j];
			if(input[j] == '0'){
				MAP[i][j] = 0;
			}
			if(input[j] == '1'){
				MAP[i][j] = 1;
			}			
		}
	}

	for(unsigned int i=0; i<N; i++){
		for(unsigned int j=0; j<N; j++){
			if(!isVisit[i][j] && MAP[i][j]){ //count 미리미리 하는 습관!! 
				complexCount++;
				apartCount[complexCount]++;
				BFS(i, j);								
			}
		}
	}
	sort(apartCount, apartCount+complexCount+1);
	cout << complexCount << endl;
	for(unsigned int i=1; i<=complexCount; i++){
		cout << apartCount[i] << endl;
	}
}
