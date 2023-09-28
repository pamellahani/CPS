#include "arg_var.h"

void minimum(int num , ...){

    va_list ap; 
    //double n; 
    va_start(ap, num);   
    double n = va_arg(ap,double);
    double min = n; 
    for (int i =0; i<num;i++){
        printf("%f\n",n);
        if (min>n){
            min = n; 
        } 
        n = va_arg(ap,double);
        va_end(ap);  
    }
    printf("min is: %f\n",min); 
}

int main(){
    minimum(5,3.5,2.7,1.5,2.0,2.2); 
    return 0; 
}