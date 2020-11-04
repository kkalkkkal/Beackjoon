#include<iostream>
using namespace std;
int n, m;
int* tree;
//union-find 알고리즘 사용

int findTree(int x) {
	if (tree[x] == x) {//루트 노드인 경우
		return x;
	}
	else {
		return tree[x] = findTree(tree[x]);//시간을 줄이기 위해 찾는 도중에 모든 자식노드를 루트노드 밑으로 옮기기
	}
}
void unionTree(int x, int y) {
	int rootX = findTree(x);
	int rootY = findTree(y);
	tree[rootY] = rootX;
}

int main(void) {
	//cin, cout 버퍼 확인하는 과정 거치지 않게함
	cin.tie(NULL);//////////////////입출력이 반복해서 나타나는 경우 꼭 해줘야 시간초과 안남
	cin >> n >> m;
	tree = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		tree[i] = i;//초기상태는 자기 자신이 루트 노드
	}
	for (int i = 0; i < m; i++) {
		int uf, x, y;
		cin >> uf >> x >> y;
		if (uf == 0) {//합집합
			unionTree(x, y);
		}
		else {//find
			if (x == y) {
				cout << "YES" << '\n';
				continue;
			}
			if (findTree(x) == findTree(y)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}

	return 0;
}
