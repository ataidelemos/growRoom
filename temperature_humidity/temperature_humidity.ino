// ======================= MAPA DE PINOS DO DHT11 =====================
// Instalação sensor DHT11
// VCC (esquerda) -> +5V
// pino 2 do sensor ao pino de dados definido em seu Arduino(analogico)
// GND do sensor ao GND
// Conecte o resistor de 10K entre pin 2 (dados)
// e ao pino 1 (VCC) do sensor

// ** Analogico
// A2 -> conector 2 da esquerda para direita no DHT11

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN A1                               // pino que estamos conectado
#define DHTTYPE DHT11                           // DHT 11
DHT dht(DHTPIN, DHTTYPE);                       // inicializa o sensor termohigrometro

int rele_humidificador = 7;                      //Porta ligada ao pino IN1 do modulo. Aciona o humidificador
float h=0;                                      //grava leitura de umidade
float t=0;                                      //grava leitura de temperatura

void setup()
{
  
  pinMode(rele_humidificador, OUTPUT);          //Define pinos para o rele como saida
  dht.begin();                                  //liga o sensor
  Serial.begin(9600);                           //liga o monitor serial
}

void loop()
{
  h = dht.readHumidity();                       //Realiza a leitura da umidade
  t = dht.readTemperature();                    //Realiza a leitura da temperatura
  
  if (isnan(t) || isnan(h)){                    //Testa o retorno da leitura de umidade e temperatura se é válido
    Serial.println("Failed to read from DHT");  //Mensagem de erro caso as leituras falhem
  } 
  else{
    
    Serial.println("Temperatura "+String(t)+" Umidade "+String(h));//imprime o valor no monitor serial
  }
  delay(5000);                                  //Aguarda 5 segundos antes da proxima leitura
}
 
