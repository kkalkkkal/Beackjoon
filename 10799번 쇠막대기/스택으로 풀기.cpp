#include<iostream>
#include<stack>
using namespace std;
int main(void) {
	
	char s[100001] = { 0, };
	stack<char> strStack;
	cin >> s;
	int answer = 0, count = 0;
	
	for (int i = 0; i < 100000; i++) {
		if (s[i] == 0) {
			break;
		}
		else if (s[i] == '(') {
			strStack.push(s[i]);
			count++;//현재 겹쳐있는 조각의 수
		}
		else if (s[i] == ')') {
			count--;
			strStack.pop();
			if (s[i - 1] == '(') {//레이저인 경우
				answer += count;
			}
			else {
				answer += 1;
			}
			
		}
	}
	cout << answer << endl;
	
	return 0;
}
