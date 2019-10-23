#include <iostream>
#include <string.h>

using namespace std;

long int decimal(char *num, long int base, int tam) {
    long int b_dec = 0;
    long int bas = 1;
    for(int i = tam-1; i >= 0; i--) {
        if(num[i] >= '0' and num[i] <= '9')
            b_dec += (num[i]-'0')*bas;
        else
            b_dec += (num[i]-'A'+10)*bas;
        bas*= base;
    }
    return b_dec;
}

void comprobar_base(char *num_a , char *num_b,int base_a , int base_b , int tam1 , int tam2){
    bool comp = true;
    int i;
    for(base_a; base_a <= 36; base_a++) {
        for( i = base_b; i <= 36; i++) {
            if(decimal(num_a, base_a, tam1) == decimal(num_b, i, tam2)) {
                cout<<num_a<<" (base "<<base_a<<") = "<<num_b<<" (base "<<base_b<< ")\n";
                comp  = false;
                return;
            }
        }
    }
    if(comp== true){
        cout<<num_a<<" is not equal to "<<num_b<<" in any base 2..36\n";
        return;}

}

void bases(char *num, int tam , int base){
    for(int i = 0; i < tam; i++) {
        if(num[i] >= '0' && num[i] <= '9')
            if(base > num[i]-'0' )
                base = base;
            else
                base = num[i]-'0';
        else
            if(base > num[i]-'A'+10)
                base = base;
            else
                base =num[i]-'A' + 10;
    }
}

int main() {
    char num1[50], num2[50];
    while(scanf("%s %s", num1, num2) == 2) {
        int tam1 = strlen(num1), tam2 = strlen(num2);
        bool comp = true;
        int base1 = 1;
        int base2 = 1;
        bases(num1,tam1,base1);
        for(int i = 0; i < tam2; i++) {
            if(num2[i] >= '0' && num2[i] <='9')
                if(base2 > num2[i]-'0')
                    base2 = base2;
                else
                    base2 =num2[i]-'0';
            else
                if(base2 > num2[i]-'A'+10)
                    base2 = base2;
                else
                    base2 =num2[i]-'A'+10;
        }
        base1++;
        base2++;
        comprobar_base(num1,num2,base1,base2,tam1,tam2);
    }
    return 0;
}