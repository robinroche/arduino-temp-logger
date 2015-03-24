# arduino-temp-logger

A basic Arduino temperature temperature logger

### Context

Simply out of curiosity, I needed a way to log the temperature in my office. This can be done easily using an Arduino and a 1-wire temperature sensor, as described below. This tutorial is based on another one by [hobbytronics.co.uk](http://www.hobbytronics.co.uk/tutorials-code/arduino-tutorials/ds18b20-arduino).

### Hardware setup

For this basic project, you need:

- An Arduino, an SD/Ethernet/Wifi shield (whichever you have, I have the Wifi one), and a USB cable,
- A DS18B20 1-wire temperature sensor ([datasheet](http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)),
- A micro-SD card,
- A 4.7 kOhm resistor,
- A breadboard and wires.

The DS18B20 sensor reports a temperature measurement (in degrees Celcius) in 9 to 12 bits, which can be easily used, especially with Dallas' [temperature control library](http://www.milesburton.com/?title=Dallas_Temperature_Control_Library) and Paul Stoffregen's [1-wire library](http://www.pjrc.com/teensy/td_libs_OneWire.html).

Connect all parts as shown on the figure below (the Wifi shield is not shown). Make sure you connect the sensor the right way; check with the [datasheet](http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf).

![Hardware setup](http://robinroche.com/webpage/images/500px-Schema_arduino_ds18b20_bb.png)

### Libraries setup

The source code uses the following libraries:

- OneWire.h
- DallasTemperature.h
- SD.h
- SPI.h

As the first two are not available by default in Arduino, you need to retrieve and install them:

- Download Dallas' [temperature control library](http://www.milesburton.com/?title=Dallas_Temperature_Control_Library),
- Unzip the file,
- Copy the dallas-temperature-control folder in your Arduino libraries folder (typically something like C:\Program Files (x86)\Arduino\libraries),
- Rename the folder as DallasTemperature.

Follow the same process for Paul Stoffregen's [1-wire library](http://www.pjrc.com/teensy/td_libs_OneWire.html).

After the libraries are installed, re-start the Arduino IDE so that these new libraries are loaded.

### Using the code

You can then copy and paste the attached code (logger_sketch.ino) in the IDE, assuming:

- You want a temperature measurement done every minute or so (use a real-time clock if you need time accuracy),
- The sensor middle pin is connected to the Arduino's pin 2.
- You want to save data on the SD card in a file named datalog.txt
- All these parameters can the edited directly in the code below.

Compile and upload the code to the Arduino, and the system should start logging.

### Sample output

A sample of the measurements done by my setup is shown in the figure below. Raw, unfiltered data is shown using a basic Matlab plot. Temperature spikes can be observed because sun rays directly hit the sensor (for reliable measurements, this should be avoided).

![Sample output](http://robinroche.com/webpage/images/Ds18b20_output.png)
