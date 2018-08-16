
#include "Stack.h"

Stack::Stack(int size) {
	data = new MazeLocation[size];
	MAX_SIZE = size;
	top = -1;
  
}

bool Stack::isEmpty() const {
    return (top == -1);
}

bool Stack::isFull() const {
	return (top == MAX_SIZE - 1);
}

Stack::~Stack() {
	delete [] data;
	data = NULL;
}

void Stack::push(MazeLocation m) {
	if (isFull()) {
		std::cout << "Stack is full." << std::endl;
	} else {
		top++;
		data[top] = m;
	}
}

void Stack::pop() {
	if (isEmpty()) {
		std::cout << "There's nothing in the Stack!" << std::endl;
	} else {
		top--;
	}
}

void Stack::printTop() {
	std::cout << data[top];
}

