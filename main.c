#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_PASS_SIZE 100


typedef struct pcheck *passCheck;


struct pcheck{
    int val;
    passCheck next;
}pcheck;



char password[MAX_PASS_SIZE];
int validPass=0;
int Ecount=1;
passCheck first=NULL;
passCheck InsRear(int value){
    passCheck temp=(passCheck)malloc(sizeof(pcheck));
    temp->val=value;
    temp->next=NULL;
    passCheck curr=first;
    if(first==NULL){
        return temp;
    }while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return first;
    
}
void passChecker(char Pass[]){
    for(int i=0;i<5;i++){
        if(i==0){
            for(int j=0;j<strlen(Pass);j++){
                if(isdigit(Pass[j])){
                    first=InsRear(1);
                    break;
                }if(j==strlen(Pass)-1){
                    first=InsRear(0);       
                }
            }
        }else if(i==1){
            for(int j=0;j<strlen(Pass);j++){
                if(islower(Pass[j])){
                    first=InsRear(1);
                    break;
                }if(j==strlen(Pass)-1){
                    first=InsRear(0);       
                }
            }
        }else if(i==2){
            for(int j=0;j<strlen(Pass);j++){
                if(isupper(Pass[j])){
                    first=InsRear(1);
                    break;
                }if(j==strlen(Pass)-1){
                    first=InsRear(0);       
                }
            }
        }
        else if(i==3){
            for(int j=0;j<strlen(Pass);j++){
                if(isspace(Pass[j])){
                    first=InsRear(0);
                    break;
                }if(j==strlen(Pass)-1){
                    first=InsRear(1);       
                }
            }
        }
        else if(i==4){
            for(int j=0;j<strlen(Pass);j++){
                if(Pass[j] == '/'){
                    first=InsRear(0);
                    break;
                }if(j==strlen(Pass)-1){
                    first=InsRear(1);       
                }
            }
        }

    }
}

int passwordValidator(){
    passCheck curr=first;
    int check=1;
    while(curr!=NULL){

        Ecount++;
        if(curr->val==0){
            check=0;
            return check;
        }
        curr=curr->next;
    }return check;
    
}



void main(){

    	
    printf("Welcome to Mr. Robot's Website Password Creation Portal: ");

    printf("Please follow the following rules in order to have a \"Strong Password\"\n");
    printf("The Password Must Contain: \n");
    printf("\n1. At least one Numeric Digit. \
            \n2. At least one Small or Lowercase letter. \
            \n3. At least one Capital or Upper case letter\
            \n4. Must not have White Space\
            \n5. Must not have Slash(/)\
            \n6. Atleast of 6 charcters\n");
            printf("\n");

    printf("\n");

    printf("Please Enter Your password : ");
    scanf("%[^\n]",password);

    if(strlen(password)<=6){
        validPass=0;
        printf("Invalid Password!\n");
        printf("Password Must have 6 characters\n");

    }else{
        passChecker(password);
        validPass=passwordValidator();
        passCheck curr=first;
        
        if(validPass){
            printf("Password is valid!\n");
        }else{
            printf("Password is Invalid!\n");
            switch (Ecount)
            {
            case 1:printf("Password Must have at least one Numeric Digit.\n ");
                break;
            case 2:printf("Password Must have at least one Smaller or Lowercase character.\n ");
                break;
            case 3:printf("Password Must have at least one Capital or Uppercase character.\n ");
                break;
            case 4:printf("Password Must not contain any WhiteSpace.\n ");
                break;
            case 5:printf("Password Must not have Slash(/). \n");
                break;
            }
            
        }

    }
}
