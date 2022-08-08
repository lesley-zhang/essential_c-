#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string user_name;
    int user_guess;
    int num_tries;              // �ܵĲ²���
    int num_right;              // �ܵ���ȷ��
    double user_score = 0.0;
    char user_rsp;
    char try_again;//�ٴγ��� 
    bool next_seq = true;       // ��ʾ��һ������ 
    bool go_for_it = true;      // �û��������һ��
    bool got_it = false;         // �û��Ƿ�¶� 
    const int max_tries = 3;

    const int seq_size = 18;
    const int max_seq = 6;
    int elem_seq[seq_size] = {
        1, 2, 3,    // Fibonacci
        3, 4, 7,    // Lucas
        2, 5, 12,   // Pell
        3, 6, 10,   // Triangular
        4, 9, 16,   // Square
        5, 12, 22   // Pentagonal
    };
    string seq_names[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonal"
    };
    int cur_index = 0;


    // �û���Ҫ������ĳ������
    while (next_seq == true && cur_index < seq_size)
    {
        // ��ʾ���е�ǰ��������
        std::cout << "The first 2 elements of the sequence are: "
                    << elem_seq[cur_index] << ", " << elem_seq[cur_index+1] << endl;
        std::cout << "What is the next element?";
        int tries_cnt = 0;
        next_seq = true;
        go_for_it = true;
        got_it = false;
        // �û����²���ȷ && �û���Ҫ�ٲ�һ��
        while(!got_it && go_for_it && (++tries_cnt <= max_tries))
        {
            std::cin >> user_guess;
            ++num_tries;
            //  �������ȷ
            if(user_guess == elem_seq[cur_index+2])
            {
                ++num_right;//�¶��� 
                std::cout << "Very good, yes, " << elem_seq[cur_index+2]
                            << " is the next element in the "
                            << seq_names[cur_index/3] << "  sequence." << endl;
                got_it = true;
            }else{
            // ����𰸴���
                switch (tries_cnt)
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
                    go_for_it = false;
            } 
        } // �ڲ�while����
        std::cout  << "Want to try another sequence? (y/n)?" << endl;
        std::cin >> try_again;
        if(try_again == 'N' || try_again == 'n')
            next_seq = false;
        else
            cur_index += 3;
    }   // ���while����
    
    return 0;
}
