 #include <iostream>
 #include <algorithm>


#define MAX_CARD 1002
#define MAX_COST 10000

using namespace std;


int main(void)
{

    int N;
    int P[MAX_CARD];
    int D[MAX_CARD] = { 0, };
    int ans;

    cin >> N;

    for (size_t i = 1; i <= N; i++)
    {
        cin >> P[i];
    }

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            D[i] = max(D[i], P[j] + D[i - j]);
        }
        
    }

    ans = D[N];


    cout << ans << endl;
	
}
