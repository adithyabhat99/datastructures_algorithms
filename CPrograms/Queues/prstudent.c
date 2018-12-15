/*Priority Queue based on usn of students and deleting based on position using array implementation*/
#include<stdio.h>
#include<string.h>
#define max 5
struct student 
{
    int usn;
    char name[10];
    float grade;
}s[max-1];
int f,r=-1;
void insert()
{
    if(r==max-1)
    {
        printf("Queue is fll\n");
        return;
    }
    else
    {
        int u; float g; char name[10];
        printf("Enter usn,name,grade\n");
        scanf("%d%s%f",&u,name,&g);
        if(r==-1 || s[r].usn<u)
        {
            s[++r].usn=u;
            strcpy(s[r].name,name);
            s[r].grade=g;
            return;
        }
        else{
            int i,j;
            for(i=f;i<=r;i++)
            {
                if(s[i].usn>u)
                {
                    for(j=r;j>=i;j--)
                        s[j+1]=s[j];
                    s[i].usn=u;
                    strcpy(s[i].name,name);
                    s[i].grade=g;
                    r++;
                    return;
                }
            }
        }
    }
}
void display()
{
    int i,j;
    if(r==-1)
    {
        printf("Empty\n");
        return;
    }
    for(i=f,j=1;i<=r;i++,j++)
    {
        printf("Details of student %d\n",j);
        printf("\tUSN:%d\n\tName:%s\n\tGrade:%f\n",s[i].usn,s[i].name,s[i].grade);
    }
}
void delete(int n)
{
    int i,j;
    if(r==-1)
    {
        printf("Empty\n");
        return;
    }
    if(n<f || n>r)
    {
        printf("Invalid position\n");
        return;
    }
    for(i=f;i<=r;i++)
    {
      if(i==n)
      {
          for(j=i-1;j>=f;j--)
            s[j+1]=s[j];
          f++;
          break;
      }  
    }
    if(f>r)
    {
        f=0; r=-1;
    }
}
void main()
{
    int ch,i;
    do{
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
            break;
            case 2:printf("Enter position between %d and %d\n",f,r);
            scanf("%d",&i);
            delete(i);
            break;
            case 3:display();
            break;
            case 4:return;
        }
    }while(ch!=4);
}
