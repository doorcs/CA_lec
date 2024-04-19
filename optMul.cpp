#include <iostream>

unsigned short Multiplicand, Multiplier; // 2바이트 == 16비트
unsigned int Product; // 4바이트 == 32비트

int main() {
    std::cin >> Multiplicand >> Multiplier;

    Product += Multiplier; // Product의 하위 16비트를 Multiplier로 초기화
    for (int i = 0; i < 16; i++) { // 시프트를 16번 수행
        if (Product & 1) Product += (Multiplicand << 16); // LSB가 1일때만 Multiplicand를 상위 16비트에 더해줌
        Product >>= 1; // 오른쪽 시프트는 항상 수행
    }

    std::cout << Product << '\n'; // 16비트 ALU와 32비트 레지스터로 16비트 곱셈 수행 가능!
}
