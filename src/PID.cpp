#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

void PID::UpdateError(double cte) {
    p_error = cte;
    i_error += cte;
    if(prev_cte == 0) {
        prev_cte = cte;
    }
    d_error = cte-prev_cte;
    prev_cte = cte;
}

double PID::TotalError() {
    return -Kp*p_error - Ki*i_error - Kd*d_error;
}

