#include"server.h"
void main()
{   
    time_t t = time(NULL);
    local = localtime(&t);//local time is assigned 
    char s[10];
    printf("-----------BUG TRACKING SYSTEM-------------\n");
    printf("Enter your designation\n1)Manager\n2)User\n3)Employee\n");
    scanf("%s",s);//The user enters the designation and is redirected accordingly
    fflush(stdin);
    if((strcmp(s, "manager") == 0)||(strcmp(s,"1")==0))   
    {
      read();
    } 
    else if ((strcmp(s, "user") == 0)||(strcmp(s,"2")==0))
    {
      input();
      write();
    }    
    else if ((strcmp(s, "employee") == 0)||(strcmp(s,"3")==0))
    {
      change(); 
      remove("person.txt");//remove removes the original unupdated file  
      rename("change.txt","person.txt"); //renames the changed file name to original
    }    
    else
    {
      printf("Please renter");
    }
    
}


