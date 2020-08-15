#ifndef SKYLINE_H_INCLUDED
#define SKYLINE_H_INCLUDED

class Skyline
{
public:
    Skyline(int);

    void set_coeff(int, int, double const &);
    double get_coeff(int, int);
    void factoLU(void);
    void print(void);

private:
    int *m_index;
    double *m_coeff;
    int m_dim;
    int m_coeff_size;
};


#endif
