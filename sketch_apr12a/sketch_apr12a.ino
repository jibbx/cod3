// ej_01_pulsador_luz
// por montoyamoraga
// v0.0.1 abril 2022
// hecho con Arduino Uno y IDE 1.8.19

// variable para leer info
int pinLectura = 7;

// variable para almacenar estado pulsador
int estadoPulsador = 0;

// variable para conectar LED
int pinLED = 6;
int pinAzul = 8;
int pinRojo = 5;

// variable para estado LED
int estadoLED = 0;

// variable para pausa de intermitencia
const long intervalo = 500;

unsigned long tiempoAnterior = 0;
unsigned long tiempoActual = 0;

int pinEntrada = A0;

int valorSensor = 0;

int valorMin = 1024;
int valorMax = 0;

int rangoMin = 0;
int rangoMax = 255;

int valorMapeado = 0;

void setup() {

  // definir pin lectura como entrada digital
  pinMode(pinLectura, INPUT);

  // definir pin LED como salida digital
  pinMode(pinLED, OUTPUT);
  pinMode(pinAzul, OUTPUT);
  pinMode(pinRojo, OUTPUT);

  // abrir comunicacion serial
  Serial.begin(9600);

}

void loop() {

    // actualizar valor sensor
  valorSensor = analogRead(pinEntrada);

  // actualizar valor minimo
  if (valorSensor < valorMin) {
    valorMin = valorSensor;
  }

  if (valorSensor > valorMax) {
    valorMax = valorSensor;
  }

  // mapear valor
  valorMapeado = map(valorSensor, valorMin, valorMax, rangoMin, rangoMax);

//   imprimir valores min y max
   Serial.print("actual, min, max, mapeado: ");
   Serial.print(valorSensor);
   Serial.print(", ");
   Serial.print(valorMin);
 Serial.print(", ");
   Serial.print(valorMax);
   Serial.print(", ");
  Serial.print(valorMapeado);
   Serial.println("");

  // prender LED segun brillo
  //analogWrite(pinRojo, valorMapeado);

  // leer pin y actualizar variable interna
  estadoPulsador = digitalRead(pinLectura);

  // imprimir informacion por puerto serial
  // Serial.println(estadoPulsador);

  // actualizar estado LED
 // estadoLED = estadoPulsador;

  // usar salida digital para controlar LED
  digitalWrite(pinLED, estadoPulsador);
  analogWrite(pinRojo, valorMapeado);
  //digitalWrite(pinAzul, HIGH);

  if (estadoPulsador > 0) // PRESIONADO
  { 
    digitalWrite(pinRojo, LOW);
    Serial.println("Tercera luz apagada");
    

      // actualizar tiempo actual
    tiempoActual = millis();

    // comprobar si tiempo transcurrido es mayor que intervalo
    if (tiempoActual - tiempoAnterior >= intervalo) 
    {

      // actualizar tiempo previo
      tiempoAnterior = tiempoActual;

      estadoLED = !estadoLED;
      digitalWrite(pinAzul, estadoLED);
    
  }
  }
  else {
      digitalWrite(pinAzul, HIGH);
  
  }

 
  
  
  } 
