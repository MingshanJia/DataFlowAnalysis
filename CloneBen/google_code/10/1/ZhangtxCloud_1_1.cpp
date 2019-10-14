#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <math.h>
#include <Windows.h>
#include <time.h>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <utility>
using namespace std;


void function(int i, ifstream& in_file, ofstream& out_file)
{
    int dim;
    in_file >> dim;
    string direction;
    in_file >> direction;

    int **board = new int* [dim];
    int **result = new int* [dim];
    for(int i = 0; i < dim; i++)
    {
        board[i] = new int[dim];
        result[i] = new int[dim];
        for(int j = 0; j < dim; j++)
        {
            in_file >> board[i][j];
            result[i][j] = 0;
        }
    }

    if(direction == "left")
    {
        
        for(int i  = 0; i < dim; i++)
        {
            int label = 0;
            int j = 0;
            int last = 0;
            for(j = 0; j < dim; j++)
            {
                if(board[i][j] == 0)
                    continue;
                if(board[i][j] == last)
                {
                    result[i][label] = 2 * board[i][j];
                    label ++;
                    last = 0;
                }
                else
                {
                    if(last != 0)
                    {
                        result[i][label] = last;
                        last = board[i][j];
                        label ++;
                    }
                    else
                    {
                        last = board[i][j];
                    }
                }
                
            }
            if(last != 0)
                result[i][label] = last;
        }
    }

    if(direction == "right")
    {

        for(int i  = 0; i < dim; i++)
        {
            int label = dim - 1;
            int j = 0;
            int last = 0;
            for(j = dim - 1; j >= 0; j--)
            {
                if(board[i][j] == 0)
                    continue;
                if(board[i][j] == last)
                {
                    result[i][label] = 2 * board[i][j];
                    label --;
                    last = 0;
                }
                else
                {
                    if(last != 0)
                    {
                        result[i][label] = last;
                        last = board[i][j];
                        label --;
                    }
                    else
                    {
                        last = board[i][j];
                    }
                }

            }
            if(last != 0)
                result[i][label] = last;
        }
    }

    if(direction == "up")
    {

        for(int j  = 0; j < dim; j++)
        {
            int label = 0;
            int i = 0;
            int last = 0;
            for(i = 0; i < dim; i++)
            {
                if(board[i][j] == 0)
                    continue;
                if(board[i][j] == last)
                {
                    result[label][j] = 2 * board[i][j];
                    label ++;
                    last = 0;
                }
                else
                {
                    if(last != 0)
                    {
                        result[label][j] = last;
                        last = board[i][j];
                        label ++;
                    }
                    else
                    {
                        last = board[i][j];
                    }
                }

            }
            if(last != 0)
                result[label][j] = last;
        }
    }

    if(direction == "down")
    {

        for(int j  = 0; j < dim; j++)
        {
            int label = dim - 1;
            int i = 0;
            int last = 0;
            for(i = dim - 1; i >= 0; i--)
            {
                if(board[i][j] == 0)
                    continue;
                if(board[i][j] == last)
                {
                    result[label][j] = 2 * board[i][j];
                    label --;
                    last = 0;
                }
                else
                {
                    if(last != 0)
                    {
                        result[label][j] = last;
                        last = board[i][j];
                        label --;
                    }
                    else
                    {
                        last = board[i][j];
                    }
                }

            }
            if(last != 0)
                result[label][j] = last;
        }
    }

    out_file << "Case #"<<i<<": \n";
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            out_file << result[i][j];
            if(j != (dim - 1))
                out_file <<" ";
        }
        out_file <<"\n";
    }
}

int main()
{
    ifstream in_file;
    in_file.open("B-large.in");
    ofstream out_file;
    out_file.open("B-large.out");

    int num;
    in_file >> num;
    for(int i = 0; i < num; i ++)
    {
        function(i + 1, in_file, out_file);
    }



    

    in_file.close();
    out_file.close();
	return 0;
};