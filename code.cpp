#include <iostream>
#include <string>
using namespace std;

int count(int a, int b ,int k){
  int counter = 0;
  for(int i = a; i <= b; i++){
    if( i % k == 0){
      counter++;
    }
  }
  return counter;
}

int main(){
  int t,a,b,k;
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> a;
    cin >> b;
    cin >> k;
    cout << "Case "<< i+1 << ": " << count(a,b,k) << endl;
  }
  
  return 0;
}
