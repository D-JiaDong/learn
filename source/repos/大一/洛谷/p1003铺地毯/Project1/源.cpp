#include<iostream>
using namespace std;
class Dt
{
public:
	int a, b, g, k;
};
int main()
{
	int n;
	cin >> n;
	Dt d[10001];
	for (int i = 0; i < n; i++)
	{
		cin >> d[i].a >> d[i].b >> d[i].g >> d[i].k;
	}
	int x, y, z=-1;
	cin >> x >> y;
	for (int i= n - 1; i >= 0; i--)
		if (x >= d[i].a && x <= d[i].a + d[i].g && y >= d[i].b && y <= d[i].b + d[i].k)
		{
			cout << i + 1 << endl;
			z++;
			break;
		}
	if (z == -1)
		cout << z << endl;
	system("pause");
	return 0;
}