#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

#pragma warning(disable : 4996)

#define INF 100000000000




int main(void)
{

	int count = 0; // 0의 개수

	priority_queue<long long> Q;
	priority_queue<long long> Q2;
	priority_queue<long long> Q3;
	priority_queue<long long> Q4;
	priority_queue<long long> TEMP_Q;
	priority_queue<long long> TEMP_Q2;
	priority_queue<long long> TEMP_Q3;
	priority_queue<long long> ANS;

	int N;

	cin >> N;

	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0); // 느려터진 ios, cin, cout 의 속도 가속시킴 
			   // (이게 있어야 정답 처리됨. c++은 느려서 printf나 scanf를 써야하지만 굳이 쓰고 싶으면 이걸 써야한다고 함.)

	long long temp;

	//입력
	for (size_t i = 0; i < N * 4; i++)
	{
		cin >> temp;

		// 우선 순위 큐이기 때문에 알아서 정렬될 것이다.
		if (i % 4 == 0)
		{
			Q.push(temp);
		}
		else if (i % 4 == 1)
		{
			Q2.push(temp);
		}
		else if (i % 4 == 2)
		{
			Q3.push(temp);
		}
		else
		{
			Q4.push(temp);
		}

	}

	// 두 개씩 합을 합치기 : A+B, C+D

	long long a = 0;
	int length = 0;

	TEMP_Q = Q2; // 큐 복사

	while (!Q.empty())
	{
		a = Q.top();
		Q.pop();
		
		length = Q2.size();

		for (size_t i = 0; i < length; i++)
		{
			TEMP_Q2.push(a + Q2.top());
			Q2.pop();
		}
		
		Q2 = TEMP_Q;
	}


	TEMP_Q = Q4;

	while (!Q3.empty())
	{
		a = Q3.top();
		Q3.pop();
		length = Q4.size();

		for (size_t i = 0; i < length; i++)
		{
			TEMP_Q3.push(a + Q4.top());
			Q4.pop();
		}

		Q4 = TEMP_Q;
	}
	


	//// 다시 합치기 : A+B+C+D
	// TEMP_Q3 ( C, D) , TEMP_Q2( A , B)


	TEMP_Q = TEMP_Q3;

	while (!TEMP_Q2.empty())
	{
		a = TEMP_Q2.top();
		TEMP_Q2.pop();
		length = TEMP_Q3.size();

		for (size_t i = 0; i < length; i++)
		{
			ANS.push(a + TEMP_Q3.top());
			TEMP_Q3.pop();
		}

		TEMP_Q3 = TEMP_Q;
	}


	// 0의 개수 세기

	while (!ANS.empty())
	{
	
		if (ANS.top() == 0)
			count++;

		ANS.pop();
		
	}
	


	//답안 출력
	printf("%d\n",count);

	return 0;
}
