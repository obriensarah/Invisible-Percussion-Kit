
#define buff_size 5
int bufferX[buff_size] = {};
int bufferY[buff_size] = {};
int counter = 0;
unsigned long prevMillisL = 0;
unsigned long prevMillisR = 0;
int debounce = 200; //milliseconds

void setup()
{
  // Initialize serial communication at 115200 baud
  Serial.begin(115200);
  unsigned long prevMillisL = millis();
  unsigned long prevMillisR = prevMillisL;
  delay(1000);
}

// Read, scale, and print accelerometer data
void loop()
{
  if (counter >= buff_size) {
    counter = 0;
  }

  int rawX = analogRead(A0);
  int rawY = analogRead(A1);
  int rawZ = analogRead(A2);

  int rawZ_left = analogRead(A5);
  int rawX_left = analogRead(A3);
  int rawY_left = analogRead(A4);

  bufferX[counter] = rawX;
  bufferY[counter] = rawY;

  int sumX = 0;
  int sumY = 0;
  for (int j = 0; j < buff_size; j++) {
    sumX += bufferX[j];
    sumY += bufferY[j];
  }

  int avgX = sumX / buff_size;
  int avgY = sumY / buff_size;

  int upper_bound = 500;
  int lower_bound = 400;

  if (rawX >= 400) {
    int volume = (rawX - lower_bound) * 85;
    volume = volume / (upper_bound - lower_bound);
    volume += 60;
    if (volume > 145) {
      volume = 145;
    }

    if (millis() - prevMillisR > debounce) {
      prevMillisR = millis();
      Serial.write(255); //signaling new hit

      if (avgY <= 295 && volume < 130) {
        Serial.write(130);
      }
      else {
        Serial.write(volume); //writes the volume, then the Y value
      }

      if (avgY >= 365) { //left
        Serial.write(1);
      }
      else if (avgY >= 305 && avgY < 348) { //up
        Serial.write(2);
      }
      else if (avgY <= 295) { //right
        Serial.write(3);
      }
    }
  }

  int lb_left = 280;
  int ub_left = 240;
  if (rawX_left <= lb_left) {

    //    int volume_left = (lb_left - rawX_left) * 85;
    //    volume_left = volume_left / (lb_left - ub_left);
    //    volume_left += 60;
    //
    //    if (volume_left > 145) {
    //      volume_left = 145;
    //    }

    int volume_left = 0;
    if (rawX_left <= 300 && rawX > 270) {
      volume_left = 100;
    }
    else if (rawX_left <= 270 && rawX > 240) {
      volume_left = 140;
    }
    if (millis() - prevMillisL > debounce) {
      prevMillisL = millis();
      Serial.write(255);
      Serial.write(volume_left);

      Serial.write(4);
    }
  }
  delay(50);
  counter++;
}
