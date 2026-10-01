#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, E;

vector<vector<int>> adj;
vector<int> indegree;
vector<int> result;

void topology(){
  queue<int> q;

  for (int i =1; i<=N; i++){
    if(indegree[i] == 0){
      q.push(i);
    } 
  }

  for (int i =1; i<= N; i++){
    if (q.empty()) break;

    int x = q.front();
    result[i] = x;
    q.pop();

    for (int j = 0; j < adj[x].size(); j++){
      int y = adj[x][j];
      indegree[y] -=1;
      if (indegree[y] == 0){
        q.push(y);
      }
    }
  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
  T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N >> E;

    adj.assign(N+1,vector<int>());
    indegree.assign(N+1,0);
    result.assign(N+1,0);

    for (int i=1; i<= E; i++){
      int start,end;
      cin >> start >> end;
      adj[start].push_back(end);
      indegree[end]++;
    }

    topology();

    cout << "#" << test_case << " ";
    for (int i=1; i<=N; i++){
      cout << result[i] << " ";
    }

    cout << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}