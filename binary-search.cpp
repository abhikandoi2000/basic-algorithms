#include<iostream>
using namespace std;
void insertion_sort(int *numbers, int n);
bool binary_search(int num, int *numbers, int begin, int end);
int main() {
    int n, num;
    //input
    cout<<"Enter the no. of numbers:";
    cin>>n;
    cout<<"Enter "<<n<<" numbers:"<<endl;
    int *numbers = new int[n];
    for(int i = 0; i < n; ++i) {
        cin>>numbers[i];
    }
    cout<<"Enter the number to be searched for:";
    cin>>num;
    
    //sorting in ascending order
    insertion_sort(numbers, n);
    
    //binary search
    int element_found = binary_search(num, numbers, 0, n - 1);
    
    //output
    if(element_found) {
        cout<<"Element found!"<<endl;
    } else {
        cout<<"Element is not present in the array."<<endl;
    }
    
    return 0;	//no errors
}

/*
 * Functions
*/

//insertion sort
void insertion_sort(int *numbers, int n) {
    int num;
    for(int i = 1; i < n; ++i) {
        num = numbers[i];
        if(num < numbers[0]) {		//min element
                //shift right by one
                for(int k = i - 1; k >= 0 ; --k) {
                    numbers[k+1] = numbers[k];
                }
                numbers[0] = num;
        } else if(num > numbers[i-1]) {		//max element
            continue;
        } else {		//element somewhere in between
            for(int j = i - 1; j >= 0; --j) {
                numbers[j+1] = numbers[j];
                if(num >= numbers[j]) {
                    numbers[j+1] = num;
                    break;
                }
            }
        }
    }
}
//9 in 0 3 4 5 6
//9 in 5 6
//9 in 6
//search for num in numbers from begin to end
bool binary_search(int num, int *numbers, int begin, int end) {
    int mid = (begin + end)/2;
    
    //base case
    if(begin == end) {
        if(numbers[begin] == num) {
            return true;
        } else {
            return false;
        }
    }
    
    if(numbers[mid] == num) {
        return true;
    } else if(num > numbers[mid]) {
        return binary_search(num, numbers, mid + 1, end);
    } else {
        return binary_search(num, numbers, begin, mid - 1);
    }
}
