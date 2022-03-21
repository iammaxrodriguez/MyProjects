/*
Maxwell Rodriguez 
03/06/22
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int data[7][10];
extern char *topics[7];

void startSurveryData();
void welcomeGuest();
void getSurvey();
void calculateData();
void printData();


int numberOfParticipants = 0;
int inaccurate = 0;
int choice;
int rating;

int racismTotal = 0;
int ccTotal = 0;
int caTotal = 0;
int tTotal = 0;
int daTotal = 0;
int joTotal = 0;
int iiTotal = 0;


int main(){
    //main that starts it all
    startSurveryData();

    while(1) {
        //simple while loop that is true until the user makes their choice 2, which breaks the loop. 
        
        welcomeGuest();

        if (choice == 2){
        break;
        }

        switch(choice){
            //switch that helps me figure out what the user picked, and simply give them what they asked the program to do. 
            case 1: 
                getSurvey();
                numberOfParticipants++;
            break; 

            case 2: 
            break;

            default:
                printf("\nInvalid choice, showing options again\n");
            break;
        }
    }
    
    calculateData();
    int totaldata[7] = {racismTotal,ccTotal,caTotal,tTotal,daTotal,joTotal,iiTotal};
    printData(totaldata);
    printf("\n\nNumber participated on survey: %d\n\n", numberOfParticipants);
    if (inaccurate > 0){
        printf("\n%s\n", "****User entered incorrect importancy number, please exit and restart****");
    }
    return 0;
}
   /* for (int i =0; i<7; i++){
    printf("%s\n\n", *(topics+i));
    }
    */



void welcomeGuest(){
    printf("\n*****Welcome to my survey, You will rate the issues displayed 1-10, with 10 being Most Important.*****\n\n");
    printf("\tIf you would you like to add another survey, enter 1.\n\tIf you would you like to stop the survey and see the results, enter 2.\n");

    scanf("%d", &choice);
}

void startSurveryData(){
    for (int i = 0; i < 7; i++){
        for (int j = 0; j<10; j++){
            *(*(data + i) + j) = 0;
        }
    }
}

void getSurvey(){
    for (int i = 0; i<7; i++){
        printf("Rate %s from 1 to 10 on importancy\n", *(topics+i));
        scanf("%d", &rating);
        if (rating >=1 && rating <=10){
            for (int j = 0; j<10; j++){
                if (rating-1 == j){
                    (*(*(data + i) + j))++;
                }
                else{
                }
            }
        }
        else{
            printf("\n%s\n\n", "You must enter a rating 1-10. This survey is now inaccurate.");
            inaccurate++;
        }
    }
}

void printData(int num[]){
    printf("\n%s","*** Each number in the categories represents the amount of votes it had in total. ***\n\n");
    printf("\n%-30s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\nTopic:\n%120s\t%s\n", "Importancy(1-10):","1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Total points:", "Average importancy:");
    for (int i = 0; i < 7; i++){
        printf("%-30s\t", *(topics+i));
        for (int j = 0; j<12; j++){
            if (j == 10){
                printf("%d\t\t", *(num+i));
            }
            else if (j==11){
                printf("%s: %d\t", *(topics+i), *(num+i)/numberOfParticipants);
            }
            else{
            printf("%d\t", *(*(data + i) + j));
            }
        }
        printf("\n");
    }
}

void calculateData(){
    for (int i = 0; i < 1; i++){
        for (int j = 0; j<10; j++){
            racismTotal += (*(*(data + i) + j))*(j+1);
        }
    }
    for (int i = 1; i < 2; i++){
        for (int j = 0; j<10; j++){
            ccTotal += (*(*(data + i) + j))*(j+1);
        }
    }
    for (int i = 2; i < 3; i++){
        for (int j = 0; j<10; j++){
            caTotal += (*(*(data + i) + j))*(j+1);
        }
    }
    for (int i = 3; i < 4; i++){
        for (int j = 0; j<10; j++){
            tTotal += (*(*(data + i) + j))*(j+1);
        }
    }
    for (int i = 4; i < 5; i++){
        for (int j = 0; j<10; j++){
            daTotal += (*(*(data + i) + j))*(j+1);
        }
    }
    for (int i = 5; i < 6; i++){
        for (int j = 0; j<10; j++){
            joTotal += (*(*(data + i) + j))*(j+1);
        }
    }
    for (int i = 6; i < 7; i++){
        for (int j = 0; j<10; j++){
            iiTotal += (*(*(data + i) + j))*(j+1);
        }
    }
}
