#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N,M,C;


vector<vector<int>> v;
vector<vector<int>> profit;

int maxSubProfit;

int ans=0;


void backtrack(int r, int c, int idx, int sum, int psum){
  if (sum > C) return;

  if (idx == M){
    maxSubProfit = max(maxSubProfit, psum);
    return;
  }
  else{
    backtrack(r,c,idx+1, sum + v[r][c+idx], psum + v[r][c+idx] * v[r][c+idx]);
    backtrack(r,c,idx+1, sum, psum);
  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N >> M >> C;
    
    v.assign(N, vector<int>(N,0));
    profit.assign(N, vector<int>(N,0));

    for(int i=0; i<N; i++){
      for (int j =0; j<N; j++){
        cin >> v[i][j];
      }
    }

    for (int i =0 ; i<N; i++){
      for (int j =0; j<=N-M; j++){
        maxSubProfit = 0;
        backtrack(i,j,0,0,0);
        profit[i][j] = maxSubProfit;
      }
    }
    ans = 0;

    for (int i =0; i < N; i++){
      for (int j=0; j <= N-M; j++){
        for (int k=0; k < N; k++){
          for (int t=0; t <= N-M; t++){
            if (i == k && abs(j-t) < M) continue;
            ans = max(ans, profit[i][j] + profit[k][t]); 
          }
        }
      }
    }
  cout << "#" <<test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}