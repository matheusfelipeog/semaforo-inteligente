// Botões do semáforo para os pedestres
int btn_semaforo_1 = 13;
int btn_semaforo_2 = 2;

// Semáforo principal --------------------
int led_1_red = 11;
int led_1_yellow = 10;
int led_1_green = 9;


// Semáfaro pedestres ---------------------
// primeira dupla
int led_pedestre_1_green = 7;
int led_pedestre_1_red = 6;

// segunda dupla
int led_pedestre_2_green = 4;
int led_pedestre_2_red = 3;


// Funções para ligar semáforo principal --------
void ligaVerde(void){
  digitalWrite(led_1_green, LOW);
  digitalWrite(led_1_red, HIGH);
}

void ligaAmarelo(void){
  digitalWrite(led_1_red, LOW);
  digitalWrite(led_1_yellow, HIGH);
  delay(2000);
}

void ligaVermelho(void){
  digitalWrite(led_1_yellow, LOW);
  digitalWrite(led_1_green, HIGH);
  delay(5000);
}


// Funções para ligar semáforos pedestre ---------
void ligaVerdePedestre(void){
  digitalWrite(led_pedestre_1_green, HIGH);
  digitalWrite(led_pedestre_2_green, HIGH);
  digitalWrite(led_pedestre_1_red, LOW);
  digitalWrite(led_pedestre_2_red, LOW);
}

void ligaVermelhoPedestre(void){
  digitalWrite(led_pedestre_1_green, LOW);
  digitalWrite(led_pedestre_2_green, LOW);
  digitalWrite(led_pedestre_1_red, HIGH);
  digitalWrite(led_pedestre_2_red, HIGH);
}


// Definindo modo dos pinos
void setup()
{
  pinMode(btn_semaforo_1, INPUT);
  pinMode(btn_semaforo_2, INPUT);
  
  pinMode(led_1_red, OUTPUT);
  pinMode(led_1_yellow, OUTPUT);
  pinMode(led_1_green, OUTPUT);
  
  pinMode(led_pedestre_1_green, OUTPUT);
  pinMode(led_pedestre_2_green, OUTPUT);
  pinMode(led_pedestre_1_red, OUTPUT);
  pinMode(led_pedestre_2_red, OUTPUT);
  
  Serial.begin(9600);
}

int btn_pressionado = 0;

// Loop para o funcionamento do semáforo
void loop()
{
  Serial.println(digitalRead(btn_semaforo_1));
  
  if (digitalRead(btn_semaforo_1) == HIGH ||
      digitalRead(btn_semaforo_2) == HIGH){
    btn_pressionado = 1;
  	ligaAmarelo();
  	ligaVerdePedestre();
  	ligaVermelho();
  }
  
  ligaVermelhoPedestre();
  ligaVerde();
  
  // Aguardar 5 segundos após pressionar o botão
  if (btn_pressionado == 1){
    delay(5000);
    btn_pressionado = 0;
  }
  
  
  delay(250); // Evita loop desnecessário
  
}