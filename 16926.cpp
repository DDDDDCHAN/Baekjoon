#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){

	int N, M, R;
	int array[400][400];
	int copy[400][400];

	cin >> N >> M >> R;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> array[i][j];
		}
	}

	memcpy(copy, array, sizeof(array));
	
}