#ifndef __PID__
#define __PID__

#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"

void pidInit(float p,float i,float d,float lI,float lT);
float pidCalculate(float trueValue, float expectedValue);

#endif
