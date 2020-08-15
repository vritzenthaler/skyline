#include <iostream>
#include <string>
#include <math.h>
#include "skyline.h"

using namespace std;

int main(int argx, char* argv[]){
    int n = 5;
    Skyline A(n);

    // A.set_coeff(0,0, 1);
    // A.set_coeff(0,2, 6);
    // A.set_coeff(1,2, 7);
    // A.set_coeff(1,1, 2);
    // A.set_coeff(2,2, 3);
    // A.set_coeff(3,3, 4);
    // A.set_coeff(4,4, 5);
    // A.set_coeff(3,4, 4);
    // A.set_coeff(2,4, 3);

    for(int i=0; i<n; i++){
        A.set_coeff(i,i, 2.);
        if(i<n-1){A.set_coeff(i,i+1, -1.);}
        if(i>=1){A.set_coeff(i-1,i, -1);}
    }

    // int k = 1;
    // for(int i=n-1; i>=0; i--){
    //     for(int j=n-1; j>=i; j--){
    //         // A.set_coeff(i,j,k);
    //         A.set_coeff(i,j,k);
    //         k++;
    //     }
    // }

    // A.set_coeff(0,0,1);
    // A.set_coeff(1,1,1);
    // A.set_coeff(2,2,1);
    // A.set_coeff(1,2,3);
    // A.set_coeff(0,2,1);
    // A.set_coeff(3,4,2);
    // A.set_coeff(3,3,3);
    // A.set_coeff(2,4,3);
    // A.set_coeff(2,3,5);
    // A.set_coeff(2,2,6);
    // A.set_coeff(1,4,4);
    // A.set_coeff(0,4,5);
    // A.set_coeff(1,3,8);
    // A.set_coeff(1,2,9);
    // A.set_coeff(1,1,10);

    cout << "" << endl;
    A.print();

    cout << "" << endl;
    A.factoLU();

    A.print();

    return 0;
}
