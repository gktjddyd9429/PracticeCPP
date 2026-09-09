#include<iostream>
#include<vector>

using namespace std;

int N = 5;
int R = 3;

vector<int> arr = {1,2,3,4,5};
vector<int> selected(R);
vector<int> visited(N,false);


int main(){
  // 조합:
  for (int i =0; i<N; i++){
    for (int j = i+1; j < N; j++){

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

}
