#include <iostream>
#include <iomanip>
using namespace std;

void opt_bubble(int arr[],int length){
    bool noSwaps;
    for(int i = length-1; i > 0; i--) {
        noSwaps = true;
        if (arr[i-1] > arr[i]) {
            int temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
            noSwaps = false;
        }
        if (noSwaps) return; 
    }

}

double findMedian(int arr[], int num, int index){
    arr[index] = num;
    cout << "Taking " << num<< endl;
    opt_bubble(arr, index + 1);
    if ((index + 2) % 2 == 0){
        return arr[((index + 2) / 2)-1];
    }
    else{
        double avg = (arr[((index + 2) / 2)-1] + arr[(index + 2) / 2]) / 2.0;
        return avg;
    }
}
int main()
{
    cout << "Enter Stream length : ";
    int length;
    cin >> length;
    int arr[length];
    cout << "Enter values one by one of the stream  " << endl;
    int n;

    for (int i = 0; i < length; i++){
        cin >> n;
        arr[i] = n;
    }
    
    int medianArr[length];
    
    for (int index = 0; index < length; index++){
        double med = findMedian(medianArr, arr[index], index);
        printf("Current meadian of the running list : %.1f \n", med);
    }
    return 0;
}
