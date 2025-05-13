#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Number{
    char name[50];
    char phone[20];
    struct Number* next;
} Number;

//연락처 추가
void addNumber(Number** head, const char* name, const char* phone) {
    Number* newNumber = (Number*)malloc(sizeof(Number));
    strcpy(newNumber->name, name);
    strcpy(newNumber->phone, phone);
    newNumber->next = *head;
    *head = newNumber;
}
//연락처 검색 
void searchNumber(Number* head, const char* name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("이름: %s, 전화번호: %s\n", head->name, head->phone);
            return;
        }
        head = head->next;
    }
    printf("'%s' 연락처를 찾을 수 없습니다.\n", name);
}

//연락처 삭제
void deleteNumber(Number** head, const char* name) {
    Number* current = *head;
    Number* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("'%s' 연락처가 삭제되었습니다.\n", name);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("'%s' 연락처를 찾을 수 없습니다.\n", name);
}

//연락처 출력
void printNumber(Number* head) {
    if (head == NULL) {
        printf("전화번호부가 비어 있습니다.\n");
        return;
    }

    while (head != NULL) {
        printf("이름: %s, 전화번호: %s\n", head->name, head->phone);
        head = head->next;
    }
}

//메모리 해제
void freeList(Number* head) {
    Number* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Number* phonebook = NULL;

    // 1. 연락처 추가
    addNumber(&phonebook, "길동", "010-1234-5678");
    addNumber(&phonebook, "철수", "010-9876-5432");
    addNumber(&phonebook, "영희", "010-1111-2222");

    // 2. 연락처 검색
    searchNumber(phonebook, "철수");

    // 3. 연락처 삭제
    deleteNumber(&phonebook, "길동");

    // 4. 전체 연락처 출력
    printNumber(phonebook);

    // 5. 메모리 해제
    freeList(phonebook);

    return 0;
}
