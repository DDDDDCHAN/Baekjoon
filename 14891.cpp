#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool gears[5][200];
int K;
int rotate_who[110];
int rotate_dir[110];


void rotate(int gear_number, int dir);
void solve(int tobni, int direction);

int main(){

	memset(gears, 0, sizeof(gears));
	memset(rotate_who, 0, sizeof(rotate_who));
	memset(rotate_dir, 0, sizeof(rotate_dir));

	int score1;
	int score2;
	int score3;
	int score4;

	int divide[10];

	// save initial status of gears

	for(int i=0; i<4; i++){
		cin >> divide[i];		
	}
	for(int i=1; i<5; i++){
		for(int j=7; j>=0; j--){
			gears[i][j] = divide[i] % 10;
			divide[i] /= 10;
		}
	}
	
	cin >> K;
	for(int i=0; i<K; i++){
		cin >> rotate_who[i] >> rotate_dir[i]; 
	}
	for(int i=0; i<K; i++){
		if(rotate_dir[i] == -1){
			rotate_dir[i] = 0;
		}
	}

	for(int i=0; i<K; i++){
		solve(rotate_who[i], rotate_dir[i]);
	}

	score1 = gears[1][0];
	score2 = gears[2][0];
	score3 = gears[3][0];
	score4 = gears[4][0];
	
	cout << score1 << endl << score2 << endl << score3 << endl << score4;

}

void rotate(int gear_number, int dir){
	int temp;
	// rotate right	
	if(dir == 1){ 		
		temp = gears[gear_number][7];
		for(int i=7; i>0; i--){
			gears[gear_number][i] = gears[gear_number][i-1]; 		
		}
		gears[gear_number][0] = temp;
	}
	//rotate left
	else{
		temp = gears[gear_number][0];
		for(int i=1; i<8; i++){
			gears[gear_number][i-1] = gears[gear_number][i];
		}
		gears[gear_number][7] = temp;
	}
}

void solve(int tobni, int direction){
	if(tobni == 1){		
		if(gears[2][6] != gears[1][2]){
			if(gears[3][6] != gears[2][2]){
				if(gears[4][6] != gears[3][2]){
					rotate(4, !direction);
					rotate(3, direction);
					rotate(2, !direction);
				}
				rotate(3, direction);
				rotate(2, !direction);				
			}
			rotate(2, !direction);
		}
		rotate(1, direction);
	}

	if(tobni == 2){		
		if(gears[1][2] != gears[2][6]){
			rotate(1, !direction);
		}
		if(gears[3][6] != gears[2][2]){
			if(gears[4][6] != gears[3][2]){
				rotate(4, direction);
				rotate(3, !direction);
			}
			rotate(3, !direction);
		}
		rotate(2, direction);
	}
	if(tobni == 3){		
		if(gears[2][2] != gears[3][6]){
			if(gears[1][2] != gears[2][6]){
				rotate(1, direction);
				rotate(2, !direction);
			}
			rotate(2, !direction);
		}
		if(gears[4][6] != gears[3][2]){
			rotate(4, !direction);
		}
		rotate(3, direction);
	}
	if(tobni == 4){		
		if(gears[3][2] != gears[4][6]){
			if(gears[2][2] != gears[3][6]){
				if(gears[1][2] != gears[2][6]){
					rotate(1, !direction);
					rotate(2, direction);
					rotate(3, !direction);
				}
				rotate(2, direction);
				rotate(3, !direction);
			}
			rotate(3, !direction);
		}
		rotate(4, direction);
	}
		

}
