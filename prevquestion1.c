#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* head = NULL; 

void createList(int n) {
    struct node *newnode, *tmp;
    printf("Enter the data for the 1st node: ");
    head = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &head->data);
    head->link = NULL;
    tmp = head;

    for (int i = 2; i <= n; i++) { 
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for %dth node: ", i);
        scanf("%d", &newnode->data);
        newnode->link = NULL;
        tmp->link = newnode;
        tmp = tmp->link;
    }
}

void insertion_newnode(int pos, int data) {
    if (pos == 1) {
        
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->link = head;
        head = newnode;
    } else {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        struct node* ptr = head;
        for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
            ptr = ptr->link;
        }
        if (ptr == NULL) {
            printf("Invalid position.\n");
            return;
        }
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}

void linearsearch(int key, int n) {
    struct node* ptr = head;
    int pos = 1;
    while (ptr != NULL) {
        if (ptr->data == key) {
            insertion_newnode(pos + 1, 14);
        }
        ptr = ptr->link;
        pos++;
    }
}

void printData() {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        struct node* ptr = head;
        while (ptr != NULL) {
            printf("CURRENT ADDRESS: %p\n DATA: %d\n Next address: %p\n", ptr, ptr->data, ptr->link);
            ptr = ptr->link;
        }
    }
}

void del_at_pos(int pos) {
    if (pos == 1) {
        struct node* tmp = head;
        head = head->link;
        free(tmp);
        return;
    } else {
        struct node* prev = NULL;
        struct node* current = head;
        int count = 1;
        while (current != NULL && count < pos) {
            prev = current;
            current = current->link;
            count++;
        }
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
        prev->link = current->link;
        free(current);
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createList(n);
    int key;
    printf("Enter the key to search for: ");
    scanf("%d", &key);
    linearsearch(key, n);
    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);
    del_at_pos(position);
    printData();
    return 0;
    
}
