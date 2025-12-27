#include <iostream>
using namespace std;

int a[10001] = { 0 };
int b[10001] = { 0 };
int num, pr, cnt = 0;

void infect(int* virus, int pr)
{
	for (int i = 1; i <= num; i++)
	{
		if (virus[i] == 1)
		{
			for (int j = 1; j <= pr; j++)
			{
				if (a[j] == i)
				{ 
					if (virus[b[j]] == 0)
						cnt++;
					virus[b[j]] = 1;
				}
				if (b[j] == i)
				{
					if (virus[a[j]] == 0)
						cnt++;
					virus[a[j]] = 1;
				}
			}
		}
	}
}

int main()
{
	cin >> num;
	cin >> pr;

	int* virus = new int[num + 1];
	virus[1] = 1;
	for (int i = 2; i <= num; i++) 
		virus[i] = 0;

	for (int i = 1; i <= pr; i++)
		cin >> a[i] >> b[i];

	for (int k = 0; k < pr; k++)
		infect(virus, pr);

	cout << cnt;

	return 0;
}