#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->head == NULL)
        return TRUE;

    return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // 새 노드 생성

    newNode->data = data;         // 새 노드에 데이터 저장
    newNode->next = pstack->head; // 새 노드가 최근에 추가된 노드를 가리킴

    pstack->head = newNode; // 포인터 변수 head가 새 노드를 가리킴
}

Data SPop(Stack *pstack)
{
    Node *rNode;
    Data rData;

    if (SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rNode = pstack->head;       // 삭제할 노드의 주소값을 임시로 저장
    rData = pstack->head->data; // 삭제할 노드의 데이터를 임시로 저장

    pstack->head = pstack->head->next; // 삭제할 노드의 다음 노드를 head가 가리킴
    free(rNode);                       // 노드 삭제
    return rData;                      // 삭제된 노드의 데이터 반환
}

Data SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->head->data; // head가 가리키는 노드에 저장된 데이터 반환
}