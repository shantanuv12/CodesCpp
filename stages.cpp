#include <iostream>
using namespace std;

char[] sort(char[] array){
  for(int i=0;i<array.size();i++){
    for(int j=i+1;j<array.size();j++){
      if(array[i]>array[j]){
        char temp = array[i];
        array[j] = array[i];
        array[i] = array[j];
      }
    }
  }
  return array;
}

int main(){
  

}
