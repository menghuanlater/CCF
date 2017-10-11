#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;

    const int singlePrice = 10;

    int max5,total5 = 0;

    max5 = n/(5*singlePrice);

    total5 = max5*7;

    n = n - max5*5*singlePrice;

    int max3,total3 = 0;

    max3 = n/(3*singlePrice);

    total3 = max3*4;

    n = n - max3*3*singlePrice;

    int total1 = n/10;

    cout<<total1+total3+total5<<endl;

    return 0;
}
