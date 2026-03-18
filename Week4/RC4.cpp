#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 

using namespace std;

class RC4 {
private:
    vector<int> S;
    vector<int> K;
    int N;

public:
    RC4(vector<int> key, int n_size) : K(key), N(n_size) {
        S.resize(N);
    }

    // Giai đoạn 1: Khởi tạo mảng S (KSA)
    void ksa() {
        for (int i = 0; i < N; i++) S[i] = i;
        int j = 0;
        int key_len = K.size();
        for (int i = 0; i < N; i++) {
            j = (j + S[i] + K[i % key_len]) % N;
            swap(S[i], S[j]);
        }
        
        cout << "Ket qua mang S sau buoc KSA: ";
        for (int x : S) cout << x << " ";
        cout << "\n" << endl;
    }

    // Giai đoạn 2: Tạo dòng khóa và mã hóa (PRGA)
    void encrypt(string plaintext) {
        int i = 0, j = 0;

        // In tiêu đề bảng
        cout << left << setw(10) << "Ky tu" 
             << setw(15) << "ASCII (m)" 
             << setw(10) << "Khoa k" 
             << setw(15) << "Ma (Dec)" 
             << "Ma (ASCII)" << endl;
        cout << string(65, '-') << endl;

        for (char &m : plaintext) {
            i = (i + 1) % N;
            j = (j + S[i]) % N;
            swap(S[i], S[j]);
            
            int t = (S[i] + S[j]) % N;
            int k = S[t]; // Giá trị dòng khóa 

            // Tính toán bản mã: C = m XOR k
            unsigned char m_val = (unsigned char)m;
            unsigned char c_val = m_val ^ k;
            char c_char = (char)c_val;

            cout << left << setw(10) << m 
                 << setw(15) << (int)m_val 
                 << setw(10) << k 
                 << setw(15) << (int)c_val;
            
            // Kiểm tra nếu ký tự in được thì hiển thị
            if (c_val >= 32 && c_val <= 126) {
                cout << c_char << endl;
            } else {
                cout << "[non-print]" << endl;
            }
        }
    }
};

int main() {
    // Thông số đề bài
    vector<int> seed_K = {2, 4, 1, 7};
    int N_size = 10; 
    string text = "cybersecurity";

    cout << "BAO CAO KET QUA MA HOA RC4" << endl;
    cout << "--------------------------" << endl;

    RC4 rc4(seed_K, N_size);
    
    // Thực hiện KSA
    rc4.ksa();
    
    // Thực hiện PRGA và in bảng mã hóa
    rc4.encrypt(text);

    return 0;
}