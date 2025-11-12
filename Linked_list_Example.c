#include <stdio.h>
#include <stdlib.h> // malloc, free 함수 사용을 위해 포함

// ===============================================
// 1. 노드 구조체 정의
// ===============================================

// 연결 리스트의 '노드'는 데이터와 다음 노드를 가리키는 포인터로 구성됩니다.
typedef struct Node
{
    int data;          // 노드에 저장할 데이터 (정수형)
    struct Node *next; // 다음 노드의 주소를 저장할 포인터 (자기 참조 구조체)
} Node;

// ===============================================
// 2. 핵심 함수: 삽입 (맨 앞에 추가)
// ===============================================

/**
 * @brief 리스트 맨 앞에 새로운 노드를 삽입하는 함수
 * @param headPtr Head 포인터의 주소 (Head 자체를 변경하기 위해 이중 포인터를 사용)
 * @param newData 새로 삽입할 데이터
 */
void insertFront(Node **headPtr, int newData)
{
    // 1. 새로운 노드 생성 및 메모리 할당
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("메모리 할당 실패!\n");
        return;
    }

    // 2. 새 노드에 데이터 저장
    newNode->data = newData;

    // 3. 새 노드의 next를 현재의 head가 가리키던 노드에 연결
    newNode->next = *headPtr;

    // 4. Head 포인터 업데이트: 이제 Head가 새 노드를 가리키도록 변경
    *headPtr = newNode;

    printf("[삽입 성공] %d를 리스트 맨 앞에 추가했습니다.\n", newData);
}

// ===============================================
// 2-1. 핵심 함수: 삽입 (맨 끝에 추가)
// ===============================================

/**
 * @brief 리스트 맨 끝에 새로운 노드를 삽입하는 함수
 * @param headPtr Head 포인터의 주소 (Head 자체를 변경할 가능성 때문에 이중 포인터를 사용)
 * @param newData 새로 삽입할 데이터
 */
void insertRear(Node **headPtr, int newData)
{
    // 1. 새로운 노드 생성 및 메모리 할당
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("메모리 할당 실패!\n");
        return;
    }

    // 2. 새 노드에 데이터 저장하고, next를 NULL (끝)로 설정
    newNode->data = newData;
    newNode->next = NULL;

    // 3. 리스트가 비어있는 경우 (Head가 NULL인 경우)
    if (*headPtr == NULL)
    {
        *headPtr = newNode;
        printf("[삽입 성공] %d를 (빈 리스트의) 맨 끝에 추가했습니다.\n", newData);
        return;
    }

    // 4. 리스트의 맨 끝 노드(Tail)를 찾기 위해 탐색 시작 (Traversal)
    Node *current = *headPtr;
    while (current->next != NULL)
    {
        // current 포인터를 다음 노드로 계속 이동
        current = current->next;
    }

    // 5. Tail 노드를 찾았으므로, Tail 노드의 next를 새 노드에 연결
    current->next = newNode;

    printf("[삽입 성공] %d를 리스트 맨 끝에 추가했습니다.\n", newData);
}

// ===============================================
// 3. 핵심 함수: 삭제 (맨 앞 노드 삭제)
// ===============================================

/**
 * @brief 리스트 맨 앞의 노드를 삭제하는 함수
 * @param headPtr Head 포인터의 주소 (Head 자체를 변경하기 위해 이중 포인터를 사용)
 */
void deleteFront(Node **headPtr)
{
    // 리스트가 비어있는지 확인
    if (*headPtr == NULL)
    {
        printf("[삭제 실패] 리스트가 비어있습니다.\n");
        return;
    }

    // 1. 삭제할 노드(현재 Head 노드)를 임시로 기억
    Node *nodeToDelete = *headPtr;
    int deletedData = nodeToDelete->data;

    // 2. Head 포인터를 다음 노드로 이동 (리스트의 시작점을 변경)
    *headPtr = (*headPtr)->next;

    // 3. 메모리 해제 (삭제)
    free(nodeToDelete);

    printf("[삭제 성공] 맨 앞 노드 (%d)를 삭제했습니다.\n", deletedData);
}

// ===============================================
// 4. 유틸리티 함수: 리스트 출력
// ===============================================

/**
 * @brief 리스트의 모든 노드를 순회하며 출력하는 함수
 * @param head Head 포인터
 */
void printList(Node *head)
{
    Node *current = head; // current 포인터는 Head부터 시작

    printf("\n--- 현재 연결 리스트 구조 ---\n");
    if (current == NULL)
    {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    // current가 NULL이 될 때까지 (= 리스트의 끝에 도달할 때까지) 반복 (Traversal)
    while (current != NULL)
    {
        printf("[%d] ", current->data);
        if (current->next != NULL)
        {
            printf("-> "); // 다음 노드가 있으면 화살표 출력
        }
        current = current->next; // 다음 노드로 이동
    }
    printf(" (NULL)\n");
    printf("---------------------------\n");
}

// ===============================================
// 5. 메인 함수 (실행 예제)
// ===============================================
int main()
{
    // Head 포인터 선언 및 초기화 (NULL은 '리스트가 비어있음'을 의미)
    Node *head = NULL;

    printf("--- 연결 리스트 (Linked List) 기본 동작 시연 ---\n");

    // 1. 맨 앞 삽입 테스트
    insertFront(&head, 10); // [10] -> NULL
    insertFront(&head, 20); // [20] -> [10] -> NULL

    printList(head); // 20 -> 10

    // 2. 맨 끝 삽입 테스트 (새로 추가된 기능)
    insertRear(&head, 5); // [20] -> [10] -> [5] -> NULL
    insertRear(&head, 1); // [20] -> [10] -> [5] -> [1] -> NULL

    printList(head); // 20 -> 10 -> 5 -> 1

    // 3. 맨 앞 삭제 테스트
    deleteFront(&head); // [10] -> [5] -> [1] -> NULL

    printList(head); // 10 -> 5 -> 1

    // 4. 모든 노드 삭제 (메모리 정리)
    deleteFront(&head);
    deleteFront(&head);
    deleteFront(&head);

    printList(head); // 리스트가 비어있습니다.

    // 5. 빈 리스트에서 삭제 시도 (실패)
    deleteFront(&head);

    return 0;
}