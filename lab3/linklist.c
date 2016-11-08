
/*
*Target:A universal menu program
*Author:Dou Yiming
*Date:2016/09/23
*/

#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

tDataNode* FindCmd(tDataNode * head,char * cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }
    tDataNode *p = head;
    while(p != NULL)
    {
        if(strcmp(p->cmd, cmd)==0)
	    {
	        return p;
	    }
	    p = p->next;
    }
    return NULL;
}
int ShowAllCmd(tDataNode * head)
{
    printf("Menu list:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->node);
	    p = p->next;
    }
    return 0;
}

