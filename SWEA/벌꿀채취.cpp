#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int N, M, C; 

vector<vector<int>> v;
vector<vector<int>> profit;

int maxSubProfit;

int ans=0;


void dfs(int r, int c, int idx, int sum, int pSum){
  if (sum > C) return;

  if (idx == M){
    maxSubProfit = max(maxSubProfit, pSum);
    return;
  }
  else{
    dfs(r,c, idx+1, sum+ v[r][c+idx], pSum + v[r][c+idx]*v[r][c+idx]);
    dfs(r,c, idx+1, sum, pSum);
  }
}


int getmaxProfit(int r, int c){
  maxSubProfit = 0;
  dfs(r,c,0,0,0);
  return maxSubProfit;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N >> M >> C;

    v.assign(N,vector<int>(N));
    profit.assign(N,vector<int>(N));

    ans=0;

    for (int i=0; i<N; i++){
      for (int j=0; j<N; j++){
        cin >> v[i][j];
      }
    }

    for (int i=0; i< N; i++){
      for (int j=0; j<=N-M; j++){
        profit[i][j] = getmaxProfit(i,j);
      }
    }
    

    for (int i1 =0; i1< N; i1++){
      for (int j1=0; j1<=N-M; j1++){

        for (int i2=0; i2<N; i2++){
          for (int j2=0;j2<= N-M; j2++){
            if(i1==i2 && abs(j1- j2) < M) continue;
            ans = max(ans, profit[i1][j1] + profit[i2][j2]);
          }
        }
      }
    }

    cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}