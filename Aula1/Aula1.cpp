// Aula1.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <ostream>
#include <iostream>
using namespace std;

//A classe vai implementar o metodo + (com override) e vai falar o que a classe vai fazer
class String {
    public:
        String() {
            *characters = new char[0];
        }

        String(char c) {
            *characters = new char[1];
            *characters[0] = c;
        }

        String(const char* cs) {
            *characters = cs;


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

        char** characters;
};

int main()
{


    //Item a 

    //String a = String();
    //String b = String('a');
    String c = String("Caio Pinho");

    cout << "\n";
    cout << c.characters;
    

}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
