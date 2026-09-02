
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

    int roomNum=0;
    int max_num=0;

    for (int i=0; i<N; i++){
      for (int j =0; j<N; j++){
        for (int t=0; t<4; t++){
          int nx = j + dc[t];
          int ny = i + dr[t];

          if (nx<0 || nx >=N || ny<0 || ny >=N) continue;

          if (v[ny][nx] == (v[i][j]+1)){
            cnt[ny][nx] += (cnt[i][j]+1);
          }

          if (cnt[ny][nx] > max_num){
            max_num = cnt[ny][nx];
          }
        }
      }
    }

    cout << "#" << test_case << " " << max_num << "\n";
    
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}