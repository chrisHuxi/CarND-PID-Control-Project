#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Kd = Kd;
	this->Ki = Ki;
	this->d_error = 0.0;
	this->p_error = 0.0;
	this->i_error = 0.0;
}

void PID::UpdateError(double cte) {
	double last_cte = this->p_error;
	double cte_diff = cte - last_cte;

	this->d_error = cte_diff;
	this->i_error = this->i_error + cte;
	this->p_error = cte;
}

double PID::TotalError() {
	double error = 0;
	error = -(this->Kp * this->p_error + this->Kd * this->d_error + this->Ki * this->i_error);
	return error;
}

