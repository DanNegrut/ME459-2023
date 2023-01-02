// Credits to Nic Olsen for original creation

#ifndef DLL_ALLOC_H
#define DLL_ALLOC_H

#include "dllist.h"

// Allocates memory for count nodes and links them together into a
// circular, doubly-linked list
void CreateDLL(ListNode** head, int count);

// Frees memory for all count nodes in a circular, doubly-linked list
void FreeDLL(ListNode* head, int count);

#endif
