#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
/*	Takes a set S of integers and a number k and prints out all combinations (a, b, c, d) such that a + b+ c*d < k.
	Input: from the command line (for file I/O, redirect input file to terminal and standard output to output file)
		first line: comma-separated integers (set S); numbers do not have to be unique
		second line: integer k
	Output: to the command line, tuples (a,b,c,d) printed on new lines.
*/

using namespace std;
/* For every valid combination, output the solutions (a,b,c,d), (a,b,d,c), (b,a,c,d), and (b,a,d,c), since all of these are solutions if a+b+c*d < k, as addition & multiplication of integers is commutative.
*/
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

	/* gets the first input line as a string and create a stringstream */
	getline(cin, inputStr);
	stringstream ss(inputStr);

	/* stringstream (ss) parses the largest integer from input string and inserts it into vector (ar)
	then it peeks at the string & ignores all spaces and one comma. then it loops. */

	int i;
	while (ss >> i) {
		ar.push_back(i);
		while (ss.peek() == ' ') ss.ignore();
		if (ss.peek() == ',') ss.ignore();
		while (ss.peek() == ' ') ss.ignore();
	}
	/* n is the number of integers in S */
	int n = ar.size();
	if (n<4){
		cout << "ERROR: S must contain at least 4 integers\n";
		return -1;
	}
	/* sort the vector */
	sort(ar.begin(), ar.end());
	/* Input K */
	cout << "Enter k:\n>> ";
	int k;
	cin >> k;

	/* Generate all pairs (a,b) and (c,d) such that a + b + c*d < k , by iterating over the set.
		For every valid combination, output the solutions (a,b,c,d), (a,b,d,c), (b,a,c,d), and (b,a,d,c), since all of these are valid solutions if a+b+c*d < k.
	*/
	cout << "\n";
	int a, b, c, d;
	for(int i1 = 0; i1 < n; i1++){
		a = ar[i1];
		// check for unique value of a
		if (i1>0 && a==ar[i1-1]) continue;
		// a & b can be interchanged since addition of integers is commutative
		for(int i2 = i1+1; i2 < n; i2++){
			b = ar[i2];
			// check for unique value of b
			if (i2>i1+1 && b==ar[i2-1]) continue;
			for(int i3 = 0; i3 < n; i3++){
				if (i3 != i1 && i3 != i2){
					c = ar[i3];
					// check for unique value of c
					if (i3>0 && c==ar[i3-1]) continue;
					// c & d can be interchanged since multiplication of integers is also commutative
					for(int i4 = i3+1; i4 < n; i4++){
						if (i4 != i1 && i4 != i2){
							d = ar[i4];
							// check for unique value of d
							if (i4>i3+1 && d==ar[i4-1]) continue;
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
