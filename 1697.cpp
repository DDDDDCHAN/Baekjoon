#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
bool isVisit[200000];    // isVisit의 경우 10만이 넘었다가 -1로 다시 돌아올 수 있기 때문에 넉넉하게! 
queue<int> q;
int time[200000];        // 여기서의 Time은 그 배열 no의 위치에 접근하는 시간을 저장하므로 배열 no에 접근하는게 위처럼 10만이 넘을 수 있기 때문에 넉넉하게! 
int forever = 1;


void BFS(int start, int goal){
	isVisit[start] = true;
	q.push(start);

	while(forever){
		int current = q.front();
		
		q.pop();
		if(current == goal){
			forever = 0;
			break;
		}
		// N과 M은 존재할 수 있는 위치가 0~10만이기 때문에  x <= 10만의 조건을 넣어줘야한다! 
		if(current-1<=100000 && current-1 >=0 && !isVisit[current-1]){  
			isVisit[current-1] = true;
			q.push(current-1);
			time[current-1] = time[current]+1;
		}
		if(current+1<=100000 && current+1 >=0 && !isVisit[current+1] ){
			isVisit[current+1] = true;
			q.push(current+1);
			time[current+1] = time[current]+1;
		}
		if(current*2<=100000 && current*2 >=0 && !isVisit[current*2]){
			isVisit[current*2] = true;
			q.push(current*2);
			time[current*2] = time[current]+1;
		}
	}
}

int main(){
	cin >> N >> K;

	memset(isVisit, 0, sizeof(isVisit));
	memset(time, -1, sizeof(time));
	BFS(N, K);
	if(N==K)
		cout << 0;
	else
		cout << time[K]+1;

}
