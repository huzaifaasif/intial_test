//
//  ahrs.cpp
//  AHRSproject
//
//  
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include <stdio.h>
#include "AHRS.h"
#include <cmath>
#include <new>

void AHRS::matrix(double a, double b, double c){
    
    double mat[1][9]={
        {
            10*a, 20*b, 30*c, 40*a, 50*b, 60*c, 70*a, 80*b, 90*c
        }
    };
    
    
    int j;
    double tran[3][3];
    
    
    double (&reshapeMatrix)[3][3]=*reinterpret_cast<double(*)[3][3]>(mat);
    
    for (int i=0;i<3;i++){
        for (j=0;j<3;j++){
            tran[j][i]=reshapeMatrix[i][j];
        }
    }
    for (int i=0; i<3; i++){
        for (j=0; j<3; j++){
            printf ("%f, ",tran[i][j]);
        }
        
        if (j==3){
            printf("\n");
        }
    }
    
}
   // -----------------int newMat[3][3]-----------------;

double **(AHRS::func(double p[][3])){
    double sum=0.0;
    int i,j;
    
    sum = sum+p[0][0];
    
    printf ("==suma is: %f\n",sum);
    
    double quad[2][2] = {
        {1, 5},
        {3, 2}
    };
    
    
    double **foo = new double*[2];
    
    for (i=0;i<2;i++){
        foo[i] = new double[2];
    }
    
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            foo[i][j] = quad[i][j];
        }
    }
    
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            printf ("\nughA---:%f\n",foo[i][j]);
        }
        
    }
    
    return foo;
}

double **(AHRS::returnArr(double p[][3])){
    double sum;
    int i,j,maxColumn = 0;
    double Pa, Pb, Pc, Pd, minNumber, maxNumber=0;
    
   
    //trace
    sum = p[0][0] + p[1][1] + p[2][2];
    Pa = 1+sum;
    Pb = 1+2*p[0][0]-sum;
    Pc = 1+2*p[1][1]-sum;
    Pd = 1+2*p[2][2]-sum;
    
    printf ("Constants: Pa=%f, Pb=%f, Pc=%f, Pd=%f\n",Pa,Pb,Pc,Pd);
    
    double maxMatrix [1][4] = {
        {
            Pa, Pb, Pc, Pd
        }
    };
    minNumber = maxMatrix[0][0];
    maxNumber = minNumber;
    
    for (i=0;i<1;i++){
        for (j=0;j<4;j++){
            
            if (minNumber<maxMatrix[i][j]){
                maxNumber = maxMatrix[i][j];
                minNumber = maxNumber;
                maxColumn = j;      //need to +1
            }
        }
    }
    maxColumn++;
    
    double a = 0.0,b = 0.0,c=0.0,d=0.0;
    
    switch(maxColumn){
        case 1:
            a = 0.5*sqrt(Pa);
            b = ( p[2][1]-p[1][2] )/(4*a);
            c = ( p[0][2] - p[2][0])/(4*a);
            d = ( p[1][0] - p[0][1])/(4*a);
            break;
            
        case 2:
            b = 0.5*sqrt(Pb);
            c = ( p[1][0]+p[0][1] )/(4*b);
            d = ( p[0][2] + p[2][0])/(4*b);
            a = ( p[2][1] - p[1][2])/(4*b);
            break;
            
        case 3:
            c = 0.5*sqrt(Pc);
            d = ( p[2][1]+p[1][2] )/(4*c);
            a = ( p[0][2]-p[2][0] )/(4*c);
            b = ( p[1][0]+p[0][1] )/(4*c);
            break;
            
        case 4:
            d = 0.5*sqrt(Pd);
            a = ( p[1][0]-p[0][1])/(4*d);
            b = ( p[0][2]+p[2][0])/(4*d);
            c = ( p[2][1]+p[1][2])/(4*d);
            break;
            
    }
    
    if (a<= 0){
        a = -a;
        b = -b;
        c = -c;
        d = -d;
    }
    
    
    static double quat_vector[4][1] = {
        {a},
        {b},
        {c},
        {d}
    };
    
    //--------------------
    
    double **foo = new double*[4];
   
    for (i=0;i<4;i++){
        foo[i] = new double[1];
    }
    
    for (i=0;i<4;i++){
        for (j=0;j<1;j++){
            foo[i][j] = quat_vector[i][j];
        }
    }
    
    
    
    //--------------------
    
    
    for (i=0;i<4;i++){
        for (j=0;j<1;j++){
            printf ("FOO is: %0.4f,",foo[i][j]);
        }
        printf ("\n");
    }
    printf ("----Size of foo: %lu\n",sizeof(foo));
    printf ("----Size of quat: %lu\n",sizeof(quat_vector[0][0]));
   // printf ("\nmaxColum is: %d\n",maxColumn);
    //-------------------
    
    printf ("\nMax number: %f \nCorresponding Column: %d \n",maxNumber,maxColumn);
    
    printf ("\nSum: %f\n",sum);
    
    //printing out input matrix
    
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf ("%f, ",p[i][j]);
        }
        if (j==3){
            printf ("\n");
        }
    }
    
   // pointer = &quat_vector[4][1];
  
    
    return foo;
   
}

void AHRS::rund(double x){
    
    printf ("b(index) == %0.4f\n",x);
}









    

