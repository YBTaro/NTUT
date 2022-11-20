#ifndef VECTOR_SPACE_H
#define VECTOR_SPACE_H

double *add(double *u, int dim_u, double *v, int dim_v){
    if (dim_u <= 0){       
        throw std::string("undefined.");
    }
    if (dim_u != dim_v){
        throw std::string("undefined.");
    }
    double *result = new double[dim_u];

    for (int i=0 ; i<dim_u ; i++){
        result[i] = u[i] + v[i];
    }
    return result;
}

double *scale(double *u, int dim_u, double a){
    if (dim_u <= 0){       
        throw std::string("undefined.");
    }
    double *result = new double[dim_u];

    for (int i=0; i<dim_u; i++){
        result[i]= u[i] * a;
    }

    return result;
}






#endif
