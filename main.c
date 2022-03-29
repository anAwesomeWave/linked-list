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


int main() {
    struct Node* head = NULL;
    for(int i = 0; i < 5; i ++) {
        push_front(&head, i);
        printList(head);
        printf("\n");
    }
}
