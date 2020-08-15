#include <iostream>
#include <stdlib.h> // realloc, free, exit ...
#include "skyline.h"

using namespace std;

Skyline::Skyline(int dim){
    m_dim = dim;
    m_coeff_size = dim;
    m_coeff = new double[dim];
    m_index = new int[dim+1];

    int i=0;
    for(; i<dim; i++){
        m_coeff[i] = 0.;
    }
    cout << "index = ";
    for(i=0; i<dim+1; i++){
        cout << i << " ";
        m_index[i] = i;
    }
    cout << endl;
}

void Skyline::set_coeff(int i, int j, double const &val){
    if(i>j){
        int tmp = j;
        j = i;
        i = tmp;
    }

    if((j-i)<(m_index[j+1]-m_index[j])){
        m_coeff[m_index[j]+(j-i)] = val;
    }else{
        if(i==j){
            m_coeff[m_index[j]] = val;
        }else{
            int n_to_alloc = (j-i)-(m_index[j+1]-m_index[j]-1);
            m_coeff_size += n_to_alloc;

            double *new_coeff = new double[m_coeff_size];

            int k, idx, d=0;

            for(k=0; k<j; k++){
                for(idx=m_index[k]; idx<m_index[k+1]; idx++){
                    new_coeff[idx] = m_coeff[idx];
                }
            }

            for(idx=m_index[j]; idx<m_index[j+1]+n_to_alloc; idx++){
                if(idx<m_index[j+1]){
                    new_coeff[idx] = m_coeff[idx];
                }else{
                    new_coeff[idx] = 0.;
                }
            }
            new_coeff[idx-1] = val;

            for(k=j+1; k<m_dim+1; k++){
                m_index[k] = m_index[k] + n_to_alloc;
            }

            for(k=j+1; k<m_dim; k++){
                for(idx=m_index[k]; idx<m_index[k+1]; idx++){
                    new_coeff[idx] = m_coeff[idx-n_to_alloc];
                }
            }

            m_coeff = new_coeff;
        }
    }

    cout << " coeff = ";
    for(int p=0; p<m_coeff_size; p++){
        cout << m_coeff[p] << " ";
    }
    cout << "\n index = ";
    for(int p=0; p<m_dim+1; p++){
        cout << m_index[p] << " ";
    }
    cout << endl;
}

double Skyline::get_coeff(int i, int j){
    if(i>j){
        int tmp = j;
        j = i;
        i = tmp;
    }

    if((j-i)>=(m_index[j+1]-m_index[j])){
        return 0;
    }else{
        return m_coeff[m_index[j]+(j-i)];
    }
}

void Skyline::factoLU(void){
    int i,j,k;
    double piv;

    for(k=0; k<m_dim; k++){
        for(j=k+1; j<m_dim; j++){
            piv = (*this).get_coeff(k,k);
            if((k-j)<(m_index[k+1]-m_index[k])){
                (*this).set_coeff(j,k, (*this).get_coeff(j,k)/piv);
            }
            for(i=k+1; i<m_dim; i++){
                if((i-j)<(m_index[i+1]-m_index[i])){
                    (*this).set_coeff(j,i, (*this).get_coeff(j,k)*(*this).get_coeff(k,i));
                }
            }
        }
    }
}

// def FactoLU(A):
//     n = np.shape(A.toarray())[0]
//     for k in range(n):
//         for j in range(k+1,n):
//             if A[k,k] == 0:
//                 return "Erreur pivot nul"
//             else:
//                 A[j,k] = A[j,k]/A[k,k]
//                 A[j,k+1:n] -= A[j,k]*A[k,k+1:n]
//     return(A)


void Skyline::print(void){
    for(int i=0; i<m_dim; i++){
        for(int j=0; j<m_dim; j++){
            cout << (*this).get_coeff(i,j) << " " ;
        }
        cout << "" << endl;
    }
}
