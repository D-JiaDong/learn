#include<iostream>
using namespace std;
int main()
{
	int x1[3], x2[3], x3[3];
	for (int i1 = 1; i1 < 4; i1++)
	{
		x1[0] = i1;
		for (int j1 = 1; j1 < 10; j1++)
		{
			if (j1 != i1)
			{
				x1[1] = j1;
				for (int k1 = 1; k1 < 10; k1++)
				{
					if (k1 != i1 && k1 != j1)
					{
						x1[2] = k1;
						for (int i2 = 1; i2 < 8; i2++)
						{
							if (i2 != i1 && i2 != j1 && i2 != k1)
							{
								x2[0] = i2;
								for (int j2 = 1; j2 < 10; j2++)
								{
									if (j2 != i1 && j2 != j1 && j2 != k1 && j2 != i2)
									{
										x2[1] = j2;
										for (int k2 = 1; k2 < 10; k2++)
										{
											if (k2 != i1 && k2 != j1 && k2 != k1 && k2 != i2 && k2 != j2)
											{
												x2[2] = k2;
												for (int i3 = 1; i3 < 10; i3++)
												{
													if (i3 != i1 && i3 != j1 && i3 != k1 && i3 != i2 && i3 != j2 && i3 != k2)
													{
														x3[0] = i3;
														for (int j3 = 1; j3 < 10; j3++)
														{
															if (j3 != i1 && j3 != j1 && j3 != k1 && j3 != i2 && j3 != j2 && j3 != k2 && j3 != i3)
															{
																x3[1] = j3;
																for (int k3 = 1; k3 < 10; k3++)
																{
																	if (k3 != i1 && k3 != j1 && k3 != k1 && k3 != i2 && k3 != j2 && k3 != k2 && k3 != i3 && k3 != j3)
																	{
																		x3[2] = k3;
																		if (2*(x1[0] * 100 + x1[1] * 10 + x1[2]) == x2[0] * 100 + x2[1] * 10 + x2[2] && 3*(x1[0] * 100 + x1[1] * 10 + x1[2]) == x3[0] * 100 + x3[1] * 10 + x3[2])
																			cout << x1[0] * 100 + x1[1] * 10 + x1[2] << ' ' << x2[0] * 100 + x2[1] * 10 + x2[2] << ' ' << x3[0] * 100 + x3[1] * 10 + x3[2] << endl;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}