#include <stdio.h>
void selectionsort(int *,int);
void swap(int*,int*);
int main()
{
    int a[] = {12,23,12,44,34,65,2,3};
    int n = sizeof(a)/sizeof(a[0]);
    selectionsort(a,n);
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
void selectionsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        swap(&a[min],&a[i]);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b =temp;
}