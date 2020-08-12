#include<iostream>
using namespace std;
int t;
int map[2][100001];

int dp[2][100001];
int n;

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}
int main(void) {
	cin >> t;
	while (t--) {
		cin >> n;
		int temp;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> temp;
				map[i][j] = temp;
				dp[i][j] = -1;
			}
		}
		dp[0][0] = map[0][0];
		dp[1][0] = map[1][0];
		dp[1][1] = map[0][0] + map[1][1];
		dp[0][1] = map[1][0] + map[0][1];
		for (int i = 2; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0) {
					dp[j][i] = map[j][i] + max(dp[j + 1][i - 1], dp[j + 1][i - 2]);
				}
				else if (j == 1) {
					dp[j][i] = map[j][i] + max(dp[j - 1][i - 1], dp[j - 1][i - 2]);
				}
			}
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';

	}


	return 0;
}
