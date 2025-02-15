#include <ee.h>
#include <ee_irq.h>

DeclareTask(TaskPwm);
DeclareTask(TaskPin);

extern unsigned char EE_SHARED_IDATA adc;
extern unsigned char EE_SHARED_IDATA on_off;


static void setPinValue() {
	P14_IOCR4.U &= ~(0xF8000000);
	P14_IOCR4.U |=   0x10000000;	//input pull-up
}
static void clrPinValue() {
	P14_IOCR4.U &= ~(0xF8000000);
	P14_IOCR4.U |=   0x08000000;	//input pull-down
}
static void setPwmValue() {
	P33_IOCR8.U &= ~(0x00F80000);
	P33_IOCR8.U |=   0x00100000;	//input pull-up
}
static void clrPwmValue() {
	P33_IOCR8.U &= ~(0x00F80000);
	P33_IOCR8.U |=   0x00080000;	//input pull-down
}



TASK(TaskPwm)
{

	//TODO: implement your code here
	TerminateTask();
}

TASK(TaskPin)
{
	//TODO: implement your code here
}


/*
 * MAIN TASK
 */
int main(void)
{
	clrPinValue();
	clrPwmValue();

	StartOS(DONOTCARE);
}
