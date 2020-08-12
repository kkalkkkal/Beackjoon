#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int sticker[3][100002] = { 0, }; // 초기화
int check[3][100002] = { 0, };



int main(void)
{
	int T, N;

	cin >> T >> N;


	for (size_t i = 0; i < T; i++) // 입력
	{
		for (size_t j = 1; j < 2 + 1; j++)
		{
			for (size_t k = 1; k < N + 1; k++)
			{
				cin >> sticker[j][k];
			}

		}



		int ans = 0;
		int count = 0;

		priority_queue<int, vector<int>, less<int>> q;

		check[1][1] = sticker[1][1];
		check[2][1] = sticker[2][1];
		q.push(check[1][1]);
		q.push(check[2][1]);


		count++;



		while (!q.empty())
		{


			check[1][count + 1] = check[2][count] + max(max(sticker[1][count + 3], sticker[2][count + 1]), sticker[2][count + 2]);
			q.push(check[1][count] + max(max(sticker[1][count + 2], sticker[2][count + 2]), sticker[2][count + 3]));

			check[2][count + 1] = check[1][count] + max(max(sticker[2][count + 3], sticker[1][count + 1]), sticker[1][count + 2]);
			q.push(check[2][count] + max(max(sticker[2][count + 2], sticker[1][count + 2]), sticker[1][count + 3]));

			count++;

			if (count == N)
			{
				cout << q.top() << endl; // 최댓값 출력
				break;
			}



		}

		while (!q.empty())
		{
			q.pop();
		}

	}

	return 0;
}

