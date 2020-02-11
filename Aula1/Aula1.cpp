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

            size = 0;
        }

        String(char c) {
            characters = new char[2];
            
            characters[0] = c;
            characters[1] = '\0';
            
            size = 1;
        }

        String(const char* cs) {
            char c = cs[0];
            size = 0;

            while (c != '\0') {
                c = cs[++size];
			}

            characters = new char[size + 1];
            
            for(int i = 0; i < size; i++) {
                characters[i] = cs[i];
			}

            characters[size] = '\0';
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
            char* newArray = new char[size + sizeCs + 1];

            //Copiando os valores ja existentes pro array copia
            for (int i = 0; i < size; i++){
                newArray[i] = characters[i];
            }

            //Introduzindo os novos valores no fim do vetor
            for (int i = 0; i < sizeCs; i++) {
                newArray[size + i] = cs[i];
            }

            //Atualizando os valores da classe
            size += sizeCs;

            characters = new char[size + 1];

            for (int i = 0; i < size; i++) {
                characters[i] = newArray[i];
            }

            characters[size] = '\0';

            return *this;
        }

        String operator + (String cs) {
            *this = *this + cs.characters;
            return *this;
        }

        String operator = (const char* s) {
            return String(s);
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

    cout << "\n";

    //Item d
    String e = "Joao";
    e += " Ferreira";
    e += " da Costa Filho";
    cout << e.characters;

    cout << "\n";

    String f = "Senhor ";
    f += e;
    cout << f.characters;
}