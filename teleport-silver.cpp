/*
Jeffrey Chen
70 minutes
4/10 test cases
9/10 difficulty
It was pretty hard to notice that the y part of the teleporter must be on one of the endpoints of the manure. I'm not sure how to improve over my O(n^2) time
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

	int n;
	cin >> n;
	vector<pair<long long, long long>> position;
	long long minSum = 0;

	for (int i = 0; i < n; ++i) {
		pair<long long, long long> pos;
		cin >> pos.first >> pos.second;
		position.push_back(pos);
		minSum += abs(pos.first - pos.second);
	}
	
	for (int i = 0; i < n; ++i) {
		long long teleY = position[i].second;
		long long curSum = 0;
		for (int j = 0; j < n; ++j) {
			curSum += min(abs(position[j].first - position[j].second), abs(position[j].first) + abs(position[j].second - teleY));
		}
		if (curSum < minSum) {
			minSum = curSum;
		}
	}
	cout << minSum << endl;

	return 0;
}