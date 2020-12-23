#include <iostream>
#include <algorithm>

using namespace std;

/*
맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 
이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 

아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력 : 
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력 :
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.


*/




int main(void)
{

	int ans =0 ;
	int N;
	int dp[502] = { 0, };
	int triangle[502] = { 0, };
	int sum[502] = { 0, };

	cin >> N;

	cin >> sum[1]; // 1번 줄
	dp[1] = sum[1];

	if (N > 1)
	{
		for (size_t i = 2; i < N + 1; i++) // 2번 줄부터
		{
			for (size_t j = 1; j < i + 1; j++) // j번 줄 데이터 입력 i회
			{
				cin >> triangle[j];
				dp[j] = sum[j];
			}

			for (size_t k = 1; k < i + 1; k++)
			{
				if (k == 1) // 가장 왼쪽이면 
				{
					
					sum[1] += triangle[1];
				}
				else if (k < i && k > 1)
				{
					sum[k] = triangle[k] + max(dp[k - 1], dp[k]);
				}
				else // 가장 오른쪽이면
				{
					sum[i] = dp[i-1] + triangle[i];
				}

			}

		}
	}
	
	ans = sum[1];

	for (size_t i = 0; i < N+1; i++)
	{
		if (sum[i] > ans)
		{
			ans = sum[i];
		}
	}

	cout << ans << endl;

	return 0;
}
