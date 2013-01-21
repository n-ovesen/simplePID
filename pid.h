#ifndef PID_h
#define PID_h

/**
 * @file pid.h
 * File containing function prototypes and access modifiers for the pid class
 *
 * @author Nikolai Andre Ek Ovesen (nikolai.ovesen(at)gmail.com)
 */

/**
 * Basic implementation of the PID controller
 */
class pid {

	private:
		int output;
		unsigned long lastTime, now;
		double timeChange;
		float Kp, Ki, Kd, error, lastError, errorSum;

	public:
		void setTunings(float p, float i, float d);
		int nav(float input, float setpoint);
};

#endif