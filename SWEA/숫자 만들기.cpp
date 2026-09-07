#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

vector<int> op;
vector<int> num;

int total_min = 1e9;
int total_max = -1e9;

void backtrack(int idx, int n){
  if (idx >= N ){
    total_min = min(total_min, n);
    total_max = max(total_max, n);
    return;
  }
  else{
    if (op[0]){
      op[0]--;
      backtrack(idx+1, n+num[idx]);
      op[0]++;
    }
    if (op[1]){
      op[1]--;
      backtrack(idx+1, n-num[idx]);
      op[1]++;
    }
    if (op[2]){
      op[2]--;
      backtrack(idx+1, n*num[idx]);
      op[2]++;
    }
    if (op[3]){
      op[3]--;
      backtrack(idx+1, n/num[idx]);
      op[3]++;
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
    cin >> N;

    op.assign(4,0);
    
    // 0: + | 1: - | 2: * | 3: /
    for (int i=0; i<4; i++){
      cin >> op[i];
    }

    num.assign(N, 0);
    for (int i =0; i<N; i++){
      cin >> num[i];
    }

    total_min = 1e9;
    total_max = -1e9;

    backtrack(1, num[0]);

    cout << "#" << test_case << " " << total_max-total_min << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}