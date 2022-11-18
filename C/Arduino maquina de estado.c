//Receptor (con máquina de estado implementada con puntero a funciones)

#define TX 0
#define RX 1

#define LED 4
#define T 1000

void h(void);
void o(void);
void l(void);
void a(void);

void (*estado)(void) = h;

int main(void){
    pinMode(TX, OUTPUT);
    pinMode(RX, INPUT);

    pinMode(LED, OUTPUT);

    for(;;){
        estado();
    }

}

void h(void){
    if(Serial.available()>0 && Serial.read() == 'h'){
        estado = o;
    }
}

void o(void){
    if(Serial.available()>0 && Serial.read() == 'o'){
        estado = l;
    }
    else{
        estado = h;
    }
}

void l(void){
    if(Serial.available()>0 && Serial.read() == 'l'){
        estado = a;
    }
    else{
        estado = h;
    }
}

void a(void){
    digitalWrite(LED, HIGH);
    delay(T);
    digitalWrite(LED, LOW);
    estado = h;
}


//Transmisor

#define RX 0
#define TX 1

void setup() {
  // put your setup code here, to run once:
  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write("hola");
}
