#define _CRT_SECRUE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 99999999

// 스택 : 한쪽으로 들어가서 한쪽으로 나오는 자료구조
// PUSH(넣기) POP(빼기 )

int stack[SIZE];
int top = -1;

void push(int data) {
	if (top == SIZE - 1) {
		printf("스택 오버플로우가 발생했습니다.\n");
		return;
	}
	stack[++top] = data;
}

int pop() {
	if (top == -1) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	return stack[top--];
}

void show() {
	printf("최상단");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("최하단");
}



// 연결리스트를 이용한 스택구현

typedef struct {
	int data;
	struct Node* next;

} Node;

typedef struct {
	Node* top;
} Stack;

void push(Stack* stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));	//새로운 노드 메모리 할당
	node->data = data;							// 새로운 노드 값 추가
	node->next =  stack->top;					// 새로운 노드의 다음 노드가 현재 의 탑이 되도록 바꾸기
	stack->top = node;							// 이제 새로운 노드가 탑이 된다.
}

int pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("스택 언더플로우\n");
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
	printf("최상단");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("최하단");
}
int main(void) {
	Stack stack;
	stack.top = NULL;

	push(&stack,7);		// 포인터를 받기 위해 &사용
	pop(&stack);
	return 0;
}