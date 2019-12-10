//I made this a seperate file so I don't accidentally mess up what we already have
//changes: displays the start of the game and sets up for some of the other functions which will let it loop until it's done
//specific code changed: added displayGame and getCoords functions and set up most of case 1 in the switch

#include <stdio.h>

//maybe a #define or two

//lot of function prototypes here
//int changeDifficulty(int difficulty);
void displayGame(int gameSize, char revealed[][gameSize], char cards[][gameSize]);
void getCoords(int gameSize, int xcoord[], int ycoord[]);
_Bool checkMatch(char **grid, int xcoord[], int ycoord[]);

int main () {
  //declare variables
  int menu, difficulty, gameSize;

  //menu
  do
  {
    printf("***MEMORY!***\n");
    printf("1 - Play Game\n");
    printf("2 - Check Scores\n");
    printf("0 - Exit\n");
    scanf("%d", &menu);

    switch(menu)
    {
	//Play Game
	case 1: printf("Enter difficulty (1, 2, or 3): ");
		scanf("%d", &difficulty);
		
		//the board's temp just a 2x2 until we get the change difficulty function
		gameSize = 2;//changeDifficulty();
		{
		char revealed[gameSize][gameSize], cards[gameSize][gameSize];
		int xcoord[gameSize], ycoord[gameSize];
		
		//char **cards;
		

		//sets all the revealed spots to "false" to start with
		//we can trasfer this to a function if we want
		int i1, i2;
		for (i1 = 0; i1 < gameSize; i1++)
		{
		  for (i2 = 0; i2 < gameSize; i2++)
		  {
		    revealed[i1][i2] = 0;
		    cards[i1][i2] = '!';
		  }
		}
			
		//temp
		int allRevealed = 0;
		
		//game
		do
		{
		  displayGame(gameSize, revealed, cards);
		  
		  getCoords(gameSize, xcoord, ycoord);
		  //checkMatch();
			//if it is a match, set the revealed array at that coord to 1
		  /*int i;
		  if (checkMatch(cards, xcoord, ycoord) == 1)
		  {
		    for(i = 0; i <= 2; i++)
	 	    {
		      revealed[xcoord - 1, ycoord - 1] = 1;
		    }
		  }*/
		  
		} while (allRevealed == 0);
			//allRevealed will be a bool function which will check to see if all the values in the revealed array are 1

		
		}
		break;

	//Check Scores
	case 2: printf("**HIGH SCORES**\n");
		//display top 10 scores
		printf("\n");
		break;

	//Exit
	case 0: break;

	//Other
	default: printf("Please enter a valid menu option.\n\n");
		break;
    }

 
  } while (menu != 0);
  
  
 return 0; 
}

//lot of fuckin function definitions

void displayGame(int gameSize, char revealed[][gameSize], char cards[][gameSize])
{
  int i, rowIndex, colIndex;

  //prints tons of newlines to clear screen
  for (i = 0; i <= 50; i++)
  {
    printf("\n");
  }

  //displays board
  for (rowIndex = 0; rowIndex < gameSize; rowIndex++)
  {
    for (colIndex = 0; colIndex < gameSize; colIndex++)
    {
      if (revealed[rowIndex][colIndex] == 1)
      {
	printf("[%c]", cards[rowIndex][colIndex]);
      }
      else
      {
	printf("[ ]");
      }
    }
    printf("\n");
  }
}

void getCoords(int gameSize, int xcoord[], int ycoord[])
{
  int i;

  for (i = 0; i <= 1; i++)
  {
    printf("Enter your coordinates from 1 to %d\n", gameSize);
    scanf("%d%d", &xcoord[i], &ycoord[i]);

    //makes sure coords are between range
    while (xcoord[i] > gameSize || ycoord[i] > gameSize)
    {
      printf("Please enter valid coordinates between 1 and %d\n", gameSize);
      scanf("%d%d", &xcoord[i], &ycoord[i]);
    }
  }
}

_Bool checkMatch(char **grid, int xcoord[], int ycoord[])
{
  int userCoordinate1 = xcoord[1], userCoordinate2 = ycoord[1], userCoordinate3 = xcoord[2], userCoordinate4 = ycoord[2];
	
   return *(*(grid + userCoordinate1 -1) + userCoordinate2 -1) == *(*(grid + userCoordinate3 -1) + userCoordinate4 -1);
   
}

void selectDifficulty(int difficulty)
{

    int coordinate1, coordinate2, coordinate3, coordinate4;
    int score;
    int gameSize;
    char **grid;
    int i, j;
    score = 0;
    
    //Need to check if the game is over
    while(!allRevealed()==0)
    {
        switch(difficulty)
        {
            case 1:
                //2X2
                gameSize = 2;
                
                
                break;
                
            case 2:
                //4X4
                gameSize = 4;
                
                   
                break;
                
            case 3:
                //6X6
                gameSize = 6;
            
                  
                break;
                
            default:
                printf("Please enter a valid option \n");
        }
        char revealed[gameSize][gameSize], cards[gameSize][gameSize];
        int xcoord[gameSize], ycoord[gameSize];
            
    }
    //change the variable that sets the size of the index
}

