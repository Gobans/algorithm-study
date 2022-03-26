#include <stdio.h>

int main()
{
	int x1, x2, x3;
	int y1, y2, y3;

	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	int ccw = x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3;
	if(ccw >0)
		printf("1\n");
	else if( ccw<0)
		printf("-1\n");
	else
		printf("0\n");
}