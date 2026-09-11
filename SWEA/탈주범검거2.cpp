#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//상 하 좌 우
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int opp[4] = {1,0,3,2};

int flag[8][4] = {
  {0,0,0,0},
  {1,1,1,1},
  {1,1,0,0},
  {0,0,1,1},
  {1,0,0,1},
  {0,1,0,1},
  {0,1,1,0},
  {1,0,1,0},
};

vector<vector<int>> v;
vector<vector<bool>> visited;
int N, M, R, C, L;

struct Node{
  int r;
  int c;
  int time;
};

int bfs(int R, int C){
  queue<Node> q;
  q.push({R,C,1});
  visited[R][C] = true;
  
  int total_num = 1;

  while(!q.empty()){
    int cr = q.front().r;
    int cc = q.front().c;
    int time = q.front().time;
    q.pop();

    if (time >= L) continue;


    for (int i=0; i<4; i++){
      int nr = cr + dr[i];
      int nc = cc + dc[i];

      if (nr < 0 || nr >= N || nc < 0 || nc >=M) continue;
      if (v[nr][nc] == 0) continue;


      if (!visited[nr][nc] && flag[v[cr][cc]][i] == 1 &&flag[v[nr][nc]][opp[i]] == 1){
        visited[nr][nc] = true;
        q.push({nr,nc,time+1});
        total_num++;
      }
    }
  }

  return total_num; 
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N >> M >> R >> C >> L;
    v.assign(N,vector<int>(M,0));
    visited.assign(N,vector<bool>(M,false));
    for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
        cin >> v[i][j];
      }
    }

    int ans = bfs(R,C);
    cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}