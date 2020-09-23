#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

#pragma warning(disable : 4996)

#define INF 100000000000

int bishop[11][11];
int line_count[10]; // 가로줄별 0의 개수 세기


void init()
{
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			bishop[i][j] = -1;

		}
	}
}


int main(void)
{

	int count = 0; // 0의 개수
	init();

	int N;

	cin >> N;


	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> bishop[i][j];
		}

	}

	// 대각선의 개수는 2N-1개 * 2
	// 좌우 대각선 배치중 많은 것을 우선한다.

	//↘

	int count2 = 0;

	for (size_t i = 0; i < N; i++)
	{
		count2 = 0;

		for (size_t j = 0; j <= i; j++)
		{
			if (bishop[i+j][j] == 1)
			{
				count2++;
			}
		}

		if (count2 > 0)
			count++;
		
	}

	for (size_t i = 1; i < N; i++)
	{
		count2 = 0;

		for (size_t j = 0; j < i; j++)
		{
			if (bishop[i + j][j] == 1)
			{
				count2++;
			}
		}

		if (count2 > 0)
			count++;

	}

	int a = count;

	//↙

	count = 0;

	for (size_t i = 0; i < N; i++)
	{
		count2 = 0;

		for (size_t j = 0; j <= i; j++)
		{
			if (bishop[i - j][j] == 1)
			{
				count2++;
			}
		}

		if (count2 > 0)
			count++;

	}

	for (size_t i = 1 ; i < N; i++)
	{
		count2 = 0;

		for (size_t j = 0; j < i; j++)
		{
			if (bishop[N - 1 - j][i + j] == 1)
			{
				count2++;
			}
		}

		if (count2 > 0)
			count++;
		
	}
		
	int b = count;


	//답안 출력
	printf("%d\n",max(a, b));

	return 0;
}
