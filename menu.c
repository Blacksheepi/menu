/*
*Target:A universal menu program
*Author:Dou Yiming
*Date:2016/09/23
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void Love();
void Help();
void Date();
void Convert();

int main()
{
    char cmd[100];
    printf("My Majesty,very glad to serve you!\nPlease tap your command:");

    while(1)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "help")==0)
	    {
	        Help();
	    }
	    else if(strcmp(cmd, "quit")==0)
	    {
	        printf("Bye,my Majesty.\n");
	        exit(0);
	    }
	    else if(strcmp(cmd, "try")==0)
	    {
	        printf("If at first you don\'t succeed, try, try, try again!\n");
	    }
	    else if(strcmp(cmd, "love")==0)
	    {
	        Love();
	    }
	    else if(strcmp(cmd, "which")==0)
	    {
	        printf("PHP is the best language!\n");
	    }
	    else if(strcmp(cmd, "date")==0)
	    {
	        Date();
	    }
	    else if(strcmp(cmd, "motto")==0)
	    {
	        printf("You have a strong appeal for members of the same sex.\n");
	    }
	    else if(strcmp(cmd, "convert")==0)
	    {
	        Convert();
	    }
	    else
	    {
	        printf("Wrong cmd!\n");
	    }
	    printf("Please tap your next command:");

    }
}
void Love()
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
void Help()
{
    printf("In this program,you can tap:\n1.help\n2.love\n3.which\n4.date\n5.motto\n6.convert\n7.try\n8.quit\n");
}
void Date()
{
    time_t tt;
    char tmpbuf[80];

    tt=time(NULL);
    strftime(tmpbuf,80,"%Y-%m-%d %H:%M:%S\n",localtime(&tt));
    printf(tmpbuf);
}
void Convert()
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
