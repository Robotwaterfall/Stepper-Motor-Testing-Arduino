#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

int step_number = 0;

// Half-step sequence (8 steps)
const int stepSequence[8][4] = {
  {HIGH, LOW,  LOW,  LOW},
  {HIGH, HIGH, LOW,  LOW},
  {LOW,  HIGH, LOW,  LOW},
  {LOW,  HIGH, HIGH, LOW},
  {LOW,  LOW,  HIGH, LOW},
  {LOW,  LOW,  HIGH, HIGH},
  {LOW,  LOW,  LOW,  HIGH},
  {HIGH, LOW,  LOW,  HIGH}
};

void setup() {
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop() {
  OneStep(true);  // true = forward, false = backward
  delay(2);       // Adjust this delay to change speed
}

void OneStep(bool dir) {
  if (dir) step_number++;
  else     step_number--;

  if (step_number > 7) step_number = 0;
  if (step_number < 0) step_number = 7;

  digitalWrite(STEPPER_PIN_1, stepSequence[step_number][0]);
  digitalWrite(STEPPER_PIN_2, stepSequence[step_number][1]);
  digitalWrite(STEPPER_PIN_3, stepSequence[step_number][2]);
  digitalWrite(STEPPER_PIN_4, stepSequence[step_number][3]);
}