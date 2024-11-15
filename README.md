## NOTE: Each exercise stored in 1 branch. Switch branch to see the expected project.
# Lab 1: General Purpose Input Output 

- Ex1: Control led3 ON in 2s and then OFF in 4s.

- Ex2: Ex1 with 1 delay statement (use counter and an extra variable to save the led status).

- Ex3: Simulate the traffic light operation using led2, led_y0 and led_y1.

# Lab 2: Timer Interrupt and LED Scanning

- Ex1: Use software timer to:
    + Toogle led3 every 2s.
    + Turn led_y0 on 2s and turn led_y1 off 4s.
    + Turn led_y0 on 5s and turn led_y1 off 1s.

- Ex2: Simulate the traffic light in lab 1 using software timer.

- Ex3: Change LED_7SEG frequency to 1Hz, 25Hz, 100Hz.

- Ex4: Simulus the digital 7-segment LED.

- Ex5: Display 4 different number in the LED_7SEG and shift them right every 1s.

# Lab 3: LCD and Button matrix

Building a state machine and implementing a traffic light control system for a crossroad intersection with the following requirements: 

- The application will control six traffic lights representing two directions at the intersection. Each direction has:
    - 2 Green Lights
    - 2 Red Lights
    - 2 Yellow Lights
    
- The traffic lights will be displayed on an LCD screen.

- There are 3 control buttons:
    - **Button 1**: Used to select the operating mode.
    - **Button 2**: Used to adjust the cycle time of the lights.
    - **Button 3**: Used to confirm the adjusted parameters.

- The system has at least 4 modes, controlled by Button 1. Button 1 cycles through the modes from Mode 1 to Mode 4 and then back to Mode 1.
    - **Mode 1 - NORMAL Mode**:
        - Traffic lights operate on a standard cycle, simulating normal traffic light operation at an intersection.

    - **Mode 2 - MODIFY Red Light Cycle**:
        - The red light will blink at a frequency of 2Hz to indicate modification mode.
        - The adjustable cycle value is displayed on the LCD.
        - The LCD also shows the current operating mode.
        - **Button 2** increases the red light cycle duration.
        - The red light cycle duration can be set between 1 and 99 seconds.
        - **Button 3** confirms the selected red light cycle duration.

    - **Mode 3 - MODIFY Green Light Cycle**:
        - Similar to Mode 2, but for the green light.

    - **Mode 4 - MODIFY Yellow Light Cycle**:
        - Similar to Mode 2, but for the yellow light.