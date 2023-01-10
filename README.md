# Librería para control de Hardware
## Arduino
* Shield para Arduino nano Kaanbal
* C++

### Comprimir archivo en power shell, para después añadir desde el IDE de arduino
```
Compress-Archive .\kaanbal-lib\*.* -DestinationPath .\kaanbal.zip -F
```
### Copiar a la carpeta de libraries
```
$user="irvyn"
Copy-Item -Path "C:\Users\$user\Documents\ic\hwlib\Kaanbal" -Destination "C:\Users\$user\Documents\Arduino\libraries" -Recurse -Force
```

![kaanbal-chimalli](https://drive.google.com/uc?export=view&id=17g-OoKZGfAfieqKLzZ5uVrpLoWZCDVBi)

# Librería para control de hardware
## Raspberry pico o pico w
* Python
GPIO control para raspberry pi pico

### Input Devices
- Touch Sensor
- Potenciometer
- Joystick
- PIR
- LM35
### Ouput Devices
- LED
- Reley
- Solid state relay
- Motor DC
- RGB
- Servo motor


```python
from gpiopico import Led

led1 = Led(2, True)
led1.change_pwm(125) #value 0-255
```