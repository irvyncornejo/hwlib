from umachine import Pin
import utime

_VOLTAGE_REF: float = 3.3
_SAMPLES: int = 65535

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

class AnalogicMap:
    """
       create_map = AnalogicMap()
       print(create_map.create_map(x, 0, 64300, 0, 100))
    """
    def __init__(self, return_float=False):
        self._return_float = return_float

    def create_map(
        self,
        x,
        in_min,
        in_max,
        out_min,
        out_max
    ):
        
        _value_map = (
            (x-in_min)*(out_max-out_min)/(in_max - in_min)+out_min
        )
        return _value_map if self._return_float else int(_value_map)
        

class AnalogicInputs:
    """
        valid pins: int [26, 27, 28]
    """
    def __init__(
        self,
        adc_pin: int,
        voltage_ref: float = _VOLTAGE_REF
    ) -> None:
        if adc_pin not in list(range(26,29)):
            raise ValueError('adc_pin isn´t analogic pin')
        self._input = umachine.ADC(adc_pin)
        self._conversion_factor = voltage_ref / _SAMPLES

    def read_voltage(self) -> float:
        return self._input.read_u16() * self._conversion_factor
    
    def read_adc(self) -> int:
        return self._input.read_u16()

class Potentiometer(AnalogicInputs):
    """
        adc_input = Potentiometer(28)
        while True:
            print(adc_input.read_adc())
            utime.sleep(0.1)
        
        :adc_pin
        :voltage_ref
    """
    def __init__(
        self,
        adc_pin: int,
        voltage_ref: float = _VOLTAGE_REF
    ) -> None:
        super().__init__(adc_pin, voltage_ref)