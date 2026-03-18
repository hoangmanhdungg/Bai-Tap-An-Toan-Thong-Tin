# Thuật toán Mã hóa Playfair - Lab 01

## Thông tin sinh viên
- **Họ và tên:** Hoàng Mạnh Dũng
- **MSSV:** 20234002
- **Môn học:** An toàn thông tin

---

## 1. Thiết lập Ma trận Playfair (Matrix Generation)

Với từ khóa (Keyword) là **MONARCHY**, ma trận 5x5 được tạo ra bằng cách điền từ khóa trước (bỏ các chữ cái trùng và thay J bằng I), sau đó điền các chữ cái còn lại trong bảng chữ cái.

**Ma trận kết quả:**
| | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| **0** | M | O | N | A | R |
| **1** | C | H | Y | B | D |
| **2** | E | F | G | I | K |
| **3** | L | P | Q | S | T |
| **4** | U | V | W | X | Z |

---

## 2. Quy trình mã hóa chi tiết (Step-by-Step)

Văn bản gốc (Plaintext): `Do you like to learn Cryptography course`
Chuẩn hóa (Digraphs): `DO YO UL IK ET OL EA RN CR YP TO GR AP HY CO UR SE`

Dưới đây là bảng phân tích chi tiết quy trình mã hóa cho từng cặp ký tự dựa trên ma trận trên:

| Cặp gốc | Vị trí trong ma trận | Quy tắc áp dụng | Kết quả | Giải thích |
| :---: | :--- | :--- | :---: | :--- |
| **DO** | D(1,4), O(0,1) | Hình chữ nhật | **HR** | D lấy cột của O (1,1) là **H**, O lấy cột của D (0,4) là **R**. |
| **YO** | Y(1,2), O(0,1) | Hình chữ nhật | **HN** | Y lấy cột của O (1,1) là **H**, O lấy cột của Y (0,2) là **N**. |
| **UL** | U(4,0), L(3,0) | Cùng cột | **MU** | U xuống dưới (0,0) là **M**, L xuống dưới (4,0) là **U**. |
| **IK** | I(2,3), K(2,4) | Cùng hàng | **KI** | I sang phải (2,4) là **K**, K sang phải (2,3) là **I**. |
| **ET** | E(2,0), T(3,4) | Hình chữ nhật | **RK** | E lấy cột của T (2,4) là **K**, T lấy cột của E (3,0) là **L**. (Ví dụ: EK) |
| **OL** | O(0,1), L(3,0) | Hình chữ nhật | **PM** | O lấy cột của L (0,0) là **M**, L lấy cột của O (3,1) là **P**. |
| **EA** | E(2,0), A(0,3) | Hình chữ nhật | **IM** | E lấy cột của A (2,3) là **I**, A lấy cột của E (0,0) là **M**. |
| **RN** | R(0,4), N(0,2) | Cùng hàng | **MO** | R sang phải (0,0) là **M**, N sang phải (0,3) là **A**. |

*(Lưu ý: Bảng trên mô phỏng một số cặp tiêu biểu để minh họa quy tắc Hình chữ nhật, Cùng hàng, Cùng cột).*

---

## 3. Các quy tắc áp dụng trong Code
1.  **Cùng hàng:** Thay thế bằng ký tự bên phải (theo vòng tròn).
2.  **Cùng cột:** Thay thế bằng ký tự bên dưới (theo vòng tròn).
3.  **Hình chữ nhật:** Thay thế bằng ký tự ở góc đối diện cùng hàng.
4.  **Xử lý chữ trùng:** Nếu gặp cặp chữ giống nhau (ví dụ: `LL`), chương trình tự động chèn `X` ở giữa thành `LX`.
5.  **Xử lý độ dài lẻ:** Nếu tổng số ký tự là số lẻ, thêm `X` vào cuối.

---

## 4. Hướng dẫn chạy chương trình

### Biên dịch
```bash
g++ Playfair.cpp -o Playfair