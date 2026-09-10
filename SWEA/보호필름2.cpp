#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> v;


int total_min = 1e9;

bool check(){
  int flag = true;
  for (int i =0; i<M; i++){
    int c= 1;
    for (int j = 1; j<N; j++){
      if (v[j][i] == v[j-1][i]){
        c++;
      }
      else {
        c=1;
      }
      if (c >= K) break;
    }
    if (c < K) return false;
  }
  return true;;
}

void changeLine(int i, int val){
  for (int j=0; j<M; j++){
    v[i][j] = val;
  }
}

void backtrack(int idx, int med_cnt){
  if (med_cnt >= total_min) return;

  if(idx == N){
    if (check()){
      total_min = min(total_min,med_cnt);
      return;
    }
  }
  else{
    vector<int> t;
    backtrack(idx+1, med_cnt);

    t = v[idx];
    changeLine(idx,0);
    backtrack(idx+1, med_cnt+1);
    v[idx] = t;

    changeLine(idx,1);
    backtrack(idx+1, med_cnt+1);
    v[idx] = t;

  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N >> M >> K;

    v.assign(N,vector<int>(M,0));
    total_min = 1e9;

    for (int i=0; i<N; i++){
      for (int j =0; j<M; j++){
        cin >> v[i][j];
      }
    }

    backtrack(0,0);
  
  cout << "#" << test_case << " "<< total_min << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}