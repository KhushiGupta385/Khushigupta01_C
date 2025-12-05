// SELF
#include <stdio.h>
#include <stdlib.h>

struct Dlink_list {
    struct Dlink_list *prev;
    int info;
    struct Dlink_list *next;
};
typedef struct Dlink_list Dnode;

Dnode *lp = NULL, *rp = NULL;   // lp = left (start), rp = right (end)
int num;

/* Function declarations */
void create();
void display();
void insert_first();
void insert_last();
void delete_first();
void delete_last();
void insert_before();
void insert_after();
void delete_n();

/* MAIN */
int main() {
    int ch;

    do {
        printf("\n\n====== DOUBLY LINKED LIST MENU ======");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Insert at Beginning");
        printf("\n4. Insert at End");
        printf("\n5. Delete First Node");
        printf("\n6. Delete Last Node");
        printf("\n7. Insert Before Given Value");
        printf("\n8. Insert After Given Value");
        printf("\n9. Delete Nth Node");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert_first(); break;
            case 4: insert_last(); break;
            case 5: delete_first(); break;
            case 6: delete_last(); break;
            case 7: insert_before(); break;
            case 8: insert_after(); break;
            case 9: delete_n(); break;
            case 0: printf("\nExiting program..."); break;
            default: printf("\nInvalid choice!");
        }
    } while (ch != 0);

    return 0;
}

/* CREATE FUNCTION */
void create() {
    int ch;
    Dnode *ptr;
    num = 0;

    if (lp == NULL)
    {
        lp = (Dnode *)malloc(sizeof(Dnode));
        lp->prev = NULL;
        ptr = lp;
    }

    do {
        printf("\nEnter value for node %d: ", num + 1);
        scanf("%d", &ptr->info);
        printf("Press 1 to add more nodes: ");
        scanf("%d", &ch);
        if (ch == 1) {
            ptr->next = (Dnode *)malloc(sizeof(Dnode));
            ptr->next->prev = ptr;
            ptr = ptr->next;
        }
        num++;
    } while (ch == 1);

    ptr->next = NULL;
    rp = ptr;  /*assign the addr. of rightmost node to rp*/
    printf("\nTotal nodes = %d\n", num);
}

/* DISPLAY FUNCTION */
void display() {
    Dnode *ptr = lp;

    if (lp == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nForward: ");
    while (ptr != NULL)
    {
        printf(" %d", ptr->info);
        if (ptr->next == NULL)
            rp = ptr;
        ptr = ptr->next;
    }

    printf("\nBackward: ");
    ptr = rp;
    while (ptr != NULL) {
        printf(" %d", ptr->info);
        ptr = ptr->prev;
    }
    printf("\n");
}

/* INSERT FIRST */
void insert_first() {
    Dnode *new1 = (Dnode *)malloc(sizeof(Dnode));
    printf("\nEnter value to insert at beginning: ");
    scanf("%d", &new1->info);

    if (lp == NULL)
    {
        new1->next = NULL;
        new1->prev = NULL;
        lp = rp = new1;
    } else {
        new1->next = lp;
        new1->prev = NULL;
        lp->prev = new1;
        lp = new1;
    }
    printf("\nNode inserted at beginning.\n");
}

/* INSERT LAST */
void insert_last() {
    Dnode *new1 = (Dnode *)malloc(sizeof(Dnode));
    printf("\nEnter value to insert at end: ");
    scanf("%d", &new1->info);

    if (lp == NULL) {
        new1->next = NULL;
        new1->prev = NULL;
        lp = rp = new1;
    } else {
        rp->next = new1;
        new1->prev = rp;
        new1->next = NULL;
        rp = new1;
    }
    printf("\nNode inserted at end.\n");
}

/* DELETE FIRST */
void delete_first() {
    if (lp == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    Dnode *temp = lp;
    if (lp == rp) {
        lp = rp = NULL;
    } else {
        lp = lp->next;
        lp->prev = NULL;
    }
    free(temp);
    printf("\nFirst node deleted successfully.\n");
}

/* DELETE LAST */
void delete_last() {
    if (rp == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    Dnode *temp = rp;
    if (lp == rp) {
        lp = rp = NULL;
    } else {
        rp = rp->prev;
        rp->next = NULL;
    }
    free(temp);
    printf("\nLast node deleted successfully.\n");
}

/* INSERT BEFORE VALUE */
void insert_before() {
    int val;
    printf("\nEnter value before which to insert: ");
    scanf("%d", &val);

    Dnode *ptr = lp;
    while (ptr != NULL && ptr->info != val)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("\nValue not found!\n");
        return;
    }

    Dnode *new1 = (Dnode *)malloc(sizeof(Dnode));
    printf("Enter value to insert: ");
    scanf("%d", &new1->info);

    new1->next = ptr;
    new1->prev = ptr->prev;

    if (ptr->prev != NULL)
        ptr->prev->next = new1;
    else
        lp = new1;  // inserting before first node

    ptr->prev = new1;

    printf("\nNode inserted before %d.\n", val);
}

/* INSERT AFTER VALUE */
void insert_after() {
    int val;
    printf("\nEnter value after which to insert: ");
    scanf("%d", &val);

    Dnode *ptr = lp;
    while (ptr != NULL && ptr->info != val)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("\nValue not found!\n");
        return;
    }

    Dnode *new1 = (Dnode *)malloc(sizeof(Dnode));
    printf("Enter value to insert: ");
    scanf("%d", &new1->info);

    new1->prev = ptr;
    new1->next = ptr->next;

    if (ptr->next != NULL)
        ptr->next->prev = new1;
    else
        rp = new1;  // inserted at end

    ptr->next = new1;

    printf("\nNode inserted after %d.\n", val);
}

/* DELETE Nth NODE */
void delete_n() {
    int n, count = 1;
    printf("\nEnter node position to delete: ");
    scanf("%d", &n);

    Dnode *ptr = lp;

    if (lp == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    while (ptr != NULL && count < n) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        printf("\nInvalid position!\n");
        return;
    }

    if (ptr == lp)
        delete_first();
    else if (ptr == rp)
        delete_last();
    else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        printf("\nNode %d deleted successfully.\n", n);
    }
}
