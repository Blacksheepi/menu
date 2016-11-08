/*
*Target:A universal menu program
*Author:Dou Yiming
*Date:2016/09/23
*/

/*data struct and its operations*/
typedef struct DataNode
{
    char* cmd;
    char* node;
    int (*handler)();
    struct DataNode *next;
}tDataNode;

/* find a cmd in the linklist and return the point */
tDataNode* FindCmd(tDataNode * head,char * cmd);
/* show all cmd in linklist */
int ShowAllCmd(tDataNode * head);
