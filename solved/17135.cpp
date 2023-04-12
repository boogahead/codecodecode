#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>
#include <tuple>
#include <string>
using namespace std;
vector<vector<int>>table(16, vector<int>(16));
vector<vector<int>>loc(16, vector<int>(16));
int answer = -1;
void tableout(int n, int m)
{
	cout << "\n\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << loc[i][j] << " ";
		}cout << "\n";
	}
}
int main(void)
{
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> table[i][j];
		}
	}
	for (int i = m-1; i >= 2; i--)
	{
		vector<bool>archers(m, 0);
		archers[i] = true;
		for (int j = i - 1; j >= 1; j--)
		{
			archers[j] = true;
			for (int k = j - 1; k >= 0; k--)
			{
				archers[k] = true;
				loc = table;
				int tmp = n-1;
				int count = 0;
				while (tmp > -1)
				{
					for (int x = m - 1; x >= 0; x--)
					{
						if (archers[x])
						{
							cout <<"ARCHER "<< x << " ";
							bool shot = false;
							for (int gg = 0; gg <d && tmp-gg>=0; gg++)
							{
								//for (int kk = 0; kk<d-gg&&x-kk>-1; kk++)
								//for(int kk=d-gg-1;kk>=0&&x-kk>-1;kk--)
								for (int kk = d - gg - 1; kk >= 0 && x - kk > -1; kk--)
								{
									if (loc[tmp - gg][x - kk] == 1)
									{
										loc[tmp - gg][x - kk] = 0;
										shot = true; count++;
										cout << "LEFT\n";
										tableout(n, m); 
										break;
									}
								}
								if (shot)break;
							}
							if (shot == false)
							{
								for (int gg = 0; gg < d && tmp - gg >= 0; gg++)
								{
									//for (int kk = 0; kk<d-gg&&x-kk>-1; kk++)
									//for(int kk=d-gg-1;kk>=0&&x-kk>-1;kk--)
									for (int kk = 0; kk<d - gg-1 && x + kk<m; kk++)
									{
										if (loc[tmp - gg][x + kk] == 1)
										{
											loc[tmp - gg][x + kk] = 0;
											shot = true; count++;
											cout << "RIGHT\n";
											tableout(n, m);
											break;
										}
									}
									if (shot)break;
								}
							}
						}
						//tableout(n, m);
					}
					tmp--;
					cout << "\n----------MINUS!!!!-----------\n";
					//answer = max(count, answer);
				}
				//cout << "\n";
				answer = max(count, answer);
				cout << "\n\n\n--------------------------answer " << answer << "\n";
				archers[k] = false;
			}
			archers[j] = false;
		}
		archers[i] = false;
	}
	cout << answer << "\n";
	return 0;
}