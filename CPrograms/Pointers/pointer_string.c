#include<stdio.h>
void main()
{
    int i;
    char *a[5]={
        "adithya",
        "name",
        "dope",
        "pointer",
        "string"
    };
    for(i=0;i<5;i++)
    {
        printf("%s\n",a[i]);
    }
}