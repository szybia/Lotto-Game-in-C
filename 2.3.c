/* This program will play the Lotto game. (Assignment 2)
 Author: Szymon Bialkowski (C15533517)
 Compiler: Codeblocks Windows 10
 Date: 18/02/2016     */

#include <stdio.h>
#define SIZE 6

void mainmenu();                    //Prints Main Menu
void scan_usernum(int*);            //Scans Menu Option
void no_entry(void);                //If user cant access a function
void function1(int*, int*, int*);   //Scans in numbers
void function2(int*);               //Displays those numbers
void function3(int*);               //Sort numbers
void function4(int*);               //Play the Lotto
void function5(int*, int*, int*);   //Displays frequency of entered numbers
void function6(int*);               //Used to exit the program

int main()
{
    int num_array[6]={0};				   //Stores the users Lotto numbers until new ones are entered
	  int content_array[42]={0};		 //Stores the numbers which the user has used already
	  int amount_array[42]={0};			 //Stores the amount of times the user used a specific number
    int end;							         //Counter for the main loop
    int usernum;						       //Number which user enters in the main menu

    printf("Welcome to the Lotto game. ");
    printf("Follow the menu to play the game.\nI hope you enjoy and goodluck.\n\n");

    for(end=0; end!=1;)			//Main loop
    {
      scan_usernum(&usernum);

      switch (usernum)    //Switch statement which calls the functions
      {
        case 1:
        {
          function1(num_array, content_array, amount_array);
				   break;
        }
  			case 2:
  			{
  				function2(num_array);
  				break;
  			}
  			case 3:
  			{
  				function3(num_array);
  				break;
  			}
  			case 4:
  			{
  				function4(num_array);
  				break;
  			}
  			case 5:
  			{
  				function5(content_array, amount_array, num_array);
  				break;
  			}
  			case 6:
  			{
  				function6(&end);
  				break;
			  }
      }//end switch
    }//end for
}//end of main()


//*****IMPLEMENT SCAN_USERNUM*****
void scan_usernum(int* usernum)
{
    register int i;
    char ch;

    for(i=0; i!=1;)
    {
			mainmenu();
			*(usernum) = 0;
      scanf("%1d", usernum);


			if(*(usernum)>0 && *(usernum)<7)
      {
          i++;
      }
      else
      {   system("cls");
          printf("Invalid input. Please choose one of the choices.\n");
      }

      }//end for
}//end scan_usernum

//*****IMPLEMENT NO_ENTRY*****
void no_entry(void)
{
    system("cls");
    printf("You have not entered in your Lotto numbers. ");
    printf("Please select option 1 in the menu.\n");
}//end no_entry

//*****IMPLEMENT MAIN MENU*****
void mainmenu()
{
	printf("\n\t\t***MAIN MENU***\t\t");
	printf("\n1. Enter your %d lottery numbers to play the game.\n", SIZE);
	printf("2. Display the lottery numbers that you picked.\n");
	printf("3. Sort your %d numbers in increasing order.\n", SIZE);
	printf("4. Compare your chosen Lotto numbers with the winning numbers.\n");
	printf("5. Display how many times you entered specific Lotto numbers.\n");
	printf("6. Exit program.\n");
}//end main menu

//*****IMPLEMENT FUNCTION 1*****
void function1(int* num_array, int* content_array, int* amount_array)
{

  register int i, j, x;
	int z;
	int check;
	char ch;

    system("cls");
    printf("Please enter in your %d Lotto numbers one by one. (Range: 1-42)\n", SIZE);
    memset(num_array, 0, SIZE);         //Clears num_array

    for(z=0; z!=1;)
    {
       for(i=0; i<SIZE; i++)
        {
            for(j=0; j!=1;)
            {
                printf("Number %d: ", i+1);
                scanf("%d", &*(num_array+i));
                while( ( ch = getchar() ) != '\n' && ch != EOF );  //Stops infinite loop if char is entered
                {
                   if(*(num_array+i) < 43 && *(num_array+i) > 0)
                   {
                        j++;
                   }
                   else
                   {    system("cls");
                        printf("Invalid input. You must enter a number between 1-42.\n");
                   }
                }//end while
            }//end for(3)
        }//end for(2)

        if(*(num_array)==*(num_array+1)   || *(num_array)==*(num_array+2)   ||  //Checks if user entered in 2 same numbers
		       *(num_array)==*(num_array+3)   || *(num_array)==*(num_array+4)   ||
           *(num_array)==*(num_array+5)   || *(num_array+1)==*(num_array+2) ||
			     *(num_array+1)==*(num_array+3) || *(num_array+1)==*(num_array+4) ||
           *(num_array+1)==*(num_array+5) || *(num_array+2)==*(num_array+3) ||
			     *(num_array+2)==*(num_array+4) || *(num_array+2)==*(num_array+5) ||
           *(num_array+3)==*(num_array+4) || *(num_array+3)==*(num_array+5) ||
			     *(num_array+4)==*(num_array+5)  )
        {
            system("cls");
            printf("You have entered in 2 same numbers or an invalid data type.\nPlease try again");
			      printf(" with valid numbers. E.g. 1,2,3,4,5,6...\n");
        }
        else	//If all elements are right this executes
        {
    			//Next loop carries out the functionality of function 5

    			for(i=0; i<SIZE; i++)		//Scans over each new number
    			{
    				for(j=0; j<42; j++)		//Scans over each element in array containing used integers
    				{
    					if(*(num_array+i) == *(content_array+j))     //If new number is already used its used value is incremented
    					{
    						(*(amount_array+j))++;
    						j=42;				                     //Terminates loop because character is already found
    					}
    					else if(j==41)			                     //If element not in array this executes
    					{
    						for(x=0; x<42; x++)                     //Scans over elements of array containing used numbers
    						{
    							if(*(content_array+x) == 0)         //If element is free(0) then this will execute
    							{
    								*(content_array+x) = *(num_array+i);     //Places new integer into the array
    								(*(amount_array+x))++;                   //Increments amount this integer is used (0->1)
    								x=42;			                         //Terminates loop since free element was found
    							}
    						}
    					}
    				}    //end for(2)
    			}        //end for(1)
    			z++;	 //Once all elements are in, this terminates the loop
        }
    }//end for(1)
    system("cls");
}//end function 1

//*****IMPLEMENT FUNCTION 2*****
void function2(int* num_array)
{
	register int i;

	if(*(num_array)!=0)
	{
	    system("cls");
		printf("You have entered in the following Lotto numbers: ");
		for(i=0; i<(SIZE-1); i++)
		{
			printf("%d, ", *(num_array+i));
		}//end of for
		printf("%d.\n", *(num_array+(SIZE-1)));
	}//end  if
	else
	{
	    no_entry();
	}
}//end function 2

//*****IMPLEMENT FUNCTION 3*****
void function3(int* num_array)
{
	register int i, j;
	int temp=0;

        if((*(num_array))!=0)
		{
			for(j=0; j!=1;)
			{
				for(i=0; i<(SIZE-1); i++)
				{
						if((*(num_array+i)) > (*(num_array+(i+1))))
						{
							temp=(*(num_array+(i+1)));
							(*(num_array+(i+1)))=(*(num_array+i));
							(*(num_array+i))=temp;
						}
				}
				if(*(num_array) < *(num_array+1) && *(num_array+1) < *(num_array+2) &&
				   *(num_array+2) < *(num_array+3) && *(num_array+3) < *(num_array+4) &&
				   *(num_array+4) < *(num_array+5)        )
				{
					j++;
				}
			}
			system("cls");
			printf("Your numbers have now been succesfully sorted.\n");
		}
		else
		{
		    no_entry();
		}
}//end of function 3

//*****IMPLEMENT FUNCTION 4*****
void function4(int* num_array)
{
	register int i, j;
	int winning[SIZE]={1,3,5,7,9,11};
	int bonus_num=42;
	int bonus=0;
	int amount=0;

	if((*(num_array))!=0)
	{
		for(i=0; i<SIZE; i++)
		{
			for(j=0; j<SIZE; j++)
			{
				if(*(num_array+j)==*(winning+i))
				{
					amount++;
				}

			}//end for(2)
            if(*(num_array+i)==bonus_num)
            {
                bonus++;
            }
		}//end for(1)

		if(amount<3)
		{   system("cls");
			printf("Sorry, you didn't win anything in this round of the Lotto game. Keep trying!\n");
		}
		else
		{
			switch (amount)
			{
				case 3:
				{
					if(bonus==1)
					{   system("cls");
						printf("CONGRATULATIONS!!! You've won a cinema ticket!. Well done!.\n");
					}
					else
					{   system("cls");
						printf("You didn't win anything in this round of the Lotto game. Keep trying!\n");
					}
					break;
				}
				case 4:
				{
					if(bonus==1)
					{   system("cls");
						printf("CONGRATULATIONS!!! You've won a weekend away!. Well done!.\n");
					}
					else
					{   system("cls");
						printf("CONGRATULATIONS!!! You've won a night out!. Well done!.\n");
					}
					break;
				}
				case 5:
				{
					if(bonus==1)
					{   system("cls");
						printf("CONGRATULATIONS!!! You've won a new car!. Well done!.\n");
					}
					else
					{   system("cls");
						printf("CONGRATULATIONS!!! You've won a holiday!. Well done!.\n");
					}
					break;
				}
				case 6:
				{   system("cls");
					printf("YOU'VE HIT THE JACKPOT!!! WELL DONE!\n");
					break;
				}
			}//end switch
		}//end else
	}//end if
	else
	{
	    no_entry();
	}
}//END OF FUNCTION 4

//*****IMPLEMENT FUNCTION 5*****
void function5(int* content_array, int* amount_array, int* num_array)
{
	register int i;

	if((*(num_array))!=0)
	{
	    system("cls");
		for(i=0; i<42; i++)
		{
			if(*(content_array+i) != 0)
			{
			    if(*(content_array+i) <10)
                {
                    printf(" ");
                }
				printf("Number %d has been selected %d times.\n", (*(content_array+i)), (*(amount_array+i)));
			}
			else
			{
                i=42;
			}
		}
	}
	else
	{
	    no_entry();
	}//end while
}//END OF FUNCTION 5

//*****IMPLEMENT FUNCTION 6*****
void function6(int* end)
{
	char input;

    system("cls");
	printf("Are you sure you want to Exit Program? Enter 'Y' to Exit, press any key to cancel.\n");
	scanf("%c", &input);
	if(input=='Y' || input=='y')
	{
		printf("Thank you for playing our Lotto game.\n");
		(*end)++;		//Ends main loop therefore ending program
	}
	else
	{
	    system("cls");
	}
}//END OF FUNCTION 6
