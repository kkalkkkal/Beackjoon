#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Pos{
	public:
	int x;
	int y;
	Pos(){}
	Pos(int x, int y){
		this->x = x;
		this->y = y;
	}
};
int calChickenDistance(int N, vector<Pos> chickenHome, vector<Pos> home, vector<int> v){
	/**3. 테스트 하기**/
	//치킨집을 1로 두고, 나머지 0 (테두리는 -1)
	int **map = new int*[N+2];
	for(int i=0; i<N+2;i++){
		map[i] = new int[N+2];
		for(int j=0; j<N+2; j++){
			map[i][j] = -1; // 전부 -1로 채우고,
		}
	}
	for(int i=1; i<N+1; i++){
		for(int j=1; j<N+1; j++)
			map[i][j] = 0; // 테두리만 -1로 남기고 나머지 속은 0으로 채우기
	}
	queue<Pos> q;
	for(int i=0; i<v.size(); i++){
		Pos tmpPos = chickenHome[v[i]];
		map[tmpPos.y+1][tmpPos.x+1] = 1;
		q.push(tmpPos);
	}
	//치킨집 위치를 모두 queue에 넣어주고, BFS 탐색으로 퍼지면서 모든 map 영역의 치킨거리 계산
	//BFS 시작
	while(!q.empty()){
		Pos tmpPos = q.front();
		q.pop();
		if(map[tmpPos.y+1-1][tmpPos.x+1] == 0){
			//상
			map[tmpPos.y+1-1][tmpPos.x+1] = map[tmpPos.y+1][tmpPos.x+1] + 1;
			q.push(Pos(tmpPos.x, tmpPos.y-1));
		}
		if(map[tmpPos.y+1+1][tmpPos.x+1] == 0){
			//하
			map[tmpPos.y+1+1][tmpPos.x+1] = map[tmpPos.y+1][tmpPos.x+1] + 1;
			q.push(Pos(tmpPos.x, tmpPos.y+1));
		}
		if(map[tmpPos.y+1][tmpPos.x+1-1] == 0){
			//좌
			map[tmpPos.y+1][tmpPos.x+1-1] = map[tmpPos.y+1][tmpPos.x+1] + 1;
			q.push(Pos(tmpPos.x-1, tmpPos.y));
		}
		if(map[tmpPos.y+1][tmpPos.x+1+1] == 0){
			//우
			map[tmpPos.y+1][tmpPos.x+1+1] = map[tmpPos.y+1][tmpPos.x+1] + 1;
			q.push(Pos(tmpPos.x+1, tmpPos.y));
		}
	}
	//가정집 위치의 치킨거리를 모두 더하면 해당 test case에 대한 치킨거리 완성
	//총합 구하기
	int sum=0;
	for(int i=0; i<home.size(); i++){
		Pos tmpPos = home[i];
		sum+=(map[tmpPos.y+1][tmpPos.x+1]-1);
	}
	return sum;
}
int main() {
	/** 1. 주어진 데이터 저장 **/
	//치킨집 위치, 가정집 위치 따로 저장. map의 정보는 map의 크기만 알면 된다.
	vector<Pos> chickenHome;
	vector<Pos> home;
	int N, M;
	cin >> N >> M;
	for(int i=0; i<N;i++){
		for(int j=0; j<N; j++){
			int tmp;
			cin >> tmp;
			if(tmp==1){
				home.push_back(Pos(j, i));
			}
			else if(tmp==2){
				chickenHome.push_back(Pos(j, i));	
			}
		}
	}
	/** 2. brute force할 모든 테스트 케이스 겹치지 않게 잘 모으기 **/
	//queue를 활용하여, 모든 테스트 케이스를 겹치지 않게 만들어서 queue에 넣어주었다.
	queue<vector<int>> testCases;
	for(int i=0; i<chickenHome.size(); i++){
		vector<int> tmp;
		tmp.push_back(i);
		testCases.push(tmp);
	}
	for(int h=1; h<M; h++){
		int testCaseSize = testCases.size();
		for(int i=0; i<testCaseSize; i++){
			vector<int> outVector = testCases.front();
			testCases.pop();
			if(outVector[h-1]+1 >= chickenHome.size()){
				continue;
			}
			for(int j=outVector[h-1]+1; j<chickenHome.size(); j++){
				vector<int> newVector;
				for(int k=0; k<outVector.size(); k++){
					newVector.push_back(outVector[k]);
				}
				newVector.push_back(j);
				testCases.push(newVector);
			}
		}
	}
	int min = N*N*N; // 초기값은 일단 큰값(에이.. 치킨거리값이 아무리커야 N^3을 넘겠어..?)
	/** 4. 테스트 케이스 중에서 가장 작은 친구 찾기 **/
	while(!testCases.empty()){
		vector<int> tmpVector = testCases.front();
		testCases.pop();
		int tmp = calChickenDistance(N, chickenHome, home, tmpVector);
		min = min > tmp ? tmp : min;
	}
	cout << min << endl;
	return 0;
}
