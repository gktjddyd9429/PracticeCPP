#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v(100);
void dump(){
    int maxIdx=0, minIdx=0, maxVal=0, minVal=1e9;
    for (int i=0; i< 100; i++){
        if (maxVal <v[i]){
            maxVal = v[i];
            maxIdx = i;
        }
        if (minVal > v[i]){
            minVal = v[i];
            minIdx = i;
        }
    }
    v[maxIdx]--;
    v[minIdx]++;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T= 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        

        int N;
        cin >> N;
        
        for (int i=0; i< 100; i++){
            int input;
            cin >> input;
            v[i] = input;
        }

        while (N--){
            dump();
        }

        sort(v.begin(),v.end());
        cout << "#" << test_case << " " << v[99] - v[0] << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}