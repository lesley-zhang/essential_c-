#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> vec);
void bubble_sort(vector<int> vec);
void swap(int val1, int val2);

int main(){
	int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
	vector<int> vec(ia, ia+8);
	cout << "vector before sort: " << endl;
    display(vec);
    cout << endl;

    bubble_sort(vec);
    cout << "vector after sort: " << endl;
    display(vec);
    return 0; 
	
}

void display(vector<int> vec){
	for(int i=0; i<vec.size(); ++i){
		cout << vec[i];
	}
}

void bubble_sort(vector<int> vec){
	for(int ix=0; ix<vec.size(); ++ix){
		for(int jx=ix+1; jx<vec.size(); ++jx){
			if(vec[ix]>vec[jx]){
				swap(vec[ix], vec[jx]);
			}
		}
	}
}

void swap(int val1, int val2){
	int temp = val1;
	val1 = val2;
	val2 = temp;
}
