#include <iostream>
#include <bitset>
#include <vector>
using namespace std;


struct if_mistake{
    int num_of_mistakes = -1;
    int sum_of_mistakes = -1;
};

int massage{

};


int is_parity(int n){
    if ((n & (n-1))==0){
        return 1;
    }
    else return 0;
}


if_mistake find_mistake(string input){
    int num_of_mistakes = 0;
    int sum_of_mistakes = -1;
    if_mistake mist;
    for (int i = 0; i < input.length(); i++) {
        int n = i + 1;
        int mistake = -1;
        if (is_parity(n)) {
            int step = n;
            int sum = 0;
            for (int j = n - 1; j < input.length(); j += 2 * step) {
                for (int z = j; z < j + step - 1; z++){
                    if (input[j] == '1') {
                        sum++;
                    }
                    sum = sum % 2;
                }
            }
            if (sum == 0 and input[n] == '0')
                mistake = -1;
            else if (sum == 1 and input[n] == '1') {
                mistake = -1;
            } else {
                mistake = n;
            }
        }
        if (mistake){
            num_of_mistakes++;
            sum_of_mistakes+=mistake;
        }
        mist.num_of_mistakes = num_of_mistakes;
        mist.sum_of_mistakes = sum_of_mistakes;
    }
    return mist;
};

int main(){
    int n = 0;
    int p = 0;
    cin >> n;
    string input;
    vector<string> strings;
    vector<string> answers;
    if_mistake if_mistake;

    // strings.resize(n);
    while (cin >> input) {

        strings.push_back(input);
        string temp_str;
        temp_str.resize(input.length());
        temp_str = input;
        int sum_of_mistakes = -1;
        string new_str = "";
        if_mistake = find_mistake(temp_str);
        if (if_mistake.num_of_mistakes) {
            sum_of_mistakes = if_mistake.sum_of_mistakes;
            if (temp_str[sum_of_mistakes] == '0') {
                temp_str[sum_of_mistakes] = '1';
            } else temp_str[sum_of_mistakes] = '0';
        }
        for (int j = 0; j < input.length(); j++) {
            if (is_parity(j + 1) == 0) {
                new_str += temp_str[j];
            }
        }
        answers.push_back(new_str);
        //cout << '\n';
            cout << answers[p++] << "\n";
    }
    return 0;
}