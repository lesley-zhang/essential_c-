//#include<iostream>
//#include<vector>
//#include<fstream>
//using namespace std;
//
//ofstream ofil("text_out1");
//
//void display(const vector<int> & vec){
//	for(int i = 0; i <vec.size(); ++i){
//		cout << vec[i] << " " << endl;
//	}
//} 
//
//void swap(int &val1, int &val2){
//	int temp = val1;
//	val1 = val2;
//	val2 = temp;
//	
//}
//
////void swap(int &val1, int &val2){
////	ofil << "swap(" << val1
////	<< ", " << val2 << ")\n";
////	
////	int tamp = val1;
////	val1 = val2;
////	val2 = tamp;
////	ofil << "after swap(): val1 " << val1 << " val2: " << val2 << "\n";
////}
//
//void bubble_sort(vector<int> &vec){
//	for(int ix = 0; ix < vec.size(); ++ix) {
//		for(int jx = jx + 1; jx < vec.size(); ++jx){
//			if(vec[ix] > vec[jx]){
//				swap(vec[ix], vec[jx]);
//			}
//		}
//		
//	}
//	
//	
//}
//
//
////void bubble_sort(vector<int> vec){
////	for(int ix = 0; ix < vec.size(); ++ix){
////		for(int jx = ix + 1; jx < vec.size(); ++jx){
////			if(vec[ix] > vec[jx]){
////				ofil << "about to call swap!"
////				<< "ix: " << ix << "jx: " << jx << '\t'
////				<< "swapping: " << vec[ix] << " with " << vec[jx] << endl;
////				swap(vec[ix], vec[jx]);
////				for(int i = 0; i <vec.size(); ++i){
////						cout << vec[i] << " "  << endl;
////						}
////			}
////			cout <<endl;
////		}
////		cout << endl;
////	}
////	
////}
//
//int main(){
//	int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
//	vector<int>  vec(ia, ia + 8);
//	
//	cout << "vector before sort: ";
//	display(vec);
//	
//	bubble_sort(vec);
//	
//	cout << "vector after sort: ";
//	display(vec);
//	return 0;
//	
//}
#include <iostream>
#include <vector>
using namespace std;

//函数声明好像没用 

//void display(vector<int> & vec);
//void bubble_sort(const vector<int> & vec);
//void swap(int & val1, int & val2);




void display(const vector<int> & vec)
{
    for (int index = 0; index < vec.size(); index++)
        cout << vec[index] << " ";
    cout << endl;
}

void bubble_sort(vector<int> & vec)
{
    for(int ix = 0; ix < vec.size(); ix++)
        for(int jx = ix+1; jx < vec.size(); jx++)
            if(vec[ix] > vec[jx])
                swap(vec[ix], vec[jx]);
}

void swap(int & val1, int & val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

int main()
{
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia+8);
    cout << "vector before sort: ";
    display(vec);

    bubble_sort(vec);
    cout << "vector after sort: ";
    display(vec);
    return 0;
}
