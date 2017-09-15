/*
 *  Author: Osvaldo A. Ramirez
 *	ICOM5007 - Laboratory work
 *	LAb00 - Excersice 3: Working with structures
 *  Language: C
 */

#include<stdio.h>

/* defines a new datatype with more than one member creating datatype student */
struct student{
  float gpa;      /* Student gpa */
  char name[50];  /* Student name */
};

typedef student std;   /* gives symbolic name to student */

int main()
{

  int rightNumber = 0;    /* Control wheather the entered number is wrong or not */
  int nos = 0;            /* number of students */
  std a;                  /* temporary variable for sorting */

  while(!rightNumber){

    printf("Enter the number of students to manage. \n(number must be between 1 - 20)\n");
    scanf("%d",&nos);         /* get number of students */
    getchar();                /* Clear input buffer */
    //printf("%d\n",nos);       /* TEST */
    if(nos >= 1 && nos <=20){       /* Check if number is between 1-20 */
      rightNumber = 1;            /* If true set rightNumber to 1 */
    }else{
      printf("Invalid number! (number must be between 1 - 20) \nTry again: ");
    }

  }

  std s[nos];         /* Array type student */

  /* Get all the students (name & gpa) */
  for(int i=0;i<nos;i++){
    printf("Please enter the name:");
    scanf("%s",s[i].name);
    getchar();        /* Clear input buffer */
    printf("Please enter the gpa:");
    scanf("%f",&s[i].gpa);
    getchar();        /* Clear input buffer */
  }

  /* Bubble sort algorithm */
  for (int i = 0; i < nos; ++i){
    for (int j = i + 1; j < nos; ++j){
      if (s[i].gpa > s[j].gpa){   /* Compare number with all the other numbers */
        /* if number if biggger change positions */
        a =  s[i];        /* store current student in a */
        s[i] = s[j];      /* store compared student in current student position */
        s[j] = a;         /* Store current student in the compared student old position */
      }
    }
   }

  /* Print all the students */
  for(int i=0;i<nos;i++){
    printf("Name: %s GPA:%f\n",s[i].name,s[i].gpa);
  }

  return 0;
}
