#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

int isFull(Stack *s){
    return s->top == MAX - 1;
}

void push(Stack *s,char c){
    if(!isFull(s)){
        s->data[++(s->top)]=c;
    }
}

char pop(Stack *s){
    if(!isEmpty(s)){
        return s->data[(s->top)--];
    }
    return '\0';
}



int main(){
    char str[MAX];
    Stack s;
    init(&s);
    
    printf("문자열 입력 : \n");
    scanf("%s",str);
    
    int len = strlen(str);
    
    for(int i=0;i<len;i++){
        push(&s,str[i]);
    }
    for(int i=0;i<len;i++){
        str[i]=pop(&s);
    }
    
    printf("반전된 문자열 : %s\n",str);
    
    return 0;
}