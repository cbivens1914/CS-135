//CS135.1002
//NetIds: ajara, 
//Purpose: A simplified game of memory

#include <stdio.h>

//maybe a #define or two

//lot of function prototypes here

int main () {
  //declare variables
  int menu, difficulty;

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
		//game
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
