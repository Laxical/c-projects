#include<stdio.h>

int power(int a,int b){
    int num=1;
    for(int i=0;i<b;i++)
        num = num*a;
    return num;
}

int isPrime(int n){
    if(n==1||n==0)
        return 0;

    if(n==2)
        return 1;

    else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0)
                return 0;
        }
        return 1;
    }
}

int fib(int n){
    if(n==0||n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

int palindrome(int n){
    int temp,sum = 0;
    temp = n;

    while(temp>0){
        sum = sum*10 + (temp%10);
        temp = temp/10;
    }

    if(sum == n)
        return 1;
    else 
        return 0;
}

int flipnum(int n){
    int sum = 0;
    while(n>0){
        sum = sum*10 + (n%10);
        n = n/10; 
    }
    return sum;
}

int factorial(int n){
    if(n==0||n==1)
        return 1;
    else
        return n*factorial(n-1);
}

int armstrong(int n){
    int sum = 0;
    while(n>0){
        sum = sum + power(n%10,3);
        n = n/10;
    }
    return sum;
}

int sumOfDigits(int n){
    int sum=0;
    while(n>0){
        sum = sum + n%10;
        n = n/10;
    }
    return sum;
}

int main(){
    int n,option;
    while(1){
        printf("\nSelect a option:\n1) Print Prime numbers upto n\n2) check if Prime\n3) Print fibanocci numbers\n4) Check Palindrome\n5) flip number\n6) factorial\n7) Check if Armstrong\n8) Sum of the digits\n9) Exit\n");
        scanf("%d",&option);
        
        if(option == 9)
            break;
        
        printf("Enter a number: ");
        scanf("%d",&n);
        
        if(option == 1){
            for(int i=0;i<=n;i++){
                if(isPrime(i))
                    printf("%d ",i);
            }
            printf("\n");
        }

        else if(option == 2){
            if(isPrime(n))
                printf("%d is a Prime number\n",n);
            else
                printf("%d is NOT a Prime number\n",n);
        }
        
        else if(option == 3){
            for(int i=0;i<n;i++){
                printf("%d ",fib(i));
            }
            printf("\n");
        }
        
        else if(option == 4){
            if(palindrome(n))
                printf("%d is a palindrome\n",n);
            else
                printf("%d is not a palindrome\n",n);
        }
        
        else if(option == 5)
            printf("reversed number = %d\n",flipnum(n));

        else if(option == 6)
            printf("factorial of %d is %d\n",n,factorial(n));

        else if(option == 7){
            if(n == armstrong(n))
                printf("%d is an armstrong number\n",n);
            else
                printf("%d is not an armstrong number\n",n);
        }

        else if(option == 8)
            printf("Sum of the digits of %d = %d\n",n,sumOfDigits(n));
    }

    return 0;
}
