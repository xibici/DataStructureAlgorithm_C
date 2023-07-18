#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void prinArr(int arr[], int n);
int is_sorted(const int arr[], int n);

int is_sorted(const int arr[], int n) {//假如有一个不是
    for (size_t i = 0; i < n-1; i++) if (arr[i] > arr[i + 1]) return 0;
    return 1;
}

//八大排序 先是基础
void bubbleSort(int arr[],int n) {
    int comCount=0 , swapCount = 0;
    for (size_t i = 0; i < n-1; i++)
    {
        int tmp;
        //mode1
        /*for (size_t j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j +1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }*/
        ////mode2
        //for (size_t i = 0; i < n-1; i++)
        //{
        //    int tmp;
        //    for (size_t j = n-1-i; j >0; j--)
        //    {
        //        if (arr[j]<arr[j-1]) {
        //            tmp = arr[j - 1];
        //            arr[j - 1] = arr[j];
        //            arr[j] = tmp;
        //        }
        //    }
        //}
        //mode3
        char c = '-';
        int exChange = 0;
        printf("パス%d:\n", i+1);
        for (size_t j = n - 1; j > i; j--)
        {
            comCount++;
            c = '-';
            if (arr[j - 1] > arr[j]) {
                exChange = 1;
                swapCount++;
                c = '+';
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
            for (size_t i = 0; i < n; i++)
            {
                printf(i==j-1?"%d%c":"%d ", arr[i], c);
            }
            printf("\n");

        }
        if (exChange == 0) break;
        printf("\n");
    }
    printf("\n交换了%d次, 比较了%d次\n",swapCount,comCount);

}

void insertSort(int arr[], int n) {
    int tmp=0, j=0;
    for (size_t i = 1; i < n; i++)
    {
        tmp = arr[i];
        for ( j = i-1; j >=0 && arr[j] > tmp; j--)
        {
                arr[j + 1]= arr[j ];
        }
        arr[j+1 ] = tmp;
    }

}
void selectSort(int arr[], int n) {

    for (size_t i = 0; i < n; i++)
    {
        int minIndex=i;
        for (size_t j = i; j < n; j++)
        {
            if (arr[j]<arr[minIndex] ) {
                minIndex = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }


}

void prinArr(int arr[], int n) {
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}

int doBubble() {
    int n = 7;
    int arr[] = { 6,4,3,7,1,9,8 };
    int f = is_sorted(arr, 7);
    //prinArr(arr,7);
    bubbleSort(arr, sizeof(arr) / sizeof(int));
    //prinArr(arr, 7);
    f = is_sorted(arr, 7);
    printf("是%d  1升顺0不是\n\n", f);

    system("pause");
}

int doSelect() {
    int arr[] = { 6,4,3,7,1,9,8 };
    prinArr(arr, 7);
    insertSort(arr, 7);
    prinArr(arr, 7);
}

int main()
{
    //doBubble();
    //doSelect();


    double a = 1.0;
    printf("E%4.1lfE", a);
    int a = 10;
    int arr[a];

    return EXIT_SUCCESS;
}