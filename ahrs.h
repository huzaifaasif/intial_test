//
//  ahrs.h
//  AHRSproject
//
//  Created by Huzaifa Asif on 2017-05-10.
//  Copyright © 2017 Huzaifa Asif. All rights reserved.
//

#ifndef ahrs_h
#define ahrs_h

#ifdef __cplusplus
extern "C" {
#endif
    
    double returnArr(double C_LB_from_quat_value);
    
#ifdef __cplusplus
}
#endif


class AHRS{
    public:
    
    static const double a;
    static const double b;
    static const double c;
   // static double *p;
   // static int identityMat[3][3];
    //static double (*p)[4][1];
    static double **p;
    static double **arr;
    
    void matrix(double a, double b, double c);
    
    double **(returnArr(double pointer[][3]));
    
    double **func(double p[][3]);
    
    void rund(double x);
 
};

#endif /* ahrs_h */
