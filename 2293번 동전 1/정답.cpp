#include<iostream>
using namespace std;
int n, k;
int coin[101];
int dp[10001] = { 0, };//dp[i]는 가치의 합이 i인 경우의 수 
int main(void) {

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;//동전을 1개만 사용했을 때 dp[0]값을 그대로 가져올거라서 1가지로 설정
	//
	
	for (int j = 0; j < n; j++) {//중복 계산 안하기 위해 0번 동전 경우의수->0, 1번 동전 경우의수->0,1,2번 동전 ...
		
		for (int i = 1; i <= k; i++) {
			//현재 가치의 합이 i인 경우의 수는 coin[j] 한개+가치의 합이 (i-coin[j])인 경우의 수
			int cur_index = i - coin[j];
			if (cur_index < 0) {
				continue;
			}
			dp[i] += dp[cur_index];
		}
	}
	cout << dp[k] << '\n';
	return 0;
}
