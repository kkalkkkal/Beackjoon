#include<iostream>
using namespace std;
int n;
int input[501][501] = { 0, };
int answer[501][501] = { 0, };
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> input[i][j];
		}
	}
	answer[0][0] = input[0][0];
	answer[1][0] = input[1][0] + answer[0][0];
	answer[1][1] = input[1][1] + answer[0][0];

	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int maxValue = 0;
			if (j > 0) {
				maxValue = answer[i - 1][j - 1];
			}
			if (maxValue < answer[i - 1][j]) {
				maxValue = answer[i - 1][j];
			}
			answer[i][j] = maxValue + input[i][j];
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < answer[n - 1][i]) {
			max = answer[n - 1][i];
		}
	}

	cout << max << '\n';

	return 0;
}
