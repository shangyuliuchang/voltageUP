#include "pid.h"

float kp=0,ki=0,kd=0;
float kp2=0,ki2=0,kd2=0;
float error,error2;
float Ierror,Ierror2;
float errorPr,errorPr2;
float Derror,Derror2;
float limI,limI2;
float limT,limT2;
uint8_t first,first2;
float pc,ic,dc,c;
float pc2,ic2,dc2,c2;

void pidInit(float p,float i,float d,float lI,float lT){
	kp=p;
	ki=i;
	kd=d;
	limI=lI;
	limT=lT;
	error=0.0f;
	Ierror=0.0f;
	Derror=0.0f;
	errorPr=0.0f;
	first=1;
}
void pidInit2(float p,float i,float d,float lI,float lT){
	kp2=p;
	ki2=i;
	kd2=d;
	limI2=lI;
	limT2=lT;
	error2=0.0f;
	Ierror2=0.0f;
	Derror2=0.0f;
	errorPr2=0.0f;
	first2=1;
}
float pidCalculate(float trueValue, float expectedValue){
	if(!first){
		error=expectedValue-trueValue;
		Ierror+=error;
		if(Ierror>limI){
			Ierror=limT;
		}else if(Ierror<-1*limI){
			Ierror=-1*limI;
		}
		Derror=error-errorPr;
		pc=error*kp;
		ic=Ierror*ki;
		dc=Derror*kd;
		c=pc+ic+dc;
		if(c>limT){
			c=limT;
		}
		errorPr=error;
	}else{
		first=0;
		error=expectedValue-trueValue;
		errorPr=error;
		c=0;
	}
	if(c<0)c=0;
	return c;
}
float pidCalculate2(float trueValue, float expectedValue){
	if(!first2){
		error2=expectedValue-trueValue;
		Ierror2+=error2;
		if(Ierror2>limI2){
			Ierror2=limT2;
		}else if(Ierror2<-1*limI2){
			Ierror2=-1*limI2;
		}
		Derror2=error2-errorPr2;
		pc2=error2*kp2;
		ic2=Ierror2*ki2;
		dc2=Derror2*kd2;
		c2=pc2+ic2+dc2;
		if(c2>limT2){
			c2=limT2;
		}
		errorPr2=error2;
	}else{
		first2=0;
		error2=expectedValue-trueValue;
		errorPr2=error2;
		c2=0;
	}
	if(c2<0)c2=0;
	return c2;
}
