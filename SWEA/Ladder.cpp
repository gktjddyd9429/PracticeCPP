#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// 좌 우 상
int dr[3] = {0,0,-1};
int dc[3] = {-1,1,0};

vector<vector<int>> v;  
vector<vector<bool>> visited;

int startX=0;
int startY=0;
int arriveX=0;
int arriveY=0;

void bfs(int x, int y){
  queue<pair<int,int>> q;
  visited[y][x] = true;
  q.push({x,y});

  while (!q.empty()){
    int tx= q.front().first;
    int ty= q.front().second;
    q.pop();

    for (int i=0; i<3; i++){
      int nx = tx + dc[i];
      int ny = ty + dr[i];

      if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100 ) continue;
      
      if (ny == 0){
        startX=nx;
        return;
      }

      if (v[ny][nx] == 1 && !visited[ny][nx]){
        q.push({nx,ny});
        visited[ny][nx] = true;
        break;
      }
    }
  }
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(true);
  cin.tie(NULL);
	int test_case;
	int T;
	
	T= 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int n;
    cin >> n;

    v.assign(100,vector<int>(100,0));
    visited.assign(100,vector<bool>(100,false));

    startX =0;

    for (int i=0; i<100; i++){
      for (int j =0; j<100; j++){
        cin >> v[i][j];
        if (v[i][j] == 2){
          arriveX = j;
          arriveY = i;
        }
      }
    }

    bfs(arriveX, arriveY);

    cout << "#" << test_case << " " << startX << "\n";
    
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}