void left(int value) {
    
    if (value >= 0) {
        digitalWrite(ML_IN1, HIGH);
        digitalWrite(ML_IN2, LOW);
    } else {
        digitalWrite(ML_IN1, LOW);
        digitalWrite(ML_IN2, HIGH);
        value = -value;
    }
    analogWrite(ML_PWM, value);
}

void right(int value) {
    
    if (value >= 0) {
        digitalWrite(MR_IN1, LOW);
        digitalWrite(MR_IN2, HIGH);
    } else {
        digitalWrite(MR_IN1, HIGH);
        digitalWrite(MR_IN2, LOW);
        value = -value;
    }
    analogWrite(MR_PWM, value);
}
