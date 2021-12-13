#define LED_PIN 10
#define PERIOD 120


char* string = "Escribí un cuento de cien palabras perfecto. La gente lo leía con avidez, y lo enviaban entusiasmados a sus amigos. Me llamaron para hablar sobre el cuento en la tele, y desde Hollywood querían adaptarlo. Entonces alguien descubrió que había escrito porque, en vez de por qué, así que ahora sobraba una palabra. Pero quitar cualquiera de ellas desmontaba el delicado mecanismo de relojería que había conseguido construir. Finalmente eliminé un artículo, pero ya no es lo mismo. Los críticos literarios me ignoran, han cancelado el programa al que tenía que ir, y Scorsese ya no me coge el teléfono.";
int string_length;

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  string_length = strlen(string);
  digitalWrite(LED_PIN,HIGH);
}

void loop() 
{
  for(int i = 0; i < string_length; i ++)
  {
    send_byte(string[i]);
  }
  delay(PERIOD);
}

void send_byte(char my_byte)
{
  digitalWrite(LED_PIN, LOW);
  delay(PERIOD);

  //transmission of bits
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(LED_PIN, (my_byte&(0x01 << i))!=0 );
    delay(PERIOD);
  }

  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);

}
