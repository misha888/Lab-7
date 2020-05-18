#include "Stdafx.h"

 list* init(float a) // �- �������� ������� ����
{
    struct list* lst;
    // ��������� ������ ��� ������ ������
    lst = ( list*)malloc(sizeof( list));
    lst->field = a;
    lst->ptr = nullptr; // ��� ��������� ���� ������
    return(lst);
}
 list* addelem(list* lst, float number)
{
     list* temp, * p;
    temp = ( list*)malloc(sizeof(list));
    p = lst->ptr; // ���������� ��������� �� ��������� ����
    lst->ptr = temp; // ���������� ���� ��������� �� �����������
    temp->field = number; // ���������� ���� ������ ������������ ����
    temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
    return(temp);
}
void init( Queue* q)
{
    q->frnt = 0;
    q->rear = 0;
}

int isempty(struct Queue* q)
{
    if (q->frnt == 0)
        return 1;
    else
        return 0;
}


void insert( Queue* q, float x)
{
    if ((q->rear == 0) && (q->frnt == 0)) {
        q->rear = init(x);
        q->frnt = q->rear;
    }
    else
        q->rear = addelem(q->rear, x);
}

void print(struct Queue* q) {
    struct list* h;
    if (isempty(q) == 1) {
        printf("������� �����!\n");
        return;
    }
    for (h = q->frnt; h != nullptr; h = h->ptr)
        printf("%2.1f ", h->field);
    return;
}

float remove( Queue* q)
{
    struct list* temp;
    float x;
    if (isempty(q) == 1) {
        printf("������� �����!\n");
        return 0;
    }
    x = q->frnt->field;
    temp = q->frnt;
    q->frnt = q->frnt->ptr;
    free(temp);
    return x;
}

float test( Queue* q)
{
    float x;
    x = q->frnt->field;
    return x;
}

