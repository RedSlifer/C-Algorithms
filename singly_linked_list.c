#include <stdio.h>
#include <stdlib.h>

struct node {
    int element;
    struct node *link;
};

int is_empty(struct node *head_link);
int find(int element, struct node *head_link);
int get_length(struct node **head_link);
int get_front(struct node *head_link);
int get_back(struct node *head_link);
void insert_front(int element, struct node **head_link);
void insert_back(int element, struct node **head_link);
void insert(int element, int position, struct node **head_link);
void remove_front(struct node **head_link);
void remove_back(struct node **head_link);
void remove_node(int position, struct node **head_link);
void print_list(struct node *head_link);

int main() {
    struct node *head_link = NULL;

    if (is_empty(head_link)) {
        printf("List empty\n");
    }

    insert(0, 0, &head_link);
    insert(1, 1, &head_link);
    insert(2, 2, &head_link);
    insert(3, 3, &head_link);
    insert(4, 4, &head_link);

    print_list(head_link);
    //printf("Length: %d\nFront: %d\nBack: %d\n", get_length(&head_link), get_front(head_link), get_back(head_link));
    remove_front(&head_link);
    //printf("Length: %d\nFront: %d\nBack: %d\n", get_length(&head_link), get_front(head_link), get_back(head_link));
    print_list(head_link);
    remove_back(&head_link);
    print_list(head_link);
    remove_node(2, &head_link);
    print_list(head_link);
    //printf("Length: %d\nFront: %d\nBack: %d\n", get_length(&head_link), get_front(head_link), get_back(head_link));

    if (find(2, head_link)) {
        printf("Element found\n");
    }
    else {
        printf("Element not found\n");
    }

    if (is_empty(head_link)) {
        printf("List empty\n");
    }

    return 0;
}

int is_empty(struct node *head_link) {
    return head_link == NULL;
}

int find(int element, struct node *head_link) {
    struct node *jumper = head_link;

    while (jumper != NULL) {
        if (jumper->element == element)
            return 1;

        jumper = jumper->link;
    }

    return 0;
}

int get_length(struct node **head_link) {
    struct node *jumper = *head_link;
    int length = 0;

    while (jumper != NULL) {
        length++;
        jumper = jumper->link;
    }

    return length;
}

int get_front(struct node *head_link) {
    return head_link->element;
}

int get_back(struct node *head_link) {
    struct node *jumper = head_link;

    while (jumper->link != NULL) {
        jumper = jumper->link;
    }

    return jumper->element;
}

void insert_front(int element, struct node **head_link) {
    struct node *new_node = malloc (sizeof (struct node));
    new_node->element = element;
    new_node->link = NULL;

    if (*head_link == NULL) {
        *head_link = new_node;
    }
    else {
        new_node->link = *head_link;
        *head_link = new_node;
    }
}

void insert_back(int element, struct node **head_link) {
    struct node *new_node = malloc(sizeof (struct node));
    struct node *jumper = *head_link;

    new_node->element = element;
    new_node->link = NULL;

    while (jumper->link != NULL) {
        jumper = jumper->link;
    }

    jumper->link = new_node;
}

void insert(int element, int position, struct node **head_link) {
    if (position == 0)
        insert_front(element, head_link);
    else if (position == get_length(head_link))
        insert_back(element, head_link);
    else {
        struct node *new_node = malloc(sizeof (struct node));
        struct node *jumper = *head_link;
        int index = 0;

        new_node->element = element;
        new_node->link = NULL;

        while (index != position - 1) {
            index++;
            jumper = jumper->link;
        }

        new_node->link = jumper->link;
        jumper->link = new_node;
    }
}

void remove_front(struct node **head_link) {
    struct node *jumper = *head_link;

    *head_link = (*head_link)->link;
    free(jumper);
}

void remove_back(struct node **head_link) {
    struct node *jumper = *head_link;

    while (jumper->link->link != NULL) {
        jumper = jumper->link;
    }

    free(jumper->link);
    jumper->link = NULL;
}

void remove_node(int position, struct node **head_link) {
    if (position == 0)
        remove_front(head_link);
    else if (position == get_length(head_link))
        remove_back(head_link);
    else {
        struct node *jumper = *head_link;
        struct node *aux_pointer = *head_link;
        int index = 0;

        while (index != position - 1) {
            index++;
            jumper = jumper->link;
            aux_pointer = aux_pointer->link;
        }

        aux_pointer = aux_pointer->link;
        jumper->link = jumper->link->link;
        free(aux_pointer);
    }
}

void print_list(struct node *head_link) {
    while (head_link != NULL) {
        printf("%d ", head_link->element);
        head_link = head_link->link;
    }
    printf("\n");
}
