#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 상 하 좌 우
int dr[4] = {1,-1, 0, 0};
int dc[4] = {0,0,-1,1};
vector<vector<int>> adj;
vector<pair<int, int>> cores;

int T;
int max_cores;
int min_wire_len;
int N;
bool can_place(int r, int c, int dir){
  int nr = r + dr[dir];
  int nc = c + dc[dir];

  while( nr >= 0 && nr < N && nc >= 0 && nc < N){
    if (adj[nr][nc] != 0) return false;
    nr += dr[dir];
    nc += dc[dir];
  }
  return true;
}

int set_wire(int r, int c, int dir, int val) {
  int len = 0;
  int nr = r + dr[dir];
  int nc = c + dc[dir];
  
  while (nr >= 0 && nr < N && nc >= 0 && nc < N){
    adj[nr][nc] = val;
    len++;
    nr += dr[dir];
    nc += dc[dir];
  }
  return len;
}

void backtrack(int idx, int core_cnt, int wire_len){
  if (idx == cores.size()){
    if (core_cnt > max_cores){
      max_cores = core_cnt;
      min_wire_len = wire_len; 
    }
    else if (core_cnt == max_cores) {
      min_wire_len = min(min_wire_len, wire_len);
    }
    return;
  }

  if (core_cnt + ((int)cores.size() - idx) < max_cores) return;
  

  int r = cores[idx].first;
  int c = cores[idx].second;

  for (int dir = 0; dir < 4; dir++){
    if (can_place(r,c,dir)) {
      int len = set_wire(r,c,dir,2);
      backtrack(idx+1, core_cnt+1, wire_len + len);
      set_wire(r,c,dir,0);
    }
  }

  backtrack(idx+1, core_cnt, wire_len);
}

int main(int argc, char** argv)
{
	int test_case;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    
    cin >> N;
    cores.clear();
    max_cores = 0;
    min_wire_len = 1e9;
    
    adj.assign(N+1, vector<int>(N+1, 0));

    max_cores = 0;
    for (int i=0; i <N; i++){
      for (int j =0; j<N ; j++){
        cin >> adj[i][j];      
        if (adj[i][j] == 1){
          if (i>0 && i <N-1 && j > 0 && j < N-1) cores.push_back({i,j});
        }
      }
    }

    backtrack(0,0,0);
    cout << "#" << test_case << " " << min_wire_len << "\n";
	}
	return 0;
}