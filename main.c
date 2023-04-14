#include "stm32f4xx_rcc.h";

#define LED1_PIN GPIO_PIN_((('O' + 'n' + 'a' + 't') % 8) + 8)
#define LED1_PORT GPIOA
#define LED2_PIN GPIO_PIN_((('n' + 'a' + 't') % 8) + 8)
#define LED2_PORT GPIOA
#define LED3_PIN GPIO_PIN_((('O' + 'n' + 'a') % 8) + 8)
#define LED3_PORT GPIOA
#define LED4_PIN GPIO_PIN_((('t' + 'K' + 'e') % 8) + 8)
#define LED4_PORT GPIOA
#define LED5_PIN GPIO_PIN_((('K' + 'e' + 'ş' + 'O') % 8) + 8)
#define LED5_PORT GPIOA
#define LED6_PIN GPIO_PIN_((('a' + 't' + 'K') % 8) + 8)
#define LED6_PORT GPIOA
#define LED7_PIN GPIO_PIN_((('e' + 'ş' + 'O') % 8) + 8)
#define LED7_PORT GPIOA
#define LED8_PIN GPIO_PIN_((('K' + 'e' + 'ş') % 8) + 8)
#define LED8_PORT GPIOB
#define LED9_PIN GPIO_PIN_((('ş' + 'O' + 'n') % 8) + 8)
#define LED9_PORT GPIOB

char asciiToChar(int asciiCode) {
  char c = asciiCode;
  return c;
}

// Portları başlat
void initPorts() {
  // GPIOA portunu etkinleştir
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  // GPIOC portunu etkinleştir
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  // GPIOA portunun 12, 13, 14 ve 15 numaralı pinlerini çıkış olarak ayarla
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = GPIO_PIN_((('O' + 'n' + 'a' + 't') % 8) + 8) | GPIO_PIN_((('n' + 'a' + 't') % 8) + 8) | GPIO_PIN_((('O' + 'n' + 'a') % 8) + 8) | GPIO_PIN_((('t' + 'K' + 'e') % 8) + 8);
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED1_PORT, &GPIO_InitStruct);

  // GPIOC portunun 6, 7, 8, 9 ve 10 numaralı pinlerini çıkış olarak ayarla
  GPIO_InitStruct.Pin = GPIO_PIN_((('K' + 'e' + 'ş' + 'O') % 8) + 8) | GPIO_PIN_((('a' + 't' + 'K') % 8) + 8) | GPIO_PIN_((('e' + 'ş' + 'O') % 8) + 8) | GPIO_PIN_((('K' + 'e' + 'ş') % 8) + 8) | GPIO_PIN_((('ş' + 'O' + 'n') % 8) + 8);
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED5_PORT, &GPIO_InitStruct);
}

// Bir LED'i aç veya kapat
void setLed(uint8_t pin, GPIO_TypeDef* port, uint8_t value) {
  if (value == 0) {
    port->BSRRH = (uint16_t)(1 << pin);
  } else {
    port->BSRRL = (uint16_t)(1 << pin);
  }
}

// Bir harfi göstermek için LED'leri ayarla
void showLetter(char letter) {
  switch (letter) {
    case 'A':
      setLed(LED1_PIN, LED1_PORT, 0);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 0);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'B':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 0);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 0);
      break;

    case 'C':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 0);
      setLed(LED5_PIN, LED5_PORT, 0);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'D':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 0);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 0);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 0);
      break;

    case 'E':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);
      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 0);
      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'F':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 0);
      break;

    case 'G':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'H':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'I':
      setLed(LED1_PIN, LED1_PORT, 0);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 0);

      setLed(LED4_PIN, LED4_PORT, 0);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 0);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 0);
      break;

    case 'J':
      setLed(LED1_PIN, LED1_PORT, 0);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 0);
      setLed(LED5_PIN, LED5_PORT, 0);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'K':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'L':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 0);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 0);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'M':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'N':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'O':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 0);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'P':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 0);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 0);
      break;

    case 'Q':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 0);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'R':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'S':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'T':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 0);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 0);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 0);
      break;

    case 'U':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 0);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'V':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 0);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 0);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 0);
      break;

    case 'W':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;
    
    case 'X':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 0);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 0);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    case 'Y':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 0);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 0);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 0);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 0);
      break;

    case 'Z':
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);

      setLed(LED4_PIN, LED4_PORT, 0);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 0);

      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;

    default:
      // Bilinmeyen bir karakter gösteriliyorsa tüm LED'leri kapat
      setLed(LED1_PIN, LED1_PORT, 1);
      setLed(LED2_PIN, LED2_PORT, 1);
      setLed(LED3_PIN, LED3_PORT, 1);
      setLed(LED4_PIN, LED4_PORT, 1);
      setLed(LED5_PIN, LED5_PORT, 1);
      setLed(LED6_PIN, LED6_PORT, 1);
      setLed(LED7_PIN, LED7_PORT, 1);
      setLed(LED8_PIN, LED8_PORT, 1);
      setLed(LED9_PIN, LED9_PORT, 1);
      break;
  }
}

int main(void) {
  // Portları başlat
  initPorts();

  // Test amaçlı bir harf göster
  showLetter(asciiToChar(65));  // ASCII 65 = A 

  while (1) {
    // Sonsuz döngü
  }
}