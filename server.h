#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 20
struct tm* local;
struct bug  
{ 
    int id; 
    char status[20]; 
    char name[20];
    char type[20];
    char priority[20];
    char description[50]; 
    char time[20]; 
}logger;//the struct variable has the above attributes
void read();
void write();
void change();
void input();