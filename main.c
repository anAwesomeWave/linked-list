#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* next;
};

void push_front(struct Node** head, int data) {
    struct Node* ptr;
    if(!(ptr = (struct Node *)malloc(sizeof(struct Node)))) {
        printf("Allocation error");
        return;
    }
    ptr->data = data;
    if(*head == NULL) {
        *head = ptr;
        ptr->next = NULL;
    } else {
        ptr->next = (*head);
        (*head) = ptr;
    }
};

void printList(struct Node* h) {
    /*while(h != NULL) {
        printf("%d ", h->data);
        h = h->next;
    }*/
    if(h == NULL)
        return;
    printf("%d ", h->data);
    printList(h->next);
}

struct Node* get_last_el(struct Node* ptr) {
    if(ptr->next == NULL)
        return ptr;
    return get_last_el(ptr->next);
}

void push_back(struct Node** ptr, int data) {
    struct Node* new_el = (struct Node *)malloc(sizeof(struct Node));
    new_el -> data = data;
    new_el->next = NULL;
    if(*ptr == NULL) {
        (*ptr) = new_el;
    } else {
        struct Node* last = get_last_el(*ptr);
        (*last).next = new_el;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for(int i = 0; i < 5; i ++) {
        push_back(&head, i);
        printList(head);
        printf("\n");
    }
    //printf("%d", get_last_el(head)->data);
}
