#include <iostream>
#include <stdio.h>

using namespace std;

void quickSort(int *,int,int);

int partition(int *, int,int);

int main()
{
    //int A[10]={6,10,13,5,3,3,2,25,4,11};
    int A[100];
    int index = 0;
    int value = 0;
    int p=0,q=99;

    cout <<"please input some number for sort:"<<endl; 
    while (value != -1 && index <= 99) {
        cin >> value;
        A[index++] = value;
    } 
    q = index-2;

    cout<<"======Original======="<<endl;
    for(int f=0; f<=q; f++)
        cout<<A[f]<<endl;

    quickSort(A,p,q);

    cout<<"======Sorted======="<<endl;
    for(int f=0; f<=q; f++)
        cout<<A[f]<<endl;
}

void quickSort(int *A, int p, int q) 
{
    int part;
    if (p < q) {
        part = partition(A, p, q);
        quickSort(A, p, part - 1);
        quickSort(A, part +1, q);
    }
}

int partition0 (int *A, int p, int q) {
    int i = p-1, j = q+1;
    int key = A[p];
    while (1) {
        while (--j && A[j] > key);
        while (++i && A[i] < key);
        if (i < j) {
            int temp = A[i];
            cout <<i << j << A[i] << A[j] << endl;
            A[i] = A[j];
            A[j] = temp;
        } else {
            break;
        }
    }   
    //return j;
    return (j < p)?p:j;
}

int partition2 (int *A, int p, int q) {
    int key = A[p];
    int i = p, j = q ;
    while (i < j) {
        while (j > i) {
            if (A[j] < key) {
                A[i++] = A[j];
                break;
            }
            j--;
        }
        while (i < j) {
            if (A[i] > key) {
                A[j--] = A[i];
                break;
            }
            i++;
       }
    }
    A[j] = key;
    return j;
}
void myswap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition(int *A, int p, int q) {
    int left = p;
    int key = A[q];
    for (int i = p; i <= q-1; i++) {
        if (A[i] <= key) {
            myswap(A[left], A[i]);
            left++;
        }
    }
    myswap(A[left], A[q]);
    return left;
}
int partition00(int *A, int p, int q) {
    int left = p - 1;
    int key = A[q];
    for (int i = p; i <= q-1; i++) {
        if (A[i] <= key) {
            left++;
            myswap(A[left], A[i]);
        }
    }
    myswap(A[left+1], A[q]);
    return left+1;
}

/*
int partition(int *A, int p, int q)
{
    int left = p;
    int key = A[p];
    int temp;
    for (int i = p + 1; i <= q; i++) {
        if (A[i] < key) {
            swap(&A[i], &A[left]);
            left ++;
        }
    }
    if (left != p) {
            temp = A[left];
            A[left] = A[p];
            A[p] = temp; 
    }
    return left;
}
*/

/*

void quickSort(int *A, int p, int q)
{
    int r;
    if (p < q) {
        r = partition(A, p, q);
        quickSort(A, p, r-1);
        quickSort(A, r+1, q);
    }
}
int partition(int *A, int p, int q)
{
    int check = A[p];
    int i = p, j;
    int temp;
    for (j = p+1; j <= q; j++) {
       if (A[j] <= check) {
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }

    if (i != p) {
        temp = A[i];
        A[i] = A[p];
        A[p] = temp;
    }
    
    return i;
}
 */

/*
void quickSort(int *A, int p,int q)
{
    int r;
    if(p<q)
    {
        r=partition(A, p,q);
        quickSort(A,p,(r-1)); //I think the problem is here this first quickSort call
                              // is reducing the value of r and hence value of q becomes
                              // less than p recursively. How can I separate both calls
                              // one for left and one for right sub array of the pivot. 
        quickSort(A,(r+1),q);
    }
}


int partition(int *A, int p,int q)
{
    int x= A[p];
    int i=p;
    int temp;
    int j;

    for(j=p+1; j<=q; j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            temp= A[j];
            A[j]=A[i];
            A[i]=temp;
        }

    }

    temp= A[p];
    A[p]=A[i];
    A[i]=temp;

    return i;
}
 */
