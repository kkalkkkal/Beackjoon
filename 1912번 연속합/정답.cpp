#include <iostream>
#include <algorithm>

using namespace std;
/*

n개의 정수로 이루어진 임의의 수열이 주어진다.
우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 
여기서 정답은 12+21인 33이 정답이 된다.

첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 
수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.
*/



int main(void)
{
	int N;

	cin >> N; 

	int sum[100001] = { -1, }; // 초기화
	int input[100001] = { -1, };

	int ans = 0;

	for (size_t i = 0; i < N; i++)
	{
		cin >> input[i]; // 일단 순서대로 다 입력 받음.
	}

	sum[0] = input[0];
	ans = sum[0];

	for (size_t i = 1; i < N; i++)
	{
		if (sum[i - 1] + input[i] > input[i])
		{
			sum[i] = sum[i - 1] + input[i];
		}
		else
		{
			sum[i] = input[i];
		}

		ans = max(ans, sum[i]);

	}

	
	cout << ans << endl;



	return 0;
}
