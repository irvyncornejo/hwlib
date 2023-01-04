from umachine import Pin
import utime

class RotaryEncoder:
    """
        :dt_pin int
        :clk_pin int
        :sw: int
        :max_step int
        :wrapper bool
        
        encoder = RotaryEncoder(2, 3, 4, max_step=100)

        while True:
            encoder.read()
            utime.sleep(0.009)
            print(encoder.value)
            print(encoder.is_pressed)
    """
    def __init__(
        self,
        dt_pin: int,
        clk_pin: int,
        sw: int,
        max_step: int=10,
        wrapper: bool=True
    ) -> None:
        self._value: int = 0
        self._is_pressed: bool = False
        self._DT_Pin = Pin(dt_pin, Pin.IN, Pin.PULL_UP)
        self._CLK_Pin = Pin(clk_pin, Pin.IN, Pin.PULL_UP)
        self._SW = Pin(sw, Pin.IN, Pin.PULL_UP)
        self._wrapper: bool = wrapper
        self._previousValue: int = 1
        self._max_step:int = max_step
    
    @property
    def value(self):
        return self._value
    
    @property
    def is_pressed(self):
        return self._is_pressed
    
    def _read_rotatory_state(self) -> None:
        if self._previousValue != self._CLK_Pin.value():
            if not self._CLK_Pin.value():
                if not self._DT_Pin.value():
                    self._value = (self._value - 1)%self._max_step
                else:
                    self._value = (self._value + 1)%self._max_step
            self._previousValue = self._CLK_Pin.value()
        
    def _read_button_state(self) -> None:
        if self._SW.value() == 0:
            if self._wrapper:
                self._is_pressed = not(self._is_pressed)
            else:
                #TODO Change this for Event()
                self._is_pressed = True
    
    def read(self) -> None:
        self._read_button_state()
        self._read_rotatory_state()

