#include <stdio.h>
#include <string.h>
#include <time.h>

struct Patient{  
  char fname[100];//first name
  char lname[100];//last name
  int dd,mm,yy;//bithday
  char sex[6];//sex(Male/Female/Do not wish to identify)
  int pdd,pmm,pyy;//date you for the shot
  int dnum;//dose number
  char vacctype[100];//type of vaccine
  char zip[6];//zipcode
};//holds the data of the users
int gAge(int pdate, int pmonth, int pyear, int bdate, int bmonth, int byear){
   int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//days per month
   if (bdate > pdate){//what to do if birth day is greater than dose day
      pdate = pdate + month[bmonth - 1];
      pmonth = pmonth - 1;
   }
   if (bmonth > pmonth){//what to do if birth month is greater than dose month
      pyear = pyear - 1;
      pmonth = pmonth + 12;
   }
   int fdate = pdate - bdate;//final date is equal to pdate-bdate 
   int fmonth = pmonth - bmonth;//final month is equal to pmonth-bmonth 
   int fyear = pyear - byear;//final year is equal to pyear-byear
   
   return fyear;//used to solve for the age
}
int main(void){
  struct Patient u1[10];
  int choice;
  char id[8];
  char age[2];
  int i;

  for(i = 0;i<10;i++){
    printf("Enter detail for %d person : \n",i+1);
    printf("Enter First Name : ");
    scanf("%s", u1[i].fname);//user inputs first name
    printf("Enter Last Name : ");
    scanf("%s", u1[i].lname);//user inputs last name
    printf("Enter Birth Date(mm/dd/yyyy) : ");
    scanf("%d/%d/%d",&u1[i].dd,&u1[i].mm,&u1[i].yy);//user inputs birthday
    printf("Choose sex : \n");
    printf("\t1. Male\n");
    printf("\t2. Female\n");
    printf("\t3. N/A\n\tEnter choice : ");
    scanf("%d", &choice);
    if(choice == 1)
      strcpy(u1[i].sex, "Male");
    else if(choice == 2)
      strcpy(u1[i].sex, "Female");
    else if(choice == 3)
      strcpy(u1[i].sex, "N/A");
    else{
      printf("Please choose valid sex.\n");
      return 1;
    }//makes sure user inputs a valid choice 
    printf("Enter Dose Number : ");
    scanf("%d", &u1[i].dnum);
    if(!(u1[i].dnum == 1 || u1[i].dnum == 2)){
      printf("Please enter valid dose number.\n");
      return 1;//user enter the dose number either 1 or 2
    }
    if(u1[i].dnum == 2){
      printf("Enter Your Last Dose Date(mm/dd/yyyy) : ");
      scanf("%d/%d/%d",&u1[i].dd,&u1[i].mm,&u1[i].yy);  
    }//checks the second dose
    printf("Choose type of vaccine : \n");
    printf("\t1. Pfizer\n");
    printf("\t2. Moderna\n");
    printf("\t3. Johnson&Johnson\n\tEnter choice : ");
    scanf("%d", &choice);//user choses on of the 3 vaccine types
    if(choice == 1)
      strcpy(u1[i].vacctype, "Pfizer");
    else if(choice == 2)
      strcpy(u1[i].vacctype, "Moderna");
    else if(choice == 3)
      strcpy(u1[i].vacctype, "Johnson&Johnson");
    else{
      printf("Please choose valid vaccine.\n");
      return 1;//make sure that the user selected a valid vaccine typr
    }
    printf("Enter Zip : ");
    scanf("%s", u1[i].zip);//user to input zipcode
    id[0] = u1[i].fname[0];
    id[1] = u1[i].lname[0];//copy first letter of first name and last name
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);//gets current time
    int ageTemp = gAge( tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900,u1[i].dd,u1[i].mm,u1[i].yy);//calculates the age
    id[2] = (char)(ageTemp/10+ '0');
    id[3] = (char)(ageTemp%10+ '0');//copies the age
    id[4] = u1[i].vacctype[0];//copies the vaccine type
    id[5] = u1[i].zip[3];
    id[6] = u1[i].zip[4];
    id[7] = u1[i].zip[5];//copes zip code
    printf("\nFirst Name : %s\n",u1[i].fname);
    printf("Last Name : %s\n",u1[i].lname);
    printf("Birthdate : %d/%d/%d\n",u1[i].mm,u1[i].dd,u1[i].yy);
    printf("Sex : %s\n",u1[i].sex);
    printf("Dose Number : %d\n",u1[i].dnum);
    if(u1[i].dnum == 2){
      printf("Previous Dose Date : %d/%d/%d\n",u1[i].pmm,u1[i].pdd,u1[i].pyy);
    }
    printf("Vaccine type : %s\n",u1[i].vacctype);
    printf("Zip : %s\n",u1[i].zip);
    printf("Code : %s\n\n",id);
  }//displays all the information on the patient 
  return 0;
}