from umachine import Pin

class DigitalSimpleControl:
    def __init__(self, pin: int, inverted_logic:bool = False):
        self._inverted_logic = inverted_logic
        self._state = True if inverted_logic else False
        self._pin(pin, Pin.OUT)

    @property
    def state(self):
        return self._state

    def change_state(self, state:bool):
        self._state = (
            state if self._inverted_logic else not(state)
        )
        self._pin.value(self._state)

class DigitalFullControl(DigitalSimpleControl):
    def __init__(self, pin: int, inverted_logic: bool = False):
        super().__init__(pin, inverted_logic)
        self._pwm_value = 0

    @property
    def pwm_value(self):
        return 0

    def change_pwm(self, pwm_value: int):
        pass

class Relay(DigitalSimpleControl):
    def __init__(self, pin: int, inverted_logic: bool = False):
        super().__init__(pin, inverted_logic)

class SolidStateRelay(DigitalFullControl):
    def __init__(self) -> None:
        super().__init__()

class Led(DigitalFullControl):
    def __init__(self, pin: int, inverted_logic: bool = False):
        super().__init__(pin, inverted_logic)

class Motor:
    pass