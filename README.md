# Robot Sumo

## Giới thiệu
Dự án **Robot Sumo** được phát triển nhằm:
- **Tìm hiểu cách sử dụng cảm biến HC-SR04** và cảm biến dòng TCRT-5000.
- **Thử nghiệm khả năng động cơ** và hiệu suất khi thi đấu với các đối thủ.
- Robot được thiết kế để tham gia thi đấu tại **Học Viện Hàng Không** và đã đạt tới vòng Tứ Kết.

Dự án được thực hiện với mục tiêu học hỏi thêm kinh nghiệm lập trình nhúng và phát triển thuật toán điều khiển robot sumo tự động.

---

## Công nghệ và phần cứng sử dụng
- **Arduino Uno**: Vi xử lý chính điều khiển robot.
- **BTS7960 (x2)**: Điều khiển động cơ DC mạnh mẽ.
- **HC-SR04**: Cảm biến siêu âm để phát hiện đối thủ.
- **4x TCRT-5000**: Cảm biến hồng ngoại để nhận diện vạch trên sàn đấu.
- **Động cơ DC**: Loại động cơ mạnh mẽ (không nhớ tên chính xác).
- **Nguồn điện**: Pin cung cấp năng lượng cho toàn bộ hệ thống.

---

## Tính năng
### Tính năng chính:
1. **Tự động dò tìm đối thủ**: Robot sử dụng cảm biến HC-SR04 để xoay vòng tìm đối thủ trên sàn đấu.
2. **Đẩy đối thủ ra khỏi sàn**: Khi phát hiện đối thủ, robot sẽ tăng tốc đẩy đối thủ ra khỏi sàn.
3. **Tránh vượt qua vạch sàn**:
   - Sử dụng cảm biến TCRT-5000 để nhận diện vạch trắng.
   - Robot tự lùi hoặc tiến lên khi phát hiện gần vượt qua vạch.
4. **Điều chỉnh tốc độ và hướng**:
   - Có các chế độ chạy nhanh, chạy chậm, lùi, và xoay tròn để linh hoạt chiến đấu.

---

## Hướng dẫn đấu dây
### Kết nối động cơ với BTS7960 và Arduino:
- **LPWM1 (TIẾN PHẢI)** → Chân số 5 trên Arduino.
- **RPWM1 (TIẾN TRÁI)** → Chân số 10 trên Arduino.
- **LPWM2 (LÙI PHẢI)** → Chân số 6 trên Arduino.
- **RPWM2 (LÙI TRÁI)** → Chân số 11 trên Arduino.

### Kết nối cảm biến HC-SR04 với Arduino:
- **Trig** → Chân A1 trên Arduino.
- **Echo** → Chân A2 trên Arduino.

### Kết nối cảm biến TCRT-5000 với Arduino:
- **D1 (TRƯỚC PHẢI)** → Chân số 3 trên Arduino.
- **D2 (TRƯỚC TRÁI)** → Chân số 4 trên Arduino.
- **D4 (SAU)** → Chân số 12 trên Arduino.

---

## Hướng dẫn sử dụng
1. **Flash mã nguồn**:
   - Sử dụng Arduino IDE để tải mã nguồn từ repository lên Arduino Uno.

2. **Chuẩn bị thi đấu**:
   - Đặt robot lên sàn đấu sumo.
   - Bật nguồn và robot sẽ tự động hoạt động.

3. **Chế độ hoạt động**:
   - **Tìm kiếm đối thủ**: Robot xoay vòng để tìm đối thủ.
   - **Tấn công**: Khi phát hiện đối thủ, robot tăng tốc để đẩy đối thủ ra khỏi sàn.
   - **Tránh vạch trắng**: Robot tự lùi hoặc đổi hướng khi phát hiện vạch trắng trên sàn.

---

## Kết quả
- **Hoạt động ổn định**: Robot thực hiện đầy đủ các chức năng dò tìm đối thủ, đẩy đối thủ, và tránh vạch trắng.
- **Kết quả thi đấu**: Robot tham gia thi đấu tại **Học Viện Hàng Không** và dừng lại ở vòng Tứ Kết.
- **Mục tiêu đạt được**: Học hỏi thêm về cảm biến, lập trình và điều khiển động cơ.

---

## Hạn chế và hướng phát triển
### Hạn chế:
- Phát hiện đối thủ chưa thực sự nhanh và chính xác ở các góc xa.

### Hướng phát triển:
- Tích hợp thêm cảm biến góc rộng hoặc camera để phát hiện đối thủ tốt hơn.
- Nâng cấp động cơ mạnh mẽ hơn để cải thiện lực đẩy.
- Phát triển thuật toán thông minh hơn để tối ưu chiến lược chiến đấu.

---

## Hình ảnh và video
### 1. Mô hình Robot Sumo:
*(Thêm hình ảnh thực tế của robot tại đây)*

---

## Tài liệu tham khảo
- [Datasheet HC-SR04](https://example.com/hc-sr04-datasheet)
- [TCRT-5000 Documentation](https://example.com/tcrt5000-docs)
- [BTS7960 Motor Driver](https://example.com/bts7960-docs)
