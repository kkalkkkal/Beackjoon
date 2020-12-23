#BFS를 이용해 겉 테두리를 찾아가는 

#include<iostream>
#include<queue>
using namespace std;
int r, c;
int map[100][100];
bool checked[100][100];
int time = 0, cheeze = 0;
int prevCh;
int moveR[4] = { -1, 0, 1, 0 };
int moveC[4] = { 0, 1, 0, -1 };
int main(void) {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				cheeze++;
			}
			checked[i][j] = false;
		}
	}
	//공기 칸 구하기
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	checked[0][0] = true;
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		map[curX][curY] = 3;
		for (int i = 0; i < 4; i++) {
			if (curX + moveR[i] >= 0 && curX + moveR[i] < r&&curY + moveC[i] >= 0 && curY + moveC[i] < c && checked[curX + moveR[i]][curY + moveC[i]] == false) {
				if (map[curX + moveR[i]][curY + moveC[i]] == 0) {
					q.push(make_pair(curX + moveR[i], curY + moveC[i]));
					checked[curX + moveR[i]][curY + moveC[i]] = true;
				}
			}
			
		}
	}
	while (true) {
		time++;
		prevCh = cheeze;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] == 1) {
					bool check = false;
					for (int k = 0; k < 4; k++) {
						if (i + moveR[k] >= 0 && i + moveR[k] < r&&j + moveC[k] >= 0 && j + moveC[k] < c) {
							if (map[i + moveR[k]][j + moveC[k]] == 3) {
								check = true;
							}
						}
						
					}
					if (check) {//산소와 접촉한 경우
						map[i][j] = 2;
					}
				}
			}
		}
		queue<pair<int, int>> hole;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] == 2) {
					cheeze--;
					map[i][j] = 3;
					for (int k = 0; k < 4; k++) {
						if (i + moveR[k] >= 0 && i + moveR[k] < r&&j + moveC[k] >= 0 && j + moveC[k] < c) {
							if (map[i + moveR[k]][j + moveC[k]] == 0) {
								hole.push(make_pair(i + moveR[k], j + moveC[k]));
							}
						}

					}
				}
			}
		}
		while (!hole.empty()) {//구멍에 공기가 접촉한 경우
			int curX = hole.front().first;
			int curY = hole.front().second;
			hole.pop();
			map[curX][curY] = 3;
			for (int i = 0; i < 4; i++) {
				if (curX + moveR[i] >= 0 && curX + moveR[i] < r&&curY + moveC[i] >= 0 && curY + moveC[i] < c && checked[curX + moveR[i]][curY + moveC[i]] == false) {
					if (map[curX + moveR[i]][curY + moveC[i]] == 0) {
						hole.push(make_pair(curX + moveR[i], curY + moveC[i]));
						checked[curX + moveR[i]][curY + moveC[i]] = true;
					}
				}
				
			}
		}
		/*
		cout << time << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
		cout << endl;
		*/
		if (cheeze == 0) {
			break;
		}

	}
	cout << time << '\n';
	cout << prevCh << '\n';
	return 0;
}
