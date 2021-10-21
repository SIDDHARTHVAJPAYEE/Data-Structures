#include<stdio.h>
#include<stdlib.h>
struct Node
{
int num;
struct Node *next;
};

struct Node *start;

void addAtEnd(int num)
{
struct Node *t,*j;
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->next=NULL;
if(start==NULL)
{
start=t;
}
else
{
j=start;
while(j->next!=NULL)
{
j=j->next;
}
j->next=t;
}
}

void addAtTop(int num)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->next=start;
start=t;
}

void addAtPosition(int num,int pos)
{
struct Node *t,*p1,*p2;
int x;
if(pos<0)
{
printf("Invalid Position");
return;
}
x=0;
p1=start;
while(p1!=NULL && x<pos)
{
p2=p1;
p1=p1->next;
x++;
}
if(p1==NULL && x<pos)
{
printf("Invalid position");
return;
}
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->next=NULL;
if(start==NULL)
{
start=t;
return;
}
if(p1==start)
{
t->next=start;
start=t;
return;
}
if(p1==NULL)
{
p2->next=t;
return;
}
t->next=p1;
p2->next=t;
return;
}

void traverseTopToBottom()
{
struct Node *t;
t=start;
while(t!=NULL)
{
printf("%d",t->num);
t=t->next;
}
}

void removeAt(int pos)
{
struct Node *p1,*p2;
int x;
if(pos<0)
{
printf("Invalid Position\n");
return;
}
p1=start;
x=0;
while(p1!=NULL && x<pos)
{
p2=p1;
p1=p1->next;
x++;
}
if(p1==NULL)
{
printf("Invalid Position\n");
return;
}
if(p1==start)
{
start=start->next;
free(p1);
}
else
{
p2->next=p1->next;
free(p1);
}
}

int main()
{
int num,ch,pos,x;
while(1)
{
printf("1.Enter a number to add at end:\n");
printf("2.Enter a number to add at top:\n");
printf("3.Enter a number to add at position:\n");
printf("4.Remove from certain position:\n");
printf("5.Traverse\n");
printf("6.Exit\n");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter a number to add at end:");
scanf("%d",&num);
addAtEnd(num);
}
if(ch==2)
{
printf("Enter a number to add:");
scanf("%d",&ch);
addAtTop(num);
}
if(ch==3)
{
printf("Enter the number to add:");
scanf("%d",&ch);
printf("Enter the position to add:");
scanf("%d",&pos);
addAtPosition(num,pos);
}
if(ch==4)
{
printf("Enter the position to remove:");
scanf("%d",&pos);
fflush(stdin);
removeAt(pos);
}
if(ch==5)
{
traverseTopToBottom();
}
if(ch==6)
{
break;
}
}
}