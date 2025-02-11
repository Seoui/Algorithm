#pragma once
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

inline void error(const char* message)
{
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20;

// �迭�� �̿��� ���� Ŭ����
class ArrayStack
{
	int top;
	int data[MAX_STACK_SIZE];

public:
	ArrayStack() 
	{ 
		top = -1; 
		fill(data, data + MAX_STACK_SIZE, 0);
	}
	~ArrayStack() {}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(int e)
	{
		if (isFull()) printf("���� ��ȭ\n");
		data[++top] = e;
		return;
	}

	int pop()
	{
		if (isEmpty()) printf("���� ����\n");
		return data[top--];
	}

	int peek()
	{
		if (isEmpty()) printf("���� ����\n");
		return data[top];
	}

	void display()
	{
		printf("[���� �׸��� �� = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; ++i)
			printf("<%2d>", data[i]);
		printf("\n");
	}
};

// �ǿ����� ���� Ŭ����
class OperandStack
{
	double data[MAX_STACK_SIZE];
	int top;
public:
	OperandStack() :data{} { top = -1; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }
	void push(double e) {
		if (isFull()) printf("���� ��ȭ ����\n");
		data[++top] = e;
	}
	double pop() {
		if (isEmpty()) printf("���� ���� ����\n");
		return data[top--];
	}
};