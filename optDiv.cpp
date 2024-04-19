#include <iostream>

unsigned short Dividend, Divisor, Remainder, Quotient; // 2바이트 == 16비트
unsigned int Temp; // 4바이트 == 32비트 // 상위 16비트는 Remainder, 하위 16비트는 Quotient

int main() {
    std::cin >> Dividend >> Divisor;

    Temp += Dividend; // Temp 레지스터의 하위 16비트를 Dividend로 초기화
    for (int i = 0; i < 16; i++) {
        Temp <<= 1; // 일단 레지스터 전체를 왼쪽으로 한 칸 시프트
        if ((Temp >> 16) >= Divisor) { // 레지스터의 상위 16비트에서 Divisor를 뺄 수 있는 경우:
            Temp -= (Divisor << 16); // 상위 16비트에서 Divisor를 빼 주고,
            Temp |= 1; // LSB를 1로 바꿔주기
        }
    }

    Remainder = (Temp >> 16); // Temp 레지스터의 상위 16비트는 Remainder(나머지)
    Quotient |= Temp; // Temp 레지스터의 하위 16비트는 Quotient(몫)

    std::cout << Quotient << ' ' << Remainder << '\n';
}
