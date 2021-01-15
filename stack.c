// Program to implement a stack that supports FindMiddle()
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

/* A Doubly Linked List Node */
struct DLLNode 
{ 
	struct DLLNode *prev; 
	int data; 
	struct DLLNode *next; 
}; 

/* Representation of the stack data structure that supports findMiddle() 
in O(1) time. The Stack is implemented using Doubly Linked List. It 
maintains pointer to head node, pointer to middle node and count of 
nodes */
struct myStack 
{ 
	struct DLLNode *head; 
	struct DLLNode *mid; 
	int count; 
}; 

/* Function to create the stack data structure */
struct myStack *createMyStack() 
{ 
	struct myStack *ms = (struct myStack*) malloc(sizeof(struct myStack)); 
	ms->count = 0; 
	return ms; 
}; 

/* Function to push an element to the stack */
void push(struct myStack *ms, int new_data) 
{ 
	/* allocate DLLNode and put in data */
	struct DLLNode* new_DLLNode = (struct DLLNode*) malloc(sizeof(struct DLLNode)); 
	new_DLLNode->data = new_data; 

	/* Since we are adding at the beginning, 
	prev is always NULL */
	new_DLLNode->prev = NULL; 

	/* link the old list off the new DLLNode */
	new_DLLNode->next = ms->head; 

	/* Increment count of items in stack */
	ms->count += 1; 

	/* Change mid pointer in two cases 
	1) Linked List is empty 
	2) Number of nodes in linked list is odd */
	if (ms->count == 1) 
	{ 
		ms->mid = new_DLLNode; 
	} 
	else
	{ 
		ms->head->prev = new_DLLNode; 

		if (ms->count & 1) // Update mid if ms->count is odd 
		ms->mid = ms->mid->prev; 
	} 

	/* move head to point to the new DLLNode */
	ms->head = new_DLLNode; 
} 

// Function for finding middle of the stack 
int FindMiddle(struct myStack *ms) 
{ 
	if (ms->count == 0) 
	{ 
		printf("Stack is empty now\n"); 
		return -1; 
	} 

	return ms->mid->data; 
} 

// Check for prime
int CheckPrime (int num) 
{
    int flag = 1;
    
    if (num == 1 || num == 0) {
        flag = 0;
        return flag; 
    }
    
    for (int j = 2; j <= num / 2; ++j) 
    {
    	if (num % j == 0) { 
		    flag = 0; 
		    break; 
	    } 
	}
	return flag;
}

// Driver program to test functions of myStack 
int main() 
{
	struct myStack *ms = createMyStack();
    int lower = 1, upper = 100, counter = 5;
    srand(time(0)); 
    
    printf("Stack: ");
    while (counter != 0)
    {
        int num = (rand() % (upper - lower + 1)) + lower;
        if (CheckPrime(num) == 1){
            push(ms, num);
            counter--;
            printf("%d", num);
            if (counter != 0)
                printf("->");
        }
    }
    printf("\n");
    
	printf("ortadaki Eleman: %d\n", FindMiddle(ms)); 
	return 0; 
} 
