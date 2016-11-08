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
#include"menu.h"
tLinkTable *head = NULL;
int Help(int argc,char **argv);

#define CMD_MAX_LEN 128
#define NOTE_LEN 1024
#define CMD_NUM 10
#define CMD_MAX_ARGV_NUM 32
/*data struct and its operations*/
typedef struct DataNode
{
    tLinkTableNode *pNext;
    char* cmd;
    char* node;
    int (*handler)(int argc,char **argv);
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

int MenuConfig(char *cmd, char *desc, int (*handler)(int argc, char **argv))
{
    tDataNode *pNode = NULL;
    if(head == NULL)
    {
        head = CreateLinkTable();
        pNode = (tDataNode*)malloc(sizeof(tDataNode));
        pNode->cmd = "help";
        pNode->node = "Menu List:";
        pNode->handler = Help;
        AddLinkTableNode(head, (tLinkTableNode*)pNode);
    }
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->node = desc;
    pNode->handler = handler;
    AddLinkTableNode(head, (tLinkTableNode*)pNode);
    return 0;
}
int ExcuteMenu()
{
    /* cmd line Begin */
    while(1)
    {
        int argc = 0;
        char *argv[CMD_MAX_ARGV_NUM];
        char cmd[CMD_MAX_LEN];
        char *pcmd = NULL;
        /* Input cmd */
        printf("Input a cmd: ");
        pcmd = fgets(cmd, CMD_MAX_LEN, stdin);
        if(pcmd == NULL)
        {
            continue;
        }
/* convert cmd to argc and argv  */
        pcmd = strtok(pcmd, " ");
        while(pcmd != NULL && argc < CMD_MAX_ARGV_NUM)
        {
            argv[argc] = pcmd;
            ++argc;
            pcmd = strtok(NULL, " ");
        }  
        if(argc == 1)
        {
            int len = strlen(argv[0]);
            *(argv[0] + len -1) = '\0';
        }
        tDataNode *p = FindCmd(head, argv[0]);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n");
            continue;
        }
        printf("%s\n", p->node);
        if(p->handler != NULL)
        {
            p->handler(argc, argv);
        }
    }
}
int Help(int argc, char **argv)
{
    printf("--------------------------------------------------------\n");
    ShowAllCmd(head);
    printf("--------------------------------------------------------\n");
    return 0;
}
