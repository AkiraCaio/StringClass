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
        }

        String(char c) {
            characters = new char[1];
            characters[0] = c;
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
        }

 //       int length() {
 //           return characters.size();
 //       }

//        String operator + (char* a) {
//            characters = malloc(x * sizeof(char))
//        }

        String operator = (char* s) {
            return String(s);
        }

        //ostream& operator <<(String const& v) {

        //}

        char* characters;
};

int main() {

    //Item a 

    String a = String();
    String b = String('a');
    String c = String("Caio Pinho");
    cout << c.characters;

}