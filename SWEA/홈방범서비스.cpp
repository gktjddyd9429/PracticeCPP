#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;

int N, M;
int gold=0;

int total_max = 0;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N >> M;
    
    v.assign(N, vector<int>(N)); 

    for (int i=0; i<N; i++){
      for (int j=0; j<N; j++){
        cin >> v[i][j];
      }
    }
    total_max = 0;

    for (int i=0; i<N; i++){
      for (int j=0; j<N; j++){
        for (int k=1; k<=2*N+1; k++){
          int gold =0;

          for (int r=0; r< N; r++){
            for (int c=0; c<N; c++){
              if (abs(r-i) + abs(c-j) < k && v[r][c] == 1) gold++;
            }
          }
          int cost = k*k + (k-1)* (k-1);
          int temp = gold*M - cost;
          
          if (temp >= 0){
            total_max = max(total_max,gold);
          }
        }
      }
    }

    cout << "#" << test_case << " " << total_max << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}