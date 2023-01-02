// Credits to Nic Olsen for original creation

#include <stdio.h>
#include <stdlib.h>
#include "dll_alloc.h"
#include "dllist.h"
#include "traversal.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: ./task2 <num_elements>\n");
        return 1;
    }

    int count = atoi(argv[1]);
    if (count <= 0) {
        printf("num_elements must be positive\n");
        return 1;
    }

    // Allocate and initialize a DLL 
    ListNode* head;
    CreateDLL(&head, count);

    // Print DLL forward and backward
    PrintDLLForward(head);
    PrintDLLReverse(head);

    // Free memory used for the DLL
    FreeDLL(head, count);
    return 0;
}
