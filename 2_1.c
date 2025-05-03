#include <stdio.h>

int main()
{
	double s=1.0,t;
	int i=1;
	for(i=0;i<100;i++)
	{

		s=s*0.5;
		t=s+1.0;
		if(t<=1.0)
		{
			s=s*2.0;
			printf("Double: %d \t %.30g \n",i,s);
			break;
		}
	}
	return 0;
}
