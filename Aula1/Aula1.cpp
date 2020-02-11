// Aula1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <ostream>
#include <iostream>
using namespace std;

//A classe vai implementar o metodo + (com override) e vai falar o que a classe vai fazer
class String {
    public:
        String() {
            characters = new char[1];

            characters[0] = '\0';

            length = 0;
        }

        String(char c) {
            characters = new char[2];
            
            characters[0] = c;
            characters[1] = '\0';
            
            length = 1;
        }

        String(const char* cs) {
            char c = cs[0];
            length = 0;

            while (c != '\0') {
                c = cs[++length];
			}

            characters = new char[length + 1];
            
            for(int i = 0; i < length; i++) {
                characters[i] = cs[i];
			}

            characters[length] = '\0';
        }

 //       int length() {
 //           return characters.size();
 //       }

        String operator + (const char* cs) {
            char c = cs[0];
            int sizeCs = 0;

            while (c != '\0') {
                c = cs[++sizeCs];
            }

            //Criando o array copia com o tamanho atualizado
            char* newArray = new char[length + sizeCs + 1];

            //Copiando os valores ja existentes pro array copia
            for (int i = 0; i < length; i++){
                newArray[i] = characters[i];
            }

            //Introduzindo os novos valores no fim do vetor
            for (int i = 0; i < sizeCs; i++) {
                newArray[length + i] = cs[i];
            }

            //Atualizando os valores da classe
            length = length + sizeCs;

            characters = new char[length + 1];

            for (int i = 0; i < length; i++) {
                characters[i] = newArray[i];
            }

            characters[length] = '\0';

            return *this;
        }

        String operator + (String cs) {
            *this = *this + cs.characters;
            return *this;
        }

        String operator = (char* s) {
            return String(s);
        }

        String operator = (String s) {
            return String(s.characters);
        }


        //ostream& operator <<(String const& v) {

        //}

        char* characters;
        int length;
};

int main() {

    //Item a 

    String a = String();
    //cout << a.characters << endl;

    String b = String('a');
    cout << b.characters << endl;

    String c = String("Caio Pinho");

    //Item b
    String d = "abc";
    String e = String("abc");
    String f = b;
    cout << f.characters << endl;;

    //Item c
    String oi = c + "aaaa";
    cout << oi.characters << endl;

    String g = oi + d + e;
    cout << g.characters << endl;




}