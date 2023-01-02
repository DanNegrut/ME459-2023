// Credits to Nic Olsen for original creation

#include <stdlib.h>
#include "dll_alloc.h"
#include "dllist.h"

void CreateDLL(ListNode** head, int count) {
    // allocate a node for the list head
    *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* curr = *head;  // curr is a tracker pointer
    curr->data = 0;          // the head's value is 0

    // allocate rest of the nodes so that they link to in both next and prev directions
    for (int i = 1; i < count; i++) {
        // allocate the next node
        curr->next = (ListNode*)malloc(sizeof(ListNode));

        // point the next node's prev to the current node
        curr->next->prev = curr;

        // set the data of the new
        curr->next->data = i;

        // advance curr to the next node in the list, which has now been allocated
        curr = curr->next;
    }

    // connect the final node to the head both directions
    // this completes the circular linked list
    curr->next = *head;
    (*head)->prev = curr;
}

void FreeDLL(ListNode* head, int count) {
    ListNode* curr = head;  // curr is a tracker pointer
    ListNode* next = NULL;  // temporary pointer for tracking the next node

    // run the freeing process starting at the head until the head address is reached again
    while (next != head) {
        // save the next node to free
        next = curr->next;

        // free the current node
        free(curr);

        // advance curr to the saved next node
        curr = next;
    }
}
