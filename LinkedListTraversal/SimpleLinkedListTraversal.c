#include <stdio.h>

struct NODE {
    int value;
    struct NODE* next;
};

struct NODE newNode(int x) {
    struct NODE n;
    n.value = x; n.next = NULL;
    return n;
}

void appendNode(struct NODE* p1, struct NODE* n2) {
    p1->next = n2;
    printf("value of p1->next = %ld\n", (long int) p1->next);
}

void printNodeList(struct NODE* first) {
    int i = 0;
    struct NODE* current = first;
    while(current != NULL) {
        printf("value = %d, position = %d\n", current->value, i);
        i++;
        current = current->next;
    }
}


int main() {
    struct NODE* p;
    p = NULL;

    struct NODE n1 = newNode(1);
    struct NODE n2 = newNode(2);
    struct NODE n3 = newNode(3);
    struct NODE n4 = newNode(4);
    struct NODE n0 = newNode(0);
    
    appendNode(&n0, &n1); // n0 -> n1
    appendNode(&n1, &n2); // n1 -> n2
    appendNode(&n2, &n3); // n2 -> n3
    appendNode(&n3, &n4); // n3 -> n4


    printf("value of n1.next = %ld\n", (long int) n0.next);
    printf("value of n2.next = %ld\n", (long int) n1.next);
    printf("value of n3.next = %ld\n", (long int) n2.next);
    printf("value of n4.next = %ld\n", (long int) n3.next);
    
    printNodeList(&n0);

    return 0;
}

