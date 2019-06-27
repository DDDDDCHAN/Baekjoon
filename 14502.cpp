#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int Lab[10][10];
int copyLab[10][10];
int safearea = 0;
int forcheck = 0;

queue<pair<int, int> > q;

//up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void wall();
void gogovirus();
void MapCOPY();

void MapCOPY(int (*a)[10], int (*b)[10]){

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			a[i][j] = b[i][j];
		}
	}

}
void wall(int count){

	if(count == 3){ // if three walls are built, spread virus and exit the function
		gogovirus();
		return; 
	}
	else
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(copyLab[i][j] == 0){
					copyLab[i][j] = 1;
					wall(count+1); // recursive
					copyLab[i][j] = 0;
				}
			}
		}

}

void gogovirus(){

	int spreadvirus[10][10];
	memcpy(spreadvirus, copyLab, sizeof(copyLab));
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(spreadvirus[i][j] == 2)
				q.push(make_pair(i,j));
		}
	} 
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int ax = cx + dx[i];
			int ay = cy + dy[i];
			if(ax>=0 && ay>=0 && ax<N && ay<M){
				if( spreadvirus[ax][ay] == 0 ){
					spreadvirus[ax][ay] = 2;
					q.push(make_pair(ax,ay));
				}
			}				
		}
	} // spreading complete
	forcheck = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(spreadvirus[i][j] == 0)
				forcheck++;
		}
	}
	if(forcheck>safearea)
		safearea = forcheck;
}

int main(){
	cin >> N >> M;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> Lab[i][j];
			copyLab[i][j] = Lab[i][j];
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(Lab[i][j] == 0){ // 0인 부분이 Lab 어레이에 있으면 그걸 기준으로 copyLab에 wall을 총 3개씩 모든 경우에 대하여 세워본다.
				copyLab[i][j] = 1;
				wall(1); // wall end 
				copyLab[i][j] = 0;
			}
		}
	}

	cout << safearea;
}
