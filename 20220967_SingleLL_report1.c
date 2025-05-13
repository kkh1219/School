#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;   
    struct Node* next;  
    
} Node;

Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; 
    
    if (head == NULL) {
        return newNode; 
    }

    newNode->next = head;
    return newNode;      
}

Node* insertLast(Node* head, int data) {
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL; 

    if (head == NULL) {
        return newNode; 
    }

    Node* current = head;
    while (current->next != NULL) { 
        current = current->next;
    }
    current->next = newNode; 

    return head;
}

void insertAfterValue(Node* head, int targetValue, int newData) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == targetValue) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int searchValue1(Node* head, int value) {
    int position = 1;
    Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

void searchValue2(Node* head, int value) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            if (prev != NULL)
                printf("앞 노드 값: %d\n", prev->data);
            else
                printf("앞 노드 없음 (첫 번째 노드)\n");

            if (current->next != NULL)
                printf("뒤 노드 값: %d\n", current->next->data);
            else
                printf("뒤 노드 없음 (마지막 노드)\n");

            return;
        }
        prev = current;
        current = current->next;
    }

    printf("값 %d는 연결리스트에 존재하지 않습니다.\n", value);
}

void freeList(Node* head) {
    Node* current = head;
    Node* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
     
    head = insertFirst(head, 20); 
    head = insertFirst(head, 10); 
    head = insertLast(head, 70); 
    head = insertLast(head, 80); 
    head = insertLast(head, 90); 
    insertAfterValue(head, 20, 40); 
    insertAfterValue(head, 40, 50); 
    insertAfterValue(head, 50, 60); 
    head = insertLast(head, 30);
    
    printList(head);
    
    int pos = -1;
	int val = 30;
	
	pos = searchValue1(head, val);
	printf("%d의 위치는 %d번째\n", val, pos);
	searchValue2(head, val);
    freeList(head);
    
    return 0;
}