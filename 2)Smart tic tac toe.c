#include<stdio.h>
int playerTurn(int *g,int position,char symbol);
int IsplayerWin(int*,char );
int chance,prevPosition;
int main()
{
    //Loop for playing again
    while(1)
    {
        system("cls");
        switch(menu())
        {
        case 1:
            smartComputer();
            chance=1;
            prevPosition=0;
            break;
        case 2:
            evilComputer();
            chance=1;
            prevPosition=0;
            break;
        case 3:
            playWithplayer();
            break;
        case 4:
            //exit(0);
        default:
            printf("##Invalid choice");
        }
    }
    getch();
    return 0;
}

//menu for players
int menu()
{

    int choice;
    printf("Enter your choice\n");
    printf("\n1.Want to play with Smart Computer");
    printf("\n2.Want to play with Evil Computer");
    printf("\n3.Want to play with player");
    printf("\n4.Exit\n");
    scanf("%d",&choice);
    return choice;
}
void evilComputer()
{

     int game[3][3]={1,2,3,4,5,6,7,8,9},mark;
     char playerName[20];
     system("cls");
     system("COLOR 2");

     //taking player name
     printf("\nEnter player name:");
     scanf("%s",playerName);
     while(1)
     {
         //clearing screen
         system("cls");

         //printing format of game and updated game
         printGameFormat(game);

         printf("%s , player 1, Enter Marking place...",playerName);
         scanf("%d",&mark);

         //player's turn  in the game
         if(playerTurn(game,mark,'X')==0)
               continue;


         //Smart computer's turn in the game
         if(chance<=2){
            //taking input by smart computer
            smartComputerTurn(game,mark);
         }
         else
         {
             smartComputerTurn(game,mark);

             //taking input by evil computer
             evilComputerTurn(game);

             //checking evil computer win or not
             if(IsplayerWin(game,'O')==2){
                 system("cls");
                 printGameFormat(game);
                 printf("you lose");
                 getch();
                 return;
             }
             //checking is draw or not
             if(Isdraw(game))
             {
                 system("cls");
                 printGameFormat(game);
                 printf("match draw!!");
                 getch();
                 return;
             }
         }

     }
}
int Isdraw(int *d)
{

    int i;
    for(i=0;i<9;i++)
    {
        if(d[i]!='X' && d[i]!='O')
        {
            return 0;
        }
    }
    return 1;
}
void evilComputerTurn(int *game)
{

    //checking row wise
    for(int i=0;i<9;i+=3)
    {
        if(game[i]=='X' && game[i+1]=='X')
        {
            game[i+2]='O';
        }
        else if(game[i]=='X' && game[i+2]=='X')
        {
            game[i+1]='O';
        }
        else if(game[i+1]=='X' && game[i+2]=='X')
        {
            game[i]='O';
        }
    }
    //checking column wise
    for(int i=0;i<3;i++)
    {
        if(game[i]=='X' && game[i+3]=='X')
        {
            game[i+6]='O';
        }
        else if(game[i]=='X' && game[i+6]=='X')
        {
            game[i+3]='O';
        }
        else if(game[i+3]=='X' && game[i+6]=='X')
        {
            game[i]='O';
        }
    }
    //checking first diagnal
    if(game[0]=='X' && game[4]=='X')
    {
         game[8]='O';
    }
    else if(game[0]=='X' && game[8]=='X')
    {
        game[4]='O';
    }
    else if(game[4]=='X' && game[8]=='X')
    {
        game[0]='O';
    }
    //checking second diagnal
    if(game[2]=='X' && game[4]=='X')
    {
        game[6]='O';
    }
    else if(game[2]=='X' && game[6]=='X')
    {
        game[4]='O';
    }
    else if(game[4]=='X' && game[6]=='X')
    {
        game[2]='O';
    }

}
void playWithplayer()
{

    system("cls");
    system("COLOR 6");
    int game[3][3]={1,2,3,4,5,6,7,8,9},mark,c,round=0;
    char FirstplayerName[20],secondPlayerName[20];

    //Taking first player name
    printf("Enter the first player name:");
    scanf("%s",FirstplayerName);

    //Taking second player name
    printf("\n\nEnter the second player name:");
    scanf("%s",secondPlayerName);
    while(1)
    {
        e:
        system("cls");

        //printing format of game and updated game
        printGameFormat(game);
        if(round>2)
        {
            if(IsplayerWin(game,'O')==2)
            {
               printf("congratulation %s you win",secondPlayerName);
               getch();
               return;
            }
        }

        //first player turn
        printf("%s, Enter marking place...",FirstplayerName);
        scanf("%d",&mark);
        if(playerTurn(game,mark,'X')==0)
        {
            goto e;
        }
        d:
        system("cls");
        //printing format of game and updated game
        printGameFormat(game);
        if(round>=1)
        {
           if(IsplayerWin(game,'X')==2)
           {
              printf("congratulation %s you win",FirstplayerName);
              getch();
              return;
           }
        }
         if(round==4)
         {
             printf("\n match draw");
             getch();
             return;
         }
        //second player turn
        printf("%s, Enter marking place...",secondPlayerName);
        scanf("%d",&mark);
        if(playerTurn(game,mark,'O')==0)
        {
            goto d;
        }
       round++;
    }
}
void smartComputer()
{

    system("cls");
    system("COLOR 3");
    int game[3][3]={1,2,3,4,5,6,7,8,9},mark,c;
    char playerName[20];

    //taking player name
    printf("Enter your name...");
    scanf("%s",playerName);
    while(1)
    {

       //clearing screen
       system("cls");

       //printing format of game and updated game
       printGameFormat(game);

       printf("%s , player 1, Enter Marking place...",playerName);
       scanf("%d",&mark);

       //player's turn  in the game
       if(playerTurn(game,mark,'X')==0)
              continue;

       //Smart computer's turn in the game
       c=smartComputerTurn(game,mark);
       if(c==1)
       {
           system("cls");
           printGameFormat(game);
           printf("you lose, better luck next time...");
           getch();
           return;
       }
       else if(c==2)
       {
           system("cls");
           printGameFormat(game);
           printf("congratulation, you win");
           getch();
           return;
       }
       else if(c==3)
       {
           system("cls");
           printGameFormat(game);
           printf("match draw");
           getch();
           return;
       }

    }
}
void printGameFormat(int Game[][3])
{

    printf("\n\n\n############################# Tic Tac Toe #############################\n\n");
    printf("First player X\n");
    printf("Second player O\n\n");

    for(int i=0;i<3;i++)
    {
        printf("     |     |     |\n");
        for(int j=0;j<3;j++)
        {
            if(Game[i][j]!='X' && Game[i][j]!='O')
            {
                printf("  %d  |",Game[i][j]);
            }
            else
            {
                printf("  %c  |",Game[i][j]);
            }
        }
        printf("\n");
        for(int b=0;b<3;b++)
        {
            printf("_____|");
        }
        printf("\n");
    }
    printf("\n\n\n########################################################################\n\n");
}
int playerTurn(int *g,int position,char symbol)
{
    if(position<0 || position>10)
    {
        printf("\n##Invalid number");
        getch();
        return 0;
    }
    else if(g[position-1]!='X' && g[position-1]!='O')
    {
            g[position-1]=symbol;
            return 1;
    }
    else
    {
        printf("\n##Invalid number");
        getch();
        return 0;
    }
}

int smartComputerTurn(int *game,int position)
{
    int i;
    if(chance==1){
        //checking player's first mark position
        if(position==1 || position==4 ||position==7)
        {
            game[position]='O';
        }
        else if(position==2 ||position==5 ||position==8)
        {
            game[position==2?0:position==5?position:6]='O';

        }
        else{
            game[position==3?5:position==6?2:7]='O';
        }
        prevPosition=position;

    }//checking player's second position
    else if(chance==2){
            if(prevPosition==1 || prevPosition==4 || prevPosition==7)
            {
                    if(prevPosition==1 && (position==4 || position==7 || position==5 || position==8))
                    {
                       game[position==5||position==8?8:position==4?6:3]='O';
                    }
                    else if(prevPosition==4 && (position==1 || position==7 || position==2 || position==8))
                    {
                        game[position==2?position:position==8?8:position==1?6:0]='O';

                    }
                    else if(prevPosition==7 && (position==1 || position==4 || position==5 || position==2))
                    {
                        game[position==5 || position==2?2:position==1?3:0]='O';

                    }else if(prevPosition==1 || prevPosition==4 || prevPosition==7){
                          if(prevPosition==1 &&(position==3 || position==6 || position==9))
                          {
                              game[position==3?5:position==6?2:4]='O';
                          }
                          else if(prevPosition==4 && (position==3 || position==6 || position==9))
                          {
                              game[position==3?1:7]='O';

                          }
                          else if(prevPosition==7 && (position==3 || position==6 || position==9))
                          {
                                   game[4]='O';
                          }
                    }
            }
            else if(prevPosition==2 || prevPosition==5 || prevPosition==8)
            {
               if(prevPosition==2 && (position==5 || position==8 || position==4 || position==7))
               {
                   game[position==4||position==7||position==8?4:7]='O';

               }
               else if(prevPosition==5 && (position==2 || position==8 || position==1 || position==4 || position==7))
               {
                   game[position==1?8:position==2?8:position==4?2:position==7||position==8?2:2]='O';
               }
               else if(prevPosition==8 && (position==1 || position==2 || position==4 || position==5))
               {
                   game[position==1 || position==2 || position==4?4:position==5?1:1]='O';
               }
               else if(prevPosition==2 || prevPosition==5 || prevPosition==8)
               {
                   if(prevPosition==2)
                   {
                       game[position==3?8:position==6?2:5]='O';
                   }
                   else if(prevPosition==5)
                   {
                        game[position==3?6:0]='O';
                   }
                   else{
                      game[position==3?1:position==6?8:5]='O';
                   }
               }
            }
            else if(prevPosition==3 || prevPosition==6 || prevPosition==9)
            {
                 if(prevPosition==3 && (position==2 ||position==5 || position==8 || position==9))
                 {
                     game[position==2||position==8?4:position==9?7:6]='O';

                 }
                 else if(prevPosition==6 && (position==2 || position==5 || position==8 || position==9))
                 {
                     game[position==2||position==8||position==9?4:3]='O';

                 }
                 else if(prevPosition==9 && (position==2 || position==3 || position==5 || position==6))
                 {
                     game[position==2?4:position==5?0:position==3?5:2]='O';

                 }
                 else if(prevPosition==3 || prevPosition==6 || prevPosition==9)
                 {
                     if(prevPosition==3)
                     {
                         game[position==1?1:position==4?0:4]='O';

                     }
                     else if(prevPosition==6)
                     {
                         game[position==1||position==4?4:3]='O';

                     }
                     else if(prevPosition==9)
                     {
                         game[position==1||position==7?4:0]='O';
                     }
                 }
            }

    }
    else{ //player after second position
          //checking is player win or not
          //-1 position number indicate that it is working for evil computer
          if(position!=-1)
          if(chance>3)
          {
              int i;
             //if it return 0 so player is not win yet
             //if it return 2 so player is win
             i=IsplayerWin(game,'X');
             if(i==0)
                goto xz;
             else
                return i;
          }
          //checking game row wise
          for(i=0;i<9;i+=3)
          {
             if(game[i]=='O' && game[i+1]=='O')
             {
                 if(game[i+2]!='X'){
                 game[i+2]='O';
                 return 1;
                 }
                 else if(position==-1)
                    return position;
                 else
                    goto xz;
             }
             else if(game[i]=='O' && game[i+2]=='O')
             {
                 if(game[i+1]!='X'){
                 game[i+1]='O';
                 return 1;
                 }
                 else if(position==-1)
                    return position;
                 else
                   goto xz;
             }
             else if(game[i+1]=='O' && game[i+2]=='O')
             {
                 if(game[i]!='X'){
                 game[i]='O';
                 return 1;
                 }
                 else if(position==-1)
                    return position;
                 else
                    goto xz;
             }
          }

          //checking game column wise
          for(i=0;i<3;i++)
          {
             if(game[i]=='O' && game[i+3]=='O')
             {
                 if(game[i+6]!='X'){
                   game[i+6]='O';
                   return 1;
                 }
                 else if(position==-1)
                    return position;
                else
                    goto xz;
             }
             else if(game[i]=='O' && game[i+6]=='O')
             {
                 if(game[i+3]!='X'){
                 game[i+3]='O';
                 return 1;
                 }
                 else if(position==-1)
                    return position;
                 else
                    goto xz;
             }
             else if(game[i+3]=='O' && game[i+6]=='O')
             {
                 if(game[i]!='X'){
                 game[i]='O';
                 return 1;
                 }
                 else if(position==-1)
                    return position;
                 else
                   goto xz;
             }
          }

          //checking game first diagnal
          if(game[0]=='O' && game[4]=='O')
          {
              if(game[8]!='X'){
              game[8]='O';
              return 1;
              }
              else if(position==-1)
                    return position;
              else
                   goto xz;
          }
          else  if(game[0]=='O' && game[8]=='O')
          {
              if(game[4]!='X'){
              game[4]='O';
              return 1;
              }
              else if(position==-1)
                    return position;
              else
                   goto xz;
          }
          else if(game[4]=='O' && game[8]=='O')
          {
              if(game[0]!='X'){
              game[0]='O';
              return 1;
              }
              else if(position==-1)
                    return position;
              else
                  goto xz;
          }


          //checking game second diagnal
          if(game[2]=='O' && game[4]=='O')
          {
              if(game[6]!='X'){
              game[6]='O';
              return 1;
              }
              else if(position==-1)
                    return position;
              else
                   goto xz;
          }
          else if(game[4]=='O' && game[6]=='O')
          {
              if(game[2]!='X'){
              game[2]='O';
              return 1;
              }
              else if(position==-1)
                    return position;
              else
                  goto xz;
          }
          else if(game[2]=='O'&& game[6]=='O')
          {
              if(game[4]!='X'){
              game[4]='O';
              return 1;
              }
             else if(position==-1)
                    return position;
             else
                goto xz;
          }
       //checking for empty place to smart computer
       xz:

       for(i=0;i<9;i++)
       {
           if(game[i]!='O' && game[i]!='X')
           {
                 game[i]='O';
                 break;
           }
       }
       //checking game is draw or not
       if(i==9)
        return 3;
    }
    chance++;
    return 0;
}

int IsplayerWin(int *g,char symbol)
{
    //checking row wise
    for(int i=0;i<9;i+=3)
    {
        if(g[i]==symbol && g[i+1]==symbol && g[i+2]==symbol)
        {
            return 2;
        }
    }
    //checking for column wise
    for(int i=0;i<3;i++)
    {
        if(g[i]==symbol && g[i+3]==symbol && g[i+6]==symbol)
        {
            return 2;
        }
    }

    //checking first diagnal
    if(g[0]==symbol && g[4]==symbol && g[8]==symbol)
    {
        return 2;
    }
    else if(g[2]==symbol && g[4]==symbol &&g[6]==symbol)
    {
        return 2;
    }
    return 0;
}
