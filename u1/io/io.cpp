#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string name;
    int num_tries;
    int num_rights;

    fstream iofile("data.txt", ios_base::in | ios_base::app);
    if(!iofile)
    {
        cerr << "Oops, unable to open file!" << endl;

    }else
    {
        iofile << "andy " << 10 << ' ' << 7 << endl;//andy������һ���ո� 
        cout << "______________________" << endl;
        string usr_name;
        int num_tries = 0;
        int num_rights = 0;
        
        // ����ios_base::app��ԭ�򣬿�ʼ��ȡ֮ǰ���뽫�ļ����¶�λ����ʼ��
        iofile.seekg(0);
        iofile >> usr_name >> num_tries >> num_rights;
        cout << "name: " << usr_name << endl;
        cout << "tot: " << num_tries << endl;
        cout << "right: " << num_rights << endl;
    }
    

    return 0;
}
