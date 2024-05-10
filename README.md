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
