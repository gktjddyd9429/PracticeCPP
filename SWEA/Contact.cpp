#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;

int N;

int ans;

void bfs(int start, int depth){
  queue<pair<int,int>> q;
  q.push({start, depth});
  visited[start] = true;

  int max_length= 0;
  int max_num = 0;

  while(!q.empty()){
    int t = q.front().first;
    int len = q.front().second;
    q.pop();

    if (max_length < len) {max_num =t; max_length = len;}
    else if (max_length == len){
      max_num = max(max_num,t);
    }


    for (int i =0; i< v[t].size(); i++){
      if(!visited[v[t][i]]){
        visited[v[t][i]] = true;
        q.push({v[t][i], len+1});
      }
    }
  }

  ans = max_num;
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	int test_case;
	int T;
	
	T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    int st_node; cin >> N >> st_node;
    
    v.assign(101,vector<int>());
    visited.assign(101, false);

    for (int i=0; i < N/2; i++){
      int start, end;
      cin >> start >> end;
      v[start].push_back(end);
    }

    ans =0;

    bfs(st_node, 0);


    cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}