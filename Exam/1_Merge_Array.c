#include <stdio.h>

void main(){
    int s1,s2,i,j;
    printf("Enter the size of the array 1: ");
    scanf("%d",&s1);
    int arr1[s1];
    for(i=0;i<s1;i++){
        scanf("%d",&arr1[i]);
    }
    for(i=0;i<s1;i++){
        for(j=i+1;j<s1;j++){
            if(arr1[i]>arr1[j]){
                int temp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;
            }
        }
    }
    printf("Enter the size of the array 2: ");
    scanf("%d",&s2);
    int arr2[s2];
    for(j=0;j<s2;j++){
        scanf("%d",&arr2[j]);
    }
    for(i=0;i<s2;i++){
        for(j=i+1;j<s2;j++){
            if(arr2[i]>arr2[j]){
                int temp=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;
            }
        }
    }
    int merged[s1+s2];
    int k=0;
    i=0;
    j=0;
    while (i < s1 && j < s2){
        if (arr1[i]<arr2[j]){
            merged[k++]=arr1[i++];
        }
        else{
            merged[k++]=arr2[j++];
        }
    }   
    while (i<s1){
        merged[k++]=arr1[i++];
    }
    while (j<s2){
        merged[k++]=arr2[j++];
    }
    printf("The merged array is: ");
    for (i=0;i<s1+s2;i++){
        printf("%d",merged[i]);
    }
}    