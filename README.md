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

# Lab 4: Real Time Clock

Building a state machine and implementing a digital clock system with an LCD display. The system requirements are as below:

- The system has three main modes and includes buttons for adjusting parameters and switching between modes, with visual feedback on the LCD.
    - **Time Display Mode**
        - The LCD displays day, date, month, year, hour, minute, and second in a readable format.
        
    - **Time Adjustment Mode**
        - Allows the user to adjust the clock's date and time settings.
        - While adjusting, the clock display pauses, and the selected parameter blinks at a frequency of 2Hz. There are 2 control buttons for this mode:
            - **Increment Button (suggested as "up arrow")**: Pressing this button increases the selected parameter by 1 while holding the button for 2 seconds increases the parameter continuously, with increments every 200ms.
            - **Save Button (suggested as "E")**: Pressing this button saves the current parameter and moves to the next parameter for adjustment.

    - **Alarm Setting Mode**
        - Allows setting an alarm with similar controls as in Time Adjustment Mode.
        - When the set time is reached, an alarm effect (e.g., flashing or blinking message) is displayed on the LCD.

- Some extra buttons should be used to switch between modes.
- The current mode should be displayed on the LCD to inform users of the active mode.

# Lab 5: Universal Asynchronous Receiver-Transmitte

- Ex 1: Ring Buffer for UART Receive Interrupt

    Implement a ring buffer to store data received via UART in an interrupt service routine (ISR). Turn on the flag and process the received data in the main loop.

- Ex2: Smart Clock with RS232 Time Update

    Upgrade the electronic clock from Lab 4 by adding a mode that allows updating the time via RS232 communication with a computer. In this mode, the time values will be updated sequentially. Below is an example of how the system requests time updates:

    - The LCD will display the message "Updating hours ...".
    - The microcontroller will send a request with the string "Hours" to the computer.
    - The computer will respond with a string containing the new time value to update (e.g., "14:30:00"). It is recommended to use the data sending feature in Hercules software for this purpose.
    - The system will store the received time value and proceed to request the next value (if necessary).
    - Once the system has received all the time values (e.g., hours, minutes, seconds), it will store these values into the DS3231 Real-Time Clock (RTC) IC.

- Ex3: Smart Clock with RS232 Time Update

    Building on the application developed in Exercise 2, the following new functionalities have been added:

    - After sending a request to the computer, if there is no response within 10 seconds, the system will automatically resend the request.
    - If there is still no response after 3 attempts, the system will display an error message on the LCD and return to normal operating mode.
    - If the data received from the computer is invalid, the system will resend the request to ensure the time data is accurately updated.
