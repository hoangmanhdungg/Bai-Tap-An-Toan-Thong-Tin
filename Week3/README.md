# BÀI TẬP: THUẬT TOÁN EUCLIDEAN MỞ RỘNG TRÊN $GF(2^{10})$

## 1. Thông tin sinh viên
*   **Họ và tên:** Hoàng Mạnh Dũng
*   **MSSV:** 20234002

## 2. Yêu cầu bài toán
Cài đặt thuật toán Euclidean mở rộng (Extended Euclidean Algorithm) để tìm nghịch đảo nhân của một số trong trường hữu hạn $GF(2^{10})$.
*   **Đa thức tối giản:** $m(x) = x^{10} + x^3 + 1$ (tương ứng giá trị thập phân `1033`).
*   **Test vector:** 
    *   Tìm nghịch đảo của $a = 523$.
    *   Tìm nghịch đảo của $b = 1015$.
*   **Yêu cầu kỹ thuật:** In ra bảng giá trị trung gian của từng bước tính toán ($r_i, q_i, v_i, w_i$) cho đến khi kết thúc thuật toán.

## 3. Lý thuyết tóm tắt
Trong trường $GF(2^{10})$, các phần tử là đa thức bậc tối đa là 9. Phép toán trên trường này khác với số nguyên thông thường:
- **Phép cộng/trừ:** Thực hiện bằng phép toán bitwise `XOR` (do đặc số bằng 2).
- **Phép nhân:** Là phép nhân đa thức không nhớ (Carry-less multiplication).
- **Phép chia:** Chia đa thức để tìm thương $q(x)$ và số dư $r(x)$.
- **Nghịch đảo nhân:** Tìm $w(x)$ sao cho $a(x) \cdot w(x) \equiv 1 \pmod{m(x)}$. Theo thuật toán EEA, điều này đạt được khi số dư cuối cùng $r_n(x) = 1$.

## 4. Cấu trúc bảng kết quả
Chương trình xuất kết quả dưới dạng bảng thập phân để dễ dàng theo dõi:
*   **i:** Chỉ số bước lặp (bắt đầu từ -1 và 0 để khởi tạo).
*   **ri:** Số dư tại bước $i$.
*   **qi:** Thương của phép chia đa thức $r_{i-2}$ cho $r_{i-1}$.
*   **vi, wi:** Các hệ số thỏa mãn phương trình: $m(x)v_i(x) + a(x)w_i(x) = r_i(x)$.
