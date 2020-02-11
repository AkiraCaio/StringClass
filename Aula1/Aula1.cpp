// Aula1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <ostream>
#include <iostream>
#include <exception>

using namespace std;

class ArrayOutOfBoundsException : public exception
{
    virtual const char* what() const throw()
    {
        return "Array out of bounds.";
    }
};

class IllegalArgumentException : public exception
{
    virtual const char* what() const throw()
    {
        return "There are illegal or inappropriate arguments.";
    }
};

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

        String operator = (const char* s) {
            return String(s);
        }

        unsigned char operator [](int index) {

            return this->characters[index];
        }

        /**
            Este método retorna o índice do primeiro local que achar o caractere c.
            Retorna -1 se não houver o caractere enviado. */
        int indice(char c) {
            int indice = 0;
            char cAux = this->characters[0];

            while (cAux != '\0') {
                if (cAux == c) {
                    break;
                }
                cAux = this->characters[++indice];
            }

            return indice == size ? -1 : indice;
        }

        String upcase(int first, int last) {
            validateRange(first, last);

            String newString = this->characters;

            for (int i = first; i < last; i++) {
                newString.characters[i] = toUppercase(this->characters[i]);
            }

            return newString;
        }

        String downcase(int first, int last) {
            validateRange(first, last);

            String newString = this->characters;

            for (int i = first; i < last; i++) {
                newString.characters[i] = toLowercase(this->characters[i]);
            }

            return newString;
        }

        String toggleCase(int first, int last) {
            validateRange(first, last);

            String newString = this->characters;

            for (int i = first; i < last; i++) {
                char c = newString.characters[i];

                if (isLowercase(c)) {
                    newString.characters[i] = toUppercase(c);
                    continue;
                }
                
                if (isUppercase(c)) {
                    newString.characters[i] = toLowercase(c);
                }
            }

            return newString;
        }

        char* characters;

    private:
        int size;

        char toLowercase(char c) {
            return isUppercase(c) ? ((int)c + 32) : c;
        }

        char toUppercase(char c) {
            return isLowercase(c) ? ((int)c - 32) : c;
        }

        bool isLowercase(char c) {
            int ascii = (int)c;

            return ascii >= 97 && ascii <= 122;
        }

        bool isUppercase(char c) {
            int ascii = (int)c;

            return ascii >= 65 && ascii <= 90;
        }

        void validateRange(int first, int last) {
            if (first < 0 || first > size || last > size || last < 0) {
                throw ArrayOutOfBoundsException();
            }

            if (first >= last) {
                throw IllegalArgumentException();
            }
        }
};

int main() {

    //Item a 
    cout << "[Item A]" << endl << endl;

    String a = String();
    cout << a.characters << endl;
    String b = String('a');
    cout << b.characters << endl;
    String c = String("Caio Pinho");
    cout << c.characters << endl << endl;

    //Item b
    cout << "[Item B]" << endl << endl;

    String d = "abc";
    String e = String("abc");
    String f = b;
    cout << f.characters << endl << endl;

    //Item c
    cout << "[Item C]" << endl << endl;

    String g = c + "aaaa";
    cout << g.characters << endl << endl;

    String h = g + d + e;
    cout << g.characters << endl << endl;

    //Item d
    cout << "[Item D]" << endl << endl;

    String i = "Joao";
    i += " Ferreira";
    i += " da Costa Filho";
    cout << i.characters << endl << endl;

    String j = "Senhor ";
    j += i;
    cout << f.characters << endl << endl;

    //Item f
    cout << "[Item F]" << endl << endl;

    String k = "Uma frase para testar";
    cout << k.indice('z') << endl << endl;

    //Item g
    cout << "[Item G]" << endl << endl;

    String l = "UMA frase DOIDA";
    l = l.upcase(0, 15);
    cout << l.characters << endl << endl;

    //Item h
    cout << "[Item H]" << endl << endl;

    String m = "UMA frase DOIDA";
    m = m.downcase(0, 15);
    cout << m.characters << endl << endl;

    //Item i
    cout << "[Item I]" << endl << endl;

    String n = "UMA frase DOIDA";
    n = n.toggleCase(0, 15);
    cout << n.characters << endl << endl;

    //Item j
    cout << "[Item J]" << endl << endl;

    String o = "Testando isso aqui";
    char ch = o[9];
    cout << ch << endl << endl;
}