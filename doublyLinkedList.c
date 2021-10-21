#include<stdio.h>
#include<stdlib.h>
struct Node
{
int num;
struct Node *next;
struct Node *previous;
};

struct Node *start;
struct Node *end;

void addAtEnd(int num)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->next=NULL;
t->previous=NULL;
if(start==NULL)
{
start=t;
end=t;
}
else
{
end->next=t;
t->previous=end;
end=t;
}
}
void insertAtTop(int num)
{
struct Node *t;
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->next=NULL;
t->previous=NULL;
if(start==NULL)
{
start=t;
end=t;
}
else
{
t->next=start;
start->previous=t;
start=t;
}
}
int insertAt(int num,int pos)
{
struct Node *t,*p1;
int x;
if(pos<0) return 0;
p1=start;
x=0;
while(p1!=NULL && x<pos)
{
p1=p1->next;
x++;
}
if(p1==NULL && x<pos)
{
printf("Invalid position\n");
return 0;
}
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->next=NULL;
t->previous=NULL;
if(p1==NULL)
{
if(start==NULL)
{
start=t;
end=t;
}
else
{
end->next=t;
t->previous=end;
end=t;
}
return 1;
}
if(p1==start)
{
t->next=start;
start->previous=t;
start=t;
return 1;
}
t->next=p1;
t->previous=p1->previous;
p1->previous->next=t;
p1->previous=t;
return 1;
}
int removeAt(int pos)
{
struct Node *p1;
int x;
if(pos<0) return 0;
p1=start;
x=0;
while(p1!=NULL && x<pos)
{
p1=p1->next;
x++;
}
if(p1==NULL && x<pos)
{
return 0;
}
if(p1==start && x<pos)
{
return 0;
}
if(p1==start && p1==end)
{
start=NULL;
end=NULL;
free(p1);
return 1;
}
if(p1==start)
{
start=start->next;
start->previous=NULL;
free(p1);
return 1;
}
if(p1==end)
{
end=end->previous;
end->next=NULL;
free(p1);
return 1;
}
p1->previous->next=p1->next;
p1->next->previous=p1->previous;
free(p1);
return 1;
}

void traverseTopToBottom()
{
struct Node *t;
for(t=start;t!=NULL;t=t->next)
{
printf("%d\n",t->num);
}
}

void traverseBottomToTop()
{
struct Node *t;
for(t=end;t!=NULL;t=t->previous)
{
printf("%d\n",t->num);
}
}

int main()
{
int ch,num,pos;
start=NULL;
end=NULL;
while(1)
{
printf("1.Add at End\n");
printf("2.Insert at top\n");
printf("3.Insert at position\n");
printf("4.Remove from position\n");
printf("5.Traverse top to Bottom\n");
printf("6.Traverse Bottom to top\n");
printf("7.Exit\n");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter a number to add at End: ");
scanf("%d",&num);
fflush(stdin);
addAtEnd(num);
printf("Number added at End\n");
}
else
{
if(ch==2)
{
printf("Enter a number to insert at top: ");
scanf("%d",&num);
fflush(stdin);
insertAtTop(num);
printf("Number inserted at top\n");
}
else
{
if(ch==3)
{
printf("Enter a number to insert: ");
scanf("%d",&num);
fflush(stdin);
printf("Enter position: ");
scanf("%d",&pos);
fflush(stdin);
if(insertAt(num,pos))
{
printf("%d inserted at position %d\n",num,pos);
}
else
{
printf("Invalid position %d\n",pos);
}
}
else
{
if(ch==4)
{
printf("Enter positin of the Elements to remove:");
scanf("%d",&pos);
fflush(stdin);
if(removeAt(pos))
{
printf("Element removed\n");
}
else
{
printf("Invalid Position\n");
}
}
else
{
if(ch==5)
{
traverseTopToBottom();
}
else
{
if(ch==6)
{
traverseBottomToTop();
}
else
{
if(ch==7)
{
break;
}
else
{
printf("Invalid Choice\n");
}
}
}
}
}
}
}
}
return 0;
}