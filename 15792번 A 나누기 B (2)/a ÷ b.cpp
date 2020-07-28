#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;
#define MAXN 10000

int A, B;
long double ans;
int N, M;

int calculate(int a, int b) {

   A = (10 * a) % b;
   return (10 * a) / b;
    
};


int main(void)
{
 

    cin >> A >> B;
    
    ans = 0;

    ans = A / B; // 몫만 우선 구함.

    printf("%d", A / B);
    printf(".");
    
    A = A % B; // 나머지를 A에 넣음.

    for (int i = 1; i < 2000; i++) // 소수점 아래 계산
    {
        printf("%d", calculate(A, B));
    }

    printf("\n");
    



    return 0;
}
