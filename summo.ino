// Declaration of IR pins
#define fIrRP A0
#define fIrLP A1
#define bIrRP A2
#define bIrLP A3

// Declaration of R motor controller pins
#define eR 11
#define in2 12
#define in1 13
// Declaration of L motor controller pins
#define eL 10
#define in4 9
#define in3 8

unsigned long long int cu = 0;
// int p1000 = 1000;
// unsigned long long int time_now1 = 0;
// unsigned long long int time_now2 = 0;

void setup()
{
    pinMode(fIrRP, INPUT);
    pinMode(fIrLP, INPUT);
    pinMode(bIrRP, INPUT);
    pinMode(bIrLP, INPUT);

    pinMode(eR, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in1, OUTPUT);

    pinMode(eL, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(2, INPUT);

    cu = millis();
    Serial.begin(115200);
    setSpeed(eL, 100);
    setSpeed(eR, 100);
}

void loop()
{
    // Serial.println(digitalRead(A1));
    Serial.println(irCh('f', 'l'));
    delay(500);
    // turn('r', 10);
    // if (millis() - cu >= 500)
    // {
    // }
}

bool irCh(char forb, char side)
{
    if (forb == 'f' && side == 'r')
        return !(digitalRead(fIrRP));
    else if (forb == 'f' && side == 'l')
        return !(digitalRead(fIrLP));
    else if (forb == 'b' && side == 'r')
        return !(digitalRead(bIrRP));
    else if (forb == 'b' && side == 'l')
        return !(digitalRead(fIrRP));
}
void setSpeed(char Motor, int speed)
{
    analogWrite(Motor, speed); // eL and eR
}
void forward()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
}
void rev()
{
    digitalWrite(in2, HIGH);
    digitalWrite(in4, HIGH);
}
void stopF()
{
    digitalWrite(in1, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in4, HIGH);
    delay(100);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
}
void stopR()
{
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
    delay(100);
    digitalWrite(in1, LOW);
    digitalWrite(in3, LOW);
}
void turn(char dir, int deg)
{
    if (dir == 'r')
    {
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        delay(deg * 100);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        delay(deg * 100);
    }
    else if (dir == 'l')
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in4, HIGH);
        delay(deg * 100);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        delay(deg * 100);
    }
}
void off()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

// if ((millis() - time_now1) >= 1000)
// {
//     time_now1 = millis();
//     unsigned int a = time_now1;
//     Serial.println("Hello");
//     Serial.println(millis());
//     Serial.println(a);
//     digitalWrite(in2, HIGH);
//     digitalWrite(in3, HIGH);
// }

// if ((millis() - time_now2) >= 1000)
// {
//     time_now2 = millis();
//     unsigned int a = time_now2;
//     Serial.println("Hello");
//     Serial.println(millis());
//     Serial.println(a);

//     digitalWrite(in2, LOW);
//     digitalWrite(in3, LOW);
// }
