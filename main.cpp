#include <iostream>
#include <cctype>
#include <random>
using namespace std;

#define LUNGHEZZA_MAX 20 // Indica il numero massimo di caratteri della password
#define LUNGHEZZA_MIN 10 // Indica il numero minimo di caratteri della password

#define NUMERO_MINIMO_MAIUSCOLE   1   // Indica il numero minimo di caratteri maiuscoli della password
#define NUMERO_MINIMO_MINUSCOLE   2   // Indica il numero minimo di caratteri minuscoli della password
#define NUMERO_MINIMO_NUMERI      1   // Indica il numero minimo di numeri che deve essere presente
#define NUMERO_CARATTERI_SPECIALI 1   // Indica il numero minimo di caratteri della password

#define PRIMO_CARATTERE_STAMPABILE  33
#define ULTIMO_CARATTERE_STAMPABILE 126

string genera_password(){
    string password;
    int lunghezza_password;

    random_device rd1; // obtain a random number from hardware
    mt19937 gen1(rd1()); // seed the generator
    uniform_int_distribution<> distr1(LUNGHEZZA_MIN, LUNGHEZZA_MAX); // define the range

    lunghezza_password = distr1(gen1);

    random_device rd2; // obtain a random number from hardware
    mt19937 gen2(rd2()); // seed the generator
    uniform_int_distribution<> distr2(PRIMO_CARATTERE_STAMPABILE, ULTIMO_CARATTERE_STAMPABILE); // define the range

    for(int i = 0 ; i < lunghezza_password ; i++) {
        char ch = distr2(gen2);
        password+=ch;
    }

    return password;
}

bool isSpecial(char c){
    bool isspecial;
    (c >= '!' and c <= '/') or (c >= ':' and  c<= '@') or (c >= '[' and  c <= 96) or (c >= '{' and  c <= 126) ? isspecial = true : isspecial = false;
    return isspecial;
}

bool check_password(string password){
    int count_maiuscole = 0;
    int count_minuscole = 0;
    int count_numeri = 0;
    int count_speciali = 0;


    for(int i = 0 ; i < password.length(); i++){
        isupper(password[i])    ? count_maiuscole++ : count_maiuscole;
        islower(password[i])    ? count_minuscole++ : count_minuscole;
        isnumber(password[i])   ? count_numeri++    : count_numeri;
        isSpecial(password[i])  ? count_speciali++  : count_speciali;
    }

    return count_maiuscole >= NUMERO_MINIMO_MAIUSCOLE and count_minuscole >= NUMERO_MINIMO_MINUSCOLE and count_numeri >= NUMERO_MINIMO_NUMERI and count_speciali >= NUMERO_CARATTERI_SPECIALI;
}

int main() {

    string password;

    do {
        password = genera_password();
    } while (check_password(password));

    cout << password;

    return 0;
}
