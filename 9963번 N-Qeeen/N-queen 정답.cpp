#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

#pragma warning(disable : 4996)

/*N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
*/

int N;
int Chess[15] = { 0, }; // 체스판의 각 열
int ans = 0;
int check = 1;

void answer(int i)
{
 	if (i == N)
		ans++;
	else
	{
		for (size_t j = 0; j < N; j++)
		{
			Chess[i] = j;

			for (size_t k = 0; k < i; k++)
			{
				// 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
 				if (Chess[k] == Chess[i] || abs(Chess[i] - Chess[k]) == (i - k))
				{
					check = 0;
					break;
				}

			}

			if(check == 1)
			{ 				
				answer(i + 1);
			}

			check = 1;
		}

	}
}


int main(void)
{
	
	
	cin >> N;
	
	ans = 0;

	// 퀸은 한 행에 한 개만 있을 수 있다는 사실을 명심

	answer(0);
	


	cout << ans << endl;

	return 0;


}

