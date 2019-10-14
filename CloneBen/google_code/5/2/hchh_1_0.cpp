	#include <iostream>
	#include <fstream>
	#include <string>
	#include <vector>
	#include <map>
	#include <iomanip>
	using namespace std;
	#define EPS 1e-8
	const double PI = acos(-1.0);


	int main()
	{
	    // open files
	    ifstream fin("B-small-attempt0.in");
	    ofstream fout("1.txt");

	    if (!fin.good())
        cout << "file is not prepared!" << endl;

	    // read the cases
	    int nCase; // number of cases
	    fin >> nCase;
	    for (int i = 1; i <= nCase; ++i)
	    {
	        int V, D;
	        fin >> V >> D;
	        double t = min (9.8 * D / (V * V * 1.0), 1.0);
	        double theta = 0.5 * asin(t) * 180 / PI;
	        fout << std::fixed << setprecision(7) << "Case #" << i << ": " << theta << endl;
	    }
	    // close files
	    fin.close();
	    fout.close();
	    return 0;
	}
