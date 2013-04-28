#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ts.h"

int main(void)
{
    /* Variables... */
    FILE *stream;
    char buf[BUFSIZ];

    /* Load customer data from addCustNode() - make function yourself using customerNode{} type */
    /* Load stock data from addStockNode() - make function yourself using stockNode{} type */

    /* Open stock file */         //TODO - make this dynamic, don't hard-code file name
    stream = fopen("stock.csv", "r");
    assert(stream);

    /* Using addStockNode */
    while (fgets(buf, BUFSIZ, stream))
    {
        addStockNode(buf);
    }

    fclose(stream);

    /* Open customer file */         //TODO - make this dynamic, don't hard-code file name
    stream = fopen("customer.csv", "r");
    assert(stream);

    /* Using addCustNode */
    while (fgets(buf, BUFSIZ, stream))
    {
        addCustNode(buf);
    }

    fclose(stream);

}


void addStockNode(char* stockLine)
{
//create linked list for stock - done
    //what is a stock node?  the whole record (id, desc etc)
    //so adding a node involves adding each field
//load file - file open for reading - done (needs work, parameterise?)
//break and tokenise - into seperate components - done
//load each bit into linked list - done (needs work)


    //Create linked list
    StockNodePtr head, new, current, previous, nextStock;
    unsigned listSize;

    char *stkTok1, *stkTok2, *stkTok3, *stkTok4;
    unsigned stkLevel;
    float stkPrice;

    listSize = 0;
    head = NULL;

/* Commented out while loop, done in loadCustomerData() */
/*    while (fgets(buf, BUFSIZ, stream))
    { */
        /* Parsing string to int   		//Comment out - some value-checking might happen, not right now
        if(sscanf(str, "%d", &anInt) != 1)
        {
            sprintf(str, "Invalid input entered \n");
            exit(EXIT_FAILURE);
        } */

        /* Create new stock node */
        if ((new = malloc(sizeof(*new))) == NULL)
        {
            fprintf(stderr,"\nMemory allocation for node insertion failed\n");
            fprintf(stderr,"Aborting\n");
            exit(EXIT_FAILURE);
        }

        /* Tokenise data */
        stkTok1 = strtok(stockLine, ",");
        stkTok2 = strtok(NULL, ",");
        stkTok3 = strtok(NULL, ",");
        stkTok4 = strtok(NULL, ",");

        /* Search to find where in insert new list node */      //TODO - needs to be adapted to sort by stock DESCRIPTION
        current = head;
        previous = NULL;
   /*     while (current != NULL && strcmp(current->description, stkTok2) < 0)	//when current = NULL, at end of list (common mistake) strcmp(current->description <
        {
            previous = current;			//for assignment, we can use strcmp()
            current = current-> nextStock;
        } */

        /* stockID */
        strcpy(new->stockID, stkTok1);

        /* Hard code for now, come back to looping (after first token) if you work out how to iterate through linked list members */
        /* description */
        strcpy(new->description, stkTok2);

        /* unitPrice */
        stkPrice = strtof(stkTok3, NULL);
        new->unitPrice = stkPrice;

        /* StockLevel */
        stkLevel = strtol(stkTok4, NULL, 10);
        new->stockLevel = stkLevel;

        /*nextStock */
        new->nextStock = current;

        /* Loop through line to assign other data to new stock node */
        /* while(stockToken != NULL)
        {
            stockToken = strtok(NULL, ",");
            //This is the prob - how to iterate through linked list members
        } */

        /* Increment listSize */
        listSize++;

        //This function, I only want to do 1 node - loadData can iterate through each line of the file */
        if(previous == NULL)			//this is when node is put in middle of the list
        {
            head = new;
        }
        else
        {
            previous->nextStock = new;
        }
        /*break;
    } */

    /* Print node details */
    current = head;
    printf("%s,%s,%f,%i\n", current->stockID, current->description, current->unitPrice, current->stockLevel);		//TODO - for assignment, fprintf and the file pointer

    /* Deallocate memory used by node */
    current = head;
    while(current != NULL)
    {
        nextStock = current->nextStock;
        free(current);
        current = nextStock;
    }

    return EXIT_SUCCESS;
}

void addCustNode(char* custLine)
{
    //Create linked list
    CustomerNodePtr head, new, current, previous, nextCust;

    char *custTok1, *custTok2, *custTok3, *custTok4, *custTok5, *custTok6, *custTok7;
    unsigned tempPc, tempPhone, listSize;

    listSize = 0;
    head = NULL;

/* Commented out while loop, done in loadCustomerData() */
/*    while (fgets(buf, BUFSIZ, stream))
    { */
        /* Parsing string to int 			//Comment out - some value-checking might happen, not right now
        if(sscanf(str, "%d", &anInt) != 1)
        {
            sprintf(str, "Invalid input entered \n");
            exit(EXIT_FAILURE);
        } */

        /* Create new stock node */
        if ((new = malloc(sizeof(*new))) == NULL)
        {
            fprintf(stderr,"\nMemory allocation for node insertion failed\n");
            fprintf(stderr,"Aborting\n");
            exit(EXIT_FAILURE);
        }

        /* Tokenise data */
        custTok1 = strtok(custLine, ",");
        custTok2 = strtok(NULL, ",");
        custTok3 = strtok(NULL, ",");
        custTok4 = strtok(NULL, ",");
        custTok5 = strtok(NULL, ",");
        custTok6 = strtok(NULL, ",");
        custTok7 = strtok(NULL, ",");

        /* Search to find where in insert new list node */      //TODO - needs to be adapted to sort by stock DESCRIPTION
        current = head;
        previous = NULL;
   /*     while (current != NULL && strcmp(current->surname, custTok2) < 0)	//when current = NULL, at end of list (common mistake) strcmp(current->description <
        {
            previous = current;			//for assignment, we can use strcmp()
            current = current-> nextStock;
        } */

        /* custID */
        strcpy(new->custID, custTok1);

        /* Hard code for now, come back to looping (after first token) if you work out how to iterate through linked list members */
        /* surname */
        strcpy(new->surname, custTok2);



        /* firstName */
        strcpy(new->firstName, custTok3);

        /* address */
        strcpy(new->address, custTok4);

        /* suburb */
        strcpy(new->suburb, custTok5);

        /* postCode */
        tempPc = strtol(custTok6, NULL, 10);
        new->postCode = tempPc;

        /* phoneNum */
        tempPhone = strtol(custTok7, NULL, 10);
        new->phoneNum = tempPhone;

        /*nextCust */
        new->nextCust = current;

        /* Loop through line to assign other data to new stock node */
        /* while(stockToken != NULL)
        {
            stockToken = strtok(NULL, ",");
            //This is the prob - how to iterate through linked list members
        } */

        /* Increment listSize */
        listSize++;

        //This function, I only want to do 1 node - loadData can iterate through each line of the file */
        if(previous == NULL)			//this is when node is put in middle of the list
        {
            head = new;
        }
        else
        {
            previous->nextCust = new;
        }

    /* Print node details */
    current = head;
    printf("%s, %s, %s, %s, %s, %i, %i\n", current->custID, current->surname, current->firstName, current->address, current->suburb, current->postCode, current->phoneNum);		//TODO - for assignment, fprintf and the file pointer

    /* Deallocate memory used by node */
    current = head;
    while(current != NULL)
    {
        nextCust = current->nextCust;
        free(current);
        current = nextCust;
    }

    return EXIT_SUCCESS;
}



