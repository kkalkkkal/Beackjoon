//https://www.acmicpc.net/problem/10799

#include <iostream>
#include <string>

using namespace std;

#define INF 1000000

int main(void)
{
	int ans =0;
	int count =0;
	
	
	int i, j;

	string str;
	


	cin >> str; // 괄호 입력

	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' ) 
		{
			if (str[i + 1] == ')') // 레이저이면
			{
				ans += count; // 쇠막대기 개수만큼 조각 추가
				i++; // 다음꺼 미리 했으니까.
			}
			else if (str[i + 1] == '(') // 그냥 쇠막대기의 시작이었으면
			{
				count++; // 쇠막대기 개수 증가
			}
			
		}
		else if (str[i] == ')')  // 쇠막대기 하나가 끝났으면
		{
			ans += 1; 
			count--;
		}
	
	}
	
	cout << ans << endl;

	return 0;
}
