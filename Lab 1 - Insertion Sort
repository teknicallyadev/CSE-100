#include <iostream>

using namespace std;

int main(){
  int length = 0;
  int *arr;
  int key;
  int count = 1; 
  int i, j, k;
  
  cin >> length; //takes in input of how long the array shall become
  arr = new int[length];
  
  for(i = 0; i < length; i++){ //takes values into array at index i
    cin >> arr[i];
  }
  
  //Insertion Sort
  for(j = 1; j < length; j++){ 
    key = arr[j]; //takes in value of array's index j
    i = j - 1; 
    count++;
  
    while(i >= 0 && arr[i] > key){
      arr[i+1] = arr[i];
      i--;
    }
    arr[i+1] = key;
    
    for(k = 0; k < count; k++){
      cout << arr[k] << ";";
    }
    cout << endl;
  }
  return 0;
}
