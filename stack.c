#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int is_empty(struct node *head_link);
int find(int element, struct node *head_link);
int get_length(struct node *head_link);
int get_front(struct node *head_link);
void push(int element, struct node **head_link);
void pop(struct node **head_link);
void print_stack(struct node *head_link);

int main () {
    struct node *head_link = NULL;

    push(2, &head_link);
    push(3, &head_link);
    push(7, &head_link);
    push(11, &head_link);
    push(13, &head_link);
    push(21, &head_link);

    print_stack(head_link);
    printf("%d\n", get_front(head_link));

    pop(&head_link);

    print_stack(head_link);
    printf("%d\n", get_front(head_link));

    return 0;
}

int is_empty(struct node *head_link) {
    return head_link == NULL;
}

int find(int element, struct node *head_link) {
    struct node *jumper = head_link;

    while (jumper != NULL) {
        if (jumper->data == element)
            return 1;

        jumper = jumper->link;
    }

    return 0;
}

int get_length(struct node *head_link) {
    int counter = 0;

    while (head_link != NULL) {
        counter++;
        head_link = head_link->link;
    }

    return counter;
}

int get_front(struct node *head_link) {
    return head_link->data;
}

void push(int element, struct node **head_link) {
    struct node *new_node = malloc(sizeof(struct node));
    struct node *jumper = *head_link;

    new_node->data = element;
    new_node->link = NULL;

    if (*head_link == NULL) {
        *head_link = new_node;
        return;
    }

    while (jumper->link != NULL) {
        jumper = jumper->link;
    }

    jumper->link = new_node;
}

void pop(struct node **head_link) {
    struct node *aux_ptr = *head_link;

    *head_link = (*head_link)->link;
    free(aux_ptr);
}

void print_stack(struct node *head_link) {
    while (head_link != NULL) {
        printf("%d ", head_link->data);
        head_link = head_link->link;
    }

    printf("\n");
}
