#include <stdio.h>
#include <stdint.h>

// m(x) = x^10 + x^3 + 1 => 2^10 + 2^3 + 1 = 1033
#define MOD_POLY 1033 

// Hàm lấy bậc của đa thức (vị trí bit cao nhất)
int get_deg(uint32_t p) {
    if (p == 0) return -1;
    int deg = 0;
    while (p >>= 1) deg++;
    return deg;
}

// Nhân đa thức trong GF(2) (XOR và dịch bit)
uint32_t gf2_mul(uint32_t a, uint32_t b) {
    uint32_t res = 0;
    for (int i = 0; i <= get_deg(b); i++) {
        if ((b >> i) & 1) res ^= (a << i);
    }
    return res;
}

// Chia đa thức trong GF(2): tính q và r sao cho a = q*b + r
void gf2_div(uint32_t a, uint32_t b, uint32_t *q, uint32_t *r) {
    *q = 0; *r = a;
    int deg_b = get_deg(b);
    if (deg_b < 0) return;
    while (get_deg(*r) >= deg_b) {
        int s = get_deg(*r) - deg_b;
        *q ^= (1 << s);
        *r ^= (b << s);
    }
}

void solve_eea_decimal(uint32_t a, uint32_t m) {
    uint32_t r[32], q[32], v[32], w[32];
    r[0] = m; v[0] = 1; w[0] = 0; 
    r[1] = a; v[1] = 0; w[1] = 1;

    printf("\n>>> THUAT TOAN EUCLIDEAN MO RONG (GF 2^10) <<<\n");
    printf("Tim nghich dao cua a = %u voi m(x) = %u\n\n", a, m);
    
    // In bảng
    printf("| %-3s | %-10s | %-10s | %-10s | %-10s |\n", "i", "ri", "qi", "vi", "wi");
    printf("|-----|------------|------------|------------|------------|\n");
    printf("| %-3d | %-10u | %-10s | %-10u | %-10u |\n", -1, r[0], "-", v[0], w[0]);
    printf("| %-3d | %-10u | %-10s | %-10u | %-10u |\n",  0, r[1], "-", v[1], w[1]);

    int i = 2;
    while (1) {
        // Tính toán
        gf2_div(r[i-2], r[i-1], &q[i], &r[i]);
        v[i] = v[i-2] ^ gf2_mul(q[i], v[i-1]);
        w[i] = w[i-2] ^ gf2_mul(q[i], w[i-1]);
        printf("| %-3d | %-10u | %-10u | %-10u | %-10u |\n", i-1, r[i], q[i], v[i], w[i]);
        if (r[i] <= 1) break; // Dừng khi dư bằng 1 (thành công) hoặc 0 (thất bại)
        i++;
    }

    if (r[i] == 1) {
        printf("|-----|------------|------------|------------|------------|\n");
        printf("\n=> KET QUA: %u^-1 mod %u = %u\n", a, m, w[i]);
    } else {
        printf("\n=> KET QUA: %u khong co nghich dao trong truong nay.\n", a);
    }
    printf("===========================================================\n");
}

int main() {
    uint32_t m = MOD_POLY;
    
    // Test vector
    solve_eea_decimal(523, m);
    solve_eea_decimal(1015, m);

    return 0;
}