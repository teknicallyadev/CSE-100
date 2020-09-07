#include <iostream>
#include <climits>

using namespace std;

int maxcrossSum(int arr[], int low, int mid, int high){
	//first loop is for left arr
	int sum = 0;
	int leftsum = INT_MIN; // -infinite
	
	for(int i = mid; i >= low; i--){
		sum = sum + arr[i];
		if(sum > leftsum){
			leftsum = sum;
		}
	}		
	//second loop is for right arr
	sum = 0;
	int rightsum = INT_MIN; // -infinite
	
	for(int i = mid+1; i <= high; i++){
		sum = sum + arr[i];
		if(sum > rightsum){
			rightsum = sum;
		}
	}
	
	sum = leftsum + rightsum;
	
	return sum;
}
	
int maxsubarrSum(int arr[], int low, int high){
	int mid, leftSum, rightSum, crossSum, sum;
	if(low == high){
		return arr[low]; //emergancy case for only one element in arr
	}
	else {
		mid = (low+high)/2;
		leftSum = maxsubarrSum(arr, low, mid);
		rightSum = maxsubarrSum(arr, mid+1, high);
		crossSum = maxcrossSum(arr, low, mid, high);
	}
	sum = 0;
	for(int i = low; i <= mid; i++){
		if(sum > leftSum){
			leftSum = sum;
		}
	}
	sum = 0;
	for(int i = mid+1; i<= high; i++){
		if(sum > rightSum){
			rightSum = sum;
		}
	}
	if(leftSum > rightSum && leftSum > crossSum){
		return leftSum;
	} else if(rightSum > leftSum && rightSum > crossSum){
		return rightSum;
	} else return crossSum;	
}
int main(){
	int size;
	cin >> size;
	int *arr;
	arr = new int[size];
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}
	
	int displaySum = maxsubarrSum(arr, 0, size-1);
	
	cout << displaySum;
	
	return 0;
}
