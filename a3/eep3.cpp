#include <iostream>
#include <string>
#include <sstream>
#include <vector>
/* Input: from the command line (for file I/O, redirect input file to terminal and standard output to output file)
		first line: comma-separated integers (set S); numbers do not have to be unique
		second line: integer k
*/

using namespace std;

void printThemNumbers(int a, int b, int c, int d){
	cout << a << "," << b << "," << c << "," << d << "\n";
	cout << a << "," << b << "," << d << "," << c << "\n";
	cout << b << "," << a << "," << c << "," << d << "\n";
	cout << b << "," << a << "," << d << "," << c << "\n";
}

int main(){
	// Input the set S
	cout << "Enter the set S as comma separated values:\n>> ";

	string inputStr;
	vector<int> ar;

	getline(cin, inputStr);
	stringstream ss(inputStr);

	int i;
	while (ss >> i) {
		ar.push_back(i);
		if (ss.peek() == ',' || ss.peek() == ' ') ss.ignore();
	}
	// n is the number of integers in S
	int n = ar.size();
	if (n<4){
		cout << "ERROR: S must contain at least 4 integers\n";
		return -1;
	}

	// Input K
	cout << "Enter k:\n>> ";
	int k;
	cin >> k;

	/* Generate all pairs (a,b) and (c,d) such that a + b + c*d < k , by iterating over the set.
		For every valid combination, output the solutions (a,b,c,d), (a,b,d,c), (b,a,c,d), and (b,a,d,c), since all of these are solutions if a+b+c*d < k.
	*/
	cout << "\n";
	int a, b, c, d;
	for(int i1 = 0; i1 < n; i1++){
		a = ar[i1];
		for(int i2 = i1+1; i2 < n; i2++){
			b = ar[i2];
			for(int i3 = 0; i3 < n; i3++){
				if (i3 != i1 && i3 != i2){
					c = ar[i3];
					for(int i4 = i3+1; i4 < n; i4++){
						if (i4 != i1 && i4 != i2){
							d = ar[i4];
							if(a+b+(c*d)<k){
								printThemNumbers(a, b, c, d);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
