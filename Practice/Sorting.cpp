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
    int n, k;
    cin >> n;
    int arr[n];
    cin >> k;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Quicksort(arr, 0, n-1);

    for(int i = k-1; i < n; i+= k){
        cout << arr[i] << endl;
    }
}
