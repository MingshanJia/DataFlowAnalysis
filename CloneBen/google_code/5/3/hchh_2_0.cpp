	#include <iostream>
	#include <fstream>
	#include <string>
	#include <vector>
	#include <map>
	#include <iomanip>
	using namespace std;
	#define EPS 1e-8
	const double PI = acos(-1.0);


	void main()
	{
	    fstream infile;
	    ofstream ofile;
	    infile.open("in.in");
	    if (!infile)
	    {
	        cout<<"file open wrong!"<<endl;
	        return;
	    }
	    ofile.open("output.txt");
	    if (!infile.eof())
	    {
        int test_num(0);
	        infile>>test_num;
	        int money;
	        for (int i=0;i<test_num;i++)
	        {
	            money=0;
	            int card_number(0);
	            infile>>card_number;
	            char **card_name;
	            card_name= new char *[card_number];
	            for(int j=0;j<card_number;++j)
	                card_name[j] = new char[100];
	            infile.getline(card_name[0],100,'\n');
	            for (int j=0;j<card_number;j++)
	                infile.getline(card_name[j],100,'\n');
            char *maxstr=card_name[0];
	            for (int m=0;m<card_number-1;m++)
	            {
	                if (strcmp(card_name[m+1],maxstr)>0)
	                    maxstr=card_name[m+1];
                else
	                    money++;

	            }
	            ofile<<"Case #"<<i+1<<": "<<money<<endl;
	            for(int j=0;j<card_number;++j)
	                delete [] card_name[j];
	            delete [] card_name;
        }
	    }
    cout<<"processed."<<endl;
	    return;
	}
