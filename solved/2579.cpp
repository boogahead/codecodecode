#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//typedef pair<int, int>info; //index,consec
//typedef pair<info, int>tot;//index, consec, total score
//alternate solution 한번 생각해볼것
int main(void)
{
	int pyo[300][3];
	vector<int>scores;
	int number;
	cin >> number;
	for (int z = 0; z < number; z++)
	{
		int tmp;
		cin >> tmp; scores.push_back(tmp);
	}
	/*
	if (number == 1) { cout << scores[0]; return 0; }
	pyo[0][1] = scores[0];
	pyo[0][2] = 0;
	pyo[1][1] = scores[1];
	pyo[1][2] = scores[1] + scores[0];
	if (number == 2) { cout << max(pyo[1][1], pyo[1][2]); return 0; }
	for (int i = 2; i < number; i++)
	{
		pyo[i][1] = max(pyo[i - 2][1], pyo[i - 2][2]) + scores[i];
		pyo[i][2] = pyo[i - 1][1] + scores[i];
	}
	cout << max(pyo[number - 1][1], pyo[number - 1][2]);*/
	

	///////////////////////////
	//alternate solution
	vector<int>answer;


}