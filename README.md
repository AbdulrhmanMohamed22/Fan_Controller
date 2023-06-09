# Fan_Controller

Implement the following Fan Controller system with the specifications listed below:

1. The aim of this project is to design a temperature-controlled fan using ATmega32     
   microcontroller, in which the fan is automatically turned ON or OFF according to the        
   temperature. Use ATmega32 Microcontroller with frequency 1Mhz
2. In this project, the LM35 temperature sensor will give continuous analog output 
   corresponding to the temperature sensed by it. This analog signal is given to the ADC, 
   which converts the analog values to digital values.
3. The microcontroller will continuously monitor the temperature and based on the 
   temperature value, the microcontroller will drive the fan like that:
      a. If the temperature is less than 30C turn off the fan.
      b. If the temperature is greater than or equal 30C turn on the fan with 25% of its
         maximum speed.
      c. If the temperature is greater than or equal 60C turn on the fan with 50% of its 
         maximum speed.
      d. If the temperature is greater than or equal 90C turn on the fan with 75% of its 
         maximum speed
      e. If the temperature is greater than or equal 120C turn on the fan with 100% of its 
         maximum speed.
4. The project implemented based on the layered architecture.
------------------------------------------------------------------------------------------
Drivers: GPIO, ADC, PWM, LM35 Sensor, LCD and DC-Motor - Microcontroller: ATmega32.
------------------------------------------------------------------------------------------
