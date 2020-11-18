/*
Shradhey Pathak
20198111
IT 3B
DOUBLY LINKED LIST
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

int menu();
struct Node *createNode(int data);
void insertAtStart(int data);
void insertAtEnd(int data);
void insertBefore_x(int x);
void insertAfter_x(int x);
void deleteFirstElement();
void displayList();
void deleteLastElement();
void delete_x(int x);

int main()
{
    printf("DOUBLY LINKED LIST\n");
    while (1)
    {
        int choice = menu();
        int n;
        switch (choice)
        {
        case 1:
            printf("Enter an element : ");
            scanf("%d", &n);
            insertAtStart(n);
            break;
        case 2:
            printf("Enter an element : ");
            scanf("%d", &n);
            insertAtEnd(n);
            break;
        case 3:
            printf("Enter x : ");
            scanf("%d", &n);
            insertBefore_x(n);
            break;
        case 4:
            printf("Enter x : ");
            scanf("%d", &n);
            insertAfter_x(n);
            break;
        case 5:
            deleteFirstElement();
            break;
        case 6:
            deleteLastElement();
            break;
        case 7:
            printf("Enter x : ");
            scanf("%d", &n);
            delete_x(n);
            break;
        case 8:
            displayList();
            break;
        case 9:
            exit(0);
        default:
            printf("Enter a valid choice\n");
        }
    }
}

int menu()
{
    printf("\nChoose an option\n");
    printf("1. Insert At Start\t2. Insert At End\t3. Insert before x\t4. Insert after x\t5. Delete First Element\n6. Delete last element\t7. Delete x\t8. Display list\t9. Exit\n");
    int choice;
    scanf("%d", &choice);
    return choice;
}

void insertAtStart(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return;
}

void insertBefore_x(int x)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->data == x)
    {
        printf("Enter the element to insert : ");
        int data;
        scanf("%d", &data);
        insertAtStart(data);
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            printf("Enter the element to insert : ");
            int data;
            scanf("%d", &data);
            struct Node *newNode = createNode(data);
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            return;
        }
        temp = temp->next;
    }
    printf("No such element exists.\n");
    return;
}

void insertAfter_x(int x)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            printf("Enter the element to insert : ");
            int data;
            scanf("%d", &data);
            struct Node *newNode = createNode(data);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next == NULL)
            {
                temp->next = newNode;
                return;
            }
            temp->next = newNode;
            temp->next->prev = newNode;
            return;
        }
        temp = temp->next;
    }
    printf("No such element exists.\n");
    return;
}

void deleteFirstElement()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return;
}

void deleteLastElement()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL)
    {
        deleteFirstElement();
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    struct Node *temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
    return;
}

void delete_x(int x)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            if (temp == head)
            {
                deleteFirstElement();
                return;
            }
            if (temp->next == NULL)
            {
                deleteLastElement();
                return;
            }
            struct Node *temp1 = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp1);
            return;
        }
        temp = temp->next;
    }
    printf("No such element exists.\n");
    return;
}

void displayList()
{
    if(head == NULL){
        printf("List is Empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
