#include <stdio.h>
#include <math.h>

int dayOfWeek(int month, int day, int year){
  int h,q,m,k,j;

  if(month == 1) {
    month = 13;
    year--;		
  }
  if (month == 2){
    month = 14;		
    year--;
  }
  
  q = day;
  m = month;
  k = year % 100;
  j = year / 100;
  h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j;
  h = h % 7;

  return h;
}

int main(){
  int m,d,y; 
  
  printf("Enter the date (mm/dd/yyyy)\n"); 
  scanf("%d%d%d",&m,&d,&y);
  
  int dow=dayOfWeek(m,d,y);
  switch(dow){
    case 0 : printf("Saturday.\n"); break;
    case 1 : printf("Sunday.\n"); break;
    case 2 : printf("Monday. \n"); break;
    case 3 : printf("Tuesday. \n"); break;
    case 4 : printf("Wednesday. \n"); break;
    case 5 : printf("Thursday. \n"); break;
    case 6 : printf("Friday. \n"); break;
  }
}
