#pragma once

#ifndef _list
#define _list
struct list
{
    float field;
     list* ptr;
};
#endif // !_list

#ifndef _Queue
#define _Queue
struct Queue {
     list* frnt, 
         * rear;
};
#endif // !_Queue

list* init(float a); // а- значение первого узла
list* addelem(list* lst, float number);
float test    ( Queue* q);
void init   (Queue* q);///Инициализация очереди
void insert ( Queue* q, float x);
int isempty (Queue* q);
void print  (Queue* q);
float remove(Queue* q);
///<\Реализация Очереди на базе list>
