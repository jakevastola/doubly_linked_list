#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct Node 
{
    int data;
    struct Node *prev, *next;
} node;

node* insert_front(node *root, int value)
{
    // Create a temp node with the desired value.
    // "prev" for the node is NULL because it is at the front of the list.
    node *temp = (node *) malloc(sizeof(node));
    temp->data = value;
    temp->prev = NULL;

    // Puts the temp node before the current root.
    temp->next = root;

    // If root has contents, then "makes space" for the new node to become the new root.
    if(root!=NULL)
    {
        root->prev = temp;
    }

    // Finalizes the new root, whether it declares a value or inserts a new node.
    root = temp;

    return root;
}

node* insert_end(node* root, int value)
{
    // The "conductor" node to traverse the list.
    node *temp2;

    // temp node holds the input info.
    node *temp;

    // Create a temp node that takes input value.
    // temp->next is NULL because it is at the end of the list.
    temp = (node *) malloc (sizeof(node));
    temp->data = value;
    temp->next = NULL;


    // If linked list is empty, set the prev of the temp node as NULL and make that the root.
    if(root==NULL)
    {
        temp->prev = NULL;
        root = temp;
    }
    else
    {
        // Use temp2 as a "conductor" node to traverse the list from the first node.
        temp2 = root;
        
        // Travels to the end of the list.
        while(temp2->next!=NULL) {
            temp2 = temp2->next;        
        }

        // Once the "conductor" node reaches the end, the new node is inserted at the end.
        temp2->next = temp;
        temp->prev = temp2;    
    }
    
    return root;
}

node* delete_node(node* root, int value)
{
    node *temp2;
    node *temp;

    if(root==NULL) {
        return root;
    }

    // If the target is at the root.
    if(root->data==value)
    {
        // Store the root in the temp node
        temp = root;

        // Make the node after the root the new node.
        root = root->next;   

        // Make the prev of the new node (formerly the second node) NULL.
        if(root != NULL)
        {
            root->prev = NULL;
            
            // Free the original root and return the new and ready root.
            free(temp);
            return root;
        }
    }

    // Set the "conductor" node to start at the beginning.
    temp2 = root;

    // Continue traversing the list until it reaches a node with the desired value.
    while(temp2->next!=NULL && temp2->next->data != value)
    {
        temp2 = temp2->next;
    }
    
    // If the traversal is completed without detecting a node with the desired value, end the method.
    if(temp2->next == NULL)
    {
        return root;    
    }

    // If the execution reaches this point, a node with the value was found.
    // temp node holds the node that the traversal node is on ("to be deleted" node).
    temp = temp2->next;

    // The node that will be deleted has its position replaced by the node after.
    temp2->next = temp2->next->next;

    // If the node after the to-be-deleted node is NOT NULL
    if(temp2->next->next!=NULL)
    {
        // The "prev" of the node after the TBD pointer now points to the node before the TBD node.
        temp2->next->next->prev = temp2->next->prev;
    }

    // If the node before the to-be-deleted node is NOT NULL
    if(temp2->next->prev!=NULL)
    {
        // The "next" of the node before the to-be-deleted node now points to the node after the TBD node
        temp2->next->prev->next = temp2->next->next;
    }
    
    free(temp);

    return root;
}


void print(node* root)
{

    if(root==NULL)
    {
        printf("The linked list is empty.\n");
        return;        
    }
    else {
        printf("[%d]", root->data);        
    }

    root = root->next;

    while(root!=NULL)
    {
        printf(" - [%d]", root->data);
        root = root->next;
    }

    printf("\n");
}

int main()
{
    srand(time(0));

    int i, value;
    int inserted_front_value = 10;
    int inserted_end_value = 20;

    node* root = NULL;

    for(i=0;i<5;i++)
    {
        root = insert_front(root, rand()%100 + 1);
    }

    print(root);

    root = insert_front(root, inserted_front_value);

    printf("\nAfter inserting %d into the front: \n", inserted_front_value);
    print(root);


    root = insert_end(root, inserted_end_value);
    printf("\nAfter inserting %d into the end: \n", inserted_end_value);
    print(root);

    printf("\nEnter the node you want to delete: ");
    scanf("%d", &value);
    root = delete_node(root, value);

    printf("\nJust deleted %d: \n", value);
    print(root);
    
    /*while(1)
    {
        
    }*/


    return 0;

}










