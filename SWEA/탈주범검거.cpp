#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,M,R,C,L;

//상 하 좌 우

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int opp[4] = {1,0,3,2};

int pipe[8][4] = {
  {0,0,0,0},
  {1,1,1,1},
  {1,1,0,0},
  {0,0,1,1},
  {1,0,0,1},
  {0,1,0,1},
  {0,1,1,0},
  {1,0,1,0}
};

vector<vector<int>> v;
vector<vector<bool>> visited;

struct Node{
  int c;
  int r;
  int time;
};


int bfs(int r,int c){
  queue<Node> q;
  q.push({c,r,1});
  visited[r][c] = true;

  int count = 1;

  while(!q.empty()){
    int cr = q.front().r;
    int cc = q.front().c;
    int time = q.front().time;
    q.pop();

    if (time >= L) continue;

    int cur_pipe = v[cr][cc];

    for (int i=0; i<4; i++){
      int nr = cr + dr[i];
      int nc = cc + dc[i];

      if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
      if (visited[nr][nc] || v[nr][nc] == 0) continue;

      int next_pipe = v[nr][nc];

      if (pipe[cur_pipe][i] == 1 && pipe[next_pipe][opp[i]] == 1){
        visited[nr][nc] = true;
        q.push({nc,nr,time+1});
        count++;
      }
    }
  }
  return count;
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

    v.assign(N, vector<int>(M,0));
    visited.assign(N, vector<bool>(M,0));

    for (int i =0; i < N; i++){
      for (int j=0; j < M; j++){
        cin >> v[i][j];
      }
    }

    int total = bfs(R,C);

    cout << "#" << test_case << " " << total << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}