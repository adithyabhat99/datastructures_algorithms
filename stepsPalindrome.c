#include<stdio.h>
#include<string.h>
void main()
{
	
	int s,i,c=0,x;
	char a[100];
	scanf("%s",a);
	s=strlen(a);
	for(i=0;i<s;i++)
	{
	 if(a[i]>a[s-i-1])
		{
			x=(int)a[i]-(int)a[s-i-1];
			c=c+(int)x;
           
		}
		 if(a[i]<a[s-i-1])
		{
			x=(int)a[s-i-1]-(int)a[i];
			c=c+(int)x;
			
		}

	}
	printf("%d\n",c/2);
	}
	

