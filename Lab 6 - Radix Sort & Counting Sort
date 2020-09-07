#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> countingsort(vector<vector<int>> vect, int j, int size) { //got vector<vector<int>> from stackoverflow
	int array[10] = {};
	int i, indexarray, indexvect;
	vector<vector<int>> vect2 = vect;
	vector<int> tempvect;

	for (i = 0; i <= size; i++) {													
		array[vect[i][j]] = array[vect[i][j]] + 1;
	}

	for (i = 1; i < 10; i++) {											
		array[i] = array[i] + array[i - 1];
	}

	for (i = size; i >= 0; i--) {													
		indexarray = vect[i][j];
		indexvect = (array[indexarray]) - 1;
		tempvect = vect[i]; //takes current value at index
		vect2[indexvect] = tempvect; //inner vector takes value of tempvect
		array[indexarray] = indexvect; 
	}
	vect = vect2;															
	return vect;															
}

void radixsort(vector<vector<int>> vect, int size) {
	int i, j;																	

	for (i = 9; i >= 0; i--) {
		vect = countingsort(vect, i, size);
	}

	for (i = 0; i <= size; i++) {
		for (j = 0; j < 10; j++) {
			cout << vect.at(i).at(j) << ";";
		}
		cout << endl;
	}
}

int main() {
	int size;	
	cin >> size;																
	
	int i, j;
	int input;	

	vector<vector<int>> vect;												

	for (i = 0; i < size; i++) {
		vector<int> vect2; //need to reinitialize vector
		for (j = 0; j < 10; j++) {
			cin >> input;
			vect2.push_back(input); //get input into inner vector
		}
		vect.push_back(vect2); //gets input into outer vector
	}
	radixsort(vect, (size - 1));
	
}

