#include <iostream>
using namespace std;

int Partition(int *arr, int p, int q){
    int x = arr[p];
    int i = p;
    for(int j = p+1; j <= q; j++){
        if(arr[j] <= x){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;


        }
    }
    int temp = arr[i];
    arr[i] = arr[p];
    arr[p] = temp;
    return i;
}

void Quicksort(int *arr, int p, int r){
    if(p < r){
        int q = Partition(arr, p , r);
        Quicksort(arr, p, q-1);
        Quicksort(arr, q+1, r);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Quicksort(arr, 0, n-1);

    int min = arr[1] - arr[0];
    for(int i = 1; i < n-1; i++){
        int temp = arr[i+1] - arr[i];
        if(temp < min){
            min = temp;
        }
    }

    cout << min << endl;
}
