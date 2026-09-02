#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> visited;

int startX = 0,startY = 0;
int endX =0, endY = 0;
bool success = false;

// 하, 상, 우, 좌
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

void dfs(int x, int y){
  visited[y][x] = true;
  if (x==endX && y==endY) {success = true; return; } 
  for (int i=0; i<4; i++){
    int nx = x + dc[i];
    int ny = y + dr[i];
    if(!visited[ny][nx] && (adj[ny][nx] == 0 || adj[ny][nx] == 3)){
      dfs(nx,ny);
    }
  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

  T=10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int n;
    cin >> n;
    // 상관없는 것.
    adj.assign(16,vector<int>(16,0));
    visited.assign(16,vector<bool>(16,false));
    success = false;
    
    
    for (int i=0; i<16; i++){
      string s;
      cin >> s;
      for (int j=0; j<16; j++){
        adj[i][j] = s[j] - '0';
        if (adj[i][j] == 2) {
          startX = j;
          startY = i;
        }
        if (adj[i][j] == 3){
          endX = j;
          endY = i;
        }
      }
    }

    dfs(startX,startY);


    if (success) cout << "#" << test_case << " 1" << "\n"; 
    else cout << "#" << test_case << " 0" << "\n"; 
	}
	return 0;
}