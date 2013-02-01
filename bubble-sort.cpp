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
    
    //bubble sort
    int tmp;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(numbers[j] > numbers[j+1]) {
                tmp = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = tmp;
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
