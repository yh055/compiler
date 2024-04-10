#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 100

// Define a stack structure
typedef struct {
    void* items[MAX_SIZE];
    int top;
} Stack;

// Initialize a stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(Stack* stack, void* value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

// Pop an element from the stack
void* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return an invalid value
    }
    void* popped = stack->items[stack->top];
    stack->top--;
    return popped;
}
void* peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return an invalid value
    }
    return stack->items[stack->top];
}