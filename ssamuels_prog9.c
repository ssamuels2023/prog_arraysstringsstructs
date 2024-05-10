/*
Sophie Samuels
COP 2220
Program 9
04.22.24
This program is a customer inventory program. The structure 'customer' is used 
to store customer information including name as a string of max 50 character,
order number as an integer, order amount as a double, location as a string with
max of 50 character, and validity of order as a character. 
Greeting function greets the user and introduces them to the program. 
FillFive function allows user to fill inventory with all information for five 
customers and their order information.
GetChoice function displays a menu with choices, asks/gets/returns user choice.
ProcessMenu function processes the user's choice and uses if/else conditions
to execute the chosen option (facilitating the initiation of other functions).
PrintOneCustomer function prints one cusromer's information onto the screen 
by first letting the user know how many orders there are, then ask/get specific
order number from user, using a do/while loop to print one customer order
information onto the screen if the number is valid.
PrintValidList function prints all orders in the valid inventory onto the 
screen using a for loop to iterate through all orders and using an if statement 
to check if each order is valid.
PrintListToFile function prints the entire customer inventory (both valid and 
invalid) into a file by declaring a file pointer 'outPtr', opening the file 
named 'report.txt' in write 'w' mode, and looping through the inventory from 
index 0 using a for loop. 
AddCustomerToList function allows the user to add a new customer/order to the 
inventory.
MakeInvalid function allows user to make a customer invalid my declare/ask/get 
an order number, using a do/while loop to make sure the user enters a valid 
order number, then setting the validity to invalid 'I'.
CalculateTotalAverage function calculates the total and average of all amounts
of valid orders by using a for loop to iterate through each order, an if 
statement to check for order validity prior to adding the amount to the sum and 
incrementing the totalCount to allow accurate calculation of the average. The 
average is calculated as prompted after an if statement to ensure that the 
calculated average is based on at least 1 order amount.
*/

#include <stdio.h>
#include <ctype.h> //for toupper and tolower

#define SIZE 50

typedef struct {
    char OrderName[50]; //stores the first name of the customer
    int OrderNumber; //stores the order number of the customer
    double OrderAmount; //stores the order amount
    char location[100]; //stores the customer’s location
    char validOrder;//stores 'V' for valid or 'I' invalid
} customer;

//(1)greet the user
void Greeting();

//(2)fill the inventory with five customers
void FillFive(customer inventory[]);

//(3)Display the menu, ask, get, and return the user choice
char GetChoice();

//(4)run the program menu (process the choice)
//use if else conditions (or switch)
void ProcessMenu(char choice, customer inventory[], int *countPtr);

//(5)print ONE customer information onto the screen
void PrintOneCustomer(customer info);

//(6)print entire VALID customer inventory onto the screen
void PrintValidList(customer inventory[], int count);

//(7)print entire customer inventory(valid and invalid) into a file
void PrintListToFile(customer inventory[], int count);

//(8)Add a new customer into the inventory
void AddCustomerToList(customer inventory[], int count);

//(9)make a customer invalid
void MakeInvalid(customer inventory[], int count);

//(10) Calculate the total and the average of all the valid orders
void CalculateTotalAverage(customer inventory[], int count);

int main()
{
    //declare character for the choice
    char choice;
    //declare an array of 50 customers (inventory )
    customer inventory[SIZE]; //capacity 50
    //declare count for the array
    int count = 0;
    //greet the user
    Greeting();
    //fill five customers into the array
    FillFive(inventory);
    //set count to 5
    count = 5;
    
    printf("\nFIVE Valid customers have been added to the inventory.\n\n");

    //get the choice - initialization
    choice = GetChoice();
    
    while (choice != 'Q') //test
    {
        ProcessMenu(choice, inventory, &count);
        choice = GetChoice(); //update
    }
    
    printf("\nHave a great day!");
    return 0;
}

//(1)greet the user
void Greeting()
{
    printf("\nWelcome to the customer inventory program, please select an option from the menu\n\n");
}
//(2)fill the inventory with five customers
void FillFive(customer inventory[])
{
    customer temp1 = { "Charlie.Cheetah", 1, 1025.50, "Cape.Town", 'V' };
    inventory[0] = temp1;
    //add 4 more
    customer temp2 = { "Wilde.Beest", 2, 205.95, "Mossel.Bay", 'V' };
    inventory[1] = temp2;
    
    customer temp3 = { "Holly.Hippo", 3, 60250.75, "Victoria", 'V' };
    inventory[2] = temp3;
    
    customer temp4 = { "Honey.Badger", 4, 55080.55, "Bloemfontein", 'V' };
    inventory[3] = temp4;
    
    customer temp5 = { "Mortimer.Mongoose", 5, 22.95, "Durban", 'V' };
    inventory[4] = temp5;
}

//(3)Display the menu, ask, get, and return the user choice
char GetChoice()
{
    char letter;
    printf("\n*****************************************************************************");
    printf("\nEnter ...A... to add a customer to the inventory ");
    printf("\nEnter ...P... to print the information for one customer ");
    printf("\nEnter ...V... to print all the valid customers in the inventory ");
    printf("\nEnter ...C... to print all the customers (valid and invalid) into a text file ");
    printf("\nEnter ...I... to make a customer Invalid ");
    printf("\nEnter ...E... to print the orders over a certain amount ");
    printf("\nEnter ...T... to calculate the total and average of all the VALID orders ");
    printf("\nEnter ...Q... to quit\n ");
    scanf(" %c", &letter);
    letter = toupper(letter);
    return letter;
}

//(4)run the program menu (process the choice)
//use if else conditions (or switch)
void ProcessMenu(char choice, customer inventory[], int* countPtr)
{
    if (choice == 'A')
    {
        printf("\nSelected A");
        //add customer to list
        AddCustomerToList(inventory, *countPtr);
        //add one to count
        * countPtr = *countPtr + 1;
    }
    else if (choice == 'P')
    {
        printf("\nSelected P");
        printf("\nThere are %d orders\n", *countPtr);
        //declare ask and get the order number
        int number;
        //use a loop to make sure the user enters a valid order number
        do{
            printf("\nEnter the order number: ");
            scanf("%d", &number);
        }while(number < 1 || number > *countPtr);
        //PrintOneCustomer(inventory[num - 1]);
        PrintOneCustomer(inventory[number - 1]); //index is one less than order number
    }
    else if (choice == 'V')
    {
        printf("\nSelected V");
        //call the print valid inventory function
        PrintValidList(inventory, *countPtr);
    }
    else if (choice == 'C')
    {
        printf("\nSelected C");
        printf("\nCreating a report");
        //call print file function
        PrintListToFile(inventory, *countPtr);
    }
    else if (choice == 'I')
    {
        printf("\nSelected I");
        //call make invalid function
        MakeInvalid(inventory, *countPtr);
    }
    else if (choice == 'E')
    {
        printf("\nSelected E");
        double amount;
        //ask and get the amount
        printf("\nEnter the maximum order amount: $");
        scanf("%lf", &amount);
        //loop through the array to display
        for (int i = 0; i < *countPtr; i++)
        {
            if (inventory[i].OrderAmount > amount)
            {
                //only print valid orders
                PrintOneCustomer(inventory[i]);
            }
        }
    }
    else if (choice == 'T')
    {
        printf("\nSelected T");
        //calculate the total and the average
        CalculateTotalAverage(inventory, *countPtr);
    }
    else printf("\nNot valid");
}


//(5)print ONE customer information onto the screen
void PrintOneCustomer(customer info)
{
    printf("\n---------------------------------------\n");
    printf("\nOrder number:\t\t\t%d", info.OrderNumber);
    //add the rest
    printf("\nName of customer:\t\t%s", info.OrderName);
    printf("\nOrder amount:\t\t\t$%.2lf", info.OrderAmount);
    printf("\nLocation of the order:\t\t%s", info.location);
    printf("\nValid or invalid:\t\t%c", info.validOrder);
}

//(6)print entire VALID customer inventory onto the screencom
void PrintValidList(customer inventory[], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (inventory[i].validOrder == 'V')
        {
            //only print valid orders
            PrintOneCustomer(inventory[i]);
        }
    }
}

//(7)print entire customer inventory(valid and invalid) into a file
void PrintListToFile(customer inventory[], int count)
{
    FILE* outPtr; //declare
    outPtr = fopen("report.txt", "w"); //connect
    int i;
    for (i = 0; i < count; i++)
    {
        fprintf(outPtr,"\n---------------------------------------\n");
        fprintf(outPtr,"\nOrder number:\t\t\t%d", inventory[i].OrderNumber);
        //add the rest
        fprintf(outPtr,"\nName of customer:\t\t%s", inventory[i].OrderName);
        fprintf(outPtr,"\nOrder amount:\t\t\t$%.2lf", inventory[i].OrderAmount);
        fprintf(outPtr,"\nLocation of the order:\t\t%s", inventory[i].location);
        fprintf(outPtr,"\nValid or invalid:\t\t%c", inventory[i].validOrder);
        
    }
    fclose(outPtr); //close
}

//(8)Add a new customer into the inventory
void AddCustomerToList(customer inventory[], int count)
{
    //set the oder number based on the count
    inventory[count].OrderNumber = count + 1;
    
    //get the name
    printf("\nPlease enter the name of the order: ");
    scanf(" %s", inventory[count].OrderName);

    //add the additional prompts and scanf statements
    printf("\nPlease enter the amount of the order: ");
    scanf(" %lf", &inventory[count].OrderAmount);
    
    printf("\nPlease enter the location of the order: ");
    scanf(" %s", inventory[count].location);
    
    //set the order as valid
    inventory[count].validOrder = 'V';
}

//(9)make a customer invalid
void MakeInvalid(customer inventory[], int count)
{
    printf("\nThere are %d orders\n", count);
    //declare ask and get the order number
    int number;

    //use a loop to make sure the user enters a valid order number
    do{
        printf("\nEnter the order number: ");
        scanf("%d", &number);
    }while(number < 1 || number > count);
        
    if (number <= 0 || number > count)
    {
        printf("\nInvalid order number. Try again.\n");
        return;
    }
    
    //inventory[number - 1].validOrder = 'I';
    inventory[number - 1].validOrder = 'I';
    printf("\nOrder number %d is indicated as invalid.\n", number);
    //order number is one greater than the index, examples:
    //index is 0 - order number is 1
    //inedx is 1 - order number is 2
}

//(10) Calculate the total and the average of all the valid orders
void CalculateTotalAverage(customer inventory[], int count)
{
    int i, totalCount = 0;
    double sum = 0.0, avg;
    //loop through the array to add up all the amounts that are valid
    for (i = 0; i < count; i++)
    {
        //check if order is valid
        if (inventory[i].validOrder == 'V')
        {
            //add order amount to sum
            sum += inventory[i].OrderAmount;
            //increment valid order count
            totalCount++;
        }
    }
    //be sure to keep a total count for the average
    //calculate average if there is >= 1 valid order
    if (totalCount > 0)
    {
        avg = sum / totalCount;
        printf("\nThe total of all the valid orders is $%.2lf", sum);
        printf("\nThe average of all the valid orders is $%.2lf", avg);
    } else 
    {
        printf("\nThere are no valid orders in the inventory.\n");
    }
}
