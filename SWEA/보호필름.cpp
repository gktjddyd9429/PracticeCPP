#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int D, W, K;

vector<vector<int>> v;

int total_min = 1e9;

bool check(){
  for (int j=0; j < W; j++){
    int cnt = 1;
    bool pass = false;

    for (int i = 1; i < D; i++){
      if(v[i][j] == v[i-1][j]) cnt++;
      else cnt=1;

      if (cnt >=K){
        pass = true;
        break;
      }
    }

    if (!pass) return false;
  }
  return true;
}

void backtrack(int idx, int cnt){
  if (cnt > total_min) return;
  if (idx == D){
    if (check()) total_min = min(total_min, cnt);
    return;
  }
  else{
    
    backtrack(idx+1, cnt);

    vector<int> temp(W);
    for (int j=0; j< W; j++){
      temp[j] = v[idx][j]; 
    }

    for (int j = 0; j < W; j++){
      v[idx][j] = 0;
    }
    backtrack(idx+1,cnt+1);

    for (int j=0; j < W; j++){
      v[idx][j] = 1;
    }
    backtrack(idx+1,cnt+1);

    for (int j=0; j<W; j++){
      v[idx][j] = temp[j];
    }
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

    v.assign(D,vector<int>(W,0));

    total_min = 1e9;

    for (int i =0; i<D; i++){
      for (int j=0; j<W; j++){
        cin >> v[i][j];
      }
    }

    backtrack(0,0);

    if (total_min == 1e9) cout << "#" <<test_case << " " << -1 << "\n";
    else cout << "#" << test_case << " " << total_min << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}