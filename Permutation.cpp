#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<int> a = {1,2,3,4};
vector<int> t;

int R = 2;

void print_arr(){
  for(int i= R-1; i>=0; i--){
    cout<< t[i] << " ";
  }
  cout << "\n";
}

void perm(int n, int r){
  if (r==0) {
    print_arr();
  }
  else{
    for (int i = n-1; i>= 0; i--){
      swap(a[i], a[n-1]);
      t[r-1] = a[n-1];
      perm(n-1,r-1);
      swap(a[i], a[n-1]);
    }
  }
}

void PI(int n, int r) {
  if (r==0) print_arr();
  else {
    for (int i= n-1; i >=0; i--){
      swap(a[i], a[n-1]);
      t[r-1] = a[n-1];
      PI(n, r-1);
      swap(a[i], a[n-1]);
    }
  }
}

int main(){
  t.resize(R);

  perm(a.size(), R);

  return 0;
}