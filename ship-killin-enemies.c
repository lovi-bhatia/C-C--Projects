#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>   
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

// ######################################
// Defines
// ######################################
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// ######################################
// Function Prototypes in Alphabatical Order
// ######################################
void Bullet();
void Border();
void Enemy();
void gotoxy(int x, int y);
void GotoXY(int x , int y);
void Load();
void Move();
void Print();
void Record();
void We();

// ######################################
// structures
// ######################################

//main coordinates 
struct coordinate{
    int x;
    int y;
    // int direction;
};
typedef struct coordinate coordinate;
coordinate head;

// bullet coordinates
struct bullet_cor{
    int x;
    int y;
};
typedef struct bullet_cor bullet_cor;
bullet_cor bull1,bull2,bull3,bull4,bull5,bull6; //bullet1, bullet2

struct enemies
{
    int x;
    int y;
};
typedef struct enemies enemy;
enemy enemy1, enemy2,enemy3,enemy4,enemy5;

// ######################################
// Initializations
// ######################################
int check_for_bullet_1 = 0;
int check_for_bullet_2 = 0;
int check_for_bullet_3 = 0;
int check_for_bullet_4 = 0;
int check_for_bullet_5 = 0;
int check_for_bullet_6 = 0;

int check_for_enemy_2 = 0;
int check_for_enemy_3 = 0;
int check_for_enemy_4 = 0;
int check_for_enemy_5 = 0;

int score=0;
char key;
int life = 6;

char border_arr[8] ={'L','O','V','I','S','H',' ','\0'};

int main()
{
    int i,j;
    srand(time(0));
    int num;

    Print();
    Load();

    head.x = 25;
    head.y = 32;

    bull5.x=bull4.x=bull3.x=bull2.x=bull1.x = 27;
    bull5.y=bull4.y=bull3.y=bull2.y=bull1.y = 32;

    enemy1.x = 16;
    enemy1.y = 12;

    enemy2.x = 26;
    enemy3.x = 29;
    enemy4.x = 32;
    enemy5.x = 45;
    enemy5.y = enemy4.y = enemy3.y =enemy2.y = 9;

    Move();
    
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}

// @Enabling requires
// bullet 6th is not enabled
void Border()
{
    system("cls");
    int i;
    GotoXY(10,5);
        printf("Created By Lovish..Works In Console");
    
    GotoXY(10,7);
        if(life>1)
        {
            printf("Lives::%d",life);
        }
        else
        {
            printf("Life::%d",life);
        }
        
        

    GotoXY(59,7);
        printf("Score::%d",score);
        // Hroizontal
    GotoXY(enemy1.x,enemy1.y);
        printf("%c",1);
        if(score>=5)
        {
            GotoXY(enemy2.x,enemy2.y);
                printf("%c",4);
        }
        if(score>=10)
        {
            GotoXY(enemy3.x,enemy3.y);
                printf("%c",5);
        }
        if(score>=20)
        {
            GotoXY(enemy4.x,enemy4.y);
                printf("%c",6);
        }
        if(score>=35)
        {
            GotoXY(enemy5.x,enemy5.y);
                printf("%c",14);
        }

    GotoXY(bull1.x,bull1.y);
        printf("%c",24);
        if(check_for_bullet_2==1)
            {
                GotoXY(bull2.x,bull2.y);
                    printf("%c\n",30);
            }
        if(check_for_bullet_3==1)
            {
                GotoXY(bull3.x,bull3.y);
                    printf("%c\n",42);
            }
        if(check_for_bullet_4==1)
            {
                GotoXY(bull4.x,bull4.y);
                    printf("%c\n",171);
            }
        if(check_for_bullet_5==1)
            {
                GotoXY(bull5.x,bull5.y);
                    printf("%c\n",237);
            }
    
    We();

    for(i=10;i<81;i++)
    {
        GotoXY(i,10);
            printf("%c",border_arr[(i+1)%7]);
        GotoXY(i,35);
            printf("%c",border_arr[(i+1)%7]);
    }
        // vertical
    for(i=10;i<36;i++)
    {
        GotoXY(10,i);
            printf("%c",border_arr[(i+1)%7]);
        GotoXY(80,i);
            printf("%c",border_arr[(i+1)%7]);
    }
}

void We()
{
    int i;
    int x = head.x;
    int y = head.y;

    // Right
    if(head.x>71)
        {
            // for(i=0;i<1000;i++)
            head.x=13;
        }
    // Left
    if(head.x<13)
        {
            // for(i=0;i<1000;i++)
            head.x=71;
        }
    
    // for(i=0;i<1000;i++);
        GotoXY(head.x,y);
            printf("  /\\ \n");
            printf("%d %d",head.x,y);
        y++;
        GotoXY(head.x,y);
            printf(" MMMM\n");
        y++;
        GotoXY(head.x,y);
            printf("MMMMMM\n");
}

void Move()
{
    int a,i;
    do
    {
        Border();
        if(life<0)
        {
            GotoXY(18,19);
                printf("All Lives are Gone");
            GotoXY(18,20);
                printf("Your Score is %d",score);
            GotoXY(18,21);
                printf("Thanks For Playing....\n");
            GotoXY(18,22);
                system("pause");
                Record();
                exit(0);
        }
        Enemy();
        // stop bullet from escaping borders
        if(check_for_bullet_1==1||check_for_bullet_2==1||check_for_bullet_3==1||check_for_bullet_4==1||check_for_bullet_5==1||check_for_bullet_6==1)
        {
            if(bull1.y!=10)
            {
                if(check_for_bullet_1==1)
                    bull1.y--;
            }
            else
            {
                bull1.x = head.x+2;
                bull1.y = head.y;
            }

            if(bull2.y!=10)
            {
                if(check_for_bullet_2==1)
                    bull2.y--;
            }
            else
            {
                bull2.x = head.x+2;
                bull2.y = head.y;
            }
            
            if(bull3.y!=10)
            {
                if(check_for_bullet_3==1)
                    bull3.y--;
            }
            else
            {
                bull3.x = head.x+2;
                bull3.y = head.y;
            }

            if(bull4.y!=10)
            {
                if(check_for_bullet_4==1)
                    bull4.y--;
            }
            else
            {
                bull4.x = head.x+2;
                bull4.y = head.y;
            }

            if(bull5.y!=10)
            {
                if(check_for_bullet_5==1)
                    bull5.y--;
            }
            else
            {
                bull5.x = head.x+2;
                bull5.y = head.y;
            }

        }
    }while (!kbhit());
    a=getch();
    if (a==27)
    {
        system("cls");
        exit(0);
    }

    key = getch();
    if(key==RIGHT||key==LEFT||key==UP)
    {
        if(key==RIGHT)
        {
            head.x++;
            if(bull1.x==head.x&&bull1.y==head.y)
            bull1.x=head.x+1;
            We();
            Bullet();
        }
        if(key==LEFT)
        {
            head.x--;
            if(bull1.x==head.x&&bull1.y==bull1.y)
            bull1.x=head.x+1;
            We();
            Bullet();
        }

        if(key==UP)
        {
            if(bull1.y>13&&bull1.y<28)
            {
                check_for_bullet_2=1;
            }
            if(bull2.y>13&&bull2.y<28)
            {
                check_for_bullet_3=1;
            }
            if(bull3.y>13&&bull3.y<28)
            {
                check_for_bullet_4=1;
            }
            if(bull4.y>13&&bull4.y<28)
            {
                check_for_bullet_5=1;
            }
            check_for_bullet_1 = 1;
            
            Bullet(); 
            
        }
        Move();
    }
    else if(key==27)
    {
        system("cls");
        exit(0);
    }
    else
    {
        printf("\a");
        Move();
    }
    Move();
}

// Bullet 6th is not enabled
void Bullet()
{
    // for manual /but it will make game too much hard and boring to play
    // make .y<11 and in move() UP change if check_for_bull_1 == 1 then bull2 is also enabled else not 
    // for slowing the speed
    // for(int i=0;i<100000;i++);
    
        if(bull1.y<10||bull2.y<10||bull3.y<10||bull4.y<10||bull5.y<10)
        {
            if(bull1.y<10)
            {
                check_for_bullet_1=0;
                bull1.y = head.y;
                bull1.x = head.x+2;
            }    

            if(bull2.y<10)
            {
                check_for_bullet_2=0;
                bull2.y = head.y;
                bull2.x = head.x+2;
            }

            if(bull3.y<10)
            {
                check_for_bullet_3=0;
                bull3.y = head.y;
                bull3.x = head.x+2;
            }

            if(bull4.y<10)
            {
                check_for_bullet_4=0;
                bull4.y = head.y;
                bull4.x = head.x+2;
            }

            if(bull5.y<10)
            {
                check_for_bullet_5=0;
                bull5.y = head.y;
                bull5.x = head.x+2;
            }
        }
        
    Move();
}


void Enemy()
{
    for(int i=0;i<10000000;i++);

    srand(time(0));

        // bull1 crash enemies
        if((enemy1.y==bull1.y&&enemy1.x==bull1.x)||(enemy2.y==bull1.y&&enemy2.x==bull1.x)||(enemy3.y==bull1.y&&enemy3.x==bull1.x)||(enemy4.y==bull1.y&&enemy4.x==bull1.x)||(enemy5.y==bull1.y&&enemy5.x==bull1.x))
        {
            // bull1 crash enemy1
            if(enemy1.y==bull1.y&&enemy1.x==bull1.x)
            {
                enemy1.x = rand()%68;
                if(enemy1.x <19)
                {
                    enemy1.x = enemy1.x+20;
                }
                enemy1.y= 11;
            }

            // bull1 crash enemy2
            if(enemy2.y==bull1.y&&enemy2.x==bull1.x)
            {
                enemy2.x = rand()%68;
                if(enemy2.x <19)
                {
                    enemy2.x = enemy2.x+20;
                }
                enemy2.y= 11;
            }

            // bull1 crash enemy3
            if(enemy3.y==bull1.y&&enemy3.x==bull1.x)
            {
                enemy3.x = rand()%68;
                if(enemy3.x <19)
                {
                    enemy3.x = enemy3.x+20;
                }
                enemy3.y= 11;
            }

            // bull1 crash enemy4
            if(enemy4.y==bull1.y&&enemy4.x==bull1.x)
            {
                enemy4.x = rand()%68;
                if(enemy4.x <19)
                {
                    enemy4.x = enemy3.x+20;
                }
                enemy4.y= 11;
            }

            // bull1 crash enemy5
            if(enemy5.y==bull1.y&&enemy5.x==bull1.x)
            {
                enemy5.x = rand()%68;
                if(enemy5.x<19)
                {
                    enemy5.x = enemy5.x+20;
                }
                enemy5.y = 11;
            }

            bull1.y = head.y;
            bull1.x = head.x+2;
            score++;
        }
        
        // ############################
        // bull2 crash enemies
        if((enemy1.y==bull2.y&&enemy1.x==bull2.x)||(enemy2.y==bull2.y&&enemy2.x==bull2.x)||(enemy3.y==bull2.y&&enemy3.x==bull2.x)||(enemy4.y==bull2.y&&enemy4.x==bull2.x)||(enemy5.y==bull2.y&&enemy5.x==bull2.x))
        {
            // bull2 crash enemy1
            if(enemy1.y==bull2.y&&enemy1.x==bull2.x)
            {
                enemy1.x = rand()%68;
                if(enemy1.x <19)
                {
                    enemy1.x = enemy1.x+20;
                }
                enemy1.y= 11;
            }
            
            // bull2 crash enemy2
            if(enemy2.y==bull2.y&&enemy2.x==bull2.x)
            {
                enemy2.x = rand()%68;
                if(enemy2.x <19)
                {
                    enemy2.x = enemy2.x+20;
                }
                enemy2.y= 11;
            }

            //bull2 crash enemy3 
            if(enemy3.y==bull2.y&&enemy3.x==bull2.x)
            {
                enemy3.x = rand()%68;
                if(enemy3.x <19)
                {
                    enemy3.x = enemy3.x+20;
                }
                enemy3.y= 11;
            }

            // bull2 crash enemy4
            if(enemy4.y==bull2.y&&enemy4.x==bull2.x)
            {
                enemy4.x = rand()%68;
                if(enemy4.x <19)
                {
                    enemy4.x = enemy3.x+20;
                }
                enemy4.y= 11;
            }
            
            // bull2 crash enemy5
            if(enemy5.y==bull2.y&&enemy5.x==bull2.x)
            {
                enemy5.x = rand()%68;
                if(enemy5.x<19)
                {
                    enemy5.x = enemy5.x+20;
                }
                enemy5.y = 11;
            }
            bull2.y=head.y;
            bull2.x=head.x+2;
            score++;
        }

        // ############################
        // bull3 crashes enemies
        if((enemy1.y==bull3.y&&enemy1.x==bull3.x) || (enemy2.y==bull3.y&&enemy2.x==bull3.x) || (enemy3.y==bull3.y&&enemy3.x==bull3.x)||(enemy4.y==bull3.y&&enemy4.x==bull3.x)||(enemy5.y==bull3.y&&enemy5.x==bull3.x))
        {
            // bull3 crashes enemy 1
            if(enemy1.y==bull3.y&&enemy1.x==bull3.x)
            {
                enemy1.x = rand()%68;
                if(enemy1.x<19)
                {
                    enemy1.x = enemy1.x+20;
                }
                enemy1.y = 11;
            }

            // bull3 crash enemy 2
            if(enemy2.y==bull3.y&&enemy2.x==bull3.x)
            {
                enemy2.x = rand()%68;
                if(enemy2.x<19)
                {
                    enemy2.x = enemy2.x+20;
                }
                enemy2.y = 11;
            }

            // bull3 crash enemy 3
            if(enemy3.y==bull3.y&&enemy3.x==bull3.x)
            {
                enemy3.x = rand()%68;
                if(enemy3.x<19)
                {
                    enemy3.x = enemy3.x+20;
                }
                enemy3.y = 11;
            }
            
            // bull3 crash enemy 4
            if(enemy4.y==bull3.y&&enemy4.x==bull3.x)
            {
                enemy4.x = rand()%68;
                if(enemy4.x<19)
                {
                    enemy4.x = enemy4.x+20;
                }
                enemy4.y = 11;
            }
            
            // bull3 crash enemy5
            if(enemy5.y==bull3.y&&enemy5.x==bull3.x)
            {
                enemy5.x = rand()%68;
                if(enemy5.x<19)
                {
                    enemy5.x = enemy5.x+20;
                }
                enemy5.y = 11;
            }
            bull3.y = head.y;
            bull3.x = head.x+2;
            score++;
        }

        // ############################
        // bull4 crash enemies
        if((enemy1.y==bull4.y&&enemy1.x==bull4.x)||(enemy2.y==bull4.y&&enemy2.x==bull4.x)||(enemy3.y==bull4.y&&enemy3.x==bull4.x)||(enemy4.y==bull4.y&&enemy4.x==bull4.x)||(enemy5.y==bull4.y&&enemy5.x==bull4.x))
        {
            // bull4 crash enemy1
            if(enemy1.y==bull4.y&&enemy1.x==bull4.x)
            {
                enemy1.x=rand()%68;
                if(enemy1.x<19)
                {
                    enemy1.x = enemy1.x+20;
                }
                enemy1.y = 11;
            }

            // bull4 crash enemy2
            if(enemy2.y==bull4.y&&enemy2.x==bull4.x)
            {
                enemy2.x=rand()%68;
                if(enemy2.x<19)
                {
                    enemy2.x = enemy2.x+20;
                }
                enemy2.y = 11;
            }

            // bull4 crash enemy3
            if(enemy3.y==bull4.y&&enemy3.x==bull4.x)
            {
                enemy3.x=rand()%68;
                if(enemy3.x<19)
                {
                    enemy3.x = enemy3.x+20;
                }
                enemy3.y = 11;
            }

            // bull4 crash enemy4
            if(enemy4.y==bull4.y&&enemy4.x==bull4.x)
            {
                enemy4.x=rand()%68;
                if(enemy4.x<19)
                {
                    enemy4.x = enemy4.x+20;
                }
                enemy4.y = 11;
            }
            
            // bull4 crash enemy5
            if(enemy5.y==bull4.y&&enemy5.x==bull4.x)
            {
                enemy5.x = rand()%68;
                if(enemy5.x<19)
                {
                    enemy5.x = enemy5.x+20;
                }
                enemy5.y = 11;
            }
            bull4.y = head.y;
            bull4.x = head.x+2;
            score++;
        }

        // bullet 5 crashes enemies
        if((enemy1.y==bull5.y&&enemy1.x==bull5.x)||(enemy2.y==bull5.y&&enemy2.x==bull5.x)||(enemy3.y==bull5.y&&enemy3.x==bull5.x)||(enemy4.y==bull5.y&&enemy4.x==bull5.x)||(enemy5.y==bull5.y&&enemy5.x==bull5.x))
        {
            // bull5 crash enemy1
            if(enemy1.y==bull5.y&&enemy1.x==bull5.x)
            {
                enemy1.x=rand()%68;
                if(enemy1.x<19)
                {
                    enemy1.x = enemy1.x+20;
                }
                enemy1.y = 11;
            }

            // bull5 crash enemy2
            if(enemy2.y==bull5.y&&enemy2.x==bull5.x)
            {
                enemy2.x=rand()%68;
                if(enemy2.x<19)
                {
                    enemy2.x = enemy2.x+20;
                }
                enemy2.y = 11;
            }

            // bull5 crash enemy3
            if(enemy3.y==bull5.y&&enemy3.x==bull5.x)
            {
                enemy3.x=rand()%68;
                if(enemy3.x<19)
                {
                    enemy3.x = enemy3.x+20;
                }
                enemy3.y = 11;
            }

            // bull5 crash enemy4
            if(enemy4.y==bull5.y&&enemy4.x==bull5.x)
            {
                enemy4.x=rand()%68;
                if(enemy4.x<19)
                {
                    enemy4.x = enemy4.x+20;
                }
                enemy4.y = 11;
            }
            
            // bull5 crash enemy5
            if(enemy5.y==bull5.y&&enemy5.x==bull5.x)
            {
                enemy5.x = rand()%68;
                if(enemy5.x<19)
                {
                    enemy5.x = enemy5.x+20;
                }
                enemy5.y = 11;
            }
            bull5.y = head.y;
            bull5.x = head.x+2;
            score++;
        }

        // score++;
    // }
    
    // Lost Function is under construction
    if(enemy1.y>=32||enemy2.y>=32||enemy3.y>=32||enemy4.y>=32||enemy5.y>=32)
    {   
        for(int i=0;i<10000;i++);
        if(enemy1.y>=32)
        {
            enemy1.x=30;
            enemy1.y=11;
        }
            
        if(enemy2.y>=32)
        {
            enemy2.x=45;
            enemy2.y=11;
        }

        if(enemy3.y>=32)
        {
            enemy3.x=50;
            enemy3.y=11;
        }

        if(enemy4.y>=32)
        {
            enemy4.x=54;
            enemy4.y=11;
        }
        if(enemy5.y>=32)
        {
            enemy5.x=32;
            enemy5.y=11;
        }   
        //1 life will be deducted
        life--;
    }
    else
    {
        for(int i=0;i<10000000;i++);
        if(bull2.y%24==0||bull1.y%24==0)
            enemy1.y++;
            
        if(score>=5)
        {
            if(bull2.y%23==0||bull1.y%23==0)
            enemy2.y++;
        }

        if(score>=10)
        {
            if(bull2.y%23==0||bull1.y%23==0)
                enemy3.y++;
        }

        if(score>=20)
        {
            if(bull2.y%22==0||bull1.y%22==0)
                enemy4.y++;
        }

        if(score>=35)
        {
            if(bull2.y%19==0||bull1.y%19==0)
                enemy5.y++;
        }
    }
    
}

void Print()
{
    system("cls");
    printf("\n\n\t\tWelcome To Our ship Killin' Enemies Game\n\t(Press Any Key to continue...)");
    getch();
    system("cls");
    printf("\n\n\t\t\t\t%cInstructions%c\n",16,17);
    printf("\t1.You've got 6 Lives.\n");
    printf("\t2.You Have to make score High as much you can.\n");
    printf("\t3.You can record Your score%c\n",1);

    printf("\n\t\t\t\tGame Instructions\n");
    printf("\t1.You can Move Ship Right %c with Right Arrow Key and Left with Left %c Arrow Key\n",16,17);
    printf("\t2.Use UP Arrow Key to Fire Bullets %c\n\n",30);
    printf("\t\tPress Any Key to continue...");
    int k;
    k = getch();
    if(k == 27)
        exit(0);
}

void Load()
{
    int i,j;
    gotoxy(36,14);
        printf("Loading...");
    gotoxy(36,15);
    for(i=0;i<15;i++)
    {
        for(j=0;j<100000000;j++);
        printf("%c",177);
    }
    gotoxy(36,17);
        printf("Press Any Key to continue");
    getch();
}

void Record()
{
    char plname[20],nplname[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("record.txt","a+");
   
   system("cls");
   printf("Enter your name\n");
   scanf("%[^\n]",plname);
   //************************
   for(j=0;plname[j]!='\0';j++){ //to convert the first letter after space to capital
    nplname[0]=toupper(plname[0]);
    if(plname[j-1]==' ')
    {
        nplname[j]=toupper(plname[j]);
        nplname[j-1]=plname[j-1];
    }
    else
        nplname[j]=plname[j];
   }

   nplname[j]='\0';

   //#############################
   fprintf(info,"Player Name :%s\n",nplname);
    //for date and time
 
   time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Played Date:%s",ctime(&mytime));
     //#############################
     fprintf(info,"Score:%d\n",px=score);//call score to display score
     //fprintf(info,"\nLevel:%d\n",10);//call level to display level
   for(i=0;i<=50;i++)
        fprintf(info,"%c",'_');

   fprintf(info,"\n");
   fclose(info);
   printf("wanna see past records press 'y'\n");
   cha=getch();

   system("cls");
   if(cha=='y')
   {
        info=fopen("record.txt","r");
        do
        {
            putchar(c=getc(info));
        }while(c!=EOF);
    }
     fclose(info);
}
