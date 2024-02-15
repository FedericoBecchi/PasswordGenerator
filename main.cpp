#include <iostream>
#include <cctype>
#include <random>
using namespace std;

#define LUNGHEZZA_MAX 40 // Indica il numero massimo di caratteri della password
#define LUNGHEZZA_MIN 15 // Indica il numero minimo di caratteri della password

#define NUMERO_MINIMO_MAIUSCOLE   1   // Indica il numero minimo di caratteri maiuscoli della password
#define NUMERO_MINIMO_MINUSCOLE   1   // Indica il numero minimo di caratteri minuscoli della password
#define NUMERO_MINIMO_NUMERI      18  // Indica il numero minimo di numeri che deve essere presente
#define NUMERO_CARATTERI_SPECIALI 1   // Indica il numero minimo di caratteri della password

#define PRIMO_CARATTERE_STAMPABILE  33
#define ULTIMO_CARATTERE_STAMPABILE 126

int generate_number_in_range(const int start,const int end){
    random_device rd1; // obtain a random number from hardware
    mt19937 gen1(rd1()); // seed the generator
    uniform_int_distribution<> distr1(start, end); // define the range

    return distr1(gen1);
}

string genera_password(){
    string password;
    int lunghezza_password;
    vector<int> posizioni;


    // GENERAZIONE DELLA LUNGHEZZA DELLA STRINGA
    lunghezza_password = generate_number_in_range(LUNGHEZZA_MIN,LUNGHEZZA_MAX);

    //POPOLAZIONE STRINGA CON SPAZI POPOLAZIONE VECTOR CON POSIZIONI;

    for(int i = 0 ; i < lunghezza_password ; i++) {
        password += ' ';
        posizioni.push_back(i);
    };


    // GENERAZIONE ELEMENTI COME CARATTERI SPECIALI


    // GENERAZIONE ELEMENTI COME NUMERI

    // GENERAZIONE ELEMENTI COME MAIUSCOLE

    // GENERAZIONE ELEMENTI COME MINUSCOLE


    return password;
}


bool isspecial(char c){
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
        char examined_char = password[i];
        isupper(password[i])    ? count_maiuscole++ : count_maiuscole;
        islower(password[i])    ? count_minuscole++ : count_minuscole;
        isdigit(password[i])    ? count_numeri++    : count_numeri;
        isspecial(password[i])  ? count_speciali++  : count_speciali;
    }

    bool ret = (count_maiuscole >= NUMERO_MINIMO_MAIUSCOLE) and (count_minuscole >= NUMERO_MINIMO_MINUSCOLE) and (count_numeri >= NUMERO_MINIMO_NUMERI) and (count_speciali >= NUMERO_CARATTERI_SPECIALI);

    return ret;
}


int main() {

/*    string password;

    do {
        password = genera_password();
    } while (!check_password(password));

    cout << password;*/

    vector<int> el;

    return 0;
}
