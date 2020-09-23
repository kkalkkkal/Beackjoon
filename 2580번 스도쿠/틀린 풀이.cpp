#include<iostream>

using namespace std;

#pragma warning(disable : 4996)

#define INF 100000000000

int sudoku[10][10];
int line_count[10]; // 가로줄별 0의 개수 세기
int line_total[10]; // 가로줄별 총합

int line_count2[10]; // 세로줄별 0의 개수 세기
int line_total2[10]; // 세로줄별 총합


void init()
{
	for (size_t i = 0; i < 9; i++)
	{
		line_count[i] = 0;
		line_total[i] = 0;
		line_count2[i] = 0;
		line_total2[i] = 0;

		for (size_t j = 0; j < 9; j++)
		{
			sudoku[i][j] = INF;

		}

	}
}

int Total(int a, int b)
{
	int sum = 0;

	sum = sudoku[a - 1][b - 1] + sudoku[a - 1][b] + sudoku[a - 1][b + 1] + sudoku[a][b - 1] +
		sudoku[a][b] + sudoku[a][b + 1] + sudoku[a + 1][b - 1] + sudoku[a + 1][b] + sudoku[a + 1][b + 1];

	

	return sum;
}


int main(void)
{

	int count = 0; // 0의 개수
	init();

	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];

			if (sudoku[i][j] == 0)
			{
				count++;
				line_count[i]++;
				line_count2[j]++;
			}
			else { // 0이 아니면
				line_total[i] += sudoku[i][j];
				line_total2[j] += sudoku[i][j];

			}
		}

	}


	while (count > 0) // 다 채울 때까지 돌림
	{
		//각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
		for (size_t i = 0; i < 9; i++)
		{

			if (line_count[i] == 1) // 빈칸이 1개이면
			{
				//마지막 숫자 한개를 채움.
				for (size_t j = 0; j < 9; j++)
				{
					if (sudoku[i][j] == 0)
					{
						// 1~9의 합에서 총합을 빼면 그게 넣을 값.
						sudoku[i][j] = (45 - line_total[i]);
						line_count[i]--;
						line_count2[j]--;
						line_total[i] += sudoku[i][j];
						line_total2[j] += sudoku[i][j];
						count--;
						break;
					}
				}
			}

		}

		for (size_t j = 0; j < 9; j++)
		{
			if (line_count2[j] == 1) // 빈칸이 1개이면
			{
				//마지막 1개를 채움
				for (size_t i = 0; i < 9; i++)
				{
					if (sudoku[i][j] == 0)
					{
						// 1~9의 합에서 총합을 빼면 그게 넣을 값.
						sudoku[i][j] = (45 - line_total2[j]);
						line_count[i]--;
						line_count2[j]--;
						line_total[i] += sudoku[i][j];
						line_total2[j] += sudoku[i][j];
						count--;
						break;
					}

				}
			}

		}
		


		//굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
		int count2 = 0;

		for (size_t n = 1; n <= 3; n++)
		{
			for (size_t m = 1; m <= 3; m++)
			{
				int a = 1 + (n - 1) * 3;
				int b = 1 + (m - 1) * 3;

				int total = Total(a, b);

				count2 = 0;

				if (sudoku[a - 1][b - 1] == 0)
				{
					a = a - 1;
					b = b - 1;
					count2++;
				}
				if (sudoku[a - 1][b] == 0)
				{
					a = a - 1;
					b = b;
					count2++;
				}
				if (sudoku[a - 1][b + 1] == 0)
				{
					a = a - 1;
					b = b + 1;
					count2++;
				}
				if (sudoku[a][b - 1] == 0)
				{
					a = a;
					b = b - 1;
					count2++;
				}
				if (sudoku[a][b] == 0)
				{
					a = a;
					b = b;
					count2++;
				}
				if (sudoku[a][b + 1] == 0)
				{
					a = a;
					b = b + 1;
					count2++;
				}
				if (sudoku[a + 1][b - 1] == 0)
				{
					a = a + 1;
					b = b - 1;
					count2++;
				}
				if (sudoku[a + 1][b] == 0)
				{
					a = a + 1;
					b = b;
					count2++;
				}
				if (sudoku[a + 1][b + 1] == 0)
				{
					a = a + 1;
					b = b + 1;
					count2++;
				}


				if (count2 == 1)
				{
					sudoku[a][b] = 45 - total;
					count--;
					line_count[a]--;
					line_count2[b]--;
					line_total[a] += sudoku[a][b];
					line_total2[b] += sudoku[a][b];

				}


				
			}

		}
	}


	// 답안 제출
	for (size_t i = 0; i < 9; i++)
	{
		printf("%d %d %d %d %d %d %d %d %d\n", sudoku[i][0],
			sudoku[i][1], sudoku[i][2], sudoku[i][3], sudoku[i][4], sudoku[i][5],
			sudoku[i][6], sudoku[i][7], sudoku[i][8]);
	}

	return 0;
}
