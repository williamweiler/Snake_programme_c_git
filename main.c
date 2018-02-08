#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define POMME "@"
typedef struct POMMEPOS
{
  int X;
  int Y;
}POMMEPOS;
void relancepomme(int,int,POMMEPOS,int,int);
void maps(int,int);
void gotoxy(int,int);
void createPomme(POMMEPOS,int,int);
int testpomme(int,int,POMMEPOS);
int testcollision(int,int,int,int,POMMEPOS);
void positionpomme();
//void afficherMap(int tailleX, int tailleY, char map[][tailleX]);

//void rand_pomme(int*,int*);
//void position_pomme(int*,int*,int*,int*,char*);
//void long_snake(char*,char *,char *);

int main()
{
//char map[MAXMAP][MAXMAP];
POMMEPOS pommexy;
int test=0;
int i,j;
int direction = 2;//direction droite initialiser
int x;
int y;
int mouvpommex,mouvpommey;
char perso='$';

int testcolli=0;
int score=0;
x=5;
y=5;
mouvpommex=5;
mouvpommey=3;
    printf("utiliser Espace pour quitter le jeu\n");
    printf("utiliser les TOUCHES DIRECTIONELLE pour vous dirigez vers le HAUT le BAS la GAUCHE et la DROITE\n");
    printf("La partie va commencer tenez vous pret(e)");
    Sleep(3000);
    system("cls");


    do{//boucle de jeu


        if (GetAsyncKeyState(VK_LEFT))// initialisation direction gauche
        {
            direction=1;

        }
        else if (GetAsyncKeyState(VK_RIGHT))//initilisation direction droite
        {
            direction=2;

        }
        else if (GetAsyncKeyState(VK_UP))//initilisation direction haut
        {
            direction=3;
        }

        else if(GetAsyncKeyState(VK_DOWN))//initialisation direction bas
        {
            direction=4;
        }

        switch (direction){
            //direction gauche
            case 1:
                x--;
                system("cls");
            break;
            //direction droite
            case 2:
                x++;
                system("cls");
            break;
            //direction haut
            case 3:
                y--;
                system("cls");
            break;
            //direction bas
            case 4:
                y++;
                system("cls");
            break;}
            if (direction==1 || direction==2|| direction==3||direction==4){
            }
    gotoxy(1,1);
    printf(" SCORE : %i",score);//affichage score
    maps(i,j);//affichage map
    gotoxy(x,y);
    printf("%c",perso);//placement perso position de base
    createPomme(pommexy,x,y);
    relancepomme(test,score,pommexy,x,y);
    }

    while((GetAsyncKeyState(VK_SPACE)==0));
    // espace
    system("pause");
    return 0;
}

void gotoxy(int x,int y)
{
        HANDLE fenetreConsole;  //on déclare une variable de type fenetre
        COORD positionCurseur; //on déclare une variable de type coordonné

        positionCurseur.X = x;
        positionCurseur.Y = y;

        fenetreConsole = GetStdHandle(STD_OUTPUT_HANDLE);//on affecte la fenetre actuel

        SetConsoleCursorPosition(fenetreConsole,positionCurseur);      //affecte le curseur par rapport à la fenetre et la position donné en parametre
}

void createPomme(POMMEPOS pommexy,int x,int y)//creation aleatoire pomme
{

    srand(time(NULL));
    pommexy.X=rand() % 20;
    pommexy.Y=rand() % 20;

    gotoxy(pommexy.X,pommexy.Y);
    printf("%c",POMME);


}
void relancepomme(int test,int score,POMMEPOS pommexy,int x,int y)
{
do{
    test=1;
    Sleep(100);
    if (test==1);{
    test=testpomme(x,y,pommexy);
    if (test==testpomme);
    score=score+1;
    if (score==score+1);
    }}
     while ((x==pommexy.X)&&(y==pommexy.Y));
}

int testpomme(int x,int y,POMMEPOS pommexy)
{
    return ((x==pommexy.X)&&(y==pommexy.Y));
}


void maps(int i,int j)//boucle creation de maps
{


   for(i=2;i<71;i++)
   {
       gotoxy(i,2);
           printf("!");
       gotoxy(i,30);
           printf("!");
   }
   for(j=2;j<31;j++)
   {
       gotoxy(2,j);
           printf("!");
       gotoxy(70,j);
       printf("!");
    }

}
int testcollision(int i,int j,int x,int y,POMMEPOS pommexy){

  return (i==x)&&(j==y);

}


