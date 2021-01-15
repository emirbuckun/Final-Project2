#include<stdio.h>  
#include<stdlib.h>  
#include <time.h> 
  
/* Link list node */
struct Node  
{  
    int data;  
    struct Node* next;  
};

/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)  
{  
    struct Node *slow_ptr = head;  
    struct Node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("ortadaki Eleman: [%d]\n\n", slow_ptr->data);  
    }  
}  
  
void push(struct Node** head_ref, int new_data)  
{  
    /* allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));  
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  
  
// A utility function to print a given linked list  
void printList(struct Node *ptr)  
{  
    printf("LinkedList: ");
    int i = 0;
    while (ptr != NULL)
    {  
        printf("%d", ptr->data);  
        ptr = ptr->next; 
        if (i != 4)
            printf("->");
        i++;
    }  
    printf("\n");  
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

// Main Method
int main()  
{
    struct Node* head = NULL;
    int lower = 1, upper = 100, counter = 5;
    srand(time(0)); 
    
    while (counter != 0)
    {
        int num = (rand() % (upper - lower + 1)) + lower;
        if (CheckPrime(num) == 1){
            push(&head, num);
            counter--;
        }
    }
    
    printList(head);  
    printMiddle(head);  
  
    return 0;  
}
