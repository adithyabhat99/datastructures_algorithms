#include<stdio.h>
int ret(char a[1000])
{ //removes 010 pattern from a binary string,counts number of steps
	int i,count=0,size=0;

	for(i=0;a[i]!='\0';i++)
		size++;
	for(i=0;i<size;i++)
	{
		if(a[i]=='0' && a[i+1]=='1' && a[i+2]=='0')
		{
			a[i+2]='1';
			count++;
		}
	}
	return count;
}
int main()
{
	char a[1000];
	printf("Enter the binary string\n");
	scanf("%s",a);
	printf("No of steps required to make the binary string beautiful is %d\n",ret(a)); 
return 0;
}
