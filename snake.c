#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int t=10000000;//t of play in seconds
int speed=20;//speed of snake(1 to 100 is prefereble).
int cw=82,ch=22;//canvas size
char can[22][82];//canvas array
int tailx[1804]={0},taily[1804]={0},tails=0;//tail coordinates and number of tails
int dir=1,x=1,y=1;//position and direction
int fx=0,fy=0;//food positions
char c,o,l;//key pressed
int score=0;
//*************clear canvas**********************
void clr()
{
for(int i=0;i<ch;i++)
{for(int j=0;j<cw;j++)
	{if(i==0||j==0||i==ch-1||j==cw-1)
		can[i][j]='+';
	else
		can[i][j]=' ';
}}
}
//************display canvas**********************
void disp()
{system("CLS");
printf("Press x to exit...!                                                      Score = %d\n",score);
for(int i=0;i<ch;i++)
{for(int j=0;j<cw;j++)
 putchar(can[i][j]);
 printf("\n");
}
}
//*************food generation****************************
void food()
{int ftx,fty,ic=0;
 a:
 ic=0;ftx=time(NULL)%(cw-1);fty=time(NULL)%(ch-1);
 for(int e=0;e<tails;e++)
 {if(tailx[e]==ftx&&taily[e]==fty)ic=1;}
 if(ic==0&&ftx!=0&&ftx!=cw-1&&fty!=0&&fty!=ch-1&&ftx<cw-1&&fty<ch-1){fx=ftx;fy=fty;}
 else goto a;
}
//*************MAIN*******************************************************************************************************
void main()
{//*************************Main Menu*********************************************
	ma:
clr();
strcpy(can[5],"+                                Welcome To Snake Game");
strcpy(can[6],"+                                +++++++++v1.0++++++++");
strcpy(can[9],"+                                Press any Key to Start");
strcpy(can[11],"+                                Press o for Options");
strcpy(can[13],"+                                Press x for Exit");
strcpy(can[17],"+                                $$$$Created By Xidhu$$$$");
strcpy(can[19],"+                                Copyrighted By 2019 Nixin");
disp();
o=getch();
if(o=='o'){goto op;}
if(o=='x'){goto ex;}
//***************************************************************
int game=1;
food();//food initialising
for(int i=0;i<t*speed;i++)
{
 clr();
//*******************Game Over********************************
for(int u=1;u<tails;u++)
{
 if(tailx[u]==x&&taily[u]==y)
    game=0;	 
}
if(game==0)
{goto ex;}

//*************************************************************
//***********************FOOD****************************************************
   can[fy][fx]='0';//food dropping
   if(x==fx&&y==fy)//food picking
   {food();tails++;score+=speed*10;}
 //****************Key Press******************************
   if(kbhit())
   {
   c=getch();
   if(c==77&&dir!=2)dir=1;//right
   if(c==75&&dir!=1)dir=2;//left
   if(c==72&&dir!=4)dir=3;//up
   if(c==80&&dir!=3)dir=4;//down
   if(c=='x')goto ex;//exit
   }
 //****************MOVE*****************************************
 if(dir==1){can[y][x]=' ';++x;can[y][x]='*';}
 if(dir==2){can[y][x]=' ';--x;can[y][x]='*';}
 if(dir==3){can[y][x]=' ';--y;can[y][x]='*';}
 if(dir==4){can[y][x]=' ';++y;can[y][x]='*';}
 //******************Tail Generation****************************
 if(i!=0)
 {
 for(int t=tails;t>0;t--)
 {
   tailx[t]=tailx[t-1];
   taily[t]=taily[t-1];
    	
 }
 tailx[0]=x;taily[0]=y;
    for(int t=0;t<=tails;t++)
   {
	can[taily[t]][tailx[t]]='*';   
   }
   
 }else tailx[0]=x;taily[0]=y;
 //**************************************************************
 //******************Boundary Conditions*************************
 if(x==cw-1&&dir==1)//right boundary crossing
 {can[y][x]='+';
  can[y][1]='*';
  x=0;
 }

 if(x==0&&dir==2)//left boundary crossing
 {can[y][x]='+';
  can[y][80]='*';
  x=cw-1;
 }
 if(y==0&&dir==3)//up boundary crossing
 {can[y][x]='+';
  can[ch-2][x]='*';
  y=ch-1;
 }
 if(y==ch-1&&dir==4)//down boundary crossing
 {can[y][x]='+';
  can[1][x]='*';
  y=0;
 }
 if(x==0&&(dir==3||dir==4))x++;//moving through left boundary 
 if(x==cw-1&&(dir==3||dir==4))x--;//moving through right boundary
 if(y==0&&(dir==1||dir==2))y++;//moving through up boundary
 if(y==ch-1&&(dir==1||dir==2))y--;//moving through down boundary
 //***************************************************************
 
disp();//display canvas
 for(int j=0;j<580000000/speed;j++);//speed adjust
//************************************************************************************************************************
}
//*********************************************Options Menu*****************************
op:
clr();
strcpy(can[5],"+                                       Options");
strcpy(can[6],"+                                +++++++++++++++++++++");
strcpy(can[9],"+                                Press s for change Speed");
strcpy(can[13],"+                                Press m for Main Menu");
strcpy(can[17],"+                                $$$$Created By Xidhu$$$$");
strcpy(can[19],"+                                Copyrighted By 2019 Nixin");
disp();
l=getch();
if(l=='s')
{
q:
clr();
strcpy(can[5],"+                                 Speed Of Snake");
strcpy(can[6],"+                              +++++++++++++++++++++");
strcpy(can[9],"+                        Input the Speed(1 to 100 is preferable):");
disp();
scanf("%d",&speed);if(speed<1||speed>100){goto q;};
goto op;}
else if(l=='m')
goto ma;
//******************EXIT****************************************************************
ex:clr();
strcpy(can[10],"+                                 GAME OVER............!");
strcpy(can[16],"+                                 Press Any key to Exit..!");
disp();
printf("Score = %d",score);
getch();
}
