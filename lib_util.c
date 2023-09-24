#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "lib_util.h"


node* createNodeLL()
{
    char title[200];
    char author[200];
    int totalCopies;
    int copiesInStorage;

    node* nn;
    nn = (node*)malloc(sizeof(node));

    //inform, user what we are doing
    printf("\nYou have initiated the book registration procedure");
    printf("\nYou will now be asked to provide some information");

    //get title
    printf("\nBook Title:");
    fflush(stdin);
    scanf("%s", title);


    //get author
    printf("Book Author:");
    fflush(stdin);
    scanf("%s", author);

    //get totalCopies
    printf("Total Copies:");
    fflush(stdin);
    scanf("%d", &totalCopies);

    //get copiesInStorage
    printf("Copies in storage:");
    fflush(stdin);
    scanf("%d", &copiesInStorage);

    strcpy(nn->title, title);
    strcpy(nn->author, author);
    nn->totalCopies = totalCopies;
    nn->copiesInStorage = copiesInStorage;

    nn->next = NULL;

    return nn;
}

node* addNodeToHead(node* head, node* newNode)
{
    newNode->next = head;//point new node ptr to current head
    return newNode;
}

void printAllInfo(node* head)
{
    node* tmp = head;

    while(tmp!=NULL)//if node is NULL then exit loop
    {
        //print
        printf("\n\nNode Addr:0x%x", tmp);
        printf("\nTitle:%s", tmp->title);
        printf("\nAuthor:%s", tmp->author);
        printf("\nTotal Copies:%d", tmp->totalCopies);
        printf("\nCopies In Storage:%d", tmp->copiesInStorage);
        tmp = tmp->next;//point tmp to the next node
    }
}

node* autoPopLib(node* head)
{
    node* nn;

    //create new node
    nn = (node*)malloc(sizeof(node));
    //populate new node
    strcpy(nn->title, "aa");
    strcpy(nn->author, "aa");
    nn->totalCopies = 20;
    nn->copiesInStorage = 20;
    nn->next = NULL;//not entirely necessary as it will be modified in the next step
    //make new node the head of the list
    head = addNodeToHead(head, nn);

    //create new node
    nn = (node*)malloc(sizeof(node));
    //populate new node
    strcpy(nn->title, "bb");
    strcpy(nn->author, "bb");
    nn->totalCopies = 30;
    nn->copiesInStorage = 30;
    nn->next = NULL;//not entirely necessary as it will be modified in the next step
    //make new node the head of the list
    head = addNodeToHead(head, nn);

    //create new node
    nn = (node*)malloc(sizeof(node));
    //populate new node
    strcpy(nn->title, "cc");
    strcpy(nn->author, "cc");
    nn->totalCopies = 40;
    nn->copiesInStorage = 40;
    nn->next = NULL;//not entirely necessary as it will be modified in the next step
    //make new node the head of the list
    head = addNodeToHead(head, nn);

    //create new node
    nn = (node*)malloc(sizeof(node));
    //populate new node
    strcpy(nn->title, "dd");
    strcpy(nn->author, "dd");
    nn->totalCopies = 50;
    nn->copiesInStorage = 50;
    nn->next = NULL;//not entirely necessary as it will be modified in the next step
    //make new node the head of the list
    head = addNodeToHead(head, nn);

    //create new node
    nn = (node*)malloc(sizeof(node));
    //populate new node
    strcpy(nn->title, "ee");
    strcpy(nn->author, "ee");
    nn->totalCopies = 60;
    nn->copiesInStorage = 60;
    nn->next = NULL;//not entirely necessary as it will be modified in the next step
    //make new node the head of the list
    head = addNodeToHead(head, nn);

    return head;

}

void printNumOfCopies(node* head)
{
    char bookTitle[200];
    node* tmp = head;

    printf("\nPlease provide the title of a book to see how many copies are available");
    printf("\nBook Title:");
    fflush(stdin);
    scanf("%s", bookTitle);

    //iterate through the list

    while(tmp!=NULL)
    {
        if(strcmp(tmp->title,bookTitle)==0)
        {
            printf("\nBook Title:%s\nCopies Available %d",bookTitle, tmp->copiesInStorage);
            return;
        }
        tmp = tmp->next;
    }
    printf("\nBook Title:%s Not Found", bookTitle);
}

void deleteNodeFromPosition(node* head, int position)//nth position from head, index starting at 0
{
    node* tmp = head;
    node* nodeToDel;
    int i;

    if(position == 0)
    {
        printf("Cannot delete node in position 0");
    }
    else if(position == 1)
    {
        nodeToDel = tmp->next;//point to the node that needs to be deleted
        tmp->next = nodeToDel->next;//break connection to nodeToDel and connect to next
        free(nodeToDel);//de-allocate the memory from the deleted node
        return;
    }
    else
    {
        for(i=1;i<position;i++)
        {
            tmp = tmp->next;//tmp to the one before the node that we want to delete
            if(tmp->next != NULL)
            {
                nodeToDel = tmp->next;//point to the node that needs to be deleted
                if(i == (position-1))
                {
                    tmp->next = nodeToDel->next;//break connection to nodeToDel and connect to next
                    free(nodeToDel);//de-allocate the memory from the deleted node
                    return;
                }
            }
            else
            {
                printf("Cannot delete something beyond the end of the list");
                return;
            }
        }
    }
}

node* deleteBookFromDB(node* head)//returns new head
{
    //iterate through the list
    //find index number of the node that we want to delete
    //use our deleteNodeWithIndex function to delete the node

    char bookTitle[200];
    node* tmp = head;
    int indexCount = 0;

    printf("\nTitle of the book to delete:");
    fflush(stdin);
    scanf("%s", bookTitle);

    while(tmp!=NULL)
    {
        if(strcmp(tmp->title,bookTitle)==0)
        {
            break;
        }
        tmp = tmp->next;//point tmp to the next node
        indexCount++;
    }
    //at the end of this loop we have the index of
    //the node we want to remove inside the variable indexCount

    if(indexCount == 0)
    {
        head = deleteHead(head);
        return head;
    }
    else
    {
        //use the deleteNodeWithIndex function
        deleteNodeFromPosition(head, indexCount);
        return head;
    }
}

node* deleteHead(node* head)
{
    node* tmp = head;
    node* nodeToDel;

    head = head->next;//point head to 2nd node
    //tmp still points to original head
    free(tmp);//de-allocate memory that is pointed to my tmp

    return head;
}

void loanOutBook(node* head)
{
    char bookTitle[200];
    node* tmp = head;

    printf("\nWhich book do you want to loan out?");
    printf("\nBook Title:");
    fflush(stdin);
    scanf("%s", bookTitle);

    while(tmp!=NULL)
    {
        if(strcmp(tmp->title, bookTitle) == 0)
        {
            printf("\nBook Title: %s\nCopies Available (before):%d", tmp->title, tmp->copiesInStorage);
            tmp->copiesInStorage = (tmp->copiesInStorage)-1;
            printf("\nBook Title: %s\nCopies Available (after):%d", tmp->title, tmp->copiesInStorage);
            return;
        }
        tmp = tmp->next;//point tmp to the next node
    }
    printf("\nBook Title:%s Not Found", tmp->title);
}




