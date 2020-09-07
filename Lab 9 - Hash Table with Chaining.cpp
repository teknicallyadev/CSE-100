#include <iostream>
#include <list>
#include <iterator>

using namespace std;
//took some code from bst lab7
void hashinsert(list<int>* hash, int key, int size){
	int position = (key%size);
	hash[position].push_front(key);
}

void hashsearch(list<int>* hash, int key, int size){
	int position = (key%size);
	int counter = 0;
	bool boolean = false;
	list<int>::iterator chain;
	for(chain = hash[position].begin(); chain != hash[position].end(); chain++){
		if(*chain == key){
			cout << key << ":FOUND_AT" << position << "," << counter << ";" << endl;
			boolean = true;
			break; //NEED TO STOP OR ELSE IT WILL KEEP GOING!
		}
		counter++;
	}
	if(!boolean){
		cout << key << ":NOT_FOUND;" << endl;
	}
}

bool hashdelete(list<int>* hash, int key, int size){
	int position = (key%size);
	int counter = 0;
	bool boolean = false;
	list<int>::iterator chain;
	for(chain = hash[position].begin(); chain != hash[position].end(); chain++){
		if(*chain == key){
			list<int>::iterator deleter = hash[position].begin();
			advance(deleter, counter); //shifts delete iterator by counter number
			hash[position].erase(deleter); 
			cout << key << ":DELETED;" << endl;
			return true;
		}
		counter++;
	}
	if(!boolean){
		cout << key << ":DELETE_FAILED;" << endl;
	}
}
void printtable(list<int>* hash, int size){
	list<int>::iterator chain;
	for(int i = 0; i < size; i++){
		cout << i << ":";
		for(chain = hash[i].begin(); chain != hash[i].end(); chain++){
			cout << *chain << "->";
		}
		cout << ";" << endl;
	}		
}

int main(){
	int size;
	cin >> size;
	
	list<int>* hash = new list<int>[size];
	
	int key;
	
	string input;
	cin >> input;
	
	if(input[0] == 'e'){//exit
		return 0;
	}
	while(input[0] != 'e'){
		if(input[0] == 'i'){ //insert
			key = stoi(input.substr(1)); //gets number from input
			hashinsert(hash, key, size);	
		}
		if(input[0] == 'd'){ //delete
			key = stoi(input.substr(1)); //gets number from input
			hashdelete(hash, key, size);
			
		}
		if(input[0] == 's'){ //search
			key = stoi(input.substr(1)); //gets number from input
			hashsearch(hash, key, size);
			
		}
		if(input[0] == 'o'){ //output table
			printtable(hash, size);
		}
		cin >> input;
	}
	return 0;//ends program
}
