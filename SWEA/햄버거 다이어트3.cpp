#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;

vector<int> K;
vector<int> T;

int max_total = 0;
void backtrack(int idx, int s, int Ksum, int Tsum){
  if (Ksum > L) return;
  
  max_total = max(max_total, Tsum);
  
  if (idx == N) return;
  for (int i =s; i<=N; i++){
    backtrack(idx+1,i+1,Ksum + K[i], Tsum+T[i]);
  }
  

}

int main(int argc, char** argv)
{
	int test_case;
	int R;

	cin>>R;
	
	for(test_case = 1; test_case <= R; ++test_case)
	{
    cin >> N >> L;

    K.assign(N+1,0);
    T.assign(N+1,0);

    max_total = 0;
    for (int i =1 ; i<= N; i++){
      cin >> T[i] >> K[i];
    }

    backtrack(0,1,0,0);

    cout << "#" << test_case << " " << max_total << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}