#include <iostream>
#include <string>
#include <algorithm> //tried to parse key from string using erase
#include <sstream> //used for key 
using namespace std;

//pseudocode from textbook
//variables from both book and pdf

struct node{
	int key;
	node* left;
	node* right;
	node* parent;
};

/*int parsestrtoint(string input, int key){
	string removal = "id";
	for(char c: removal){
		input.erase(remove(input.begin(),input.end(), c), input.end()); //parsing int from string
	}
	key = stoi(input);
	return key;
}*/

void inordertreewalk(node* &x){ //(tree)
	if(x != NULL){
		inordertreewalk(x->left);
		cout << x->key << endl;
		inordertreewalk(x->right);
	}
}

void preordertreewalk(node* &x){ //(tree)
	if(x != NULL){
		cout << x->key << endl;
		preordertreewalk(x->left);
		preordertreewalk(x->right);
	}
}

void postordertreewalk(node* &x){ //(tree)
	if(x != NULL){
		postordertreewalk(x->left);
		postordertreewalk(x->right);
		cout << x->key << endl;
	}
}

node* treesearch(node* x, int k){ //(tree, key)
	if(x == NULL || k == x->key){
		return x;
	}
	if(k < x->key){
		return treesearch(x->left, k);
	}
	else return treesearch(x->right, k);
}

void treeinsert(node* &T, int z){ //(tree, key)
	node* y = NULL;
	node* x = T;
	node* znode = new node();
	
	znode->key = z;
	
	while(x != NULL){
		y = x;
		if(znode->key < x->key){
			x = x->left;
		}
		else x = x->right;
	}
	
	znode->parent = y;
	
	if(y == NULL){
		T = znode;
	}
	else if(znode->key < y->key){
		y->left = znode;
	}
	else y->right = znode;
}

node* treeminimum(node* &x){
	while(x->left != NULL){
		x = x->left;
	}
	return x;
}

/*node* treemaximum(node* &x){
	while(x->right != NULL){
		x = x->right;
	}
	return x;
}*/ //NEVER EVEN USED! RHEEEEE

void transplant(node* &T, node* &u, node* &v){
	if(u->parent == NULL){
		T = v;
	}
	else if(u == u->parent->left){
		u->parent->left = v;
	}
	else u->parent->right = v;
	
	if(v != NULL){
		v->parent = u->parent;
	}
}

void treedelete(node* &T, int z){ //(tree, key)
	node* znode = treesearch(T, z);
	if(znode->left == NULL){
		transplant(T, znode, znode->right);
	}
	else if(znode->right == NULL){
		transplant(T, znode, znode->left);
	}
	else{ 
		node* y = treeminimum(znode->right);
		if(y->parent != znode){
			transplant(T, y, y->right);
			y->right = znode->right;
			y->right->parent = y;
		}
	transplant(T, znode, y);
	y->left = znode->left;
	y->left->parent = y;
	}
}

int main(){
	node* tree = NULL;
	
	int key;
	
	string input;
	cin >> input;
	//cout << "input: " << input << endl; //used to test
	//key = parsestrtoint(input, key);
	//cout << "parsed: " << input << "\n"; //used to test
	//cout << "int: " << key << endl; //used to test
	if(input[0] == 'e'){ //program is finished
			return 1;
	}
	while(input[0] != 'e'){
		if(input[0] == 'i'){
			key = stoi(input.substr(1));
			//cout << "int: " << key << endl; //used to test
			treeinsert(tree, key);
		}
		else if(input[0] == 'd'){
			key = stoi(input.substr(1));
			//cout << "int: " << key << endl; //used to test
			treedelete(tree, key);
		}
		else if(input == "oin"){
			inordertreewalk(tree);
		}
		else if(input == "opre"){
			preordertreewalk(tree);
		}
		else if(input == "opost"){
			postordertreewalk(tree);
		}
		cin >> input;
	}
	return 0;
}
