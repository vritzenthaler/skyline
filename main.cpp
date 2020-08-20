#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <unistd.h>
#include "skyline.h"

using namespace std;

#define MIN_SIZE 3
#define MAX_SIZE 10000

void test(void){
    int n, i;

    for(n=MAX_SIZE; n<MAX_SIZE+1; n++){
        cout << "TEST FOR n = " << n << endl;
        Skyline A(n);
        for(i=0; i<n; i++){
            A.set_coeff(i,i, 2.);
            if(i<n-1){
                A.set_coeff(i,i+1, -1.);
                A.set_coeff(i+1,i, -1);
            }
        }
        for(i=0; i<n; i++){
            if(A.get_coeff(i,i) != 2){
                cout << "ERROR" << endl;
                exit(1);
            }
            if(i<n-1){
                if(A.get_coeff(i,i+1)!=-1){
                    cout << "ERROR" << endl;
                    exit(1);
                }
                if(A.get_coeff(i+1,i)!=-1){
                    cout << "ERROR" << endl;
                    exit(1);
                }
            }
        }
    }

    cout << "TEST DONE SUCCESSFULLY!" << endl;
}

void test_solver(void){
    int n = 1000;
    Skyline A(n);

    for(int i=0; i<n; i++){
        A.set_coeff(i,i, 2.);
        if(i<n-1){
            A.set_coeff(i,i+1, -1.);
            A.set_coeff(i+1,i, -1);
        }
    }

    // usleep(4000*1000);
    cout << "" << endl;
    // A.print();

    cout << "" << endl;
    A.factoLU();

    // A.print();

    // double* x = new double[n];
    // double* b = new double[n];
    //
    // for(int i=0; i<n; i++){
    //     b[i] = 1;
    // }
    //
    // A.solve(x, b);

    // cout << endl;
    // cout << "b = ";
    // for(int i=0; i<n; i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    //
    // cout << "x = ";
    // for(int i=0; i<n; i++){
    //     cout << x[i] << " ";
    // }
    // cout << endl;

}

int main(void){

    // test();

    test_solver();

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

    return 0;
}
