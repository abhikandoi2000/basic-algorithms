#include<iostream>
using namespace std;
void swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}
int main() {
    int n;
    //input
    cout<<"Enter the no. of numbers you want to sort:";
    cin>>n;
    cout<<"Enter "<<n<<" numbers to be sorted:"<<endl;
    int *numbers = new int[n];
    for(int i = 0; i < n; ++i) {
        cin>>numbers[i];
    }    
    
    //insertion sort
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
    
    //output
    cout<<"The numbers in sorted order are:"<<endl;
    for(int i = 0; i < n; ++i) {
        cout<<numbers[i]<<endl;
    }
    
    system("pause");
    return 0;	//no errors
}
