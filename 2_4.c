#include <stdio.h>
#include <math.h>
void main()
{
	double y,x,x1,x2;
	int i;
	x1=1.0/3.0;
	y=x1;
	x2=1.0/9.0;
	printf("n\tRecursive\tActual \n\n");
	for(i=3;i<51;i++)
	{
		x=(13.0/3.0)*x2-(4.0/3.0)*x1;
		x1=x2;
		x2=x;
		if(i==15 || i==30 || i==40 || i==50)
		{
			x=pow(y,i);
			printf("%d\t%G\t%G\n",i,x2,x);
		}
	}
}
