#include "pid.h"

float kp=0,ki=0,kd=0;
float error;
float Ierror;
float errorPr;
float Derror;
float limI;
float limT;
uint8_t first;
float pc,ic,dc,c;

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
