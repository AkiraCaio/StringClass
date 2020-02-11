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
        /**
           Cria uma String vazia.   
        */
        String() {
            characters = new char[1];

            characters[0] = '\0';

            size = 0;
        }

        /**
           Cria uma String com um único caractere.
        */
        String(char c) {
            characters = new char[2];
            
            characters[0] = c;
            characters[1] = '\0';
            
            size = 1;
        }

        /**
           Cria uma String com os caracteres passados.
        */
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

        bool operator == (String s) {
            if (size != s.length()) {
                return false;
            }

            for (int i = 0; i < size; i++) {
                if (this->characters[i] != s.characters[i]) {
                    return false;
                }
            }

            return true;
        }

        bool operator != (String s) {
            if (size != s.length()) {
                return true;
            }

            for (int i = 0; i < size; i++) {
                if (this->characters[i] != s.characters[i]) {
                    return true;
                }
            }

            return false;
        }

        bool operator > (String s) {
            return this->length() > s.length();
        }

        bool operator < (String s) {
            return this->length() < s.length();
        }

        bool operator <= (String s) {
            return this->length() <= s.length();
        }

        bool operator >= (String s) {
            return this->length() >= s.length();
        }

        /**
           Retorna a quantidade de caracteres da String.
        */
        int length() {
            return size;
        }

        /**
            Este método retorna o índice do primeiro local onde o caractere c foi encontrado.
            Retorna -1 se o caractere não for encontrado. */
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

        /**
           Modifica os caracteres dentro de intervalo para maiúsculos.
           Retorna a String com os caracteres modificados.
        */
        String upcase(int first, int last) {
            validateRange(first, last);

            String newString = this->characters;

            for (int i = first; i < last; i++) {
                newString.characters[i] = toUppercase(this->characters[i]);
            }

            return newString;
        }

        /**
           Modifica os caracteres dentro de intervalo para minúsculos.
           Retorna a String com os caracteres modificados.
        */
        String downcase(int first, int last) {
            validateRange(first, last);

            String newString = this->characters;

            for (int i = first; i < last; i++) {
                newString.characters[i] = toLowercase(this->characters[i]);
            }

            return newString;
        }

        /**
           Modifica os caracteres dentro de intervalo para maiúsculos se forem minúsculos
           e minúsculos para maiúsculos.
           Retorna a String com os caracteres modificados.
        */
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

        friend ostream& operator << (ostream& out, const String& st);
        friend istream& operator >> (istream& in, const String& st);
    private:
        char* characters;
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

ostream& operator << (ostream& out, const String& st) {
    out << st.characters;

    return out;
}

istream& operator >> (istream& in, const String& c) {
    cout << "String text: ";
    in >> c.characters;

    return in;
}

int main() {

    //Item a 
    cout << "[Item A]" << endl << endl;

    String a = String();
    cout << a << endl;
    String b = String('a');
    cout << b << endl;
    String c = String("Caio Pinho");
    cout << c << endl << endl;

    //Item b
    cout << "[Item B]" << endl << endl;

    String d = "abc";
    String e = String("abc");
    String f = b;
    cout << f << endl << endl;

    //Item c
    cout << "[Item C]" << endl << endl;

    String g = c + "aaaa";
    cout << g << endl << endl;

    String h = g + d + e;
    cout << g << endl << endl;

    //Item d
    cout << "[Item D]" << endl << endl;

    String i = "Joao";
    i += " Ferreira";
    i += " da Costa Filho";
    cout << i << endl << endl;

    String j = "Senhor ";
    j += i;
    cout << f << endl << endl;

    //Item e
    cout << "[Item E]" << endl << endl;

    cout << d << ": " << d.length() << endl;
    cout << i << ": " << i.length() << endl;

    //Item f
    cout << "[Item F]" << endl << endl;

    String k = "Uma frase para testar";
    cout << k.indice('z') << endl << endl;

    //Item g
    cout << "[Item G]" << endl << endl;

    String l = "UMA frase DOIDA";
    l = l.upcase(0, 15);
    cout << l << endl << endl;

    //Item h
    cout << "[Item H]" << endl << endl;

    String m = "UMA frase DOIDA";
    m = m.downcase(0, 15);
    cout << m << endl << endl;

    //Item i
    cout << "[Item I]" << endl << endl;

    String n = "UMA frase DOIDA";
    n = n.toggleCase(0, 15);
    cout << n << endl << endl;

    //Item j
    cout << "[Item J]" << endl << endl;

    String o = "Testando isso aqui";
    char ch = o[9];
    cout << ch << endl << endl;

    //Item K
    cout << "[Item K]" << endl << endl;

    String um = "Joao";
    String dois = "Joao";
    String tres = "Caio";
    String quatro = "Uma String";
    String cinco = "Uma String maior";

    cout << "operator [==]" << endl << endl;
    
    cout << (um == dois) << endl;
    cout << (dois == tres) << endl << endl;

    cout << "operator [!=]" << endl << endl;

    cout << (um != dois) << endl;
    cout << (dois != tres) << endl << endl;

    cout << "operator [>]" << endl << endl;

    cout << (quatro > cinco) << endl;

    cout << "operator [<]" << endl << endl;

    cout << (quatro < cinco) << endl;

    cout << "operator [<=]" << endl << endl;

    cout << (quatro <= cinco) << endl;

    cout << "operator [>=]" << endl << endl;

    cout << (quatro >= cinco) << endl;

    //Item l
    cout << "[Item l]" << endl << endl;

    cout << o << endl;

    String z;
    cin >> z;
    cout << z<< endl;
}