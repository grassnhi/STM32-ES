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

The formula for calculating the interrupt frequency is:

\[
\text{interrupt frequency} = \frac{84 \text{ MHz}}{(\text{prescaler} + 1) \times (\text{counter period} + 1)}
\]

Solving for the counter period:

\[
\text{counter period} = \frac{84 \text{ MHz}}{\text{interrupt frequency} \times (\text{prescaler} + 1)} - 1
\]

To adjust the scan frequency of the four seven-segment LEDs on the board to 1 Hz, 25 Hz, and 100 Hz, we need to set the interrupt frequency to 4 Hz, 100 Hz, and 400 Hz, respectively. This is because each LED is updated sequentially, and we require the entire display to refresh at the desired scan frequency.

By choosing a prescaler value of 839, we calculate the counter period for each desired interrupt frequency as follows:

### For an interrupt frequency of 4 Hz:
\[
\text{counter period} = \frac{84 \text{ MHz}}{4 \text{ Hz} \times (839 + 1)} - 1 = \frac{84,000,000}{4 \times 840} - 1 = \frac{84,000,000}{3,360} - 1 = 25,000 - 1 = 24,999
\]

### For an interrupt frequency of 100 Hz:
\[
\text{counter period} = \frac{84 \text{ MHz}}{100 \text{ Hz} \times (839 + 1)} - 1 = \frac{84,000,000}{100 \times 840} - 1 = \frac{84,000,000}{84,000} - 1 = 1,000 - 1 = 999
\]

### For an interrupt frequency of 400 Hz:
\[
\text{counter period} = \frac{84 \text{ MHz}}{400 \text{ Hz} \times (839 + 1)} - 1 = \frac{84,000,000}{400 \times 840} - 1 = \frac{84,000,000}{336,000} - 1 = 250 - 1 = 249
\]

Therefore, setting the counter period to 24,999, 999, and 249 will achieve interrupt frequencies of 4 Hz, 100 Hz, and 400 Hz, respectively, corresponding to LED scan frequencies of 1 Hz, 25 Hz, and 100 Hz.


- Ex4: Simulus the digital 7-segment LED.

- Ex5: Display 4 different number in the LED_7SEG and shift them right every 1s.
