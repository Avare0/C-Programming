#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

void push(Node **head, int *length)
{
    int value;
    scanf("%d", &value);
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = (*head);
    *head = tmp;
    *length += 1;
}


void pop(Node **head, int *length, int pos)
{
    int i = 0;
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp = *head;
    while (i < pos - 1)
    {
        tmp = tmp->next;
        i++;
    }
    if (pos == 0)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    else {
        Node *prev = NULL;
        prev = tmp;
        Node *next_item = NULL;
        next_item = tmp->next;
        next_item = next_item->next;
        free(tmp->next);
        prev->next = next_item;
    }
    *length -= 1;
}
void clean(Node **head, int length)
{
    for (int i = 0; i < length; i++)
        pop(head, &length, i);
}
void output_list(Node *head);
void delete_odd(Node **head, int *length)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp = *head;
    int flag = 0;
    int flag1 = 0;
    int count = 0;
    
    for (int i = 0; i < *length + count; i++)
    {
        
        if (tmp->value % 2 == 1)
        {
            count++;
            pop(head, length, i);
            if (count == 1)
            {
                flag1 = 1;
            } else {
                flag = 1;
            }
            i--;
            *length -= 1;
        }
        tmp = tmp->next;
    }
}

void output_list(Node *head)
{
    Node *p;
    p = head;
    do {
        printf("%d", p->value);
        p = p->next;
    } while (p != NULL);
}


int main() {
    int length = 0;
    Node *head = NULL;
    push(&head, &length);
    push(&head, &length);
    push(&head, &length);
    push(&head, &length);
    push(&head, &length);
    push(&head, &length);
//    pop(&head, &length, 2);
//    pop(&head, &length, 2);
    output_list(head);
    delete_odd(&head, &length);
    output_list(head);
    return EXIT_SUCCESS;
}
