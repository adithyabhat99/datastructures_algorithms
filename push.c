#include<stdio.h>
#define MAX 10
int main()
{ int a[MAX],choice,top=-1,item,i;

 do 
 { printf("Enter your choice\n1.Push\n2.Pop\n3.Display\n4.Exit");
 scanf("%d",&choice);
 switch(choice)
 {  
 	case 1:if(top==MAX-1)
           printf("Stack Overflow");
           else
           	{printf("Enter item=");
             scanf("%d",&item);
           	 top++;
           	 a[top]=item;
           	}
           	break;
    case 2:if(top==-1)
           printf("Stack underflow");
           else
           	{printf("%d is popped succesfully",a[top]);
             top--;
             }
             break;
    case 3:
           for(i=0;i<=top;i++)
           	{printf("%d",a[i]);
             }
             break;
    default: return 0;
}
}while(choice!=4);

return 0;}

