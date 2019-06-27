#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
bool isVisit[200000];    // isVisit�� ��� 10���� �Ѿ��ٰ� -1�� �ٽ� ���ƿ� �� �ֱ� ������ �˳��ϰ�! 
queue<int> q;
int time[200000];        // ���⼭�� Time�� �� �迭 no�� ��ġ�� �����ϴ� �ð��� �����ϹǷ� �迭 no�� �����ϴ°� ��ó�� 10���� ���� �� �ֱ� ������ �˳��ϰ�! 
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
		// N�� M�� ������ �� �ִ� ��ġ�� 0~10���̱� ������  x <= 10���� ������ �־�����Ѵ�! 
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
