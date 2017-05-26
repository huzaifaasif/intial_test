//
//  main.cpp
//  AHRSproject
//
//  Created by Huzaifa Asif on 2017-05-10.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "AHRS.h"
//#include "mbed.h"
//#include "matrix.h"

const double AHRS::a=1.0;
const double AHRS::b=1.0;
const double AHRS::c=1.0;
//double AHRS::*p = nullptr;
//double AHRS::arrayNum=3.2;
double **(AHRS::p) = nullptr;
//double (*AHRS::arr)[2][2] = nullptr;
double **(AHRS::arr)=nullptr;


int main(void) {

    AHRS Ahrs_Object;
    const double a_num=Ahrs_Object.a;
    const double b_num=Ahrs_Object.b;
    const double c_num=Ahrs_Object.c;
   // int identityMat[3][3];
    
    
    Ahrs_Object.matrix(a_num, b_num, c_num);
    
/*
 -----identity matrix---------
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (i==j){
                identityMat[i][j]=1;
            }
        }
    }
*/
    
    int identityMat[3][3]={
        
            {1,0,0},
            {0,1,0},
            {0,0,1}
        
    };
    
    printf ("\nSize is: %lu",sizeof(identityMat));
    printf ("\nColumn is: %lu\n",sizeof(identityMat[0])/sizeof(int));
    //------------C_LB_from_quat_value-----------
    
    static double C_LB_from_quat_value[3][3] = {
        
            {0.9930, 0.0947, 0.0701},
            {-0.1024, 0.9879, 0.1163},
            {-0.0582, -0.1226, 0.9907}
        
    };
    //double (*point)[3] = C_LB_from_quat_value;
   // printf ("\npointing address: %f\n", (*point));
    
    //double pointer[][3] = C_LB_from_quat_value;
    
    //Ahrs_Object.returnArr(identityMat);
    
    Ahrs_Object.p = Ahrs_Object.returnArr(C_LB_from_quat_value);
    
    Ahrs_Object.arr = Ahrs_Object.func(C_LB_from_quat_value);
    
    Ahrs_Object.rund(AHRS::p[1][0]);
    
    printf ("\n---HOLA---\n");
    for (int i=0;i<4;i++){
        for (int j=0;j<1;j++){
            printf ("\n%0.4f\n",Ahrs_Object.p[i][j]);
        }
    }
    
   /* printf ("\n---HOLA---\n");
    for (int i=0;i<4;i++){
        for (int j=0;j<1;j++){
            printf ("\n%0.4f\n",(*Ahrs_Object.p)[i][j]);
        }
    }
    */
    
    //Matrix myMatrix(3,3);
    
    //myMatrix.print();
    
}
