#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stdio.h>
#include <iomanip>


using namespace std;

int main()
{
    ifstream input;

    input.open("A-small-attempt2.in");
    //input.open("input.txt");
    ofstream output;
    output.open("output.txt", ios::out | ios::app);
    if(input == NULL)
    {
        cerr << "cannot open file" << endl;
    }
    if(output == NULL){
        cerr << "cannot create output file" << endl;
    }
    int T;
    input >> T;
    int n = 0;
    vector<string> vec;
    string str;
    char ch;
    //input>> ch;
    input.ignore(256, '\n');
    while(n < T){
        getline(input, str);
        if(str[0] != '\n'){
            vec.push_back(str);
            cout << str << endl;
            n++;
        }

    }

    for(int i = 0; i < T; i++){
        output << "Case #"<< i+1 <<": "<< endl;
        output << "+";
        cout << (vec[i]).size() << endl;
        int len = (vec[i]).size() + 2;
        string s(len, '-');
        output << s;
        output <<"+" << endl;
        output << "| " << vec[i];
        output <<" |" <<endl;

        output <<"+";
        output << s;
        output <<"+" << endl;

    }
    output.close();
    return 0;
}
