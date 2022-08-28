#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int get_dayStarts(int year)
{
    int day=0;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return  day;
}


int main()
{
  system ("color 5F");
  int year,month,day,dayMonth,dayweek=0,dayStarts;
  printf( "\n\nPlease Enter a Year :");
  scanf("%d",&year);
  char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
  int MonthsDays[]={31,28,31,30,31,30,31,31,30,31,30,31};


  if ((year%4==0&&year%100!=0)||year%400==0)
      MonthsDays[1]=29;

  dayStarts=get_dayStarts(year);

  for(month=0;month<12;month++)
  {
     dayMonth=MonthsDays[month];

     printf("\n\n------------------%s-------------------------\n",months[month] );
     printf("\n\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

     for(dayweek=0;dayweek<dayStarts;dayweek++)
        printf("     ");

     for (day=1;day<=dayMonth;day++)
     {
         printf("%5d",day);

         if(++dayweek>6)
         {
             printf("\n");
             dayweek=0;
         }
         dayStarts=dayweek;
     }
  }

}



