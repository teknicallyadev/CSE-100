#include <iostream>
#include <cmath>
using namespace std;

void maxheapify(int *arr, int n, int i){
	int largest;
	int l = 2*i;
	int r = (2*i) + 1;
	if(l <= n && arr[l] > arr[i]){
		largest = l;
	}
	else{ 
		largest = i;
	}
	if(r <= n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != i){
		swap(arr[i], arr[largest]); //switch positions
		maxheapify(arr, n, largest); //loops itself with largest to become i
	}
}

void buildmaxheap(int *arr, int n){
	for(int i = floor(n/2);i >= 1; i--){
		maxheapify(arr,n,i);
	}
}

void heapsort(int *arr, int n){
	buildmaxheap(arr, n);
	for(int i = n; i >= 2; i--){
		swap(arr[1], arr[i]);
		n--;
		maxheapify(arr, n, 1);
	}
}

int main(){
	int n = 0; //number of elements
	cin >> n;
	int arr[n];
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}		
	
	heapsort(arr, n);
	
	for (int i = 1; i <= n; i++){ 
        cout << arr[i] << ";"; 
	}
	return 0;
}
