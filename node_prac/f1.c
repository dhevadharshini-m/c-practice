void fibo(int n){
    int a=1;
    int b=1;
    int c;
    printf("Fibonacci series: ");
    printf("%d %d ", a, b);
    for(int i=0;i<n;i++){
        c=a+b;
        printf("%d ", c);
        a=b;
        b=c;
    }
}

void fun(int* x){
    *x = 100; 
}

int sum(int n){
    if(n<=0){
        return 0;
    }
    return n+sum(n-1);
}
int main(){
    int n=10;
    // fibo(n);
    printf("Sum of first %d natural numbers: %d\n", n, sum(n));
    printf("\n");
    double p=9.0;
    for(int i=0;i<10;i++){
        p=p*7.1;
        if(p<=16){
            continue;
        }
        printf("Value of p after %d iterations: %.lf\n", i+1, p);
    }
    printf("\n");
    printf("Final value of p: %.lf\n", p);
    printf("End of the program.\n");

    int arr[5];
    for(int i=0; i<5; i++){
        arr[i] = i+1; // Example initialization
    }
    arr[2]=908;
    for(int i=0; i<5; i++){
        printf("Array element %d: %d\n", i, arr[i]);
    }

    int val=90;
    fun(&val);
    printf("Value of val after fun: %d\n", val);

    int c=4;
    int s=2;
    c<<s;
    printf("%d\n",c);
    return 0;
}