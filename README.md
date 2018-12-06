# Usage Notes

Pressing the button on the top of the device changes the state of the LED.
- 0: OFF
- 1: BRIGHT
- 2: INTERMEDIATE
- 3: DIM
- 4: 2 HZ FLASHING

In order to conserve battery, the battery is unattached while the device is not in use. In order to turn ON, remove the lid, attach the 9 V battery to the clip, and place flat in the empty compartment.

### ECAD Changes

While testing, some changes had to be made to the PCB post-photoetching. In particular, R2 and R4 were removed, and the button was attached directly to pin 4 of the ATMega, bypassing the Zener diode. These two resistors caused voltage division that caused the microcontroller to not register the button pressing.

### Lid/CAD Notes

The lid does not fit entirely within the box, but the fit is tight enough that it remains despite not being perfect. This lid was chosen for the final product in order to minimize the risk of collisions between the PCB components in the lid while keeping a tight fit for the battery. In order to add extra security, tape can be added to the lid (though it is not needed). A future iteration of the lid was created in SolidWorks (which can be seen in the Mechanical directory) that allows more space and a tighter fit if desired.
