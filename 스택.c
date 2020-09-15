#define _CRT_SECRUE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 99999999

// ���� : �������� ���� �������� ������ �ڷᱸ��
// PUSH(�ֱ�) POP(���� )

int stack[SIZE];
int top = -1;

void push(int data) {
	if (top == SIZE - 1) {
		printf("���� �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	stack[++top] = data;
}

int pop() {
	if (top == -1) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	return stack[top--];
}

void show() {
	printf("�ֻ��");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("���ϴ�");
}



// ���Ḯ��Ʈ�� �̿��� ���ñ���

typedef struct {
	int data;
	struct Node* next;

} Node;

typedef struct {
	Node* top;
} Stack;

void push(Stack* stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));	//���ο� ��� �޸� �Ҵ�
	node->data = data;							// ���ο� ��� �� �߰�
	node->next =  stack->top;					// ���ο� ����� ���� ��尡 ���� �� ž�� �ǵ��� �ٲٱ�
	stack->top = node;							// ���� ���ο� ��尡 ž�� �ȴ�.
}

int pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("���� ����÷ο�\n");
			return -INF;
	}
	Node* node = stack->top;
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void show(Stack* stack) {
	Node* cur = stack->top;
	printf("�ֻ��");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("���ϴ�");
}
int main(void) {
	Stack stack;
	stack.top = NULL;

	push(&stack,7);		// �����͸� �ޱ� ���� &���
	pop(&stack);
	return 0;
}