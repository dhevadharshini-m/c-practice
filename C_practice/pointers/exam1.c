#include<stdio.h>

int main(){
    int arr[]={1,2,3};

   // int* ptr=&arr[0];
   int* ptr=arr;
    int val=90;
    for(int i=0;i<3;i++){
        *(arr+i)=val--;
    }
  //  sizeof(arr)=90; error as we cant assign a val to a methos, as it is not a lvalue
    for(int i=0;i<3;i++) printf("%d ",*(arr+i));
    printf("\n");
    return 0;
}