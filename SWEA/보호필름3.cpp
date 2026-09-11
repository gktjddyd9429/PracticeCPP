#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int D, W, K;
int total_min = 1e9;

vector<vector<int>> v;

bool check(){
  bool flag = true;

  for (int i=0; i < W; i++){
    int cnt = 1;
    bool colOk = false;
    for (int j=1; j< D; j++){
      if (v[j][i] == v[j-1][i]){
        cnt++;
      }
      else {
        cnt = 1;
      }
      if (cnt >= K) { colOk = true; continue;}
    }
    if (!colOk) return false;
  }
  return flag;
}

void changeRow(int row, int val){
  for (int i=0; i<W; i++){
    v[row][i] = val;
  }
}

void backtrack(int idx, int change_cnt){
  if (total_min <= change_cnt) return;
  if (idx == D ){
    if (!check()){
      return;
    }
    else{
      total_min = min(total_min, change_cnt);
    }

  }
  else{
    backtrack(idx+1, change_cnt);

    vector<int> temp(D);

    temp = v[idx];
    changeRow(idx, 0);
    backtrack(idx+1, change_cnt+1);
    v[idx] = temp;

    temp = v[idx];
    changeRow(idx, 1);
    backtrack(idx+1, change_cnt+1);
    v[idx] = temp;

  }
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> D >> W >> K;

    v.assign(D,vector<int>(W, 0));

    for (int i=0; i<D; i++){
      for (int j =0; j < W; j++){
        cin >> v[i][j];
      }
    }

    total_min = 1e9;

    backtrack(0,0);

    cout << "#" << test_case << " " << total_min << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}