#include <cs50.h>
#include <stdio.h>
#include <string.h>


bool mastercard(long long int n, char str []);
bool amex (long long int n, char str []);
bool visa (long long int n, char str []);
bool luhn (long long int n, char str []);

int main(void){
    printf("Number: ");
   
    long long int credNum = get_long_long();
    char str[256];
    sprintf(str, "%lli", credNum);
    
    
    if(mastercard(credNum, str) == true){
        printf("MASTERCARD\n");
    }
    else if(amex(credNum, str) == true){
        printf("AMEX\n");
    }
    else if(visa(credNum, str) == true){
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
    }
    return 0;
    
    
}

bool mastercard(long long int n, char str []){
   
    if(strlen(str) == 16){
        if(str[0] == '5'){
            if(str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5'){
                if (luhn(n,str)){
                    return true;
                }
            }
        }
    }
    return false;
}

bool amex (long long int n, char str []){
     if(strlen(str) == 15){
        if(str[0] == '3'){
            if(str[1] == '4' || str[1] == '7'){
                if (luhn(n,str)){
                    return true;
                }
            }
        }
    }
    return false;
    
}

bool visa (long long int n, char str []){
     if(strlen(str) == 13 || strlen(str) == 16){
        if(str[0] == '4'){
            if (luhn(n,str)){
                return true;
            }
        }
    }
    return false;
    
}

bool luhn (long long int n, char str []){
    int dub = 0;
    int sing = 0;
    for(int i = 0; i < strlen(str); i++ ){
        if(i%2 == 0){
            sing = sing + n%10;
            n = n/10;
            
        }
        else{
            int digit = 2*(n%10);
            
            dub = dub + (digit%10 + digit/10);
            n = n/10;
            
        }
    }
    
    if((sing+dub)%10 == 0){
        return true;
    }
    else return false;
    
    
}