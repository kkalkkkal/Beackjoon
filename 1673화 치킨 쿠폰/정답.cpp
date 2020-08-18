#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#pragma warning(disable : 4996)

/*
강민이는 치킨 한 마리를 주문할 수 있는 치킨 쿠폰을 n장 가지고 있다. 
이 치킨집에서는 치킨을 한 마리 주문할 때마다 도장을 하나씩 찍어 주는데, 도장을 k개 모으면 치킨 쿠폰 한 장으로 교환할 수 있다.

강민이가 지금 갖고 있는 치킨 쿠폰으로 치킨을 최대 몇 마리나 먹을 수 있는지 구하여라.
단, 치킨을 주문하기 위해서는 반드시 치킨 쿠폰을 갖고 있어야 한다.
*/


int main(void)
{

	int n, k; // n은 쿠폰(치킨 1마리), k는 도장

	long long count = 0, stamp = 0;
	int temp = 0;
	int tmp;

	while (1)
	{
		tmp = scanf("%d %d", &n, &k);//쿠폰의 개수를 입력받는다.
		
		if (tmp == EOF)//입력이 끝난다면 종료한다.
		{
			break;
		}

		count = n; // 처음에 쿠폰으로 n개 구매
		stamp = n; // n개 샀으니 당연히 도장도 n개 늘어남.

		while (stamp >= k)
		{
			temp = stamp / k;
			count += temp; // 도장을 치킨으로 바꿈.
			stamp = stamp % k; // 바꾼 수 만큼 도장이 줄어듬.
			stamp += temp; // 대신 치킨을 얻은 만큼 다시 도장이 늘어남.

		}

		printf("%lld\n", count);
	}
	
	return 0;
}

