
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> cnt;
// 하, 상, 우, 좌 
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    v.assign(N, vector<int>(N, 0));
    cnt.assign(N, vector<int>(N, 0));

    for (int i=0; i<N; i++){
      for (int j =0; j<N; j++){
        cin >> v[i][j];
      }
    }

    vector<bool> canGo(N*N+1,false);

    for (int i=0; i<N; i++){
      for (int j =0; j<N; j++){
        for (int i=0; i<4; i++){
          int nx = j + dc[i];
          int ny = i + dr[i];

          if (nx<0 || nx >=N || ny<0 || ny >=N) continue;

          if (v[ny][nx] == v[j][i]+1){
            canGo[v[j][i]] = true;
          }
        }
      }
    }

    int total_num = 0;
    int temp=0;
    int idx=0;
    for (int i=1; i<= N*N; i++){
      if(canGo[i]){
        idx = i;
        temp++;
      }
      else{
        if (total_num < temp){
          
          temp=0;
        }
      }
    }

    cout << "#" << test_case << " "  << "\n";
    
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}