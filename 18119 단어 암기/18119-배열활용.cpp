
#include <iostream>
using namespace std;
 
int N, M;
int count[10000]; // 각 행의 단어가 갖고 있는 알파벳 개수
int full[10000]; // 각 행의 단어가 갖고 있는 알파벳 최대 개수 (const임)
int bucket[10000][26]; // 입력받은 각 행의 단어가 가지는 알파벳 모음
 
void init() // 초기화
{
    cin >> N >> M; // N, M 입력받음
    for(int i = 0; i<N; i++)
        for(int j = 0; j<26; j++)
            bucket[i][j] = -1; // 입력 받지 않은 상태라는 의미로 -1을 입력
    string s;
    for (int i = 0; i < N; i++) // N개수 만큼 단어를 입력 받음.
    {
        cin >> s;
        int size = s.size();
        for (int j = 0; j < size; j++) // 단어 크기만큼 사이클
            bucket[i][s[j] - 'a'] = 1; // 알맞은 알파벳 위치에 1을 기입(기억 의미)
        for (int j = 0; j < 26; j++)
            if (bucket[i][j])  // 해당 단어에 알파벳이 존재하면
                count[i]++, full[i]++; // 알파벳 개수를 카운팅
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); // 느려터진 ios, cin, cout 의 속도 가속시킴 
                  // (이게 있어야 정답 처리됨. c++은 느려서 printf나 scanf를 써야하지만 굳이 쓰고 싶으면 이걸 써야한다고 함.)
    init();
    int flag;
    char c;
    int ans = N;
    for (int i = 0; i < M; i++)
    {
        cin >> flag >> c;
        if (flag == 1)
        {
            for (int j = 0; j < N; j++)
                if (bucket[j][c - 'a'] > 0)
                {
                    bucket[j][c-'a'] = 0;
                    count[j]--;
                    if(count[j] + 1 == full[j])
                        ans--;
                }
        }
        else
        {
            for (int j = 0; j < N; j++)
                if (!bucket[j][c - 'a'])
                {
                    bucket[j][c - 'a'] = 1;
                    count[j]++;
                    if (full[j] == count[j]) // 현재 기억하고 있는 알파벳 수와 최대치가 같으면?
                        ans++; // 정답 +1 시킴.
                }
        }
        cout << ans << "\n";
    }
}
