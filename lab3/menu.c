/*
*Target:A universal menu program
*Author:Dou Yiming
*Date:2016/09/23
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"linklist.h"

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

/* menu program */

static tDataNode head[] =
{
    {"help","this is help cmd!",Help,&head[1]},
    {"quit","exit the menu.",Quit,&head[2]},
    {"love","show a heart.",Love,&head[3]},
    {"which","the best language.",Which,&head[4]},
    {"try","how should you do when you failed.",Try,&head[5]},
    {"motto","a motto",Motto,&head[6]},
    {"date","show current time",Date,&head[7]},
    {"convert","convert between centigrade and fahrenheit",Convert,NULL }
};

int main()
{
    /* cmd line begins */
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
