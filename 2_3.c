#include <stdio.h>
#include <math.h>

void main()
{
	double y,x,x1,x2;
	int i;
	x1=(sqrt(5.0)-1.0)/2.0;
	y=x1;
	x2=x1*x1;
	printf("n\tRecursive\tActual \n\n");
	for(i=3;i<71;i++)
	{
		x=x1-x2;
		x1=x2;
		x2=x;
		if(i==16 || i==30 || i==40 || i==50)
		{
			x=pow(y,i);
			printf("%d\t%g\t%g\n",i,x2,x);
		}
	}
}
