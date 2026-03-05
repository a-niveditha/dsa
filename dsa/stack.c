#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 50
struct stack{
    char a[max];
    int top;
};
typedef struct stack st;
void createEmptyStack(st *s) {
    s->top = -1;
} 
int isfull(st *s){
    if (s -> top == (max -1) )
        return 1;
    else
        return 0;
}
int isempty(st *s){
    if (s -> top == -1 )
        return 1;
    else
        return 0;
}
void push(char val, st *s){
    if (isfull(s))
        printf("stack full");
    else
    {
        s -> top ++ ;
        s -> a[s -> top] = val;
    }
}
char pop(st *s){
    if (isempty(s))
        printf("stack empty");
    else
    {
        char temp = s -> a[s -> top] ;
        s -> top --;
        return temp;
    }
}
void postfix(st *s, char exp[]){
    int i;
    for(i = 0; i < strlen(exp); i++)
    {
        if(isalpha(exp[i]))
            printf("%c ", exp[i] );
        else if(exp[i] == '(' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^' )
            push(exp[i], s);
        else if (exp[i] == ')') 
        {
            while (!isempty(s) && s->a[s->top] != '(')
                printf("%c ", pop(s));
            pop(s);  
        }
    }
    while (!isempty(s))
        printf("%c ", pop(s));
}
void prefix(st *s, char exp[]) {
    char result[100];
    int res_index = 0;
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) {
        char ch = exp[i];
        if (isalpha(ch) ) {
            result[res_index++] = ch;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == ')') {
            push(ch, s);
        }
        else if (ch == '(') {
            while (!isempty(s) && s->a[s->top] != ')') {
                result[res_index++] = pop(s);
            }
            pop(s);
        }
    }
    while (!isempty(s))
        result[res_index++] = pop(s);

    for (int i = res_index - 1; i >= 0; i--)
        printf("%c ", result[i]);
    printf("\n");
}
int main(){
    printf("Name : Niveditha \nReg No : 24BCE2000 \n");
    st *s = (st *)malloc(sizeof(st));
    printf("Enter the infix expression\n");
    char exp[30];
    scanf("%s", exp);
    createEmptyStack(s); 
    printf("postfix conversion: \n");
    postfix(s, exp);
    createEmptyStack(s);
    printf("\nprefix conversion : \n");
    prefix(s, exp);
}

