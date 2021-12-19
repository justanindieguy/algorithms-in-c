#ifndef Chains_h
#define Chains_h
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void sortedInsert(struct Node **head, int val)
{
    struct Node *newNode, *rear = NULL, *front = *head;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while (front && front->data < val)
        {
            rear = front;
            front = front->next;
        }

        if (front == *head)
        {
            newNode->next = *head;
            *head = newNode;
        }
        else
        {
            newNode->next = rear->next;
            rear->next = newNode;
        }
    }
}

struct Node *search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

#endif
