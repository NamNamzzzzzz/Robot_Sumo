#define RPWM2 11   //LUI TRAI
#define RPWM1 10   //TIEN TRAI
#define LPWM2 6    //LUI PHAI
#define LPWM1 5    //TIEN PHAI
#define D1 3 //TCRT TRUOC PHAI
#define D2 4 //TCRT TRUOC TRAI
#define D4 12 //TCRT SAU
const int Echo2 = A2;
const int Trig2 = A1;
int T_T; // TRƯỚC TRÁI
int T_P; // TRƯỚC TRÁI
int S; // SAU PHẢI
void setup() {
  delay(4940);
  pinMode(Echo2, INPUT);
  pinMode(Trig2, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM2, OUTPUT);
  pinMode(RPWM2, OUTPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D4, INPUT);
}
void FLORENTINO() //CHẠY NHANH NHẤT
{
  analogWrite(RPWM1, 255);//TIEN TRAI
  analogWrite(LPWM1, 255);//TIEN PHAI
  analogWrite(LPWM2, 0);//LUI PHAI
  analogWrite(RPWM2, 0);//LUI TRAI
}
void TIEN() //CHẠY TỪ TỪ
{
  analogWrite(RPWM1, 200);//TIEN TRAI
  analogWrite(LPWM1, 200);//TIEN PHAI
  analogWrite(LPWM2, 0);//LUI PHAI
  analogWrite(RPWM2, 0);//LUI TRAI
}
void LUI() 
{
  analogWrite(RPWM1, 0);//TIEN TRAI
  analogWrite(LPWM1, 0);//TIEN PHAI
  analogWrite(LPWM2, 200);//LUI PHAI
  analogWrite(RPWM2, 200);//LUI TRAI
}

void SPROLL()// XOAY TRÁI VÒNG VÒNG
{
  analogWrite(RPWM1, 150);//TIEN TRAI
  analogWrite(LPWM1, 0);//TIEN PHAI
  analogWrite(LPWM2, 150);//LUI PHAI
  analogWrite(RPWM2, 0);//LUI TRAI
}
void SP_NROLL()//HÀM ROLL NHƯNG MÀ ĐẢO CHIỀU
{
  analogWrite(RPWM1, 0);//TIEN TRAI
  analogWrite(LPWM1, 200);//TIEN PHAI
  analogWrite(LPWM2, 0);//LUI PHAI
  analogWrite(RPWM2, 200);//LUI TRAI
}
void Delay(unsigned long delayTime) 
{
    static unsigned long startTime = 0;
    static bool isDelaying = false;

    if (!isDelaying) 
    {
        startTime = millis();
        isDelaying = true;
    } else if (millis() - startTime >= delayTime)
    {
        isDelaying = false;
    }
}
// }HÀM DELAY KHÔNG CHẶN, CÁCH DÙNG LÀ GỌI HÀM(THỜI GIAN MUÔN DELAY)
void loop() 
{
  // -------------------------- ĐỌC CẢM BIẾN HCSR04 --------------------------//
  unsigned long timer2;
  int dist2;

  digitalWrite(Trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig2, HIGH);
  delayMicroseconds(2);
  digitalWrite(Trig2, LOW);
  timer2 = pulseIn(Echo2, HIGH);
  dist2 = timer2 / 58.82;

  // Serial.print(dist);
  // Serial.println(" TRAI");
  // Serial.print(dist2);
  // Serial.println(" PHAI");
  // delay(100);
  //KHI CHẠY ROBOT COMMAND TOÀN BỘ CÁC DÒNG IN RA SERIAL VÌ SẼ LÀM TĂNG ĐỘ DELAY CỰC KÌ LỚN

  // -------------------------- ĐỌC CẢM BIẾN TCRT5000 --------------------------//
  T_P = digitalRead(D1);
  S = digitalRead(D2);
  T_T = digitalRead(D4);

  // Serial.print("Giá trị cảm biến TRƯỚC TRÁI: ");
  // Serial.println(T_T);
  // Serial.print("Giá trị cảm biến TRƯỚC PHẢI: ");
  // Serial.println(T_P);
  // Serial.print("Giá trị cảm biến SAU : ");
  // Serial.println(S);
  // delay(500);
  //KHI CHẠY ROBOT COMMAND TOÀN BỘ CÁC DÒNG IN RA SERIAL VÌ SẼ LÀM TĂNG ĐỘ DELAY CỰC KÌ LỚN

  // -------------------------- XỬ LÝ ĐIỀU KIỆN ------------------------------//
  static unsigned long luiStartTime = 0;
  static bool isBacking = false;
  static unsigned long rollStartTime = 0; 
  static unsigned long tienStartTime = 0;
  static bool isForward = false;
  if (dist2 < 45) {
    FLORENTINO();
  } else if ((T_T == 0) || (T_P == 0) && S == 1) {
    if (!isBacking) {

      luiStartTime = millis();
      isBacking = true;
    }
    if (millis() - luiStartTime <= 2000) { // Lùi trong 500ms
      LUI();
    } else {
      SP_NROLL(); // Xoay sau khi lùi
      isBacking = false; // Reset trạng thái lùi
    }}
     else if ((T_T == 0 && T_P == 0) && S == 1) {
    if (!isBacking) {
      luiStartTime = millis();
      isBacking = true;
    }
    if (millis() - luiStartTime <= 2000) { // Lùi trong 500ms
      LUI();
    } else {
      SP_NROLL(); // Xoay sau khi lùi
      isBacking = false; // Reset trạng thái lùi
    }
  } else if (S == 0 && (T_T == 1 || T_P == 1)) {
    if (!isForward) {
      tienStartTime = millis();
      isForward = true;
    }
    if (millis() - tienStartTime <= 1500) { // Tiến trong 1000ms
      TIEN();
    } else {
      isForward = false; // Reset trạng thái tiến
    }
  } else {
    SP_NROLL(); // Mặc định xoay
  }
}
