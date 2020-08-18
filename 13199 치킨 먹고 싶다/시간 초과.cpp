#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#pragma warning(disable : 4996)

/*
서울대학교 301동에는 아는 사람만 아는 “눕치킨”이란 치킨집이 있다. 
이 치킨집은 여느 치킨집처럼 치킨을 시킬 때 마다 쿠폰을 C 장 주고, 
쿠폰을 F 장 모으면 치킨을 공짜로 시킬 수 있다.

눕치킨의 단골이 아닌 두영이에게는 쿠폰으로 시키는 치킨에는 
쿠폰이 딸려나오지 않는다. 

하지만 눕치킨의 단골 손님인 상언이에게는 치킨집 아저씨가 
쿠폰으로 시키는 치킨에 쿠폰을 주신다. 

상언이와 두영이는 둘 다 M 원을 가지고 있고, 치킨의 가격은 P 원이다. 
이때, 상언이는 두영이보다 치킨을 얼마나 더 시켜먹을 수 있을까?
*/


int main(void)
{
	int T;
	int P, M, F, C;

	long long coupon1 = 0, coupon2 = 0;
	int temp = 0;
	
	long long count1 = 0, count2 = 0;

	cin >> T;

	for (size_t i = 0; i < T; i++)
	{
		cin >> P >> M >> F >> C;

		count1 = M / P; // 첫 주문으로 치킨을 최대한 시킴.
		count2 = M / P;

		coupon1 = count1 * C; // 첫 주문의 치킨 마리수 만큼 도장을 받음.
		coupon2 = count2 * C;


		while (coupon1 >= F) // 단골
		{
			temp = coupon1 / F; // 남은 쿠폰으로 시킬 수 있는 치킨 개수
			count1 += temp;
			coupon1 = coupon1 % F;
			coupon1 += temp * C; // 쿠폰으로 시켜도 개당 C개만큼 다시 쿠폰 줌.


		}

		

		while (coupon2 >= F) // 일반
		{
			temp = coupon2 / F; // 남은 쿠폰으로 시킬 수 있는 치킨 개수
			count2 += temp;
			coupon2 = coupon2 % F; // 쿠폰으로 얻은 치킨은 도장 안 줌 
		}

		printf("%lld\n", count1 - count2);

	}
	
}

