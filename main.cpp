#include <iostream>

#include <fstream>

#include <vector>

#include <sstream>

using namespace std;

struct Movimentacao {
    string TIPO;
    double VALOR;
    string ORIGEM;
    string DATA;
};
void SalvarMovimentacao(Movimentacao memoria) {
    
    ofstream arquivo;
    
    arquivo.open("movimentacoes.txt", ios::app);
    
    arquivo << memoria.TIPO << ";" << memoria.VALOR << ";" << memoria.ORIGEM << ";" << memoria.DATA << endl;
    
    arquivo.close();
}

void CarregarMemoria(
    double &SALDO,
    vector<Movimentacao> &memoria
) {
    ifstream arquivo_base;

    string LINHA;

    arquivo_base.open("movimentacoes.txt");

    while (getline(arquivo_base, LINHA)) {
        Movimentacao movimento;
        
        string VALOR_TEXTO;

        stringstream ss(LINHA);

        getline(ss, movimento.TIPO, ';');

        getline(ss, VALOR_TEXTO, ';');

        movimento.VALOR = stod(VALOR_TEXTO);

        getline(ss, movimento.ORIGEM, ';');

        getline(ss, movimento.DATA, ';');

        if (movimento.TIPO == "Entrada") {
            SALDO = movimento.VALOR + SALDO;
        } else if (movimento.TIPO == "Saida") {
            SALDO = SALDO - movimento.VALOR ;
        }

        memoria.push_back(movimento);
    }

}

int PerguntarAcao () {
    
    int PERGUNTA;
    
    cout<<"=====MENU=====\n 1 - Nova movimentacao\n 2 - Ver historico\n 3 - Ver saldo\n 4 - Relatorio\n 5 - Buscar e Filtros\n 0 - Sair\n Escolha:\n";
    cin>>PERGUNTA;
    
    if (PERGUNTA == 1) {
        cout<<"Voce escolheu fazer uma nova movimentacao."<<endl;
            
            return 1;
    } else if (PERGUNTA == 2) {

        system("cls");
        cout<<"Voce escolheu ver o Historico "<<endl;
            
            return 2;
    } else if (PERGUNTA == 3) {
        cout<<"Voce escolheu ver o saldo atual."<<endl;
            
            return 3;

    } else if (PERGUNTA == 4) {
        cout<<"Voce escolheu ver o Relatorio de movimentacoes."<<endl;

        return 4;
    } else if (PERGUNTA == 5) {
        
        cout<<"Voce escolheu Buscar e Filtros."<<endl;

        return 5;
    } else if (PERGUNTA == 0) {
        cout<<"Voce escolheu sair do programa."<<endl;
    
            return 0;
    } else {
        cout<<"Nenhuma opcao valida escolhida.\n Saindo do programa."<<endl;
            
            return 0;
    }
    
}

double RealizarMovimentacao (
    double SALDO,
    vector<Movimentacao> &movimentacoes
) {
    
    Movimentacao movimento;

    cout<<"Entrada / Saida?"<<endl;
    cin>>movimento.TIPO;
    
    if (movimento.TIPO == "Entrada") {
        cout<<"Quanto sera a entrada?"<<endl;
    
        cin>>movimento.VALOR;
        
        cin.ignore();
        
        SALDO = SALDO + movimento.VALOR;
        
        cout<<"De onde vem esse dinheiro?"<<endl;
        getline(cin,movimento.ORIGEM);
        
        cout<<"Data da transacao:"<<endl;
        getline(cin,movimento.DATA);
        
        system("cls");
        
        movimentacoes.push_back(movimento);
        
        SalvarMovimentacao(movimento);
        
        return SALDO;
        
    } else if (movimento.TIPO == "Saida") {
        cout<<"Quanto sera a saida?"<<endl;
    
        cin>>movimento.VALOR;
        
        cin.ignore();
        
        SALDO = SALDO - movimento.VALOR;
        
        cout<<"Para onde vai esse dinheiro?"<<endl;
        getline(cin,movimento.ORIGEM);
        
        cout<<"Data da transacao:"<<endl;
        getline(cin,movimento.DATA);
    
        system("cls");
        
        movimentacoes.push_back(movimento);    
        
        SalvarMovimentacao(movimento);
    
        return SALDO;
        
    } else {
        cout<<"Nao foi escolhida nenhuma transacao"<<endl;
        return SALDO;
    }
}
    

    void MostrarHistorico(const vector<Movimentacao>& movimentacoes) {
        
        cout<< "=====HISTORICO====="<<endl;

        for (int i = 0; i < movimentacoes.size(); i++) {

            cout<<i +1<<"- TIPO: "<<movimentacoes[i].TIPO<<endl;
            cout<<"   VALOR DA TRANSACAO: R$"<<movimentacoes[i].VALOR<<endl;
            cout<<"   ORIGEM: "<<movimentacoes[i].ORIGEM<<endl;
            cout<<"   DATA: "<<movimentacoes[i].DATA<<endl;
            cout<<endl;
        }
    }
    
    void ApagarMovimentacao(
    double &SALDO,
    vector<Movimentacao> &memoria
    ) { 

        int ESCOLHA_APAGAR;
        int i;

        cout<<"Qual Movimentacao deseja apagar?"<<endl;
        cin>>ESCOLHA_APAGAR;

        i = ESCOLHA_APAGAR - 1;

        if ((ESCOLHA_APAGAR > 0) && (ESCOLHA_APAGAR <= memoria.size())) {

            if (memoria[i].TIPO == "Entrada") {
                SALDO = SALDO - memoria[i].VALOR;
            } else if (memoria[i].TIPO == "Saida") {
                SALDO = SALDO + memoria[i].VALOR;
            }
            memoria.erase(memoria.begin() + ESCOLHA_APAGAR - 1);

            MostrarHistorico(memoria);
        } else {
            system("cls");
            cout<<"Movimentacao Invalida"<<endl;
        }
}

void ReescreverArquivo(const vector<Movimentacao>& memoria) {

    ofstream arquivo;

    arquivo.open("movimentacoes.txt");

    for (int i = 0; i < memoria.size(); i++) {


        arquivo << memoria[i].TIPO << ";" << memoria[i].VALOR << ";" << memoria[i].ORIGEM << ";" << memoria[i].DATA << endl;
           
        }

    arquivo.close();
}

void EditarMovimentacao(
    double &SALDO,
    vector<Movimentacao> &memoria
) {
    int ESCOLHA_EDITAR;
    int indice;

    cout << "Qual movimentacao deseja editar?" << endl;
    cin >> ESCOLHA_EDITAR;

    if ((ESCOLHA_EDITAR > 0) && (ESCOLHA_EDITAR <= memoria.size())) {

        indice = ESCOLHA_EDITAR - 1;

        Movimentacao antiga = memoria[indice];

        if (antiga.TIPO == "Entrada") {
            SALDO = SALDO - antiga.VALOR;
        } else if (antiga.TIPO == "Saida") {
            SALDO = SALDO + antiga.VALOR;
        }


        cout << "Qual o novo Tipo da movimentacao? (Entrada/Saida)" << endl;
        cin >> memoria[indice].TIPO;

        if ((memoria[indice].TIPO == "Entrada") ||
            (memoria[indice].TIPO == "Saida")) {

            cout << "Qual o novo Valor da movimentacao?" << endl;
            cin >> memoria[indice].VALOR;


            if (memoria[indice].TIPO == "Entrada") {
                SALDO = SALDO + memoria[indice].VALOR;
            } else {
                SALDO = SALDO - memoria[indice].VALOR;
            }

            cin.ignore();

            cout << "Qual a nova Origem da movimentacao?" << endl;
            getline(cin, memoria[indice].ORIGEM);

            cout << "Qual a nova Data da movimentacao?" << endl;
            getline(cin, memoria[indice].DATA);

            ReescreverArquivo(memoria);

            MostrarHistorico(memoria);

        } else {
            cout << "Tipo invalido." << endl;

            memoria[indice] = antiga;

            if (antiga.TIPO == "Entrada") {
                SALDO = SALDO + antiga.VALOR;
            } else if (antiga.TIPO == "Saida") {
                SALDO = SALDO - antiga.VALOR;
            }
        }

    } else {
        cout << "Movimentacao escolhida invalida." << endl;
    }
}

int MenuHistorico () {
    int CAMINHO;
    
    cout<<" 1 - Apagar Movimentacao.\n\n 2 - Editar Movimentacao.\n\n 0 - Voltar\n\n";
    cin>>CAMINHO;
    if (CAMINHO == 0) {
        return 0;
    } else if (CAMINHO == 1) {
        return 1;
    } else if (CAMINHO == 2) {
        return 2;
    } else {
        cout<<"Nenhuma opcao valida escolhida\n";
        return 0;
    }

}

void MostrarRelatorio(
    double SALDO,
    const vector<Movimentacao>& memoria
) {
    double TOTAL_ENTRADAS = 0;
    double TOTAL_SAIDAS = 0;

    for (int i = 0; i < memoria.size(); i++) {
        if (memoria[i].TIPO == "Entrada") {
            TOTAL_ENTRADAS = TOTAL_ENTRADAS + memoria[i].VALOR;
        }
        if (memoria[i].TIPO == "Saida") {
            TOTAL_SAIDAS = TOTAL_SAIDAS + memoria[i].VALOR;
        }

    }

    system("cls");

    cout<<"===== RELATORIO ====="<<endl;
    cout<<"Total de entradas: R$"<<TOTAL_ENTRADAS<<endl;
    cout<<"Total de saidas: R$"<<TOTAL_SAIDAS<<endl;
    cout<<"Saldo atual: R$"<<SALDO<<endl;
    cout<<"Quantidade de movimentacoes: "<<memoria.size()<<endl<<endl;
}

void FiltrarPorTipo(
    const vector<Movimentacao>& memoria,
    string TIPO_BUSCA
) {
    for (int i = 0; i < memoria.size(); i++) {

        if (memoria[i].TIPO == TIPO_BUSCA) {

            cout << i + 1 << " - TIPO: " << memoria[i].TIPO << endl;
            cout << "     VALOR DA TRANSACAO: " << memoria[i].VALOR << endl;
            cout << "     ORIGEM: " << memoria[i].ORIGEM << endl;
            cout << "     DATA: " << memoria[i].DATA << endl;
            cout << endl;
        }
    }
}

void FiltrarPorOrigem(
    const vector<Movimentacao>& memoria,
    string TIPO_BUSCA
) {
    for (int i = 0; i < memoria.size(); i++) {

        if (memoria[i].ORIGEM == TIPO_BUSCA) {
            cout << i + 1 << " - TIPO: " << memoria[i].TIPO << endl;
            cout << "     VALOR DA TRANSACAO: " << memoria[i].VALOR << endl;
            cout << "     ORIGEM: " << memoria[i].ORIGEM << endl;
            cout << "     DATA: " << memoria[i].DATA << endl;
            cout << endl;
        }
    }
}

void FiltrarPorValor(
    const vector<Movimentacao>& memoria,
    double TIPO_BUSCA
) {
    for (int i = 0; i < memoria.size(); i++) {

        if (memoria[i].VALOR == TIPO_BUSCA) {
            cout << i + 1 << " - TIPO: " << memoria[i].TIPO << endl;
            cout << "     VALOR DA TRANSACAO: " << memoria[i].VALOR << endl;
            cout << "     ORIGEM: " << memoria[i].ORIGEM << endl;
            cout << "     DATA: " << memoria[i].DATA << endl;
            cout << endl;
        }
    }
}

int MenuFiltro() {

    int RESPOSTA;

    cout<<"1 - Entradas"<<endl;
    cout<<"2 - Saidas"<<endl;
    cout<<"3 - Origem"<<endl;
    cout<<"4 - Valor"<<endl;
    cout<<"0 - Voltar"<<endl;
    
    cin>>RESPOSTA;
     
    if (RESPOSTA == 0) {
        system("cls");
        cout<<"Opcao escolhida: VOLTAR."<<endl;

        return 0;
    } else if (RESPOSTA == 1) {
        system("cls");
    
        cout<<"Opcao escolhida: ENTRADAS."<<endl;

        return 1;
    } else if (RESPOSTA == 2) {
        system("cls");

        cout<<"Opcao escolhida: SAIDAS."<<endl;

        return 2;
    } else if (RESPOSTA == 3) {
        system("cls");

        cout<<"Opcao escolhida: ORIGEM."<<endl;
        
        return 3;
    } else if (RESPOSTA == 4) {
        system("cls");

        cout<<"Opcao escolhida: VALOR."<<endl;
        
        return 4;

    } else {
        system("cls");

        cout<<"Nenhuma opcao foi escolhida."<<endl;

        return 0;
    }
}

int main() {
 
 double SALDO = 0;
 int OPCAO;
 int OPCAO_HISTORICO;
 int OPCAO_FILTRO;


 string NOME_USUARIO;

 cout<<"Username: "<<endl;
 cin>>NOME_USUARIO;
 
 vector<Movimentacao> movimentacoes;

 CarregarMemoria(SALDO, movimentacoes);

 OPCAO = PerguntarAcao();
 
    while (OPCAO != 0) {
    if (OPCAO == 1) {
        SALDO = RealizarMovimentacao(SALDO, movimentacoes);
    } else if (OPCAO == 2) {
        
        MostrarHistorico(movimentacoes);

        OPCAO_HISTORICO = MenuHistorico();

        while (OPCAO_HISTORICO != 0) {
            
            if (OPCAO_HISTORICO == 1){

                ApagarMovimentacao(SALDO, movimentacoes);

                ReescreverArquivo(movimentacoes);

            } else if ( OPCAO_HISTORICO == 2){

                EditarMovimentacao(SALDO,movimentacoes);

            }

             OPCAO_HISTORICO = MenuHistorico();
        }

    } else if (OPCAO == 3) {
        system("cls");
        cout<<"Saldo Atual: R$"<<SALDO<<endl;
    } else if (OPCAO == 4) {

        MostrarRelatorio(SALDO, movimentacoes);

    } else if (OPCAO == 5) {

        OPCAO_FILTRO = MenuFiltro();

        if (OPCAO_FILTRO == 1) {
            FiltrarPorTipo(movimentacoes, "Entrada");
        } else if (OPCAO_FILTRO == 2) {
            FiltrarPorTipo(movimentacoes, "Saida");
        } else if (OPCAO_FILTRO == 3) {
            string TIPO_ORIGEM;

            cin.ignore();
            
            cout<<"Digite a origem que deseja buscar: "<<endl;
            getline(cin, TIPO_ORIGEM);

            FiltrarPorOrigem(movimentacoes, TIPO_ORIGEM );
        } else if (OPCAO_FILTRO == 4 ) {
            double TIPO_VALOR;
            
            cout<<"Digite o valor que deseja buscar: "<<endl;
            cin>>TIPO_VALOR;

            FiltrarPorValor(movimentacoes, TIPO_VALOR );
        }
        
    }
    
        OPCAO = PerguntarAcao();   
    
    }
}
