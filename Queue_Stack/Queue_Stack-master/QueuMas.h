#pragma once
///<Реализация Очереди на базе масива>
#ifndef _queue
#define _queue
struct queue {///Для реализации на базе массива используется структура
	
	float qu[QMAX];
	int rear, frnt;//frnt – позиция первого элемента в очереди; rear – позиция последнего элемента в очереди
};
#endif // !_queue

void init( queue* q);///Инициализация очереди
void insert( queue* q, float x);///Добавление элемента в очередь
int isempty( queue* q);
void print( queue* q);
float remove( queue* q);
float removex( queue* q);
///<\Реализация Очереди на базе масива>


