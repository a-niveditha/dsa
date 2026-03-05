#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void insertAtBeginning(struct node** head, int val){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = (*head);
    *head = newnode;
}
void insertAtMiddle(struct node* prev, int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = prev->next;
    prev->next = newnode;
}
void insertAtLast(struct node** head, int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}
void print(struct node** head){
    struct node* temp = *head;
    while(temp != NULL){ //IF U PUT TEMP->NEXT != NULL, U WILL MISS THE LAST ELEMENT
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void delete(struct node** head, int val){
    struct node* temp = *head, *prev;
    if(temp->data == val){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp->next != NULL && temp->data != val ){
        prev = temp;
        temp = temp->next;
    }
    if(temp->next == NULL){
        printf("not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void searchnode(struct node** head, int val){
    struct node* temp = *head;
    while(temp != NULL && temp->data != val ){
        temp = temp->next;
    }
    if(temp == NULL) //HANDLE THIS FIRST, ELSE U WILL BE TRYING TO ACCESS TEMP->DATA OF A NON EXISTENT NODE. 
        printf("not found \n");
    else
        printf("found \n");
}
int main(){
    struct node* head = NULL;
    
    // Testing insertAtBeginning
    printf("Inserting at beginning: 10, 20, 30\n");
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    print(&head);
    
    // Testing insertAtLast
    printf("\nInserting at last: 5, 15\n");
    insertAtLast(&head, 5);
    insertAtLast(&head, 15);
    print(&head);
    
    // Testing insertAtMiddle
    printf("\nInserting 25 after first node\n");
    insertAtMiddle(head, 25);
    print(&head);
    
    // Testing search
    printf("\nSearching for 20:\n");
    searchnode(&head, 20);
    printf("Searching for 100:\n");
    searchnode(&head, 100);
    
    // Testing delete
    printf("\nDeleting 20:\n");
    delete(&head, 20);
    print(&head);
    
    printf("\nDeleting 30 (head):\n");
    delete(&head, 30);
    print(&head);
    
    printf("\nDeleting 100 (not in list):\n");
    delete(&head, 100);
    print(&head);
    
    return 0;
}