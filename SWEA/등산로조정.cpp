#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> v;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
  
  void backtrack(int r, int c, int cnt, int dig){
    

  }

	for(test_case = 1; test_case <= T; ++test_case)
	{
    int N, int K;
    cin >> N >> K;

    v.assign(N, vector<int>(N,0));

    for (int i=0; i< N; i++){
      for(int j=0; j<N; j++){
        cin >> v[i][j];
      }
    }
    
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}