#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main(){
    string user_name;
    int user_guess;
    int num_tries;              // �ܵĲ²���
    int num_right;              // �ܵ���ȷ��
    double user_score = 0.0;
    char user_rsp;				//�û���Ӧ 
    char try_again;
    bool next_seq = true;       // ��ʾ��һ������ 
    bool go_for_it = true;      // �û��������һ��
    bool got_it = false;         // �û��Ƿ�¶� 
    const int max_tries = 3;

    const int seq_size = 18;
    //����vector��ʼ�� 
    int elem_seq[seq_size] = {
        1, 2, 3,    // Fibonacci
        3, 4, 7,    // Lucas
        2, 5, 12,   // Pell
        3, 6, 10,   // Triangular
        4, 9, 16,   // Square
        5, 12, 22   // Pentagonal
    };
    vector<int> fibonacci(elem_seq, elem_seq+3);//������һ�����������һ�� 
    vector<int> Lucas(elem_seq+3, elem_seq+6);
    vector<int> Pell(elem_seq+6, elem_seq+9);
    vector<int> Triangular(elem_seq+9, elem_seq+12);
    vector<int> Square(elem_seq+12, elem_seq+15);
    vector<int> Pentagonal(elem_seq+15, elem_seq+18);

    const int max_seq = 6;
    //��ÿ�����е����ִ浽������ 
    string seq_names[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonal"
    };
    
    vector<int> * seq_addrs[max_seq] = {
        &fibonacci, &Lucas, &Pell,
        &Triangular, &Square, &Pentagonal
    };

    vector<int> *current_vec = 0;
    int seq_index = 0;
    
    srand(time(NULL));//������� 
    cout << "Enter your name: ";
    cin >> user_name;
    ifstream infile("seq_data.txt");
    
    if(!infile)
        cerr << "Oops, unable to open file!" << endl;
    else
    {
        string name;
        int nt;         // �µ��ܴ���
        int nc;         // �¶ԵĴ���
        int find = 0;
        while (infile >> name)
        {
            infile >> nt >> nc;
            if(name == user_name)//���ҵ���ǰ�û���˵���������  ������������ 
            {
                find = 1;
                num_tries = nt;
                num_right = nc;
            }
        }  
        if(find == 1){
        cout << "Welcome back, " << user_name
            << "TOT[" << nt << "]" 
            << "RIGHT[" << nc << "]" 
            << "\nGood, Luck!" << endl;
        }else
            cout << "Welcome, freshman " << user_name << endl;
    }
    
        // �û���Ҫ������ĳ������
    while (next_seq == true)
    {
        seq_index = rand() % max_seq;//���ѡȡһ������ 
        current_vec = seq_addrs[seq_index];//��ǰ������Ԫ�ص�ָ�� 
        //��ǰ����ǰ����Ԫ�ص�ָ������ò���� 
        std::cout << "The first 2 elements of the sequence are: "
                    << (*current_vec)[0] << ", " <<  (*current_vec)[1] << endl; 
        std::cout << "What is the next element?";
        int tries_cnt = 0;
        next_seq = true;
        go_for_it = true;
        got_it = false;
        // �û����²���ȷ && �û���Ҫ�ٲ�һ�� && �ܵĳ��Դ���С��3 
        while(!got_it && go_for_it && (++tries_cnt <= max_tries))
		//��һ�����ѭ���϶����Խ�ȥ 
        {
            std::cin >> user_guess;
            ++num_tries;
            //  �������ȷ
            if(user_guess ==  (*current_vec)[2])
            {
                ++num_right;//�¶ԵĴ���+1 
                std::cout << "Very good, yes, " <<   (*current_vec)[2]
                            << " is the next element in the "
                            << seq_names[seq_index] << "  sequence." << endl;
                got_it = true;//�´ξͽ���ȥ�ڲ�ѭ���ˣ���������ִ�� 
            }else{
            // ����𰸴���
                switch (tries_cnt)//�������²µĴ��� 
                {
                case 1:
                    std::cout << "Oops, Nice guess but not quite it." << endl;
                    break;
                case 2:
                    std::cout << "Sorry, Wrong a second time!" << endl;
                    break;
                case 3:
                    std::cout << "Ah, this is harder than it looks, isn't it?" << endl;
                    break;
                default:
                    std::cout << "It must be getting pretty frustrating by now!!!" << endl;
                    break;
                }

                std::cout << "do you want to continue?(y/n):" << endl;
                std::cin >> user_rsp;
                if(user_rsp == 'N' || user_rsp == 'n')
                    go_for_it = false;//��������£��ڲ�ѭ������ 
            } 
        } // �ڲ�while����
        
        //�¶��� 
        std::cout  << "Want to try another sequence? (y/n)?" << endl;
        std::cin >> try_again;
        //��Ը����ˣ��������ѭ�� 
        if(try_again == 'N' || try_again == 'n')
            next_seq = false;
    }   // ���while����
    
    ofstream outfile("seq_data.txt", ios_base::app);//д���ļ� 
    if(!outfile)
        cerr << "Oops, unable to open file!" << endl;
    else
    {
        outfile << user_name << ' '
                << num_tries << ' ' 
                << num_right << endl;
    }
    
    
    return 0;

}
