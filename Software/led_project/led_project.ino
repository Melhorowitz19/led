#define LED 9
#define FLASH_RATE 2
#define BUTTON_PIN 2
#define PWM_MAX 255

//mode: 0-off, 1-bright, 2-mid, 3- dim, 4-flashing
int mode = 0;
int BUTTON_PUSHED = 0;
int PWM_OUT = 0;
int freq_delay = 0;
 static int last_interrupt_time = 0;

void setup() {
  Serial.begin(9600);
	pinMode(LED, OUTPUT);
  pinMode(BUTTON_PIN,INPUT);
	attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_pushed, FALLING);
	freq_delay = 1000/FLASH_RATE;
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

void shine_LED(int pwm){
  analogWrite(LED,pwm);
}

void button_pushed(){
  int interrupt_time = millis();
 if (interrupt_time - last_interrupt_time > 200)
 {
     BUTTON_PUSHED = 1;
 }
 last_interrupt_time = interrupt_time;
}

void flash_LED(int freq){
  analogWrite(LED,PWM_MAX);
  delay(10);
  analogWrite(LED,0);
  delay(freq);
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
     Serial.print("0");
     break;
		case 1:
			PWM_OUT = PWM_MAX;
			shine_LED(PWM_OUT);
     Serial.print("1");
     break;
		case 2:
			PWM_OUT = int(PWM_MAX/2);
			shine_LED(PWM_OUT);
     Serial.print("2");
     break;
		case 3:
			PWM_OUT = int(PWM_MAX/4);
			shine_LED(PWM_OUT);
     Serial.print("3");
     break;
		case 4:
			flash_LED(freq_delay);
      Serial.print("4");
      break;
}
}



