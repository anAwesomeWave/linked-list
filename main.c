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
}

void pop_front(struct Node** head) {
    if(*head != NULL) {
        struct Node* new_head = (*head)->next;
        free(*head);
        (*head) = new_head;
    }
}

void printList(struct Node* h) {
    while(h != NULL) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
    /*if(h == NULL)
        return;
    printf("%d ", h->data);
    printList(h->next);*/
}

struct Node* get_last_el(struct Node* ptr) {
    if(ptr == NULL)
        return NULL;
    if(ptr->next == NULL)
        return ptr;
    return get_last_el(ptr->next);
}

struct Node* get_last_but_one(struct Node* head) {
    if(head == NULL || head ->next == NULL)
        return NULL;
    if(head->next->next==NULL)
        return head;
    return get_last_but_one(head->next);
}

void push_back(struct Node** head, int data) {
    struct Node* new_el = (struct Node *)malloc(sizeof(struct Node));
    new_el -> data = data;
    new_el -> next = NULL;
    if(*head == NULL) {
        (*head) = new_el;
    } else {
        struct Node* last = get_last_el(*head);
        (*last).next = new_el;
    }
}
void pop_back(struct Node** head) {
    if((*head) != NULL) {
        if((*head)->next == NULL){
            free(*head);
            *head = NULL;
        } else {
            struct Node* ptr = (get_last_but_one(*head));
            free(ptr->next);
            ptr->next = NULL;
        }

    }
}

void insert(struct Node** head, int n, int data) { // 'n' and 'i' are signed because of 'n-1'
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    new->data = data;
    if(n == 0) {
        new->next = (*head);
        *head = new;
    }else {
        int i = 0;
        struct Node *tmp = (*head);
        while (i < n - 1 && tmp->next) { // search for previous element
            tmp = tmp->next;
            i++;
        }
        new->next = tmp->next;
        tmp->next = new;
    }
}

void free_memory(struct Node* head) {
    if(!head)
        return;
    if(head->next)
        free_memory(head->next);
    free(head);
}

int main() {
    struct Node* head = NULL;
    for(int i = 1; i < 6; i ++) {
        push_back(&head, i);
        printList(head);
    }
    printf("\n");
    insert(&head, 1, 0);
    printList(head);
    insert(&head, 2, 0);
    printList(head);
    insert(&head, 0, 0);
    printList(head);
    insert(&head, 8, 0);
    printList(head);
    free_memory(head);
}
