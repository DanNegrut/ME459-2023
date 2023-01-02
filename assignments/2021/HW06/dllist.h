// Credits to Nic Olsen for original creation

#ifndef DLLIST_H
#define DLLIST_H

typedef struct ListNode {
    int data;               // This node's data
    struct ListNode* next;  // Pointer to the next node in the list
    struct ListNode* prev;  // pointer to the previous node in the list
} ListNode;

#endif
