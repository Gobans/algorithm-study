#include <stdio.h>

long long int external_product(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return ((long long int)x1*y2 - (long long int)x2*y1 + (long long int)x2*y3 - (long long int)x3*y2 + (long long int)x3*y1 - (long long int)x1*y3);
}

int main()
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;

	scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	int tmp1, tmp2;
	if(external_product(x1, y1, x2, y2, x3, y3) > 0)
		tmp1 = 1;
	else
		tmp1 = -1;
	if(external_product(x1, y1, x2, y2, x4, y4) > 0)
		tmp2 = 1;
	else
		tmp2 = -1;

	int tmp3, tmp4;
	if(external_product(x3, y3, x4, y4, x1, y1) > 0)
		tmp3 = 1;
	else
		tmp3 = -1;
	if(external_product(x3, y3, x4, y4, x2, y2) > 0)
		tmp4 = 1;
	else
		tmp4 = -1;

	if(tmp1*tmp2 == -1 && tmp3*tmp4 == -1)
		printf("1");
	else
		printf("0");
}