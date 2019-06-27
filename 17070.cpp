#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;


int N;
bool room_map[20][20];

// q: x, y, dir
// dir 0: 가로
// dir 1: 세로
// dir 2: 대각
queue<pair<pair<int, int>, int > > q;

// 우, 하, 대각
// 가로, 세로, 대각: 0, 1, 2
int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};
int answer = 0;
void BFS(){
	q.push(make_pair(make_pair(1, 2), 0));

	while(!q.empty()){
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		if( cx == N && cy == N ){
			answer++;
			continue;   // Break는 While문과 for문처럼 반복문을 빠져나오게 한다!
		}
		else if( dir == 0 ){  //가로 방향일 때

			int ax = cx + dx[0];  //가로 방향으로 이동
			int ay = cy + dy[0];
			if( ax>=1 && ay>=1 && (ax <= N) && (ay <= N) && (room_map[ax][ay] == 0))				
				q.push(make_pair(make_pair(ax, ay), 0));

			
			ax = cx + dx[2]; //대각선으로 이동
			ay = cy + dy[2];
			if( ax>=1 && ay>=1 && (ax <= N) && (ay <= N) && (room_map[ax][ay] == 0) && (room_map[ax-1][ay] == 0) && (room_map[ax][ay-1] == 0))
				q.push(make_pair(make_pair(ax, ay), 2));
		}
		else if( dir == 1 ){ //세로 방향일 때

			int ax = cx + dx[1]; //세로 방향으로 이동
			int ay = cy + dy[1];
			if( ax>=1 && ay>=1 && (ax <= N) && (ay <= N) && (room_map[ax][ay] == 0))
				q.push(make_pair(make_pair(ax, ay), 1));

			ax = cx + dx[2]; //대각선으로 이동
			ay = cy + dy[2];
			if( ax>=1 && ay>=1 && (ax <= N) && (ay <= N) && (room_map[ax][ay] == 0) && (room_map[ax-1][ay] == 0) && (room_map[ax][ay-1] == 0))
				q.push(make_pair(make_pair(ax, ay), 2));
		}
		else if( dir == 2 ){ //대각 방향일 때

			int ax = cx + dx[0]; //가로 방향으로 이동
			int ay = cy + dy[0];
			if( ax>=1 && ay>=1 && (ax <= N) && (ay <= N) && (room_map[ax][ay] == 0))
				q.push(make_pair(make_pair(ax, ay), 0));

			ax = cx + dx[1]; //세로 방향으로 이동
			ay = cy + dy[1];
			if( ax>=1 && ay>=1 && (ax <= N) && (ay <= N) && (room_map[ax][ay] == 0))
				q.push(make_pair(make_pair(ax, ay), 1));

			ax = cx + dx[2]; //대각선으로 이동
			ay = cy + dy[2];
			if( ax>=1 && ay>=1 && (ax <= N) && (ay <= N) && (room_map[ax][ay] == 0) && (room_map[ax-1][ay] == 0) && (room_map[ax][ay-1] == 0))
				q.push(make_pair(make_pair(ax, ay), 2));
		}


	}
}

int main(){

	cin >> N;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> room_map[i][j];
		}
	}
	BFS();
	cout << answer;

	

}
