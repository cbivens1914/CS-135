//CS135.1002
//NetIds: ajara, ssrinivasan
//Purpose: A simplified game of memory

#include <stdio.h>

//maybe a #define or two

//lot of function prototypes here
//int changeDifficulty(int difficulty);
void displayGame(int gameSize, int revealed[][gameSize], char cards[][gameSize]);
void getCoords(int gameSize, int *xcoord, int *ycoord);
_Bool checkMatch(int gameSize, char cards[][gameSize], int xcoord[], int ycoord[]);
_Bool allRevealed(int gameSize, int revealed[][gameSize]);
int selectDifficulty(int difficulty, int allRevealed, int gameSize);

int main () {
  //declare variables
  int menu, difficulty, gameSize, xcoord, ycoord, i, i1, i2;
  _Bool isAllRevealed = 0;

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
		{

		//the board's temp just a 2x2 until we get the change difficulty function
		gameSize = selectDifficulty(difficulty, isAllRevealed, gameSize);
		
		char cards[gameSize][gameSize];
       		int revealed[gameSize][gameSize], xcoords[gameSize], ycoords[gameSize];
		//char **cards;
		

		//sets all the revealed spots to "false" to start with
		//we can trasfer this to a function if we want
		int i1, i2;
		for (i1 = 0; i1 < gameSize; i1++)
		{
		  for (i2 = 0; i2 < gameSize; i2++)
		  {
		    revealed[i1][i2] = 0;

		    //temp sets all cards to ! for testing
		    cards[i1][i2] = 'x';
		  }
		}	
		
		
		//game
		do
		{
		  displayGame(gameSize, revealed, cards);
		  
		  for (i = 0; i < 2; i++)
		  {
		    getCoords(gameSize, &xcoord, &ycoord);
		    xcoords[i] = xcoord - 1;
		    ycoords[i] = ycoord - 1;
		  }

		  //display coords (test)
		for (i = 0; i < gameSize; i++)
		{
		  printf("xcoord%d: %d ycoord%d: %d\n", i + 1, i + 1, xcoords[i], ycoords[i]);
		}

		  
			
		  //checks if its a match and displays the appropriate response
//parts of this section repeat, should we turn it into a function?
		  if (checkMatch(gameSize, cards, xcoords, ycoords) == 1)
		  {

		    for(i = 0; i < 2; i++)
	 	    {
		      revealed[xcoords[i]][ycoords[i]] = 1;
		    }

		    //prints tons of newlines to clear screen
  		    for (i = 0; i <= 50; i++)
 		    {
  		      printf("\n");
 		    }

		    displayGame(gameSize, revealed, cards);
		    printf("MATCHED!\n");
		  }
		  else
		  {
		    for(i = 0; i < 2; i++)
	 	    {
		      revealed[xcoords[i]][ycoords[i]] = 1;
		    }

		    //prints tons of newlines to clear screen
  		    for (i = 0; i <= 50; i++)
 		    {
  		      printf("\n");
 		    }

		    displayGame(gameSize, revealed, cards);

		    for(i = 0; i < 2; i++)
	 	    {
		      revealed[xcoords[i]][ycoords[i]] = 0;
		    }
		  }
		
		//checks to see if all cards have been revealed 
		isAllRevealed = allRevealed(gameSize, revealed);
		  
		} while (isAllRevealed == 0);

		//after game is done
		int tempScore = 0;
		displayGame(gameSize, revealed, cards);
		printf("YOU WON!!!\n");
		printf("%d points!\n", tempScore);
		printf("Save Score? 1 - yes: \n");
		
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

void displayGame(int gameSize, int revealed[][gameSize], char cards[][gameSize])
{
  int rowIndex, colIndex;

  printf("\n");

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

void getCoords(int gameSize, int *xcoord, int *ycoord)
{
    printf("Enter your coordinates from 1 to %d\n", gameSize);
    scanf("%d%d", xcoord, ycoord);

    //makes sure coords are between range
    while (*xcoord > gameSize || *ycoord > gameSize)
    {
      printf("Please enter valid coordinates between 1 and %d\n", gameSize);
      scanf("%d%d", xcoord, ycoord);
    }
}

_Bool checkMatch(int gameSize, char cards[][gameSize], int xcoord[], int ycoord[])
{
  int userCoordinate1 = xcoord[0], userCoordinate2 = ycoord[0], userCoordinate3 = xcoord[1], userCoordinate4 = ycoord[1];
	
   return ((cards[userCoordinate1][userCoordinate2]) == cards[userCoordinate3][userCoordinate4]);
   
}

_Bool allRevealed(int gameSize, int revealed[][gameSize])
{
  int i1, i2, allRevealed;

  for (i1 = 0; i1 < gameSize; i1++)
  {
    for (i2 = 0; i2 < gameSize; i2++)
    {
      if (revealed[i1][i2] == 0)
      {
	return 0;
      }
    }
  }

  return 1;
}

int selectDifficulty(int difficulty, int allRevealed, int gameSize)
{

 
    
   
    
    //Need to check if the game is over
    //while(allRevealed==0)
    //{
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

		break;
        }
     
    return gameSize;       
    //}
    //change the variable that sets the size of the index
}
