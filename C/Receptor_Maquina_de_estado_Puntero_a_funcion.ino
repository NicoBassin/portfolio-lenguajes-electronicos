#define TX 1
#define RX 0

#define LED 4
#define T 1000

void h(void);
void o(void);
void l(void);
void a(void);

void (*estado)(void) = h;

void setup(){
    pinMode(TX, OUTPUT);
    pinMode(RX, INPUT);

    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);

    Serial.begin(9600);
}

void loop(){
  estado();
}

void h(void){
    if(Serial.available()>0){
        char lectura = Serial.read();
        Serial.println(lectura);
        if(lectura == 'h'){
          digitalWrite(LED, HIGH); 
        }
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
    Serial.print("estado o");
}

void l(void){
    if(Serial.available()>0 && Serial.read() == 'l'){
        estado = a;
    }
    else{
        estado = h;
    }
    Serial.print("estado l");
}

void a(void){
    Serial.print("estado a");
    digitalWrite(LED, HIGH);
    delay(T);
    digitalWrite(LED, LOW);
    estado = h;
}
