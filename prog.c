#include"server.h"
//The input function takes the details of the bug from the user and stores it into the struct variable logger
void input()
{     
    srand(time(NULL));//The id is generated randomly
    logger.id=rand();
    printf("Please enter the details of the bug\n");
    fgets(logger.description,50,stdin);
    strtok(logger.description, "\n");//The strtok function removes the trailing new line character from fgets
    printf("Enter your Name\n");
    fgets(logger.name,max,stdin);
    strtok(logger.name, "\n");
    printf("Enter the type of bug - Major,Minor,Cosmetic\n");
    fgets(logger.type,max,stdin);
    strtok(logger.type, "\n");
    printf("Enter the priority of bug - Low,Medium,High\n");
    fgets(logger.priority,max,stdin);
    strtok(logger.priority, "\n");
    strcpy(logger.status,"Notassigned");//The status is defaulted to Not assigned 
    strcpy(logger.time,asctime(local));//The present time is taken
}
/*The read funtion reads from the file and displays it to the manager 
It filters the bugs by name, category, status and dispays it the the prompt
It also asks if the file has to cleared*/
void read()
{
    int choice;
    char name[10],priority[20],status[20];
    FILE *infile;   
    infile = fopen ("person.txt", "r"); 
    if ((infile == NULL)) //If the file is empty then it diplays the error message
    { 
        fprintf(stderr,"\nNo Bugs\n"); 
        exit (1); 
    }
    printf("How would you like to filter the bugs\n1)Same person\n2)Same priority\n3)Same status\n4)All the bugs\n");
    scanf("%d",&choice);
    printf("\n");
    /*According to the choice the bugs are displayed*/
    switch (choice)
    {
    case 1:
        printf("Enter name\n");
        scanf("%s",name);
        while(fread(&logger, sizeof(struct bug), 1, infile))
            if(strcmp(logger.name, name) == 0)
                 printf ("id = %d \nstatus = %s \nname=%s \ntype=%s \npriority=%s \ndescription=%s\ntime=%s\n\n",
                      logger.id,logger.status, logger.name,logger.type,logger.priority,logger.description,logger.time); 
        break;
    case 2:
        printf("Enter priority\n");
        scanf("%s",priority);
        while(fread(&logger, sizeof(struct bug), 1, infile))
            if(strcmp(logger.priority, priority) == 0)
                 printf ("id = %d \nstatus = %s \nname=%s \ntype=%s \npriority=%s \ndescription=%s\ntime=%s\n\n",
                      logger.id,logger.status, logger.name,logger.type,logger.priority,logger.description,logger.time); 
        break;
    case 3:
        printf("Enter status\n");
        scanf("%s",status);
        while(fread(&logger, sizeof(struct bug), 1, infile))
            if(strcmp(logger.status, status) == 0)
                 printf ("id = %d \nstatus = %s \nname=%s \ntype=%s \npriority=%s \ndescription=%s\ntime=%s\n\n",
                      logger.id,logger.status, logger.name,logger.type,logger.priority,logger.description,logger.time); 
    default:
        while(fread(&logger, sizeof(struct bug), 1, infile))
                printf ("id = %d \nstatus = %s \nname=%s \ntype=%s \npriority=%s \ndescription=%s\ntime=%s\n\n",
                      logger.id,logger.status, logger.name,logger.type,logger.priority,logger.description,logger.time); 
        break;
    } 
    fclose (infile);  
    char s[10];
    printf("Do you want to clear the file?\n");//The file is deleted if the manager wishes so
    scanf("%s",s);
    if(strcmp(s,"yes")==0)
        remove("person.txt");         
}
/*The write function will update the person.txt file with the bug information entered by the user*/
void write()
{
    FILE *outfile; 
    outfile = fopen ("person.txt", "a"); 
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }  
    fwrite (&logger, sizeof(struct bug), 1, outfile);   
    if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n");  
    fclose (outfile); 
}
/*The change function will upadate the staus of the bug which can be changed by the employee*/
void change()
{   
    FILE *infile,*cha;   
    infile = fopen ("person.txt", "r");
    char cho[10];
    if ((infile == NULL)) //If the file is empty then it diplays the error message
    { 
        fprintf(stderr,"\nNo Bugs\n"); 
        exit (1); 
    }
    cha=fopen("change.txt","w");//A new file is created for the updated inforamation 
    printf("How would you like to change the status?\n1)Being_fixed\n2)Fixed\n3)Delivered\n4)Assigned\n");
    scanf("%s",cho);
    while(fread(&logger, sizeof(struct bug), 1, infile))
    {   
        strcpy(logger.status,cho);
        fwrite (&logger, sizeof(struct bug), 1, cha);
    }  
    fclose(infile);
    fclose(cha);
}

