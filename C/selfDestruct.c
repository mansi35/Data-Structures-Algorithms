#include<stdio.h> 
#include<stdlib.h> 
  
int main(int argc, char *argv[]) 
{ 
    printf("This program will be destroyed after execution and would need to be compiled again to execute again \n"); 

    remove(argv[0]);     
    return 0; 
}