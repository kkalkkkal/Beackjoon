#include<iostream>

using namespace std;
int map[20][20];
int n;
int answer = 0;
int dirR[3] = { 0, 1, 1 };
int dirC[3] = { 1, 0, 1 };
void move(int dir, int r, int c) {
	//cout << dir << " 방향 " << r << " : " << c << endl;
	if (r == n && c == n) {
		answer++;
		return;
	}
	if (dir == 0) {//가로
		for (int i = 0; i < 3; i++) {
			if (i == 1) {//세로로 이동불가
				continue;
			}
			int curR = r + dirR[i];
			int curC = c + dirC[i];
			if (map[curR][curC] == 1 || curR > n || curC > n) {//다음 위치가 벽이거나 범위 벗어나는 경우
				continue;
			}
			if (i == 2) {
				if (map[r + 1][c] == 1 || map[r][c + 1] == 1) {
					break;
				}
			}
			move(i, curR, curC);
		}
		
	}
	else if (dir == 1) {//세로
		for (int i = 0; i < 3; i++) {
			if (i == 0) {//가로로 이동불가
				continue;
			}
			int curR = r + dirR[i];
			int curC = c + dirC[i];
			if (map[curR][curC] == 1 || curR > n || curC > n) {//다음 위치가 벽이거나 범위 벗어나는 경우
				continue;
			}
			if (i == 2) {
				if (map[r + 1][c] == 1 || map[r][c + 1] == 1) {
					break;
				}
			}
			move(i, curR, curC);
		}
	}
	else if (dir == 2) {//대각선
		for (int i = 0; i < 3; i++) {
			int curR = r + dirR[i];
			int curC = c + dirC[i];
			if (map[curR][curC] == 1 || curR > n || curC > n) {//다음 위치가 벽이거나 범위 벗어나는 경우
				continue;
			}
			if (i == 2) {
				if (map[r + 1][c] == 1 || map[r][c + 1] == 1) {
					break;
				}
			}
			move(i, curR, curC);
		}
	}
}
int main(void) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = 1;
		}
	}
	cin >> n;
	int temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			map[i][j] = temp;
		}
	}
	move(0, 1, 2);

	cout << answer;

	return 0;
}
