#include "Stdafx.h"


///<Реализация Очереди на базе масива>

void init( queue* q)///Инициализация очереди
{
	q->frnt = 1;
	q->rear = 0;
	return;
}

void insert( queue* q, float x)///Добавление элемента в очередь
{
	if (q->rear < QMAX - 1) {
		q->rear++;
		q->qu[q->rear] = x;
	}
	else
		printf("Очередь полна!\n");
	return;
}

int isempty( queue* q) {
	if (q->rear < q->frnt)
		return 1;
	else 
		return 0;
}

void print( queue* q) {
	int h;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return;
	}
	for (h = q->frnt; h <= q->rear; h++)
		printf("%2.1f ", q->qu[h]);
	return;
}

float remove( queue* q) {
	float x;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return(0);
	}
	x = q->qu[q->frnt];
	q->frnt++;
	return x;
}


float removex( queue* q) {
	float x;
	int h;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
		return 0;
	}
	x = q->qu[q->frnt];
	for (h = q->frnt; h < q->rear; h++) {
		q->qu[h] = q->qu[h + 1];
	}
	q->rear--;
	return x;
}
///<\Реализация Очереди на базе масива>
