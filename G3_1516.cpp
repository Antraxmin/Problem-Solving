#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 501;
vector<int> graph[MAX];  // 건물 간의 의존 관계를 저장하는 그래프
int inDegree[MAX];      // 진입 차수 배열
int buildingTime[MAX];  // 각 건물을 짓는데 걸리는 시간
int result[MAX];        // 각 건물이 완성되는 데 걸리는 최소 시간 

int main() {
    int N;
    cin >> N;       // 건물의 수 입력 
    
    for (int i = 1; i <= N; i++) {
        cin >> buildingTime[i];
        // 먼저 지어야 하는 건물 정보 입력
        while(true) {
            int x;
            cin >> x;
            if (x == -1) break;
            graph[x].push_back(i);      // i번 건물을 짓기 위한 x번 건물
            inDegree[i]++;      // i번 건물의 진입차수 증가
        }
    }
    
    queue<int> q;       // 위상 정렬을 위한 큐
    for (int i = 1; i <= N; i++) {
        //  진입 차수가 0인 건물부터 큐에 삽입
        if (inDegree[i] == 0) {     
            q.push(i);
            result[i] = buildingTime[i];        // 건물별 초기 건설 시간
        }
    }
    
    // 위상 정렬
    while (!q.empty()) {
        int temp = q.front();       // 큐의 맨 앞 원소 삭제
        q.pop();
        
        for (int next : graph[temp]) {  // 현재 정점에 연결되어 있는 인접 노드 탐색
            result[next] = max(result[next], result[temp] + buildingTime[next]);
            inDegree[next]--;   //  진입 차수 감소
            
            if (inDegree[next] == 0) {  // 진입 차수가 0이 되면 큐에 삽입
                q.push(next);
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << result[i] << '\n';
    }
    
    return 0;
}
