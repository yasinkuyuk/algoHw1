#include <iostream>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

void quicksort(string[],int,int);
int divide(string[],int,int);
bool alphabetPresedence(string,string);

int main(){
    string strList[10] = {"selam","bana","nasil","kelime","hediye","sakal","ceviz","kolye","onluk","cam"};
    //int arr[10] = {3,92,35,2,78,5,61,72,88,68};

    quicksort(strList,0,9);
    //quicksort(arr,0,9);

    for(int i=0; i<10; i++){
        //cout << arr[i]<<" ";
        cout << strList[i]<<" ";
    }

    return EXIT_SUCCESS;
}

bool alphabetPresedence(string first,string second){ //does first string comes after from second string func
    int firstLength = first.length(); //5
    int secondLength = second.length(); //7
    int minimum = min(firstLength,secondLength);
    bool temp = false;

    for(int i=0; i<minimum; i++){ //[0,5)
        if(first[i] == second[i]){
            if(i == minimum-1 && firstLength == secondLength){
                if(firstLength > secondLength){
                    temp = true;
                }
                break;
            }
            continue;
        }

        if(first[i] > second[i]){
            temp = true;
            break;
        }
        else{
            break;
        }
    }
    return temp;
}

int divide(string arr[], int start, int end){
    string pivot = arr[start];
    //string pivot =arr[start];

    int i = start;

    for(int j = start+1; j<=end; j++ ){
        if(alphabetPresedence(arr[j],pivot)){
            i++;
            swap(arr[i],arr[j]);
        }
        /* if(pivot > arr[j]){
            i++;
            swap(arr[i],arr[j]);
        } */
    }

    swap(arr[start], arr[i]);

    return i;
}

void quicksort(string arr[],int start,int end){
    if(start < end){
        int pivot = divide(arr,start,end);

        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
}
 

