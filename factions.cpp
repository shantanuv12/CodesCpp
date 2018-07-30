#include <iostream>
#include <string>
using namespace std;
int Row, Col;
bool canBeVisited(char **land,int row, int col, bool **visited){
  return (row >= 0 && row < Row && col >= 0 && col < Col && !visited[row][col] && (land[row][col]!= '#'));
}

void DFS(char **land, int row, int col , bool **visited, int alphabets[]){
  static int rows[] = {-1,0,0,1};
  static int columns[] = {0,-1,1,0};
  visited[row][col] = true;
  if(land[row][col] != '.' && land[row][col] != '#'){
    alphabets[land[row][col]-'a'] += 1;
    }
  for(int k = 0; k < 4; k++){
    if(canBeVisited(land,row+rows[k],col+columns[k],visited)){
      DFS(land, row+rows[k] , col+columns[k], visited, alphabets);
    }
  }
}

void DFS_main(char **land){
  bool **visited;
  visited = new bool*[Row];
  for(int i = 0; i < Row; i++){
    visited[i] = new bool[Col];
  }
  for(int i = 0; i< Row; i++){
    for(int j = 0; j< Col; j++){
      visited[i][j] = false;
    }
  }
  int alphabets[26];
  int alphabet[27];
  for(int i = 0; i < 27; i++){
    alphabet[i] = 0;
  }
  for(int i = 0; i < Row; i++){
    for(int j = 0; j < Col; j++){
      if(land[i][j] != '#' && visited[i][j] == false){
        for(int k = 0; k < 26; k++){
          alphabets[k] = 0;
        }
        int count = 0;
        int index = 0;
        DFS(land , i, j, visited, alphabets);
        for(int k = 0; k < 26; k++){
          if(alphabets[k] > 0){
            count++;
            index = k;
          }
        }
        if(count > 1){
          alphabet[26] += 1;
        }
        if(count == 1){
          alphabet[index] += 1;
        }
      }
    }
  }
  for(int i = 0; i < 26; i++){
    if(alphabet[i] > 0){
      cout << char(i+'a') << " " << alphabet[i] << endl;
    }
  }
  cout << "contested" << " " <<alphabet[26] << endl;
}
int main(){
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int m,n;
    cin >> n >> m;
    Row = n;
    Col = m;
    char **land;
    land = new char*[Row];
    for(int k = 0; k < Row; k++){
      land[k] = new char[Col];
    }
    for(int j = 0; j < n; j++){
      for(int k = 0 ; k < m; k++){
        cin >> land[j][k];
      }
    }
    cout << "Case " << i+1 <<":"<<endl;
    DFS_main(land);
  }
}
