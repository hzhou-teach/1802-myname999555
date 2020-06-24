/*
Jeffrey Chen
3 minutes
10/10 test cases
1/10 difficulty
This was too easy for a bronze problem
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, char* argv[]) {
	const char* FIN = "teleport.in";
	const char* FOUT = "teleport.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	int a, b, x, y;
	cin >> a >> b >> x >> y;
	cout << (min(abs(a - b), min(abs(a - x) + abs(y - b), abs(a-y) + abs(x-b)))) << endl;

	return 0;
}