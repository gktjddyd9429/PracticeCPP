#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;

int n;

void bubbleSort(){
  for (int i=0; i<n-1; i++){
    for (int j =0; j<n-i-1; j++){
      if (v[j] > v[j+1]) swap(v[j], v[j+1]);
    }
  }
}

int main(){
  cin >> n;

  for (int i=0; i<n; i++){
    int input;
    cin >> input;
    v.push_back(input);
  }
}