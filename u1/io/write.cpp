#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name;
    int num_tries;
    int num_rights;
    ofstream outfile("1_05.txt", ios_base::app);
    bool try_again = true;
	
	while(try_again){
		cout << "do you want to end the input?(Y/N)" << endl;
		string resp;
		cin >> resp;
		if(resp=="N" || resp=="n"){
			cout << "Enter your name: ";
    		cin >> name;
    		cout << "Enter your num_tries, num_rights: ";
    		cin >> num_tries >>num_rights;
    		if (!outfile)
    		{
	 	   	   	cerr << "Oops, unable to save session data!" << endl;
    		}
			else{
        		outfile << name << ' ' 
                << num_tries << ' ' 
                << num_rights << ' ' << endl;
    			}
			try_again = true;
		}
		else{
			try_again = false;
		}
}
	
    

    return 0;
}
