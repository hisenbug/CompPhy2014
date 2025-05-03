#include <stdio.h>
#include <math.h>

void main()
{
	double y,x=1.0,y1,d;
	int i=0;
	printf("\tx\t\t(a)\t\t(b)\tFractional Error\n\n");
	for (i=0;i<9;i++)
	{
		y=sqrt(x*x+1.0)-1;
		y1=(x*x)/(sqrt(x*x+1.0)+1);
		printf("%.1E \t%.10G\t%.10G\t%.5G\n",x,y,y1,(y1-y)/y1);
		x=x/10.0;
	}
}
