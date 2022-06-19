#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void clrscr(){
    system("CLS");
}

int want_reset,want_exit;

//-----------------------------------FUNCTION DEFINETION SECTION----------
char toss_turn()
{
	int x;
	//randomize();
	x=rand();

	if((x%10)%2==0)
	{
		return('X');
	}
	else
	{
		return('O');
	}
}

void initialize(char matrix[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			matrix[i][j]='-';
		}
	}
}

void print_m(char matrix[3][3])
{
	int i,j;
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c ", matrix[i][j] );
		}
		printf("\n");
	}

}

int input_m(char matrix[3][3],char turn)
{

	char x;
	x=getch();
	if     (x=='7'||x=='q'||x=='Q')
	{
		if(matrix[0][0]=='-')
		{
			matrix[0][0]=turn; return(0);
		}
	}
	else if(x=='8'||x=='w'||x=='W')
	{
		if(matrix[0][1]=='-')
		{
			matrix[0][1]=turn;  return(0);
		}
	}
	else if(x=='9'||x=='e'||x=='E')
	{
		if(matrix[0][2]=='-')
		{
			matrix[0][2]=turn;  return(0);
		}
	}
	else if(x=='4'||x=='a'||x=='A')
	{
		if(matrix[1][0]=='-')
		{
			matrix[1][0]=turn;  return(0);
		}
	}
	else if(x=='5'||x=='s'||x=='S')
	{
		if(matrix[1][1]=='-')
		{
			matrix[1][1]=turn;  return(0);
		}
	}
	else if(x=='6'||x=='d'||x=='D')
	{
		if(matrix[1][2]=='-')
		{
			matrix[1][2]=turn;  return(0);
		}

	}
	else if(x=='1'||x=='z'||x=='Z')
	{
		if(matrix[2][0]=='-')
		{
			matrix[2][0]=turn;  return(0);
		}
	}
	else if(x=='2'||x=='x'||x=='X')
	{
		if(matrix[2][1]=='-')
		{
			matrix[2][1]=turn;  return(0);
		}
	}
	else if(x=='3'||x=='c'||x=='C')
	{
		if(matrix[2][2]=='-')
		{
			matrix[2][2]=turn;  return(0);
		}
	}
	else if(x==' ')
	{
		want_exit=1;
		return(0);
	}

	else if(x=='r'||x=='R')
	{
		want_reset=1;
		return(0);
	}
	else
	{
		printf("\n<invalid input!> try again.. ");
		return(1);
	}
}
int check_m(char matrix[3][3],char turn)
{
	if(matrix[0][0]==turn && matrix[0][1]==turn && matrix[0][2]==turn) return(1);
	else if(matrix[0][0]==turn && matrix[0][1]==turn && matrix[0][2]==turn) return(1);
	else if(matrix[1][0]==turn && matrix[1][1]==turn && matrix[1][2]==turn) return(1);
	else if(matrix[2][0]==turn && matrix[2][1]==turn && matrix[2][2]==turn) return(1);
	else if(matrix[0][0]==turn && matrix[1][0]==turn && matrix[2][0]==turn) return(1);
	else if(matrix[0][1]==turn && matrix[1][1]==turn && matrix[2][1]==turn) return(1);
	else if(matrix[0][2]==turn && matrix[1][2]==turn && matrix[2][2]==turn) return(1);
	else if(matrix[0][0]==turn && matrix[1][1]==turn && matrix[2][2]==turn) return(1);
	else if(matrix[0][2]==turn && matrix[1][1]==turn && matrix[2][0]==turn) return(1);
	else return(0);
}

int main()
{
	char XO[3][3],turn_of,winner[10];
	char Xname[10],Oname[10];
	char temp;
	int SX,SO;
	int game_no,count;
	int winning_shot;


	clrscr();
	//gotoxy(15,4);
	printf("\n\n\n\n ");
	printf("Tic Tac Toe..");
	//gotoxy(13,8);
	printf("\n\n\n\n  ");
	printf("Created by Maulik Raviya..");
	//gotoxy(5,14);
	printf("\n\n\n\n\n\n  ");
	printf("Special thanks to..");
	//gotoxy(11,16);
	printf("\n\n   ");
	printf(" Milap Radia and Sushil Yadav");

	//gotoxy(1,20);
	printf("\n\n\n\n ");

	printf("Press any key to begin..");
	getch();
	clrscr();

	reset:
	want_reset=0;


	printf("Enter the name of player 1 having 'X' .. ");
	scanf("%s",Xname);
	printf("Enter the name of player 2 having 'O' .. ");
	scanf("%s",Oname);


	game_no=0;
	SX=SO=0;
	turn_of=toss_turn();
	want_exit=0;

	while(want_exit==0)   //Staring of game
	{
		game_no++;
		count=0;
		initialize(XO);
		winning_shot=0;
		while(winning_shot==0)
		{

			clrscr();

			printf("Press SPACEBAR to exit..    |\nPress R to reset the game.. |\n----------------------------'\n\n");

			printf("\nGame #%d..\n",game_no);



			count++;

			if(count==10)
			{
				printf("  Draw!!");
				SX++;
				SO++;
				break;
			}

			printf("\nScore: %s => %d     %s => %d\n\n",Xname,SX,Oname,SO);


			printf("\nThe turn of ");
				if(turn_of=='O') printf("%s",Oname);
				else printf("%s",Xname);
				printf("(%c)..\n",turn_of);



			print_m(XO);


			while ( input_m(XO,turn_of) );

			if(want_reset==1)
			{
				clrscr();
				printf("Game reseted.\n\n");
				goto reset;
			}
			if(want_exit==1) goto scorecard;
			winning_shot=check_m(XO,turn_of);

			if(winning_shot==1)
			{
				clrscr();



				if(turn_of=='X')
				{
					SX++;
					printf("\n %s Won this game. \n",Xname);
				}
				else
				{
					SO++;
					printf("\n %s Won this game. \n",Oname);
				}


				print_m(XO);
				printf("\nScore: %s => %d     %s => %d\n\n",Xname,SX,Oname,SO);
			}



			if(turn_of=='X') turn_of='O';
			else turn_of='X';

		}

		printf("\n  Press SPACEBAR to end the game..\n  Press R to reset the game..\n\n\n Press any other key to be countiued..");
		temp=getch();
		if(temp==' ') want_exit=1;
		else if(temp=='r'||temp=='R')
		{
			clrscr();
			printf("Gmae reseted.");
			goto reset;
		}
	}//end of game loop and user want to exit

	scorecard:
	clrscr();
	if(SX<SO)
	{
		//gotoxy(15,10);
		printf("\n\n\n\n\n\n\n\n\n\n               ");
		printf("%s is Winner!! Congrats.. ",Oname);
		//gotoxy(13,12);
		printf("\n\n                 ");
		printf("Won %d out of %d games (%.2f percent)",SO,game_no,(( (float)SO/game_no )*100.00));
	}
	else if(SX>SO)
	{
		//gotoxy(15,10);
		printf("\n\n\n\n\n\n\n\n\n\n               ");
		printf("%s is Winner!! Congrats.. ",Xname);
		//gotoxy(13,12);
		printf("\n\n                 ");
		printf("Won %d out of %d games (%.2f percent)",SX,game_no,(( (float)SX/game_no )*100.00));
	}
	else
	{
		//gotoxy(15,10);
		printf("\n\n\n\n\n\n\n\n\n\n               ");
		printf("%s and %s both are winner  ",Xname,Oname);
	}


	//gotoxy(5,17);
	printf("\n\n\n\n\n\n\n     ");
	printf("Press R to play again");
	//gotoxy(5,18);
	printf("\n     ");
	printf("Press any other key to exit..");

	temp=getch();


	if(temp=='r'||temp=='R')
	{
		clrscr();
		printf("Welcome back.\n");
		goto reset;
	}
	clrscr();
	//gotoxy(5,17);
	printf("\n\n\n\n\n\n\n     ");
	printf("Thank you. Do come again ");

	printf("\n\n\n\n    A game by Maulik Raviya..");
	getch();
	return 0;
}

