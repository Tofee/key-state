# Simple key testing utility

**key-state** is a basic program that will query the kernel about current key state for a given input device.

Usage is:
```
key-state <input-device> [key]
```

where:
 - ```<input-device>``` is the path to an input device, like /dev/input/event2
 - ```key``` is an optional numerical argument specifying which keycode to test.
For a list of key codes, please see the (Linux UAPI)[https://github.com/torvalds/linux/blob/master/include/uapi/linux/input-event-codes.h] .

Return value is **0** if the given key is pressed, or ```key``` is absent and any key is pressed.
Otherwise, return value is **1**.

Example: 
* test if VOLUME_UP is pressed on event2:
```
key-state /dev/input/event2 115
```
* test if any key is pressed on event1:
```
key-state /dev/input/event1
```
 
