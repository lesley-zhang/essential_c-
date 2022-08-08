#include<iostream>
#include<fstream>
using namespace std;

int main(){
	string name;
	int num_tries;
	int num_rights;
	ifstream infile("1_05.txt");
	
	if(!infile){
		cerr << "can not open file." << endl;
	}
	else{
		//注意这个循环条件 
		while(infile >> name){
			infile >> num_tries >> num_rights;
			cout << name << endl;
			cout << num_tries << endl;
			cout << num_rights << endl;
		}
	}
	return 0;
}
