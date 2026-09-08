#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<vector<int>> v;
vector<pair<int,int>> t; 
vector<vector<bool>> visited;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int N, K;
int max_len=0;
void backtrack(int r, int c, int cnt, bool used){
  max_len = max(max_len, cnt);

  for (int i=0; i<4; i++){
    int nr = r +dr[i];
    int nc = c +dc[i];
    if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

    if (v[nr][nc] < v[r][c] && !visited[nr][nc]){
      visited[nr][nc]=true;
      backtrack(nr, nc, cnt+1, used);
      visited[nr][nc]=false;
    }
    else if (!used && v[nr][nc] - K < v[r][c] && !visited[nr][nc]){
      int temp = v[nr][nc];
      v[nr][nc] = v[r][c] - 1;
      visited[nr][nc]=true;
      backtrack(nr,nc, cnt+1, true);
      visited[nr][nc]=false;
      v[nr][nc] = temp;
    }
  }
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
  
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N >> K;

    v.assign(N, vector<int>(N,0));
    max_len = 0;

    for (int i=0; i< N; i++){
      for(int j=0; j<N; j++){
        cin >> v[i][j];
      }
    }

    int temp=0;

    for (int i=0; i< N; i++){
      for(int j=0; j<N; j++){
        if(v[i][j] > temp){
          temp = v[i][j];
          t.clear();
          t.push_back({i,j});
        }
        else if (v[i][j] == temp){
          t.push_back({i,j});
        }
      }
    }

    for(int i=0; i< t.size(); i++){
      visited.assign(N, vector<bool>(N,false));
      visited[t[i].first][t[i].second] = true;
      backtrack(t[i].first, t[i].second, 1, false);
    }


    cout << "#" << test_case << " " << max_len << "\n";

  }
  return 0;//정상종료시 반드시 0을 리턴해야합니다.   
}