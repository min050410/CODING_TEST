// 청소년 상어

#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;


class Fish {
public:
	int num, dir, r, c;
	bool live;
	Fish(){}
	Fish(int _n, int _d, int _r, int _c, bool _live) {
		num = _n; 
		dir = _d;
		r = _r;
		c = _c;
		live = _live;
	}
};

Fish fishArr[17];	//물고기 1~ 16번까지 객체 저장
int map[4][4];		//물고기 번호만 저장

//12,11,9,,,
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,-1,-1,-1,0,1,1,1 };


int ret = 0;

//배열을 함수의 파라미터로 넘길시 Call By Reference (주소값만 넘어감)
void solveDFS(int map[][4], Fish fishArr[], int shark_row, int shark_col, int s) {	

	//백트래킹을 위해 기존 배열 놔두고 카피해서 상태변화 시켜봄
	int copy_map[4][4];
	Fish copy_fishArr[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < 17; i++ ) {
		copy_fishArr[i] = fishArr[i];
	}


	//물고기 잡아먹기
	int fishNum = copy_map[shark_row][shark_col];
	int shark_dir = copy_fishArr[fishNum].dir;				//잡아먹은 물고기 방향으로 바뀜
	copy_fishArr[fishNum].live = false;
	copy_map[shark_row][shark_col] = -1;						//물고기 잡아먹어서 물고기 없어짐

	s += fishNum;
	if (ret < s) ret = s;




	//물고기 이동
	for (int f = 1; f <= 16; f++) {
		if (copy_fishArr[f].live == false) continue;

		//현재 순서인 물고기의 위치
		int cr = copy_fishArr[f].r;
		int cc = copy_fishArr[f].c;
		int cd = copy_fishArr[f].dir;

		//바꿀 타겟의 위치
		int nr = cr + dr[cd];
		int nc = cc + dc[cd];
		int nd = cd;

		//타겟이 범위 넘어가거나 상어면 회전
		while (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || (nr == shark_row && nc == shark_col)) {
			nd = (nd + 1) % 8;
			nr = cr + dr[nd];
			nc = cc + dc[nd];
		}

		//1. 타겟 칸이 물고기면

		if (copy_map[nr][nc] != -1) {
			int targetFishNum = copy_map[nr][nc];
			//타겟 물고기 위치 갱신
			copy_fishArr[targetFishNum].r = cr;
			copy_fishArr[targetFishNum].c = cc;

			//현재 물고기 위치 갱신
			copy_fishArr[f].r = nr;
			copy_fishArr[f].c = nc;
			copy_fishArr[f].dir = nd;

			//이차원 배열 번호 swap
			copy_map[nr][nc] = f;
			copy_map[cr][cc] = targetFishNum;

		}


		//2. 타겟 칸이 빈칸이면
		else {

			copy_fishArr[f].r = nr;
			copy_fishArr[f].c = nc;
			copy_fishArr[f].dir = nd;

			copy_map[nr][nc] = f;
			copy_map[cr][cc] = -1;			//원래 물고기 있던 칸은 물고기 없어짐 

		}

	}


	//상어 이동
	for(int step = 1; step <= 3; step++) {
		int nr = shark_row + dr[shark_dir] * step;
		int nc = shark_col + dc[shark_dir] * step;

		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) break;

		if (copy_map[nr][nc] != -1) {
			solveDFS(copy_map, copy_fishArr, nr, nc, s);
		}
	}




}



int main() {

	int n, d;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			cin >> n >> d;
			Fish fish = Fish(n, d-1, i, j, true);
			map[i][j] = n;		//2차원 배열에 놓기
			fishArr[n] = fish;			//물고기 객체 배열에 넣기

		}
	}



	//상어 초기 셋팅
	ret = 0;
	solveDFS(map, fishArr, 0, 0, 0);
	cout << ret;
	
	return 0;

}
