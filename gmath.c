#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {
    double magnitude = sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
    vector[0] /= magnitude;
    vector[1] /= magnitude;
    vector[2] /= magnitude;
}

//Return the dot porduct of a . b
double dot_product( double a[], double b[] ) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double * calculate_normal(struct matrix *polygons, int i) {
	//create two tmp arrays and store relevant values based on input
    double tmp0[3] = {polygons->m[0][i+1] - polygons->m[0][i], polygons->m[1][i+1] - polygons->m[1][i], polygons->m[2][i+1] - polygons->m[2][i]};
    double tmp1[3] = {polygons->m[0][i+2] - polygons->m[0][i], polygons->m[1][i+2] - polygons->m[1][i], polygons->m[2][i+2] - polygons->m[2][i]};

	//array of the points
    double * ret_matrix = malloc(sizeof(double) * 3);

	//establish the value of the points
    ret_matrix[0] = (tmp0[1] * tmp1[2]) - (tmp0[2] * tmp1[1]);
    ret_matrix[1] = (tmp0[2] * tmp1[0]) - (tmp0[0] * tmp1[2]);
    ret_matrix[2] = (tmp0[0] * tmp1[1]) - (tmp0[1] * tmp1[0]);

    return ret_matrix;
}
