#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*///////////////////////////////////////////////////////
Stack data structure
	supports: push, pop, is_full, is_empty
	reference from geekforgeeks implementation
///////////////////////////////////////////////////////*/
struct Stack {
	unsigned capacity;
	int top;
	int* array;
};
	
struct Stack* init_stack(unsigned cap) {
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = cap;
	stack->top = -1;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}

int is_empty(struct Stack* stack) {
	return stack->top == -1;
}

int is_full(struct Stack* stack) {
	return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, int item) {
	if (is_full(stack)) {
		return;
	}
	stack->array[++stack->top] = item;
	printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack) {
	if (is_empty(stack)){ 
		return INT_MIN;
	}
	return stack->array[stack->top--];
}

void print_stack(struct Stack* stack) {
	int count = stack->top;
	printf("Stack contents:\n");
	while (count > 0) {
		printf("-    %d\n", stack->array[count]);
		count--;
	}
}

/*///////////////////////////////////////////////////////
Array Functions
///////////////////////////////////////////////////////*/

void print_array(int* a[], int total) {
	int count = 0;
	while (count < total) {
		printf("%d\n", a[count]);
		count++;
	}
}
//assumes int array
void rotate_array(int** a[], int total){
	int half = total / 2;
	int count = 0;
	while (count < half) {
		a[count], a[total] = a[total], a[count];
		count++;
		total--;
	}
}

int main() {

	// Test Stack structure. 
    struct Stack* stack = init_stack(100);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
	print_stack(stack);
    printf("%d popped from stack\n", pop(stack));
 	print_stack(stack);

 	int tester[] = {0,1,2,3,4,5};
 	print_array(tester, 6);
 	rotate_array(tester, 6);
 	print_array(tester, 6);

    return 0;
}