#include "sort.h"

void swap(int *v,int i, int j)
{
    int aux = v[i];
    v[i] = v[j],v[j] = aux;
}

void shellsort(int *v,int N)
{
    int h = 1,temp,j;
    while(h<N)h = 3*h+1;
    while(h!=1)
    {
        h = h/3;
        for( int i = h; i < N;i++)
        {
            j = i,temp = v[i];
            while(j>=h && v[j-h] > temp)
                v[j] = v[j-h],j -= h;
            v[j] = temp;
        }
    }
}

int partition(int *v,int left,int right)
{
    int i = left,pivot = v[i];
    for(int j = i+1;j<=right;j++)
        if(pivot>v[j])
            swap(v,++i,j);
    swap(v,left,i);
    return i;
}

void quicksort(int *v,int left, int right)
{
    if(left<right)
    {
        int index = partition(v,left,right-1);
        quicksort(v,left,index);
        quicksort(v,index+1,right);
    }
}

void heap(int *v,int index, int N)
{
    int i = index*2+1;
    if(i<N)
    {
        heap(v,i,N);
        if(i+1<N)
        {
            heap(v,i+1,N);
            if(v[i]<v[i+1])
                i++;
        }
        if(v[index]<v[i])
        {
            swap(v,i,index);
            heap(v,index,N);   
        }
    }
}

void heapsort(int *v,int N)
{
    int index = N;
    while(--index)
    {
        heap(v,0,index);
        swap(v,0,index);
    }
}