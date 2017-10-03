using namespace std;
#include <stdio.h>

#define MAX 1000


class Stack {
	int top;
public:
	int a[MAX];

	Stack() {
		top = -1;
	}
	void push(int x);
	int pop();
	bool is_empty();
	void print_stack();

};

bool Stack::is_empty() {
	return top == -1;
}


void Stack::push( int item ) {
	if (top >= MAX) {
		return;
	}
	a[++top] = item;
	printf("%d pushed to stack\n", item);
}

int Stack::pop() {
	if (is_empty()){ 
		printf("this is an empty stack\n");
		return 0;
	}
	return a[top--];
}

void Stack::print_stack() {
	int count = top;
	printf("Stack contents:\n");
	while (count > 0) {
		printf("-    %d\n", a[count]);
		count--;
	}
}

int main() {
	struct Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.print_stack();
	s.pop();
	s.pop();
	s.print_stack();
}