/*
Maxwell Rodriguez 
2/27/22
Source code main file for Airline Reservation System. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//declaring the arrays that are in passengers.c file as well as declaring all the functions, variables I used in the program.
extern char passenger[20][30];
int passengerNumber[25];
int inPassengerList(int num);
void welcomeUser();

void initializeSeatingList();

void generateRandomClass(int num);
void generateFirstClass(int num);
void generateBizClass(int num);
void generateEconClass(int num);
void userUpgradeorDowngrade();

int isPlaneFull();
int isFirstClassFull();
int isBizClassFull();
int isEconClassFull();

void printTicket(int row, int column);
void displaySeatingChart();

void displayPassengerList();

int userEntered;
int choice;
int chooseSeat;
int seatType;
int randomSeat;
int seatingList[20][7];

int userRowNumber;
int userColumnNumber;

int main(){
    //main that starts it all

    initializeSeatingList();

    while(1) {
        //simple while loop that is true until the user makes their choice 5, which breaks the loop. 
        
        welcomeUser();

        if (choice == 5){
        break;
        }

        switch(choice){
            //switch that helps me figure out what the user picked, and simply give them what they asked the program to do. 
            case 1: ;
                printf("\nPassenger List:\n2 - BillyBob\n3 - BraxtonMartoano,\n4 - ConnorRyan,\n5 - DavidLaid,\n6 - EthanStaubus,\n7 - ErenJeager,\n8 - EugeneRodriguez,\n9 - GunnerBurkhart,\n10 - HarryOsborn,\n11 - JakeWarren,\n12 - JerryWest,\n13 - JoeDirt,\n14 - JohnDoe,\n15 - JonSkywalker,\n16 - KanyeWest,\n17 - KyleMcwhirtir,\n18 - Lebronjames,\n19 - LukeChorba,\n20 - MikasaAckerman,\n21 - PatrickBateman,\n22 - PeterParker,\n23 - RyanGosling,\n24 - ShellyStone,\n25 - TonyRodriguez,\n26 - ZaraClop\nEnter number for name below:\n");
                scanf("%d", &userEntered);
                if (inPassengerList(userEntered) == 1) {
                    printf("****Valid name, would you like to choose your seat? type 1 for yes and 2 for no (1/2):" );
                    scanf("%d", &chooseSeat);
                    if (chooseSeat == 1){
                        printf("Enter 1 for first class or Enter 2 for business class or Enter 3 for economy class(1/2/3):" );
                        scanf("%d", &seatType);
                        if (seatType == 1){
                            if (isFirstClassFull() >= 1){
                            printf("\nthere are %d seats left in First Class\n", isFirstClassFull());
                            generateFirstClass(userEntered);
                            }
                            else {
                                printf("\nThis class is full, please start again with Business class.\n");
                            }
                        } 
                        else if (seatType == 2){
                            if (isBizClassFull() >= 1){
                            printf("\nthere are %d seats left in Business Class\n", isBizClassFull());
                            generateBizClass(userEntered);
                            }
                            else {
                                printf("\nThis class is full, please start Again with Economy class.\n");
                            }
                        }
                        else {
                            if (isEconClassFull() >= 1){
                            printf("\nthere are %d seats left in Economy Class\n", isEconClassFull());
                            generateEconClass(userEntered);
                            }
                            else {
                                printf("\nThis class is full, please start over.\n");
                            }
                        }
                    }
                    else if (chooseSeat == 2){
                        if (isPlaneFull() >= 1){
                            printf("\nthere are %d seats left on the plane\n", isPlaneFull());
                            generateRandomClass(userEntered);
                        }
                        else{
                            printf("The plane is full, next flight is in 3 hours.\n");
                        }
                        }
                }
                else{
                printf("\n****Number is not on the Passenger List, Try again****\n");
                break;
                }

            break; 

            case 2: 
                printf("Hello, please enter Row number of seat(0-19):");
                scanf("%d", &userRowNumber);
                printf("Now please enter column number of seat(0-6):");
                scanf("%d", &userColumnNumber);
                printTicket(userRowNumber, userColumnNumber);
            break;

            case 3:
                displaySeatingChart();

            break; 

            case 4: 
                displayPassengerList();
        
            break;

            default:
                printf("\nInvalid choice, showing options again\n");
            break;
        }
    }
    return 0;
}


void welcomeUser(){
    //simple welcome statement so that the main isn't so big 
    printf("\n***** Welcome to Delta Airlines Seating System! *****");
    printf("\n Enter 1 to choose name and seat.\n Enter 2 to print boarding pass.\n Enter 3 to view the seating map.\n Enter 4 to view passenger list.\n Enter 5 to Quit.\nEnter Below:\n");
    scanf("%d", &choice);
}

void initializeSeatingList(){
    // set the seatingList all to 0, indicating all are open.
    for (int i = 0; i<20; i++){
        for (int j = 0; j<7; j++){
            seatingList[i][j] = 0;
        }
    }
    // Now i must set every other seat equal to 1, indicating it is a covid blocked seat and is not allowed
    for (int i = 0; i<20;i++){
        for (int j = 1; j<7;j=j+2){
            seatingList[i][j] = 1;
        }
    }
/* uncomment this to show the seating, this is what the seating map will look like.
    for (int i = 0; i<20;i++){
        for (int j = 0; j<7;j++){
            printf("%d", seatingList[i][j]);
        }
        printf("\n");
    }
*/
}

void generateRandomClass(int num){
    //generates a random seat in a random section. then asks for user input if they like the seat only giving 3 tries. 
    int i = 0;
    while(i != 4){
        int temp;
        int lower1 = 0;
        int upper1 = 19;
        int lower2 = 0;
        int upper2 = 6;
        srand(time(NULL));
        int randomSeatRow = (rand() % (upper1-lower1+1))+lower1;
        int randomSeatColumn = (rand() % (upper2-lower2+1))+lower2;
        if (i == 3){
            printf("\nSorry, you can wait till next flight in 3 hours! \n");
            break;
        }
        else if (seatingList[randomSeatRow][randomSeatColumn] == 0){
            printf("\nis seat row %d and column %d okay with you? 1 for yes, 2 for no:", randomSeatRow, randomSeatColumn);
            scanf("%d", &temp);
            if (temp == 1){
                seatingList[randomSeatRow][randomSeatColumn] = num;
                printf("Your seat is saved! Confirmatin email was sent\n");
                userUpgradeorDowngrade();
                break;
            }
            else{
                i++;
            }
        }
        else{
        }
    }
}

void generateFirstClass(int num){
    //generates a random seat in the FirstClass section. then asks for user input if they like the seat only giving 3 tries. 
    int i = 0;
    while(i != 4){
        int temp;
        int lower1 = 0;
        int upper1 = 2;
        int lower2 = 0;
        int upper2 = 6;
        srand(time(NULL));
        int randomSeatRow = (rand() % (upper1-lower1+1))+lower1;
        int randomSeatColumn = (rand() % (upper2-lower2+1))+lower2;
        if (i == 3){
            printf("\nSorry, you can wait till next flight in 3 hours! \n");
            break;
        }
        else if (seatingList[randomSeatRow][randomSeatColumn] == 0){
            printf("\nis seat row %d and column %d okay with you? 1 for yes, 2 for no:", randomSeatRow, randomSeatColumn);
            scanf("%d", &temp);
            if (temp == 1){
                seatingList[randomSeatRow][randomSeatColumn] = num;
                printf("Your seat is saved! Confirmatin email was sent\n");
                userUpgradeorDowngrade();
                break;
            }
            else{
                i++;
            }
        }
        else{
        }
    }
}

void generateBizClass(int num){
    //generates a random seat in the business section. then asks for user input if they like the seat only giving 3 tries. 
    int i = 0;
    while(i != 4){
        int temp;
        int lower1 = 3;
        int upper1 = 6;
        int lower2 = 0;
        int upper2 = 6;
        srand(time(NULL));
        int randomSeatRow = (rand() % (upper1-lower1+1))+lower1;
        int randomSeatColumn = (rand() % (upper2-lower2+1))+lower2;
        if (i == 3){
            printf("\nSorry, you can wait till next flight in 3 hours! \n");
            break;
        }
        else if (seatingList[randomSeatRow][randomSeatColumn] == 0){
            printf("\nis seat row %d and column %d okay with you? 1 for yes, 2 for no:", randomSeatRow, randomSeatColumn);
            scanf("%d", &temp);
            if (temp == 1){
                seatingList[randomSeatRow][randomSeatColumn] = num;
                printf("Your seat is saved! Confirmatin email was sent\n");
                userUpgradeorDowngrade();
                break;
            }
            else{
                i++;
            }
        }
        else{
        }
    }
}

void generateEconClass(int num){
    //generates a random seat in the econ section. then asks for user input if they like the seat only giving 3 tries. 
    int i = 0;
    while(i != 4){
        int temp;
        int lower1 = 7;
        int upper1 = 20;
        int lower2 = 0;
        int upper2 = 6;
        srand(time(NULL));
        int randomSeatRow = (rand() % (upper1-lower1+1))+lower1;
        int randomSeatColumn = (rand() % (upper2-lower2+1))+lower2;
        if (i == 3){
            printf("\nSorry, you can wait till next flight in 3 hours! \n");
            break;
        }
        else if (seatingList[randomSeatRow][randomSeatColumn] == 0){
            printf("\nis seat row %d and column %d okay with you? 1 for yes, 2 for no:", randomSeatRow, randomSeatColumn);
            scanf("%d", &temp);
            if (temp == 1){
                seatingList[randomSeatRow][randomSeatColumn] = num;
                printf("Your seat is saved! Confirmatin email was sent\n");
                userUpgradeorDowngrade();
                break;
            }
            else{
                i++;
            }
        }
        else{
        }
    }
}

int isPlaneFull(){
    //checks to see if the whole plane is full and returns seat for whole plane. Useful for when a person does not care where they sit. 
    int seats = 0;
    for (int i = 0; i<20;i++){
        for (int j = 0; j<7;j++){
            if (seatingList[i][j] == 0){
                seats++;
            }
        }
    }
    return seats;
}

int isFirstClassFull(){
    //Checks if there is room for more people, and displays the amount of seats left in First Class
    int seats = 0;
    for (int i = 0; i<3;i++){
        for (int j = 0; j<7;j++){
            if (seatingList[i][j] == 0){
                seats++;
            }
        }
    }
    return seats;
}

int isBizClassFull(){
    //Checks if there is room for more people, and displays the amount of seats left in business
    int seats = 0;
    for (int i = 3; i<7;i++){
        for (int j = 0; j<7;j++){
            if (seatingList[i][j] == 0){
                seats++;
            }
        }
    }
    return seats;
}

int isEconClassFull(){
    //Checks if there is room for more people, and displays the amount of seats left in economy
    int seats = 0;
    for (int i = 7; i<20;i++){
        for (int j = 0; j<7;j++){
            if (seatingList[i][j] == 0){
                seats++;
            }
        }
    }
    return seats;
}

void userUpgradeorDowngrade(){
    // This was tricky to implement, I had to figure out how to update the seat so that they weren't dupplicated in the reservation system. 
    // asks to upgrade or downgrade seat that the user is in, it updates the seating list by going through it in 2 for loops,
    // checking to find where the last seat location was and updating it to the new seating location. 
    int choice;
    int firstBiz;
    int bizEcon;
    printf("Would you like to upgrade or downgrade your seat? 1 for upgrade 2 for downgrade 3 to keep your seat.(1/2/3):");
    scanf("%d", &choice);
    if (choice == 1){
        for (int i = 0; i<20;i++){
            for (int j = 0; j<7;j++){
                if (seatingList[i][j] == userEntered){
                seatingList[i][j] = 0;
                    }
                }
        }
        printf("Would you like to upgrade to First Class or Business? 1 for FirstClass 2 for Business(1/2):");
        scanf("%d", &firstBiz);
            if (firstBiz == 1){
                if (isFirstClassFull() >= 1){
                     printf("\nthere are %d seats left in First Class\n", isFirstClassFull());
                     generateFirstClass(userEntered);
                }
                else {
                     printf("\nThis class is full, please start over.\n");
                }
            }
            else {
                if (isBizClassFull() >= 1){
                    printf("\nthere are %d seats left in Business Class\n", isBizClassFull());
                    generateBizClass(userEntered);
                }
                else {
                    printf("\nThis class is full, please start over.\n");
                }
            }
    }
    else if (choice == 2){
        for (int i = 0; i<20;i++){
            for (int j = 0; j<7;j++){
                if (seatingList[i][j] == userEntered){
                seatingList[i][j] = 0;
                    }
                }
        }
        printf("Would you like to downgrade to Business Class or Economy? 1 for Business 2 for Economy(1/2):");
        scanf("%d", &bizEcon);
            if (bizEcon == 1){
                if (isBizClassFull() >= 1){
                    printf("\nthere are %d seats left in Business Class\n", isBizClassFull());
                    generateBizClass(userEntered);
                }
                else {
                    printf("\nThis class is full, please start over.\n");
                }
            }
            else {
                if (isEconClassFull() >= 1){
                    printf("\nthere are %d seats left in Economy Class\n", isEconClassFull());
                    generateEconClass(userEntered);
                }
                else {
                    printf("\nThis class is full, please start over.\n");
                }
            }
    }
    else {
        printf("\nseat is saved\n");
    }
}


void printTicket(int row, int column){
    //this looks to see what class they are in first, then will print out the name and seat and class that is the user ticket.
    if (row <=2){
        if (seatingList[row][column] == 0) {
            printf("\nSeat Unassigned - No boarding pass.\n");
        }
        else if (seatingList[row][column] == 1){
            printf("\nthis seat is blocked for covid safety.\n");
        }
        else{
            printf("\nTICKET: %s, row:%d, column:%d, Level: First Class\n", passenger[(seatingList[row][column]-2)], row, column);
        }
    }
    else if (row <=6 && row >= 3){
        if (seatingList[row][column] == 0) {
            printf("\nSeat Unassigned - No boarding pass.\n");
        }
        else if (seatingList[row][column] == 1){
            printf("\nthis seat is blocked for covid safety.\n");
        }
        else{
            printf("\nTICKET: %s, row:%d, column:%d, Level: Business Class\n", passenger[(seatingList[row][column]-2)], row, column);
        }

    }
    else if (row >= 7){
        if (seatingList[row][column] == 0) {
            printf("\nSeat Unassigned - No boarding pass.\n");
        }
        else if (seatingList[row][column] == 1){
            printf("\nthis seat is blocked for covid safety.\n");
        }
        else{
            printf("\nTICKET: %s, row:%d, column:%d, Level: Economy Class\n", passenger[(seatingList[row][column]-2)], row, column);
        }
    }
}

void displaySeatingChart(){
    //shows the entire seating chart. 
    printf("\nSEATING MAP GUIDE:\n0 = open seat\n1 = covid reserved seat\n2 or greater is reserved by someone\n\n");
    for (int i = 0; i<20;i++){
        for (int j = 0; j<7;j++){
            printf("%d ", seatingList[i][j]);
        }
        printf("\n");
    }
}

void displayPassengerList(){
    //displays what passengers are on the plane and there seat number on the plane. In order of seat number. 

    for (int i = 0; i<20;i++){
        for (int j = 0; j<7;j++){
            if (seatingList[i][j] != 0 && seatingList[i][j] != 1){
            printf("\nPassenger: %s, Seat is row: %d and column: %d \n", passenger[(seatingList[i][j]-2)], i, j);
            }
        }
    }
}

int inPassengerList(int num) {
    // checks to see if the passenger is in the list the user enters. 
    int finalResult;
    if (num >= 2 && num <= 26){
        finalResult = 1;
    }
    else {
        finalResult = 0;
    }
    return finalResult;
}
