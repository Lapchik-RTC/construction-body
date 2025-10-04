#ifndef TIMERONE_h
#define TIMERONE_h

#include <Arduino.h>

class TimerOne
{
  public:
    void initialize(long microseconds=1000000);
    void start();
    void stop();
    void restart();
	void resume();
	unsigned long read();
    void attachInterrupt(void (*irq)(), long microseconds=-1);
    void detachInterrupt();
    void setPeriod(long microseconds);
    void (*irqCallback)();
};

extern TimerOne Timer1;
#endif