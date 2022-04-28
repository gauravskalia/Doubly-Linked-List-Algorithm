/*******************************************************************************************
* File Name          : assign1skeleton_v2.c
* Description        : Prog8130 - Assignment 1 (V2): Doubly Linked Lists
*                      This program uses linked lists to hold and print a list of names
*                      organized by order number assosciated with each name. Each name can
*                      consist of maximum 30 characters.
*
* Author:              Gaurav Kalia
* Date:                19th March, 2022
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure/typedef used for holding data
typedef struct {
    char name[30];
    int  order;
} inputData;

// definition of linked list data nodes
typedef struct node {
    char                  name[30];        // the name to be stored
    int                   order;           // the order to be stored
    struct node           *next;           // pointer to next node in list (NULL if the end)
    struct node           *prev;           // pointer to prev node in list (NULL if the front)
} Node;

// define linked list front and rare as global variables
Node *front = NULL;
Node *rare = NULL;


// prototypes
void AddToLinkedList(char *name, int order);
void PrintLinkedListFront(Node *front);
void PrintLinkedListRare(Node *rare);

// data used for test
// start iData
inputData iData[] = {
    { "kiwi", 1 },
    { "orange", 3 },
    { "apple", 10 },
    { "pineapple", 4 }
};
// end iData
// end of data for assignment

int main(void) {
    int i;

    // Print out the input data
    printf("Data before Linked List is:\n");
    for (i = 0; i < sizeof(iData)/sizeof(inputData); i++) {
        printf("%s,%d\n", iData[i].name, iData[i].order);
    }
    printf("--\n");

    // insert the data into Linked List
    for (i = 0; i < sizeof(iData)/sizeof(inputData); i++) {
        AddToLinkedList(iData[i].name, iData[i].order);
    }

    printf("Data after adding (front):\n");
    PrintLinkedListFront(front);
    printf("--\n");

    printf("Data after adding (rare):\n");
    PrintLinkedListRare(rare);
    printf("--\n");

    return 0;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//

// FUNCTION      : AddToLinkedList()
// DESCRIPTION   : This function takes an input a name and an order and
//                 place it in a linked list organized by priority of order number.
// PARAMETERS    : char *name               - Array of Characters with data
//                 int order                - Order of the item
// RETURNS       : void
void AddToLinkedList(char *name, int order) {
    // put code in here to add the item(s) to the linked list
    // malloc to store the new node
    Node *newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->name, name);
    newnode->order = order;
    newnode->prev = NULL;
    newnode->next = NULL;

    // check if empty
    if (front == NULL && rare == NULL)
    {
        /* code */
        front =newnode;
        rare = newnode;
        return;
    }
    
    // check if should insert before front
    if (order <= front->order)
    {
        /* code */
        newnode->next = front;
        newnode->next->prev = newnode;
        front = newnode;
        rare = newnode;
    }
    
    // check if should insert after rare
    else if (order > front->order)
    {
        /* code */
        Node *a = front;
        while (a->next != NULL && a->next->order < newnode->order)
        {
            /* code */
            a = a->next;
        }
        newnode->next = a->next;
        if (a->next != NULL)
        {
            /* code */
            newnode->next->prev = newnode;
        }
        a->next = newnode;
        newnode->prev = a;

        rare = newnode;
        
    }
    
    // general case

    return;
}

// FUNCTION      : PrintLinkedListFront() / PrintLinkedListRare()
// DESCRIPTION   : These functions take an input of the front/rare of the doubly linked list, then loops through
//                 and prints each word in the doubly linked list.
// PARAMETERS    : Node *
// RETURNS       : void

void PrintLinkedListFront(Node *front) {
    // put code in here to print the linked list out
    while (front != NULL)
    {
        /* code */
        printf("%s,%d\n",front->name,front->order);
        front = front->next;
    }
    
}

void PrintLinkedListRare(Node *rare) {
    // put code in here to print the linked list out
    while (rare != NULL)
    {
        /* code */
        printf("%s,%d\n",rare->name,rare->order);
        rare = rare->prev;
    }
    
}
