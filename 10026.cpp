#include <bits/stdc++.h>

using namespace std;

int N;
char color[110];
int normalMAP[110][110];
int colorMAP[110][110];
bool isVisit[110][110];
//up, down, left, right
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

queue<pair<int,int> > q;

int normalSector = 0;
int colorSector = 0;

void normalBFS(int node1, int node2){
	isVisit[node1][node2] = true;
	q.push(pair<int,int>(node1, node2));

	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int ax = cx + dx[i];
			int ay = cy + dy[i];
			if( (normalMAP[ax][ay] == normalMAP[cx][cy])  && !isVisit[ax][ay] && ax>=0 && ay>=0  && ax<N && ay<N ){
				isVisit[ax][ay] = true;
				q.push(pair<int,int>(ax,ay));
			}
		}
	}
}

void colorBFS(int node1, int node2){
	isVisit[node1][node2] = true;
	q.push(pair<int,int>(node1, node2));

	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int ax = cx + dx[i];
			int ay = cy + dy[i];
			if( (colorMAP[ax][ay] == colorMAP[cx][cy]) && !isVisit[ax][ay] && ax>=0 && ay>=0  && ax<N && ay<N ){
				isVisit[ax][ay] = true;
				q.push(pair<int,int>(ax,ay));
			}
		}
	}
}

int main(){

	cin >> N;

	memset(normalMAP, 0, sizeof(normalMAP));
	memset(colorMAP, 0, sizeof(colorMAP));
	memset(isVisit, 0, sizeof(isVisit));

	for(unsigned int i=0; i<N; i++){
		for(unsigned int j=0; j<N; j++){
			cin >> color[j];
			if(color[j] == 'R'){
				normalMAP[i][j] = 1;
				colorMAP[i][j] = 1;
			}
			if(color[j] == 'G'){
				normalMAP[i][j] = 2;
				colorMAP[i][j] = 1;
			}
			if(color[j] == 'B'){
				normalMAP[i][j] = 3;
				colorMAP[i][j] = 3;
			}
		}
	}

	for(unsigned int i=0; i<N; i++){        //normal count
		for(unsigned int j=0; j<N; j++){
			if(!isVisit[i][j]){
				normalBFS(i, j);
				normalSector++;
			}
		}
	}
	memset(isVisit, 0, sizeof(isVisit));

	for(unsigned int i=0; i<N; i++){       //color count
		for(unsigned int j=0; j<N; j++){
			if(!isVisit[i][j]){
				colorBFS(i, j);
				colorSector++;
			}
		}
	}

	cout << normalSector << " " << colorSector;

}
