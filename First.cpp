int height = 0; //km
int ves = 1200; //kg
int yaw = 0;
void setup() {
    pinMode(13, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
    math();
}

int math()
{
    Serial.println(" ");
    Serial.println("=========START=========");
    while(ves >= 0)
    {
        if (ves >= 1000)
        {
            height += 1;
            ves -=50;
            Serial.print(ves);
            Serial.println(" ");
        }
        if (height > 30)
        {
            ves -= 195;
        }
        if (ves <= 1000 && ves >= 400)
        {
            height += 4;
            ves -= 25;
            Serial.print(ves);
            Serial.println(" ");
        }
        if (ves <= 400)
        {
            height +=8;
            ves -= 1;
            Serial.print(ves);
            Serial.println(" ");
        }
        if (ves <= 0)
        {
            Serial.println("=========FUEL OVER=========");
            Serial.println("Height reached =");
            Serial.print(height);

        }
    }
    return 0;
}
