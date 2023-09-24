

// Código para um sensor de luminosidade.
// Definindo as variáveis
int ledVerde = 10;
int ledAmarelo = 11;
int ledVermelho = 12;
int piezo = 13;
int sensor = A0;

void setup()
  //Configurando os pinos dos três leds e do buzzer como saída e o pin do fotoresistor como entrada 
{
  Serial.begin (9600);
  pinMode (sensor, INPUT);
  pinMode (ledVerde, OUTPUT);
  pinMode (ledAmarelo, OUTPUT);
  pinMode (ledVermelho, OUTPUT);
  pinMode (piezo, OUTPUT);
}

void loop()
  //Definindo a variável leitura para exibir os valores captados pelo fotoresistor
{
  int leitura = analogRead (sensor);
  Serial.println (leitura);
  delay (200);

  if (leitura < 150  )
    // Caso o valor indicado pela leitura seja menor que 150, acenda o led verde e apague os demais
  {
    digitalWrite (ledVerde, HIGH);
    digitalWrite (ledAmarelo, LOW);
    digitalWrite (ledVermelho, LOW);
    noTone (piezo);
    delay (500);
  }
  else if (leitura >= 150 && leitura < 260)
    // Caso o valor indicado pela leitura esteja entre 150 e 260, acenda o led amarelo e apague os demais
  {
     digitalWrite (ledVerde, LOW);
    digitalWrite (ledAmarelo, HIGH);
    digitalWrite (ledVermelho, LOW);
    tone (piezo, 5000, 3000);
    delay (3000);
  }
  else
    // Caso o valor indicado pela leitura esteja acima de 260, toque o buzzer e acenda o led vermelho enquanto os outros leds se apagam
  { 
    digitalWrite (ledVerde, LOW);
    digitalWrite (ledAmarelo, LOW);
    digitalWrite (ledVermelho, HIGH);
    tone (piezo, 500, 200);
    delay (200);
  }
}
