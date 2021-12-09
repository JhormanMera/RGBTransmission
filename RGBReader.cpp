void readColor(){
  tcs.setInterrupt(false);
  // Hacer rgb medición relativa y escalar rgb a bytes
  tcs.getRGB(&valueLedR,&valueLedG,&valueLedB);//Get RGB Tiene internamente un método de GetRawData y en Get Raw Data ya está el delay, no es necesario un delay externo
  tcs.setInterrupt(true);
 Serial.println("******************");
 Serial.println("readColor");
 Serial.println(valueLedR);
 Serial.println(valueLedG);
 Serial.println(valueLedB);

}
void readVectorColor(float pos1,float pos2, float pos3){
// 00 1 (255,0,0)
// 01 2 (0,0,255)
// 10 3 (0,255,0)
// 11 4 (255,0,255)
  float comp1=255.00;
  float comp2= 255.00;
  float comp3 = 0.00;
  if((pos1==comp1)&&(pos2==comp3)&&(pos3==comp3)); binaryValue+= "00";
  if((pos1==comp3)&&(pos2==comp3)&&(pos3==comp1)); binaryValue+= "01";
  if((pos1==comp3)&&(pos2==comp1)&&(pos3==comp3)); binaryValue+= "10";
  if((pos1==comp2)&&(pos2==comp3)&&(pos3==comp3)); binaryValue+= "11";
}
void readLetter(){
Serial.print(binaryValue);
     //Minúsculas
     if (binaryValue=="01100001"){ Serial.print("a"); compareLetter='a';return;}
     if (binaryValue=="01100010"){ Serial.print("b"); compareLetter='b';return;}
     if (binaryValue=="01100011"){ Serial.print("c"); compareLetter='c';return;}
     if (binaryValue=="01100100"){ Serial.print("d"); compareLetter='d';return;}
     if (binaryValue=="01100101"){ Serial.print("e"); compareLetter='e';return;}
     if (binaryValue=="01100110"){ Serial.print("f"); compareLetter='f';return;}
     if (binaryValue=="01100111"){ Serial.print("g"); compareLetter='g';return;}
     if (binaryValue=="01101000"){ Serial.print("h"); compareLetter='h';return;}
     if (binaryValue=="01101001"){ Serial.print("i"); compareLetter='i';return;}
     if (binaryValue=="01101010"){ Serial.print("j"); compareLetter='j';return;}
     if (binaryValue=="01101011"){ Serial.print("k"); compareLetter='k';return;}
     if (binaryValue=="01101100"){ Serial.print("l"); compareLetter='l';return;}
     if (binaryValue=="01101101"){ Serial.print("m"); compareLetter='m';return;}
     if (binaryValue=="01101110"){ Serial.print("n"); compareLetter='n';return;}
     if (binaryValue=="01101111"){ Serial.print("o"); compareLetter='o';return;}
     if (binaryValue=="01110000"){ Serial.print("p"); compareLetter='p';return;}
     if (binaryValue=="01110001"){ Serial.print("q"); compareLetter='q';return;}
     if (binaryValue=="01110010"){ Serial.print("r"); compareLetter='r';return;}
     if (binaryValue=="01110011"){ Serial.print("s"); compareLetter='s';return;}
     if (binaryValue=="01110100"){ Serial.print("t"); compareLetter='t';return;}
     if (binaryValue=="01110101"){ Serial.print("u"); compareLetter='u';return;}
     if (binaryValue=="01110110"){ Serial.print("v"); compareLetter='v';return;}
     if (binaryValue=="01110111"){ Serial.print("w"); compareLetter='w';return;}
     if (binaryValue=="01111000"){ Serial.print("x"); compareLetter='x';return;}
     if (binaryValue=="01111001"){ Serial.print("y"); compareLetter='y';return;}
     if (binaryValue=="01111010"){ Serial.print("z"); compareLetter='z';return;}
     //Mayusculas
     if (binaryValue=="01000001"){ Serial.print("A"); compareLetter='A';return;}
     if (binaryValue=="01000010"){ Serial.print("B"); compareLetter='B';return;}
     if (binaryValue=="01000011"){ Serial.print("C"); compareLetter='C';return;}
     if (binaryValue=="01000100"){ Serial.print("D"); compareLetter='D';return;}
     if (binaryValue=="01000101"){ Serial.print("E"); compareLetter='E';return;}
     if (binaryValue=="01000110"){ Serial.print("F"); compareLetter='F';return;}
     if (binaryValue=="01000111"){ Serial.print("G"); compareLetter='G';return;}
     if (binaryValue=="01001000"){ Serial.print("H"); compareLetter='H';return;}
     if (binaryValue=="01001001"){ Serial.print("I"); compareLetter='I';return;}
     if (binaryValue=="01001010"){ Serial.print("J"); compareLetter='J';return;}
     if (binaryValue=="01001011"){ Serial.print("K"); compareLetter='K';return;}
     if (binaryValue=="01001100"){ Serial.print("L"); compareLetter='L';return;}
     if (binaryValue=="01001101"){ Serial.print("M"); compareLetter='M';return;}
     if (binaryValue=="01001110"){ Serial.print("N"); compareLetter='N';return;}
     if (binaryValue=="01001111"){ Serial.print("O"); compareLetter='O';return;}
     if (binaryValue=="01010000"){ Serial.print("P"); compareLetter='P';return;}
     if (binaryValue=="01010001"){ Serial.print("Q"); compareLetter='Q';return;}
     if (binaryValue=="01010010"){ Serial.print("R"); compareLetter='R';return;}
     if (binaryValue=="01010011"){ Serial.print("S"); compareLetter='S';return;}
     if (binaryValue=="01010100"){ Serial.print("T"); compareLetter='T';return;}
     if (binaryValue=="01010101"){ Serial.print("U"); compareLetter='U';return;}
     if (binaryValue=="01010110"){ Serial.print("V"); compareLetter='V';return;}
     if (binaryValue=="01010111"){ Serial.print("W"); compareLetter='W';return;}
     if (binaryValue=="01011000"){ Serial.print("X"); compareLetter='X';return;}
     if (binaryValue=="01011001"){ Serial.print("Y"); compareLetter='Y';return;}
     if (binaryValue=="01011010"){ Serial.print("Z"); compareLetter='Z';return;}
     //Números
     if (binaryValue=="00110000"){ Serial.print("0"); compareLetter='0';return;}
     if (binaryValue=="00110001"){ Serial.print("1"); compareLetter='1';return;}
     if (binaryValue=="00110010"){ Serial.print("2"); compareLetter='2';return;}
     if (binaryValue=="00110011"){ Serial.print("3"); compareLetter='3';return;}
     if (binaryValue=="00110100"){ Serial.print("4"); compareLetter='4';return;}
     if (binaryValue=="00110101"){ Serial.print("5"); compareLetter='5';return;}
     if (binaryValue=="00110110"){ Serial.print("6"); compareLetter='6';return;}
     if (binaryValue=="00110111"){ Serial.print("7"); compareLetter='7';return;}
     if (binaryValue=="00111000"){ Serial.print("8"); compareLetter='8';return;}
     if (binaryValue=="00111001"){ Serial.print("9"); compareLetter='9';return;}
     //Tildes minúsculas
     if (binaryValue=="11100001"){ Serial.print("á"); compareLetter='á';return;}
     if (binaryValue=="11101001"){ Serial.print("é"); compareLetter='é';return;}
     if (binaryValue=="11101101"){ Serial.print("í"); compareLetter='í';return;}
     if (binaryValue=="11110011"){ Serial.print("ó"); compareLetter='ó';return;}
     if (binaryValue=="11111010"){ Serial.print("ú"); compareLetter='ú';return;}
     //Tildes mayúsculas
     if (binaryValue=="11000001"){ Serial.print("Á"); compareLetter='Á';return;}
     if (binaryValue=="11001001"){ Serial.print("É"); compareLetter='É';return;}
     if (binaryValue=="11001101"){ Serial.print("Í"); compareLetter='Í';return;}
     if (binaryValue=="11010011"){ Serial.print("Ó"); compareLetter='Ó';return;}
     if (binaryValue=="11011010"){ Serial.print("Ú"); compareLetter='Ú';return;}
     //Símbolos
     if(binaryValue=="00100101"){Serial.print("%"); compareLetter='%';return;}
     if(binaryValue=="00100110"){Serial.print("&"); compareLetter='&';return;}
     if(binaryValue=="00101010"){Serial.print("*"); compareLetter='*';return;}
     if(binaryValue=="00100000"){Serial.print(" "); compareLetter=' ';return;}
     if(binaryValue=="00101110"){Serial.print("."); compareLetter='.';return;}
     if(binaryValue=="00101100"){Serial.print(","); compareLetter=',';return;}
     if(binaryValue=="00100001"){Serial.print("!"); compareLetter='!';return;}
     if(binaryValue=="00100010"){Serial.print('"'); compareLetter='"';return;}
     if(binaryValue=="00100011"){Serial.print("#"); compareLetter='#';return;}
     if(binaryValue=="00100100"){Serial.print("$"); compareLetter='$';return;}
     if(binaryValue=="00101000"){Serial.print("("); compareLetter='(';return;}
     if(binaryValue=="00101001"){Serial.print(")"); compareLetter=')';return;}
     if(binaryValue=="00101011"){Serial.print("+"); compareLetter='+';return;}
     if(binaryValue=="00101101"){Serial.print("-"); compareLetter='-';return;}
     if(binaryValue=="00101111"){Serial.print("/"); compareLetter='/';return;}
     if(binaryValue=="00111010"){Serial.print(":"); compareLetter=':';return;}
     if(binaryValue=="00111011"){Serial.print(";"); compareLetter=';';return;}
     if(binaryValue=="00111100"){Serial.print("<"); compareLetter='<';return;}
     if(binaryValue=="00111101"){Serial.print("="); compareLetter='=';return;}
     if(binaryValue=="00111110"){Serial.print(">"); compareLetter='>';return;}
     if(binaryValue=="00111111"){Serial.print("?"); compareLetter='?';return;}
     if(binaryValue=="01000000"){Serial.print("@"); compareLetter='@';return;}
     if(binaryValue=="01011011"){Serial.print("["); compareLetter='[';return;}
     if(binaryValue=="01011101"){Serial.print("]"); compareLetter=']';return;}
     if(binaryValue=="01011110"){Serial.print("^"); compareLetter='^';return;}
     if(binaryValue=="01011111"){Serial.print("_"); compareLetter='_';return;}
     if(binaryValue=="01111011"){Serial.print("{"); compareLetter='{';return;}
     if(binaryValue=="01111101"){Serial.print("}"); compareLetter='}';return;}
     if(binaryValue=="01111100"){Serial.print("|"); compareLetter='|';return;}
     if(binaryValue=="01111110"){Serial.print("~"); compareLetter='~';return;}
}
