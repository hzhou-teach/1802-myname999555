/*
Jeffrey Chen
35 minutes
10/10 test cases
4/10 difficulty
It was pretty easy for a silver problem, I just needed to remember to use long long instead of int.
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
	const char* FIN = "reststops.in";
	const char* FOUT = "reststops.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	long long l, n, rf, rb;
	cin >> l >> n >> rf >> rb;

	vector<pair<long long, long long>> stops;
	for (long long i = 0; i < n; ++i) {
		pair<long long, long long> temp;
		cin >> temp.first;
		cin >> temp.second;
		stops.push_back(temp);
	}
	vector<long long> maxAfter;
	long long curMax = 0;
	for (long long i = n - 1; i >= 0; --i) {
		if (stops[i].second >= curMax) {
			maxAfter.push_back(i);
			curMax = stops[i].second;
		}
	}
	long long curLast = 0;
	long long fresh = 0;
	for (long long i = maxAfter.size() - 1; i >= 0; --i) {
		int l = maxAfter[i];
		fresh += (stops[l].first-curLast)*(stops[l].second)*(rf-rb);
		curLast = stops[l].first;
	}
	cout << fresh << endl;

	return 0;
}