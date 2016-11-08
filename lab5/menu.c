/*
*An universal menu program
*Author:Dou Yiming
*Date:2016/09/23
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"linktable.h"

int Love();
int Help();
int Date();
int Convert();
int Quit();
int Motto();
int Try();
int Which();

#define CMD_MAX_LEN 128
#define NOTE_LEN 1024
#define CMD_NUM 10

/*data struct and its operations*/
typedef struct DataNode
{
    tLinkTableNode *pNext;
    char* cmd;
    char* node;
    int (*handler)();
    void *condition;
   // struct DataNode *next;
}tDataNode;
int SearchCondition(tLinkTableNode * pLinkTableNode)
{
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, (char*)pNode->condition) == 0)
    {
        return  SUCCESS;
    }
    return FAILURE;
}
tDataNode* FindCmd(tLinkTable * head,char * cmd)
{
    tDataNode *pNode =  (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
       pNode->condition = cmd;
       pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition);
}
int ShowAllCmd(tLinkTable * head)
{
    printf("Menu list:\n");
    tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->node);
	    pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return 0;
}

int InitMenuData(tLinkTable ** ppLinkTable)
{
    *ppLinkTable = CreateLinkTable();
    tDataNode * pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->node = "Menu List:";
    pNode->handler = Help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->node = "exit the menu";
    pNode->handler = Quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "love";
    pNode->node = "show a heart";
    pNode->handler = Love;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "which";
    pNode->node = "the best language";
    pNode->handler = Which;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "try";
    pNode->node = "how should you do when you failed";
    pNode->handler = Try;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "motto";
    pNode->node = "show a motto";
    pNode->handler = Motto;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "date";
    pNode->node = "show current time";
    pNode->handler = Date;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "convert";
    pNode->node = "convert between centigrade and fahrenheit";
    pNode->handler = Convert;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode*)pNode);
   
    return 0;
}

/* menu program */

tLinkTable * head = NULL;
int main()
{
    /* cmd line begins */
    InitMenuData(&head);
    while(1)
    {
        char cmd[CMD_MAX_LEN];
	    printf("Input a cmd number >");
	    scanf("%s", cmd);
	    tDataNode *p = FindCmd(head,cmd);
	    if(p == NULL)
	    {
	        printf("This is a wrong cmd!\n");
	        continue;
	    }
	    printf("%s - %s\n",p->cmd, p->node);
	    if(p->handler != NULL)
	    {
	        p->handler();
	    }
    }
}
int Help()
{
    ShowAllCmd(head);
    return 0;
}
int Love()
{
    float y, x, a;
    for (y = 1.5f;y > -1.5f;y -= 0.1f)
    {
        for (x = -1.5f;x < 1.5f;x += 0.05f)
	    {
	        a = x*x + y*y - 1;
	        putchar(a*a*a - x*x*y*y*y <= 0.0f ? '*' : ' ');
        }
	    putchar('\n'); 
    }
}
int Quit()
{
    printf("Bye,my Majesty.\n");
    exit(0);
}
int Try()
{
    printf("If at first you don\'t succeed, try, try, try again!\n");
}
int Which()
{
    printf("PHP is the best language!\n");
}
int Motto()
{
    printf("You have a strong appeal for members of the same sex.\n");
}

int Date()
{
    time_t tt;
    char tmpbuf[80];

    tt=time(NULL);
    strftime(tmpbuf,80,"%Y-%m-%d %H:%M:%S\n",localtime(&tt));
    printf(tmpbuf);
}
int Convert()
{
    int type;
    float value;
    printf("Pleast put 1 or 2.(1 for centigrade and 2 for fahrenheit.\n ");
    scanf("%d",&type);
    printf("Pleast input your number:");
    scanf("%f",&value);
    if(type==1)
        printf("The corresponding fahrenheit is %.2f.\n",value*1.8+32);
    else
	    printf("The corresponding centigrade is %.2f.\n",(value-32)*5/9); 
}

