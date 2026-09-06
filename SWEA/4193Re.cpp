#include<iostream>
#include<vector>
#include<queue>

using namespace std;


vector<vector<int>> adj;
vector<vector<bool>> visited;

// 상 하 좌 우
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int N; 
int ans=0;

int startX,startY,endX,endY;

struct Node {
  int x;
  int y;
  int time;
};

int bfs(int x, int y){
  queue<Node> q;
  q.push({x,y,0});
  visited[y][x] = true;

  int time=0;

  while(!q.empty()){
    int tx = q.front().x;
    int ty = q.front().y;
    int time = q.front().time;
    q.pop();

    if (tx == endX && ty == endY) return time;

    bool need_wait = false;

    for (int i=0; i<4; i++){
      int nx = tx + dc[i];
      int ny = ty + dr[i];
  

      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

      if (!visited[ny][nx] && adj[ny][nx] == 0){
        visited[ny][nx] = true;
        q.push({nx,ny, time+1});
      }
      else if (!visited[ny][nx] && adj[ny][nx] == 2){
        if(time % 3 == 2){
          visited[ny][nx] = true;
          q.push({nx,ny, time+1});
        }
        else{
          need_wait =true;
        }
      }
    }
    if (need_wait) {
        q.push({tx, ty, time + 1});
    }
  }
  return -1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

  ios::sync_with_stdio(false);
  cin.tie(NULL);
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N;

    adj.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N,false));
    ans=0;

    for (int i=0; i<N; i++){
      for (int j=0; j<N; j++){
        cin >> adj[i][j];
      }
    }

    cin >> startX >> startY >> endX >> endY;
    ans = bfs(startX, startY);
    
    cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
