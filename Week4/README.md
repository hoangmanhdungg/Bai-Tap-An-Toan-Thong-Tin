# RC4 Encryption Algorithm 

Thực hiện thuật toán mã hóa đối xứng **RC4 (Rivest Cipher 4)** dựa trên các thông số tùy chỉnh cho học phần **An toàn thông tin - E9 (2025.2)**.

## Tổng quan bài toán

Thuật toán được triển khai với các thông số cụ thể sau:
- **Vector trạng thái (S)**: Kích thước $N = 10$ (Giá trị khởi tạo: $[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]$).
- **Hạt mầm (Key)**: $K = [2, 4, 1, 7]$.
- **Thông điệp (Plaintext)**: `"cybersecurity"`.
- **Cơ chế**: Sử dụng XOR bitwise giữa mã ASCII của ký tự và dòng khóa (Keystream).

## Cấu trúc thuật toán

Chương trình bao gồm hai giai đoạn chính của RC4:
1.  **KSA (Key Scheduling Algorithm)**: Hoán vị mảng trạng thái $S$ dựa trên khóa hạt mầm $K$.
2.  **PRGA (Pseudo-Random Generation Algorithm)**: Sinh dòng khóa $k$ và thực hiện phép toán $C(t) = m(t) \oplus k(t)$.
