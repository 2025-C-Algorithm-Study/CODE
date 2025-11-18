#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//c언어로 연결리스트 구현해서 여러가지 케이스의 테스트(삽입,삭제,마지막 노드 삭제, 빈리스트에서 삭제시도) 로 설명하기. 각 함수에 주석 추가하기Pull request

typedef struct Node {       //노드 구조체 정의
    int data;               //노드 저장 데이터
    struct Node* next;      //자기참조
} Node;

//삽입(맨 앞에)---------------------------------------------------------------------------------------
void infront(Node** headptr, int newdata) {             //함수선언(head 자체 변경위해 이중 포인터)
    Node* newNode = (Node*)malloc(sizeof(Node));    //newNode 생성 및 malloc으로 데이터할당
    if (newNode == NULL) {                          //메모리 할당확인
        printf("메모리가 할당되지 않음\n");
        return;
    }

    newNode->data = newdata;            
    newNode->next = *headptr;
    *headptr = newNode;
    printf("리스트 맨 앞에 추가완료\n");
}

//삽입(맨 뒤에)---------------------------------------------------------------------------------------
void inback(Node** headptr, int newdata) {             //함수선언(head 자체 변경위해 이중 포인터)
    Node* newNode = (Node*)malloc(sizeof(Node));    //newNode 생성 및 malloc으로 데이터할당
    if (newNode == NULL) {                          //메모리 할당확인
        printf("메모리가 할당되지 않음\n");
        return;
    }

    newNode->data = newdata;    //맨 뒤 추가이니 next는 NULL에 연결
    newNode->next = NULL;

    //리스트가 비어있는경우
    if (*headptr == NULL) {
        *headptr = newNode;
        printf("빈리스트의 맨 끝에 추가완료\n");
        return;
    }

    //리스트 tail찾기 current통해
    Node* current = *headptr;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    //newNode->next = NULL;
    printf("리스트 맨 끝에 추가완료\n");
}

//삭제(맨 앞에)------------------------------------------------------------------------
void delfront(Node** headptr) {
    if (*headptr == NULL) {
        printf("리스트가 비어있습니다\n");
        return;
    }

    Node* nodetemp = *headptr;
    int deletedData = nodetemp->data;

    *headptr = (*headptr)->next;

    free(nodetemp);

    printf("삭제성공\n");
}

//삭제(맨 뒤에)------------------------------------------------------------------------
void delback(Node** headptr) {
    if (*headptr == NULL) {
        printf("리스트가 비어있습니다\n");
        return;
    }
    //current만든다음 current->next로 NULL까지 간다음 current전꺼를 NULL로 연결하기
    Node* current = *headptr;
    Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        free(current);
        *headptr = NULL;
    }
    else {
        prev->next = NULL;
        free(current);
    }

    printf("마지막 노드 삭제완료\n");
}

//리스트 출력함수----------------------------------------------------------------------
void printlist(Node* head) {
    Node* current = head;        //맨 처음인 head부터 시작함    
    if (current == NULL) {
        printf("리스트가 비어있습니다\n");
        return;
    }

    while (current != NULL) {   //리스트에서 current가 NULL이 나올때까지 current->next하며 순서대로 찾기
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");           //마지막 NULL 표시
}

int main() {
    Node* head = NULL;  //연결리스트 초기화 시키기
    int number;
    int incum;
    while (1) {             
        printf("\n1:삽입(맨 앞에)\n2:삽입(맨 뒤에)\n3:삭제(맨 앞에)\n4:삭제(맨 뒤에)\n5:리스트 출력\n6:종료\n");
        scanf("%d", &number);

        switch (number) {
        case 1:
            scanf("%d", &incum);
            infront(&head, incum);
            break;
        case 2:
            scanf("%d", &incum);
            inback(&head, incum);
            break;
        case 3:
            delfront(&head);
            break;
        case 4:
            delback(&head);
            break;
        case 5:
            printlist(head);
            break;
        case 6:
            return 0;
        }
    }
}

    
    



