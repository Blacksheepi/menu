#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include"linktable.h"

tLinkTable * CreateLinkTable()
{
    tLinkTable *pLinkTable = (tLinkTable *)malloc(sizeof(tLinkTable));
    if(pLinkTable == NULL)
    {
        return NULL;
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->sumOfNode = 0;
    pthread_mutex_init(&(pLinkTable->mutex),NULL);
    
    return pLinkTable;
}
int DeleteLinkTable(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        return FAILURE;
    }
    while(pLinkTable->pHead != NULL)
    {
        tLinkTableNode *p = pLinkTable->pHead;
	    pthread_mutex_lock(&(pLinkTable->mutex));
	    pLinkTable->sumOfNode -= 1;
	    pthread_mutex_unlock(&(pLinkTable->mutex));
	    free(p);
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->sumOfNode = 0;
    pthread_mutex_destroy(&(pLinkTable->mutex));
    free(pLinkTable);
    return SUCCESS;
}
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return FAILURE;
    }
    pNode->pNext = NULL;
    pthread_mutex_lock(&(pLinkTable->mutex));
    if(pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pNode;
    }
    if(pLinkTable->pTail == NULL)
    {
        pLinkTable->pTail = pNode;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
        pLinkTable->pTail = pNode;
    }
    pLinkTable->sumOfNode += 1 ;
    pthread_mutex_unlock(&(pLinkTable->mutex));

    return SUCCESS;     
}
int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return FAILURE;
    }
    pthread_mutex_lock(&(pLinkTable->mutex));
    if(pLinkTable->pHead == pNode)
    {
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        pLinkTable->sumOfNode -= 1 ;
        if(pLinkTable->sumOfNode == 0)
        {
            pLinkTable->pTail = NULL;   
        }
        pthread_mutex_unlock(&(pLinkTable->mutex));
        return SUCCESS;
    }
    tLinkTableNode *pTempNode = pLinkTable->pHead;
    while(pTempNode != NULL)
    {    
        if(pTempNode->pNext == pNode)
        {
            pTempNode->pNext = pTempNode->pNext->pNext;
            pLinkTable->sumOfNode -= 1 ;
            if(pLinkTable->sumOfNode == 0)
            {
                pLinkTable->pTail = NULL;   
            }
            pthread_mutex_unlock(&(pLinkTable->mutex));
            return SUCCESS;                 
        }
        pTempNode = pTempNode->pNext;
    }
    pthread_mutex_unlock(&(pLinkTable->mutex));
    return FAILURE;      
}
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        return NULL;
    }    
    return pLinkTable->pHead;
}
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return NULL;
    }
    tLinkTableNode * pTempNode = pLinkTable->pHead;
    while(pTempNode != NULL)
    {    
        if(pTempNode == pNode)
        {
            return pTempNode->pNext;                    
        }
        pTempNode = pTempNode->pNext;
    }
    return NULL;
}
