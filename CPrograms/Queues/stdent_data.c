//Student data using circular queue structure
#include<stdio.h>
#include<string.h>
#define max 5
struct student
{
    int usn;
    char name[10];
    float gpa;
}s[max-1];
int r=-1;
int f;
int c;
void insert()
{
    int u;float g; char name[10];
    if(c==max)
    {
        printf("Full\n");
        return;
    }
    printf("Enter usn,name,gpa\n");
    scanf("%d%s%f",&u,name,&g);
    r=(r+1)%max;
    s[r].usn=u;
    c++;
    strcpy(s[r].name,name);
    s[r].gpa=g;
}
void display()
{
    int i,j;
    if(c==0) 
    {
        printf("Empty\n");
        return;
    }
    if(r>f)
    {
        for(i=f,j=1;i<=r;i++,j++) {
        printf("Details of student %d\n",j);
        printf("\tUSN:%d\n\tName:%s\n\tGrade:%f\n",s[i].usn,s[i].name,s[i].gpa); }
    }
    else{
        for(i=f,j=1;i<=max;i++,j++) {
            printf("Details of student %d\n",j);
            printf("\tUSN:%d\n\tName:%s\n\tGrade:%f\n",s[i].usn,s[i].name,s[i].gpa); }
        for(i=0;i<=r;i++) {
            printf("Details of student %d\n",j);
            printf("\tUSN:%d\n\tName:%s\n\tGrade:%f\n",s[i].usn,s[i].name,s[i].gpa); j++;}
    }

}
void delete()
{
    if(c==0)
    {
        printf("Empty\n");
        return;
    }
    c--;
    printf("Data of student %d is deleted\n",s[f].usn);
    f=(f+1)%max;
}
void main()
{
    int ch;
    do{
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
            break;
            case 2:
            delete();
            break;
            case 3:display();
            break;
            case 4:return;
        }
    }while(ch!=4);
}