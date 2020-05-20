/#include <iostream>
/#include <queue>
/#include <cstring>
using namespace std;
 
int main() {
	/** 1.정보저장 **/
	int N;
	cin >> N;
	int *arr = new int[N];
	for(int i=0; i<N; i++)
		cin >> arr[i];
	/** 2.DP **/	
	priority_queue<pair<int, int>> pq; // 앞이 현재까지의 길이, 뒤가 해당 pair의 배열에서의 값
	queue<pair<int, int>> tmpQ; // pq에서 빼는 정보들 임시저장
	pq.push(make_pair(1, arr[0]));
	for(int i=1; i<N; i++){
		//현재 값보다 작은 값이 나올때까지 빼고, 그 값들은 tmpQ에 넣음
		//못찾으면 길이 1로 해서 pq에 넣는거고,
		//찾으면 tmpQ에 있던거 다시 다 넣고 그 찾은값 길이의 +1 된값으로 pq에 넣어줌 
		int emptyFlag=1;
		while(!pq.empty()){
			if(pq.top().second < arr[i]){
				pq.push(make_pair(pq.top().first+1, arr[i]));
				emptyFlag=0;
				break;
			}
			else{
				tmpQ.push(make_pair(pq.top().first, pq.top().second));
				pq.pop();
			}
		}
		if(emptyFlag==1){
			//모든 값을 찾았는데 연결되는 수열이 없는 경우
			pq.push(make_pair(1, arr[i]));
		}
		while(!tmpQ.empty()){
			//tmpQ에 있는거 다시 다 넣어주기
			pq.push(make_pair(tmpQ.front().first, tmpQ.front().second));
			tmpQ.pop();
		}
	}
	cout << pq.top().first << endl;
	return 0;
}
