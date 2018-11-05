#define LED 3
#define FLASH_RATE 2
#define BUTTON_PIN 2
#define PWM_MAX 255

//mode: 0-off, 1-bright, 2-mid, 3- dim, 4-flashing
int mode = 0;
int BUTTON_PUSHED = 0;
int PWM_OUT = 0;
int freq_delay = 0;

void setup() {
	pinMode(LED, OUTPUT);
	attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_pushed, RISING);
	freq_delay = 1000/FLASH_RATE;
}

void loop(){
	check_button_press();
	set_pwm(); //put switch case in here instead
	}

void set_pwm(){
	switch (mode){
		case 0:
			PWM_OUT =0;
			shine_LED(PWM_OUT);
		case 1:
			PWM_OUT = PWM_MAX;
			shine_LED(PWM_OUT);
		case 2:
			PWM_OUT = int(PWM_MAX/2);
			shine_LED(PWM_OUT);
		case 3:
			PWM_OUT = int(PWM_MAX/4);
			shine_LED(PWM_OUT);
		case 4:
			flash_LED(freq_delay);
}

void shine_LED(pwm){
	analogWrite(LED,pwm);
}

void button_pushed(){
	BUTTON_PUSHED = 1;
}

void flash_LED(freq){
	analogWRITE(LED,PWM_MAX);
	delay(10);
	analogWRITE(LED,0);
	delay(freq);
}

void check_button_press(){
	if (BUTTON_PUSHED==1 && mode==4){
		mode = 0;
	}
	else if (BUTTON_PUSHED==1 && mode!=4){
		mode++;
	}
	BUTTON_PUSHED=0;
}