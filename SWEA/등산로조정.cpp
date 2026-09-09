#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;




vector<vector<int>> v;
vector<vector<bool>> visited;
vector<pair<int,int>> t;

int N, K;

int total_len =0;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

void backtrack(int r, int c, int cnt, bool dig ){
  total_len = max(total_len, cnt);
  
  for (int i =0; i<4; i++){
    int nr = r + dr[i];
    int nc = c + dc[i];

    if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

    if (v[nr][nc] < v[r][c] && !visited[nr][nc]){
      visited[nr][nc] = true;
      backtrack(nr,nc,cnt+1, dig);
      visited[nr][nc] = false;
    }
    else if (!dig && v[nr][nc] - K < v[r][c] && !visited[nr][nc] && v[nr][nc] >= v[r][c]){
      int temp = v[nr][nc];
      visited[nr][nc] = true;

      v[nr][nc] = v[r][c] -1;
      backtrack(nr,nc,cnt+1,true);

      v[nr][nc] = temp;
      visited[nr][nc] = false;
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

    total_len = 0;

    v.assign(N,vector<int>(N,0));

    for (int i=0; i<N; i++){
      for (int j =0; j<N; j++){
        cin >>v[i][j]; 
      }
    }

    t.clear();
    int temp=v[0][0];

    for (int i=0; i<N; i++){
      for (int j =0; j<N; j++){
        if(temp < v[i][j]){
          t.clear();
          temp = v[i][j];
          t.push_back({i,j});
        }
        else if (temp == v[i][j]){
          t.push_back({i,j});
        }
      }
    }

    for (int i=0; i<t.size(); i++){
      visited.assign(N,vector<bool>(N,false));
      visited[t[i].first][t[i].second] = true;
      backtrack(t[i].first, t[i].second, 1, false);
    }

    cout << "#" << test_case << " " << total_len << "\n";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}