#include <iostream>
#include <cstdlib> //from pdf
using namespace std;

int partition(int arr[], int p, int r){
	// x = A[r] is pivot = arr[r]; 
	int pivot = arr[r];
	int i = p -1;
	int holder; //needed to swap values
	
	for(int j = p; j < r; j++){
		if(arr[j] <= pivot){
			i++;
			holder = arr[j];
			arr[j] = arr[i]; //switches arr[j] with arr[i]
			arr[i] = holder;
		}
	}
	
	holder = arr[r];
	arr[r] = arr[i+1]; //switches arr[r] with arr[i+1]
	arr[i+1] = holder;
	
	return i+1;
}

int randomPartition(int arr[], int p, int r){
	srand (time(NULL));
	
	int random = p + rand() % (r - p);	//taken directly from cplusplus
	
	swap(arr[random], arr[r]);
	
	return partition(arr, p, r);
}

void quickSort(int arr[], int p, int r){
	if(p < r){
		int q = randomPartition(arr, p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
	}
}

int main(){
	int n = 0; //number of elements
	cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	quickSort(arr, 0, (n - 1));
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << ";";
	}
}
