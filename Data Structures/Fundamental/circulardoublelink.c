#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
  struct node *prev;
};
struct node *head=NULL;
void create(int d)
{ struct node *new,*t;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->next=NULL;
  new->prev=NULL;
  if(head==NULL)
  { head=new;
    new->next=head;
    head->prev=new;
    new->prev=head;
  }
  else
  { t=head;
    do
    { t=t->next;
    }while(t!=head->next);
    t->next=new;
    new->prev=t;
    t=new;
    new->next=head;
    head->prev=new;
    
  }
}
void display()
{ struct node *ptr;
  ptr=head;
  do
  { printf("%d",ptr->data);
    ptr=ptr->next;
  }while(ptr!=head);
    
}
void main()
{ create(1);
  create(2);
  create(5);
  display();
}
