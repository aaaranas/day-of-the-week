#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int isDigit(char *, char *, char*);       //function for checking characters
int convertToInt(char *);                 //function for converting string

int dayOfWeek(int mmonth, int dday, int yyear){
  int dayOftheWeek,dayOftheMonth,monthVariable,yearOfCentury,zeroBasedCentury;
  if(mmonth == 1) {
    mmonth = 13;
    yyear--;        
  }
  
  if (mmonth == 2){
    mmonth = 14;        
    yyear--;
  }
  
  dayOftheMonth = dday;
  monthVariable = mmonth;
  yearOfCentury = yyear % 100;
  zeroBasedCentury = yyear / 100;
  dayOftheWeek = dayOftheMonth + 13*(monthVariable+1)/5 + yearOfCentury + yearOfCentury/4 + zeroBasedCentury/4 + 5*zeroBasedCentury;
  dayOftheWeek = dayOftheWeek % 7;

  return dayOftheWeek;
}

void solutionFunction(int m, int d, int y){
    int dow=dayOfWeek(m,d,y);
    switch(dow){
    case 0 : printf("Saturday\n"); break;
    case 1 : printf("Sunday\n"); break;
    case 2 : printf("Monday \n"); break;
    case 3 : printf("Tuesday \n"); break;
    case 4 : printf("Wednesday \n"); break;
    case 5 : printf("Thursday \n"); break;
    case 6 : printf("Friday \n"); break;    
    }
}

int main(){
  char monthArray[MAX], dayArray[MAX], yearArray[MAX];
  int digit, m, d, y, leap;
  int invalid = 0;
  while (invalid==0){
  do{
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s %s %s", monthArray, dayArray, yearArray);
    
    digit = isDigit(monthArray, dayArray, yearArray);
    m = convertToInt(monthArray);
    d = convertToInt(dayArray);
    y = convertToInt(yearArray);
    if(m>=1 && m<=12){        
        if((d>=1 && d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)){
                solutionFunction(m,d,y);
                invalid=1;
            }
            else if((d>=1 && d<=30) && (m==4 || m==6 || m==9 || m==11)){
                solutionFunction(m,d,y);
                invalid=1;
            }
            else if(d==29 && m==2 && (y%400==0 ||(y%4==0 && y%100!=0))){
                solutionFunction(m,d,y);
                invalid=1;
            }
            else{
                printf("Invalid input. ");
            } 
    }else{
        printf("Invalid input.");
    }
    
    if (digit == 0){
      printf("Invalid Input.\n");
    }
  }while(digit==0);
  }  
    
  return 0;
    }

int isDigit(char*m, char*d, char*y){ 
    char string[MAX];
    strcpy(string, m);
    strcat(string, d);
    strcat(string, y);

    for(int i=0; string[i]!='\0'; i++){
        if(isdigit(string[i])==0){
            return 0;
        }
    }
    return 1;
}

int convertToInt(char*string){
    return(atoi(string));
}
