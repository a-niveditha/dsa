#include <stdio.h>
#include <stdlib.h>
#define max 5 
struct stack{
    int arr[max];
    int head;
};
typedef struct stack st;
void createEmptyStack(st *s){
    s->head = -1;
}
int isempty(st *s){
    if(s->head == -1)
        return 1;
    else
        return 0;
}
int isfull(st *s){
    if(s->head == max - 1)
        return 1;
    else   
        return 0;
}
void push(st *s, int val){
    if(isfull(s) == 1){
        printf("stack full");
        return ;
    }else{
        s->head ++;
        s->arr[s->head] = val;
    }
}
int pop(st *s){
    if(isempty(s) == 1){
        printf("stack empty");
        return -1;
    }else{
        int temp = s->arr[s->head];
        s->head--;
        return temp;
    }
}

//stack using linked list

struct stack{
    int data;
    struct stack* next;
};
struct stack *head = NULL;
void push(int val){
    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}
void pop(){
    struct stack* temp = head;
    printf("%d \n", head->data);
    head = head->next;
    free(temp);
}
void print(){
    struct stack* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

