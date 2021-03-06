#include <iostream>
#include <climits>

using namespace std;

void merge(int arr[], int left, int middle, int right){
	int i = 0;
	int j = 0;
	int k = 0;
	int lengthLeft = middle-left+1;
	int lengthRight = right-middle;
	int holderL[lengthLeft+1]; //holds left array
	int holderR[lengthRight+1]; //holds right array
	
	for(i = 0; i < lengthLeft ; i++){ //gets values from original array and puts it into the left and right array
		holderL[i] = arr[left+i];
	}

	for(j = 0; j < lengthRight; j++){
		holderR[j] = arr[middle+j+1];
	}
	
	holderL[lengthLeft] = INT_MAX;
	holderR[lengthRight] = INT_MAX;
	
	i = 0; //gotta reset both i and j for the if statements in the k for loop
	j = 0;
	
	for(int k = left; k <= right; k++){
		if(holderL[i] <= holderR[j]){
			arr[k] = holderL[i];
			i++;
		}
		else {
			arr[k] = holderR[j];
			j++;
		}
	}
	
}

void mergesort(int *arr, int left, int right){
	
	if(left < right){
		int middle = (left+right)/2; 
		mergesort(arr, left, middle); 
		mergesort(arr, middle+1, right); 
		merge(arr, left, middle, right); 
	}
	
}

int main(){
	int length = 0;
	int *arr;
	int i = 0;
	
	cin >> length;
	arr = new int[length];
	
	for(i = 0; i < length; i++){
		cin >> arr[i];
	}
	
	mergesort(arr, 0, length-1);
	
	for(i = 0; i < length; i++){
		cout << arr[i] << ";";
	}

	return 0;
}
