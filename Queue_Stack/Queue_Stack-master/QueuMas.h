#pragma once
///<���������� ������� �� ���� ������>
#ifndef _queue
#define _queue
struct queue {///��� ���������� �� ���� ������� ������������ ���������
	
	float qu[QMAX];
	int rear, frnt;//frnt � ������� ������� �������� � �������; rear � ������� ���������� �������� � �������
};
#endif // !_queue

void init( queue* q);///������������� �������
void insert( queue* q, float x);///���������� �������� � �������
int isempty( queue* q);
void print( queue* q);
float remove( queue* q);
float removex( queue* q);
///<\���������� ������� �� ���� ������>


