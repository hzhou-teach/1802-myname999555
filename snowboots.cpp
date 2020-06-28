/*
Jeffrey Chen
60 minutes
7/10 test cases
8/10 difficulty
I used a greedy algorithm to solve it, which worked for some of the test cases but gave the wrong answer for other cases.
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
	const char* FIN = "snowboots.in";
	const char* FOUT = "snowboots.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	int n, b;
	cin >> n >> b;
	vector<int> depth;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		depth.push_back(x);
	}
	vector<pair<int, int>> boots;
	for (int i = 0; i < b; ++i) {
		pair<int, int> bootSize;
		cin >> bootSize.first >> bootSize.second;
		boots.push_back(bootSize);
	}
	int discard = 0;
	int pos = 0;
	while (pos < n-1) {
		bool pass = true;
		for (int i = min(boots[discard].second + pos, n-1); i > pos; --i) {
			if (depth[i] <= boots[discard].first) {
				pos = i;
				pass = false;
				break;
			}
		}
		//cout << pos << " ";
		if (pass) {
			++discard;
			while (boots[discard].first < depth[pos]) {
				++discard;
			}
		}
	}	
	cout << discard << endl;


	return 0;
}
