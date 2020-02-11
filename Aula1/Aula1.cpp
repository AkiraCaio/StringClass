// Aula1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <ostream>
#include <iostream>
using namespace std;

//A classe vai implementar o metodo + (com override) e vai falar o que a classe vai fazer
class String {
    public:
        String() {
            characters = new char[0];
            size = 0;
        }

        String(char c) {
            characters = new char[1];
            characters[0] = c;
            size = 1;
        }

        String(const char* cs) {
            char c = cs[0];
            int size = 0;

            while (c != '\0') {
                c = cs[++size];
			}

            characters = new char[size+1];
            
            for(int i = 0; i < size; i++) {
                characters[i] = cs[i];
			}

            characters[size] = '\0';

            this->size = size;
        }

 //       int length() {
 //           return characters.size();
 //       }

//        String operator + (char* a) {
//            characters = malloc(x * sizeof(char))
//        }

        String operator = (const char* s) {
            return String(s);
        }

        String operator += (const char* cs) {

            //Calcula o tamanho do array de chars
            int nSize = 0;
            char c = cs[0];
            while (c != '\0') {
                c = cs[++nSize];
            }

            //Cria uma copia do array de chars antigo
            char* copy = new char[size];

            for (int i = 0; i < size; i++) {
                copy[i] = this->characters[i];
            }
            
            //Cria um novo array com o tamanho maior
            this->characters = new char[size + nSize + 1];

            for (int i = 0; i < size; i++) {
                this->characters[i] = copy[i];
            }

            for (int i = 0; i < nSize; i++) {
                this->characters[size + i] = cs[i];
            }

            this->characters[size + nSize] = '\0';

            size += nSize;

            return *this;
        }

        String operator += (String s) {
            *this += s.characters;
            return *this;
        }

        //ostream& operator <<(String const& v) {

        //}

        char* characters;

    private:
        int size;
};

int main() {

    //Item a 

    String a = String();
    String b = String('a');
    String c = String("Caio Pinho");
    cout << c.characters;

    cout << "\n";

    //Item b
    String d = "abc";
    cout << d.characters;

    cout << "\n";

    //Item d
    String e = "Joao";
    e += " Ferreira";
    e += " da Costa Filho";
    cout << e.characters;

    cout << "\n";

    String f = "Senhor ";
    f += e += e;
    cout << f.characters;

    //
}