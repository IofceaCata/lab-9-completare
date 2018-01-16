#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int i;
node *p;
node *n;

void insert(node *pointer, int data){

    while(pointer->next!=NULL){
    pointer = pointer->next;
}

    pointer->next = (node *)malloc(sizeof(node));
    (pointer->next)->prev= pointer;
    pointer = pointer->next;
    pointer->data=data;
    pointer->next = NULL;
}
void print(node *pointer){
    if(pointer==NULL){
    return;}
    printf("%d ",pointer->data);
    print(pointer->next);
}

int init(node *pointer,int find){
    pointer =pointer->next;
    while(pointer!=NULL){
    if(pointer->data== find)//found find
    {
        printf("The data is in the list.");
        return 1;
    }
    pointer = pointer->next;// Search in the next node.
    }

    printf("Nu am gasit");
    return 0;
}
void swap (node *x, node *y){
    int temp= x->data;
    x->data=y->data;
    y->data=temp;
}
void sort(node*pointer){
	int i;
	while(pointer->next!=NULL){
if(pointer->data>pointer->next->data){
    swap(pointer,pointer->next);
    }
    pointer=pointer->next;
    sort(pointer);
    }
}








int main(){

node *new, *temp;
int z;
new=(node *)malloc(sizeof(node));
temp= new;
temp ->next = NULL;
temp ->prev = NULL;

for(z=0;z<10;z++){
    insert(new,(3*10)-z);
}
init(new,12);
init(new,3);
init(new,27);
init(new,7);
print(new);
sort(new);
print(new);

}

