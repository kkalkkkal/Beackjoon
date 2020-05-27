/*https://www.acmicpc.net/problem/2512*/

#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int cost[10000]; // 요청 금액


int main(void)
{
	int N=0, M=0, total =0, upper =0 , ans =0;
	int avg =0, check =0;
	priority_queue<int> Q; // top에는 가장 큰수가, back에는 가장 작은 수가 입력
	int i, j;
	

	cin >> N; // 의 수

	for (size_t i = 0; i < N; i++) // 각 지방 요청 예산
	{
		cin >> cost[i];
		Q.push(cost[i]); // 이제 정렬된 순서로 예산안들이 입력될것.
	}

	cin >> M; // 총 예산

	for(i = 0 ; i < N ; i++)
	{
		total += cost[i];
	}

	if (total > M) // 요청 예산 초과시
	{
		avg = total / N; // 평균값 구함 - 이것이 기준이됨.
		upper = avg;
		do
		{
			check = 0;
			upper--;
			for (size_t i = 0; i < N; i++)
			{
				if (cost[i] >= upper)  //상한선보다 크면
					check += upper; // 상한선에 맞춰서 합산
				else // 상한선보다 작으면
					check += cost[i]; // 그 가격 그대로 입력
			}
			
		} while (M < check);
		
		ans = upper; // 상한선이 최대값.
	}
	else //예산 초과 안하면
	{
		ans = Q.top(); // 요청 예산 중 최대값 구하기
	}

	cout << ans << endl;

	return 0;
}
