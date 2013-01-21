#include <Arduino.h>
#include "pid.h"

/**
 * @file pid.cpp
 *
 * Manages initiation and filtering of compass data
 * filtering can be done by lowPass filtering or
 * midPass/median filtering
 *
 * @author Nikolai Andre Ek Ovesen (nikolai.ovesen(at)gmail.com)
 */


/**
 * Sets tunings for the PID controller by taking in variables from a function call within main file
 */

void pid::setTunings(float p, float i, float d) {

	Kp = p;
	Ki = i;
	Kd = d;

}

/**
 * nav() Implements basic PID controller functionality 
 */

int pid::nav(float input, float setpoint) {

	now = millis();
	error = setpoint - input;
	timeChange = (now - lastTime);
	errorSum = (error * timeChange);
	error = (error * Kp) + (errorSum * Ki) + ((error - lastError) * Kd);
	output = map(error, -127, 127, -47, 207);	

	return output;	
}