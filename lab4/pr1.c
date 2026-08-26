#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

struct node insert_at_beginning(struct node *head){
    int n;
    printf("Enter value to be inserted::");
    scanf("%d",&n);
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->next = temp;
    head = ptr;
    ptr->data = n;
    free(temp);
    temp = NULL;
    return *head;
}

struct node insert_at_end(struct node *head){
    int n;
    printf("Enter value to be inserted::");
    scanf("%d",&n);
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->data = n;
    ptr->next = NULL;
    free(temp);
    temp = NULL;
    return *head;
}

struct node insert_at_any(struct node *head, int p){
    int n;
    printf("Enter value to be inserted::");
    scanf("%d",&n);
    int count = 1;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *tr= head;
    struct node *temp;
    while (count!=p-1){
        tr = tr->next;
        count++;
    }
    temp = tr->next;
    tr->next = new_node;
    new_node->next = temp;
    new_node->data = n;
    return *head;
}

struct node delete_at_beginning(struct node *head){
    struct node *temp = head->next;
    head->next = NULL;
    free(head);
    head = temp;
    return *head;
}

struct node delete_at_end(struct node *head){
    struct  node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return *head;
}

struct node delete_at_any(struct node *head, int p){
    struct node *temp = head;
    int count = 1;
    while (count != (p-1)){
        count++;
        temp = temp->next;
    }
    temp->next = temp->next->next;
    free(temp->next->next);
    temp->next->next = NULL;
    return *head;
}

void traverse_list(struct node *head){
    struct node *temp = head;
    printf("elements are::\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void search_list(struct node *head){
    int n;
    printf("Enter element to be searched::");
    scanf("%d",&n);
    struct node *temp = head;
    int count = 0;
    while(temp != NULL){
        if (temp->data == n){
            count++;
            break;
        }
    }

    if (count != 0){
        printf("Element present");
    }
    else{
        printf("Element not present");
    }
}


int main(){
    int choice,n,q,w,r;

    if(head == NULL){
        insert_at_end(head);
    }
    else{
        printf("1 Insert element\n");
        printf("2 Delete element\n");
        printf("3 Traverse list\n");
        printf("4 search element\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("1 Insert element at beginning\n");
                printf("2 Insert element at end\n");
                printf("3 Insert element at any position\n");
                scanf("%d",&n);
                switch(n){
                    case 1:
                        insert_at_beginning(head);
                        break;
                    case 2:
                        insert_at_end(head);
                        break;
                    case 3:
                        printf("enter position::");
                        scanf("%d",&q);
                        insert_at_any(head,q);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                printf("1 Delete element at beginning\n");
                printf("2 Delete element at end\n");
                printf("3 Delete element at any position\n");
                scanf("%d",&w);
                switch(w){
                    case 1:
                        delete_at_beginning(head);
                        break;
                    case 2:
                        delete_at_end(head);
                        break;
                    case 3:
                        printf("enter position::");
                        scanf("%d",&r);
                        delete_at_any(head,r);
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                traverse_list(head);
                break;
            case 4:
                search_list(head);
                break;
            default:
                break;                                    
        }
    }
    free(head);
    head = NULL;
    return 0;
}