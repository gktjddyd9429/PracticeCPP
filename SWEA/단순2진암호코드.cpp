#include<iostream>
#include<vector>
#include <string>
using namespace std;

vector<vector<int>> v;



int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int N, M;
    cin >> N >> M;

    v.assign(N,vector<int>(M, 0));
    
    vector<int> t;

    for (int i=0; i<N; i++){
      string s; cin >> s;
      for (int j=0; j<N; j++){
        v[i][j] = s[j] - '0';
      }
    }

    for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
        if (t.size() == 8){
          int temp = 0;
          int value =10000000;
          for (int k= 0; k<8; k++, value/=10){
            temp += value*t[k];
          }
          cout << temp << " ";
          t.clear();
        } 
        t.push_back(v[i][j]);
        
      }
    }




	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}