//To convert an expression from infix to postfix
#include <stdio.h>
#include<ctype.h>
#include<string.h>
char stack[20];
int top=-1;
int priority(char a)
{
   
   
    if(a=='*' || a=='/') return 3;
    else
    if(a=='^' || a=='$') return 5;
    else
    if(a=='+' || a=='-') return 2;
    
    return -1; 
}

char pop()
{
    
    return stack[top--];
}
void push(char a)
{
    stack[++top]=a;
}

int main(void) {
    char infix[20],postfix[20],sym,x;
    int i,j=0;
    stack[++top]='#';
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';i++)
    {
        sym=infix[i];
        if(isalnum(sym))
        {
            postfix[j++]=sym;
        }
        else if(sym=='(')
        {
            push(sym);
        }
        else if(sym==')')
        {
            while((x=pop())!='(')
            postfix[j++]=x;
        }
	    else if(sym=='^' && stack[top]=='^')
		    push(sym);
        else 
        {
            while(priority(stack[top])>=priority(sym))
            postfix[j++]=pop();
            push(sym);
        }
    
        
    }
        
while(stack[top]!='#')
{
    postfix[j++]=pop();
}
 postfix[j]='\0';
   
    puts(postfix);
    
    

	return 0;
}

