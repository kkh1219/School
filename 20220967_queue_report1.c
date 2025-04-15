#include <stdio.h>
#include <stdbool.h>

#define SIZE 30

typedef struct{
    int data[SIZE];
    int front;
    int rear;
}LinearQueue;

void initQueue(LinearQueue *q){
    q->front=0;
    q->rear=-1;
}

bool isEmpty(LinearQueue *q){
    return q->rear < q->front;
}
bool isFull(LinearQueue *q){
    return q->rear == SIZE - 1;
}
bool enqueue(LinearQueue *q,int value){
    if(isFull(q)){
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear]=value;
    return true;
}

int dequeue(LinearQueue *q){
    if(isEmpty(q)){
        printf("큐가 비어있습니다.\n");
        initQueue(q);
        return -1;
    }
    int value=q->data[q->front];
    q->front++;
    if(q->front > q->rear){
        initQueue(q);
    }
    return value;
}

void printQueue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return;
    }

    printf("현재 큐: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main(){
    LinearQueue q;
    initQueue(&q);
    
    int choice,value;
    while(1){
        printf("----메뉴----\n");
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 큐 데이터 출력\n");
        printf("4. 종료\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("삽입할 값을 입력하세요: \n");
                scanf("%d",&value);
                enqueue(&q,value);
                break;
            case 2:
                printf("값을 삭제합니다. \n");
                dequeue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 선택입니다! 1에서 5 사이의 숫자를 입력하세요.");
        }
    }
    
}