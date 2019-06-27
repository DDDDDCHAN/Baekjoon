#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct shark{
	int x;
	int y;
	int size;
	int eat;
	int time;	
} babyshark;

int N;
int ocean[30][30];
bool isVisit[30][30];
// up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int answer = 0;
// (x, y, time)
queue< shark > findQ;
vector< shark > v;

bool compare(shark f1, shark f2){   // sort에서 true를 리턴하면 f1이 f2보다 앞에 온다는 뜻.
	if(f1.time <= f2.time){     // 시간이 크다면 if문 안들어가고 false, 걸린시간이 제일 작은 것이 맨 앞에 온다 제일 가까운 fish를 찾는다!!
		if(f1.time == f2.time){ // 시간이 같은 것들 중
			if(f1.x <= f2.x){   // x가 크다면 false(앞으로 올 필요 없음), 즉 x가 작은, 위쪽에 있는 아이들 x가 작거나 같은 것들 중
				if(f1.x == f2.x){ // x가 작으면 true, return 같으면 다시 if문
					if(f1.y < f2.y){ // x가 더 작은게 아니면 false 맞다면 return true.
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int findBFS(){

	while(1){

		v.clear(); // edible fish storage clear		
		memset(isVisit, 0, sizeof(isVisit));
		isVisit[babyshark.x][babyshark.y] = true;
		findQ.push(babyshark); // put new babyshark info

		while(!findQ.empty()){
			int cx = findQ.front().x;
			int cy = findQ.front().y;
			int size = findQ.front().size;
			int eat = findQ.front().eat;
			int time = findQ.front().time;
			findQ.pop();

			//find edible fishes with the closest range.
			for(int i=0; i<4; i++){
				int ax = cx + dx[i];
				int ay = cy + dy[i];

				if( !isVisit[ax][ay] && ax>=0 && ay>=0 && ax<N && ay<N){ // boundary check

					// size same or no fish
					if( (ocean[ax][ay] == 0) || (babyshark.size == ocean[ax][ay]) ){
						findQ.push({ax, ay, size, eat, time+1});
						isVisit[ax][ay] = true;
					}
					else if( babyshark.size > ocean[ax][ay] ){	 // find edible fishes				
						v.push_back({ax, ay, size, eat+1, time+1});
						isVisit[ax][ay] = true;
					}

				}					
			}
		}
			//edible fish sort
		

		if(v.size() == 0) //no edible fishes
			break; // if there is no more fish left, exit while(1)

		sort(v.begin(), v.end(), compare);

		if(v[0].size == v[0].eat){ //v[0]은 먹은 fish의 위치를 갖고 있고 shark는 글로 이동해야함.
			v[0].size++;
			v[0].eat = 0;
		}

		ocean[v[0].x][v[0].y] = 0;
		// store time took
		answer += v[0].time;
		// shark info update
			babyshark = { v[0].x, v[0].y, v[0].size, v[0].eat, 0 };			
		

	}

}

int main(){
	cin >> N;

	
	memset(ocean, 0, sizeof(ocean));

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> ocean[i][j];
			if(ocean[i][j] == 9){
				ocean[i][j] = 0;
				babyshark = {i, j, 2, 0, 0};  //Struct initialize!!!
			}
		}
	}
	findBFS();

	cout << answer;



}
