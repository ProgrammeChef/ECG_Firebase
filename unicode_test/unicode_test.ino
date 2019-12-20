void setup() {
 Serial.begin(9600); 

}

long var=0;
String h;
long rec=0;
void loop() {
  Serial.print(var);
  Serial.print(" || ");
  h=String(var);
  Serial.print(h);
  rec=int(h);
  Serial.print(" || ");
  Serial.print(rec);
  Serial.print("\n");
  var+=1;
 

}
