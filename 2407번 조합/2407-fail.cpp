#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

//using namespace std;
#define MAXN 10000

long double ans;
long long N, M, R;
int count = 0;

long long factorial(int n) {

    if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else
    {
        return n * factorial(n - 1);
    }
};


int main(void)
{
    long long N2, M2, R2;


    std::cin >> N >> M;

    R = N - M;
    ans = 1;

    // nCm = (n!)/{m! * (n-m)!)} 이므로

    if (M > N/2)
    {
        M = N - M;
    }


    for (int i = 0; i < M; i++)
    {
        ans *= N - i; 
        ans /= M - i;
    }

   /* N2 = factorial(N);
    M2 = factorial(M);
    R2 = factorial(R);
    
    ans = N2 / (M2 * R2);*/

    printf("%.0llf", ans);

    return 0;
}
