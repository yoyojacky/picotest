#include "pico/stdlib.h"


int main(){

  const uint LED_PINS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 25, 26, 27, 28};
  int number_leds = sizeof(LED_PINS) / sizeof(LED_PINS[0]);
   
  for (int i=0; i< number_leds; i++) {
	gpio_init(LED_PINS[i]);
	gpio_set_dir(LED_PINS[i], GPIO_OUT);
	sleep_ms(20);
  }

  while (true) {
     for (int i=0; i< number_leds; i++) {
	     gpio_put(LED_PINS[i], 1);
	     sleep_ms(20);
     }

     sleep_ms(1000);
     for (int i=0; i< number_leds; i++) {
	     gpio_put(LED_PINS[i], 0);
	     sleep_ms(20);
     }
     sleep_ms(1000);
  }
	return 0;
}
