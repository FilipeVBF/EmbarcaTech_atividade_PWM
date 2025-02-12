#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PWM 22
#define PWM_LED 12

// F = 125M/(125*(19999+1)) = 50Hz

// Duty (x/19999)*100 = 12  -- 180
// Duty (x/19999)*100 = 7,35 -- 90
// Duty (x/19999)*100 = 2,5  -- 0

#define PULSO_0GRAUS 500
#define PULSO_90GRAUS 1470
#define PULSO_180GRAUS 2399

const uint16_t WRAP_PERIOD = 19999; //valor máximo do contador - WRAP
const float PWM_DIVISER = 125.0; //divisor do clock para o PWM (125MHz)

uint slice;

void config_pwm(int GPIO_PWM, int PWM_LEVEL){
  gpio_set_function(GPIO_PWM, GPIO_FUNC_PWM);
  uint slice = pwm_gpio_to_slice_num(GPIO_PWM);

  pwm_set_clkdiv(slice,PWM_DIVISER);
  pwm_set_wrap(slice,WRAP_PERIOD);
  pwm_set_gpio_level(GPIO_PWM,PWM_LEVEL);

  pwm_set_enabled(slice,true);
}

int main(){
  stdio_init_all();

  config_pwm(SERVO_PWM, PULSO_180GRAUS);
  config_pwm(PWM_LED, PULSO_180GRAUS);

  pwm_set_gpio_level(SERVO_PWM,PULSO_180GRAUS);
  pwm_set_gpio_level(PWM_LED, (PULSO_180GRAUS * 10));
  sleep_ms(5000);

  pwm_set_gpio_level(SERVO_PWM,PULSO_90GRAUS);
  pwm_set_gpio_level(PWM_LED, (PULSO_90GRAUS * 10));
  sleep_ms(5000);

  pwm_set_gpio_level(SERVO_PWM,PULSO_0GRAUS);
  pwm_set_gpio_level(PWM_LED, (PULSO_0GRAUS * 10));
  sleep_ms(5000);

  while(1){

    int step = 5;
    for(int us = PULSO_0GRAUS; us < PULSO_180GRAUS; us += step) {
      pwm_set_gpio_level(SERVO_PWM, us);
      pwm_set_gpio_level(PWM_LED, us * 10);
      sleep_ms(10);
      
      if (us >= 2395 || us < PULSO_0GRAUS) {
          step = -step; // Inverte a direção quando atinge os limites
      }
    }
  }
}