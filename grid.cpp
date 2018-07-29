#include <iostream>
#include <string>

using namespace std;

string reverse(string str){
  string new_string = "";
  for(int i = str.length() -1; i >= 0; i--){
    new_string = new_string + str[i];
  }
  return new_string;
}

int count_in_string(string str, string to_match){
  int count = 0;
  int len = to_match.length();
  for(int i = 0; i <= str.length() - len ; i++){
    if(str.substr(i,len) == to_match){
      count++;
    }
  }
  return count;
}

int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    string words[n];
    string w, rev;
    int counter = 0;
    for(int j = 0; j < n; j++){
      cin >> words[j];
    }
    cin >> w;
    int w_len = w.length();
    rev = reverse(w);
    int count = 0;
    for(int k = 0; k < n; k++){
      if(words[k].length() >= w_len){
        count += count_in_string(words[k],w);
        count += count_in_string(words[k],rev);
      }
    }
    for(int l = 0; l < m; l++){
      string temp = "";
      for(int o = 0; o < n; o++){
        temp += words[o][l];
      }
      if(temp.length() >= w_len){
        count += count_in_string(temp,w);
        count += count_in_string(temp,rev);
      }
    }
    for(int k = 0; k < m; k++){
      int p = 0;
      int q = k;
      string temp = "";
      while (p < n && q < m){
        temp += words[p][q];
        p = p+1;
        q = q+1;
      }
      if(temp.length() >= w_len){
        count += count_in_string(temp,w);
        count += count_in_string(temp,rev);
      }
    }
    for(int k = 1; k < n; k++){
      int p = k;
      int q = 0;
      string temp = "";
      while(p < n && q < m){
        temp += words[p][q];
        p = p+1;
        q = q+1;
      }
      if(temp.length() >= w_len){
        count += count_in_string(temp,w);
        count += count_in_string(temp,rev);
      }
    }
    for(int k = 0; k < m; k++){
      int p = 0;
      int q = k;
      string temp = "";
      while (p < n && q >-1){
        temp += words[p][q];
        p = p+1;
        q = q-1;
      }
      if(temp.length() >= w_len){
        count += count_in_string(temp, w);
        count += count_in_string(temp,rev);
      }
    }
    for(int k = 1; k < n; k++){
      int p = k;
      int q = m-1;
      string temp = "";
      while (p < n && q > -1){
        temp += words[p][q];
        p = p+1;
        q = q-1;
      }
      if(temp.length() >= w_len){
        count += count_in_string(temp, w);
        count += count_in_string(temp ,rev);
      }
    }
    cout << "Case "<< i+1<<": "<<count << endl;
  }
  return 0;
}
