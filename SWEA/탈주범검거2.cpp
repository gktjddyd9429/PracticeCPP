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
  {1,0,0,1},
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
  q.push({R,C,0});
  visited[R][C] = true;
  
  int total_num = 0;

  while(!q.empty()){
    int rr = q.front().r;
    int rc = q.front().c;
    int time = q.front().time;
    q.pop();

   

    for (int i=0; i<4; i++){
      int nr = rr + dr[i];
      int nc = rc + dc[i];

      if (nr < 0 || nr >= N || nc < 0 || nc >=M) continue;

      if (!visited[nr][nc] && flag[v[nr][nc]][i] == 1 && !visited[nr][nc] && flag[v[nr][nc]][opp[i]]){
        visited[nr][nc] = false;
        q.push({nr,nc,time+1});
      }
    }
  }

  return total_num; 
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N >> M >> R >> C >> L;
    v.assign(N,vector<int>(M,0));
    visited.assign(N,vector<bool>(M,0));
    for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
        cin >> v[i][j];
      }
    }

    bfs(R,C);


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}