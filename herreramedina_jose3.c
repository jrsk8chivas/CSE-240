#include <stdio.h>
#include <string.h>
#include <ctype.h>

#pragma warning(disable : 4996) 

// [Q1 - 5pts]	Update the struct Order to include the following fields : 
// (Please structure the object to use the least amount of memory.  
// HINT: think back to padding structure.)
//		char name[61];
//		int customerNo;
//		char item[103];
//		char address[128];
//		float cost;
struct Order {
	struct Order* next;
	int orderid;
	int customerNo;
	float cost;
	char name[61];
	char address[128];
	char item[103];
} *Queue = NULL;

void flush();						// forward declaration of functions
void branching(char c);
int insert_order(struct Order* item);
int update_order(struct Order* item);
int cancel_order(int orderid);
int process_order(int numOfItems);

int sizeofOrderStructure();
int insert_update_order_helper(char c);
int process_order_helper();
int cancel_order_helper();

int main() {
	char ch = 'i';

	ungetc('\n', stdin);			// inject input buffer with a return character

	printf("The size of the order structure is %d bytes.\n\n", sizeofOrderStructure());

	do {
		printf("Enter your selection\n");
		printf("\ti: insert a new order.\n");
		printf("\tu: update an order.\n");
		printf("\td: cancel an order.\n");
		printf("\tp: process an order.\n");
		printf("\tq: quit \n");

		flush();							// flush input buffer
		ch = tolower(getchar());			// see tutorial
		branching(ch);
	} while (ch != 113);

	return 0;
}

void flush() {
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

int sizeofOrderStructure() {
	return sizeof(struct Order);
}

void branching(char c) {					// branch to different tasks
	switch (c) {
	case 'i':
		insert_update_order_helper(c);
		break;
	case 'u':
		insert_update_order_helper(c);
		break;
	case 'd':
		cancel_order_helper();
		break;
	case 'p':
		process_order_helper();
		break;
	case 'q':
		break;
	default:
		printf("Invalid input\n");
	}
}

// [Q2 - 5pts]	Write code to capture customerNo, cost, name, address, and item
// into the new created struct Order pointed by ptr.  Assume name, address, and item
// cannot accept any spaces or return characters.  
int insert_update_order_helper(char c) {

	struct Order *ptr = (struct Order *)malloc(sizeof(struct Order));

	/* -- START CODING HERE -- */
	printf("What is the order id? ");
	scanf("%d", &ptr->orderid);

	printf("What is your customer id? ");
	scanf("%d", &ptr->customerNo);

	printf("What is your name? ");
	scanf("%s", ptr->name);

	printf("What is your address? (No spaces) ");
	scanf("%s", ptr->address);

	printf("What is the item? ");
	scanf("%s", ptr->item);

	printf("What is the cost? ");
	scanf("%f", &ptr->cost);

	ptr->next = NULL;
	/* -- END CODING HERE -- */

	if (c == 'i') {
		return insert_order(ptr);
	}
	else {
		int value = update_order(ptr);

		if (value == -1) { printf("No Record Found."); }

		return update_order(ptr);
	}
}

// [Q3 - 10pts] Implement the insert function.   The function should check 
// if existing order has been made (using the order id).   If an order 
// exist, update the record. Otherwise, insert a new order into the queue 
// – follow FIFO.      
int insert_order(struct Order* item) {

	/* -- START CODING HERE -- */
	struct Order *ptr = Queue;
	int indicator = update_order(item);

	if (indicator == -1) {
		if (!ptr) {
			item->next = NULL;
			Queue = item;

			return 0;
		}
		else {
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}

			item->next = NULL;
			ptr->next = item;
		}
	}
	/* -- END CODING HERE -- */

	return 0;
}

// [Q4 - 10pts] Implement the update function.  The function will search 
// the queue using order id to locate the existing order.  If order does 
// not exist, return -1.  Otherwise, update the existing record.  
int update_order(struct Order* item) {

	/* -- START CODING HERE -- */
	struct Order *ptr = Queue;

	if (Queue) {
		return -1;
	}

	while (ptr) {
		if (ptr->orderid == item->orderid) {
			ptr->customerNo = item->customerNo;
			strcpy(ptr->name, item->name);
			strcpy(ptr->address, item->address);
			strcpy(ptr->item, item->item);
			ptr->cost = item->cost;

			return 0;
		}

		ptr = ptr->next;
	}

	return -1;
	/* -- END CODING HERE -- */
}

int cancel_order_helper() {
	int x;

	printf("Please enter the order id: ");
	scanf("%d", &x);

	return cancel_order(x);
}

// [Q5 - 10pts] Implement the cancel function.  The function will search 
// through the queue and locate the order.  If order exist, remove it from 
// the queue.   Otherwise, please display - “Record cannot be found” - on 
// the console.  
int cancel_order(int orderid) {

	/* -- START CODING HERE -- */
	struct Order *current_ptr = Queue;
	struct Order *prev_ptr = Queue;
	struct Order *temp;

	if (Queue == NULL) {
		printf("Record cannot be found.");
		return 0;
	}

	while (current_ptr != NULL) {
		if (current_ptr->orderid == orderid) {

			if (Queue == current_ptr) {
				temp = Queue;
				Queue = Queue->next;
				free(temp);
				return 0;
			}

			prev_ptr->next = current_ptr->next;
			free(current_ptr);
			return 0;
		}

		prev_ptr = current_ptr;
		current_ptr = current_ptr->next;
	}

	printf("Record cannot be found.");
	/* -- END CODING HERE -- */

	return 0;
}

int process_order_helper() {
	int x;

	printf("How many items will the external system process? ");
	scanf("%d", &x);

	return process_order(x);
}

// [Q6 - 10pts] Implement the process function.   The function will process
// n-number of orders from the queue starting at the beginning.   Each item 
// processed will be displayed and then removed from the linked list.
// If the queue has less items then requested; process all the items in the 
// linked list and then display - "Queue is empty".   You must also consider 
// if the linked list is empty.  If so, please display – “Queue is empty” and return -1.  
int process_order(int numberOfItems) {

	/* -- START CODING HERE -- */
	struct Order *temp;

	while (numberOfItems > 0) {
		if (Queue == NULL) {
			printf("\nQueue is empty\n\n");
			return -1;
		}

		printf("\nOrder ID: \t%d", Queue->orderid);
		printf("\nCustomer: \t%d", Queue->customerNo);
		printf("\nName: \t%s", Queue->name);
		printf("\nAddress: \t%s", Queue->address);
		printf("\nItem: \t%s", Queue->item);
		printf("\nCost: \t%.2f\n", Queue->cost);
		temp = Queue;
		Queue = Queue->next;
		free(temp);

		numberOfItems--;
	}
	/* -- END CODING HERE -- */

	return 0;
}