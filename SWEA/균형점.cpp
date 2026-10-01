#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

vector<int> dist;
vector<int> m;
int N;

double binarySearch(double low, double high, int i){
  if (high - low < 1e-12){
    return high;
  }

  
  double mid = (low+high)/2.0;

  double left_force = 0;

  for (int j=0; j<=i; j++){
    double d = mid -dist[j];
    left_force += m[j] / (d*d);
  }

  double right_force = 0;
  for (int j= i+1; j< N; j++){
    double d = dist[j] - mid;
    right_force += m[j] / (d*d);
  }

  if (left_force > right_force){
    return binarySearch(mid,high,i);
  }
  else{
    return binarySearch(low,mid,i);
  }

}



int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N;

    dist.clear();
    m.clear();

    
     for (int i =0; i<N; i++){
      int input; cin >> input;
      dist.push_back(input);  
     }

     for (int i=0; i<N;i++){
      int input; cin >> input;
      m.push_back(input);
     }
     cout << "#" << test_case;

     for (int i =0;i<N-1; i++){
      double low = dist[i];
      double high= dist[i+1];

      double result = binarySearch(low,high,i);

      cout << fixed << setprecision(10) <<" " << result;
     }
     cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}