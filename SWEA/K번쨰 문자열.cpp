#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);



	int test_case;
	int T;
	

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int K;
    cin >> K;

    string s;
    cin >> s;

    set<string> substring;
    for (int i =0; i< s.length(); i++){
      string temp = "";
      for (int j =i; j < s.length(); j++){
        temp += s[j];
        substring.insert(temp);
      }
    }

    if (substring.size() < K) {
      cout << "#" << test_case << " none \n"; 
    }
    else{
      auto it = substring.begin();
      for (int i =0; i<K-1; i++){
        it++;
      }
      cout << "#" << test_case << " " << *it << "\n";
    }



	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}