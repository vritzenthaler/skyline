#include <iostream>
#include <string>
#include <math.h>
#include "skyline.h"

using namespace std;

int main(int argx, char* argv[]){
    int n = 3;
    Skyline A(n);

    for(int i=0; i<n; i++){
        A.set_coeff(i,i, 2.);
        if(i<n-1){
            A.set_coeff(i,i+1, -1.);
            A.set_coeff(i+1,i, -1);
        }
    }

    // for(int i=0; i<n; i++){
    //     A.set_coeff(i,i, 1.);
    // }

    // int k = 1;
    // for(int i=n-1; i>=0; i--){
    //     for(int j=n-1; j>=i; j--){
    //         // A.set_coeff(i,j,k);
    //         A.set_coeff(i,j,k);
    //         k++;
    //     }
    // }

    // int k = 1;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=i; j++){
    //         A.set_coeff(i,j,k);
    //         k++;
    //     }
    // }

    // int k = 1;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         A.set_coeff(i,j,k);
    //         k++;
    //     }
    // }

    cout << "" << endl;
    A.print();

    cout << "" << endl;
    A.factoLU();

    A.print();

    double* x = new double[n];
    double* b = new double[n];

    for(int i=0; i<n; i++){
        b[i] = 1;
    }

    A.solve(x, b);

    cout << endl;
    cout << "b = ";
    for(int i=0; i<n; i++){
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "x = ";
    for(int i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}
