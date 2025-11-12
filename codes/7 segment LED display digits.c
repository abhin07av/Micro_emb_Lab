void main() {
  TRISB = 0x00; // Configure PORTB as output
  while(1) {
    PORTB = 0b00111111; // Display 0
    Delay_ms(250);
    PORTB = 0b00000110; // Display 1
    Delay_ms(250);
    PORTB = 0b01011011; // Display 2
    Delay_ms(250);
    PORTB = 0b01001111; // Display 3
    Delay_ms(250);
    PORTB = 0b01100110; // Display 4
    Delay_ms(250);
    PORTB = 0b01101101; // Display 5
    Delay_ms(250);
    PORTB = 0b01111101; // Display 6
    Delay_ms(250);
    PORTB = 0b00000111; // Display 7
    Delay_ms(250);
    PORTB = 0b01111111; // Display 8
    Delay_ms(250);
    PORTB = 0b01101111; // Display 9
    Delay_ms(250);
  }
}