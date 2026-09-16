# Controle Financeiro em C++

Aplicação de linha de comando desenvolvida em C++ para registrar, consultar e gerenciar movimentações financeiras.

O projeto está funcional e continua em desenvolvimento. Atualmente, o foco está na validação de dados, tratamento de erros e robustez da aplicação.

## Sobre o projeto

O Controle Financeiro foi desenvolvido como um projeto de estudo para aplicar, na prática, conceitos aprendidos em C++ e evoluir gradualmente para uma aplicação com maior organização e persistência de dados.

A aplicação permite registrar entradas e saídas financeiras, acompanhar o saldo e consultar o histórico das movimentações diretamente pelo terminal.

Os dados são armazenados localmente em um arquivo de texto e carregados novamente quando o programa é iniciado.

## Funcionalidades

- Cadastro de entradas e saídas.
- Registro de valor, origem e data de cada movimentação.
- Cálculo automático do saldo.
- Histórico completo de movimentações.
- Edição de movimentações existentes.
- Exclusão de movimentações.
- Atualização automática do saldo após edições e exclusões.
- Relatório geral das movimentações.
- Total de entradas e saídas.
- Quantidade de movimentações registradas.
- Busca e filtros por:
  - tipo;
  - origem;
  - valor.
- Menu interativo com submenus.
- Persistência local dos dados em arquivo TXT.
- Carregamento automático das movimentações ao iniciar a aplicação.

## Validação e tratamento de erros

A aplicação possui validações para reduzir entradas inválidas e impedir que dados incorretos sejam adicionados às movimentações.

Atualmente são tratados:

- Opções inválidas nos menus.
- Entradas não numéricas em campos numéricos.
- Valores financeiros iguais ou inferiores a zero.
- Tipos de movimentação inválidos.
- Origem vazia.
- Formato básico de datas.
- Caracteres inválidos nos campos de dia, mês e ano.
- Registros inválidos encontrados no arquivo de dados.
- Falhas na abertura de arquivos.
- Criação do arquivo de dados quando ele ainda não existe.
- Limpeza do fluxo de entrada após entradas inválidas.

## Tecnologias e conceitos utilizados

- C++
- Interface de linha de comando (CLI)
- `struct`
- `vector`
- Funções
- Passagem por referência
- Estruturas condicionais
- Estruturas de repetição
- `stringstream`
- `ifstream` e `ofstream`
- Persistência em arquivo de texto
- Tratamento de exceções com `try/catch`
- Conversão de strings com `stoi` e `stod`
- Validação de entrada com `cin`
- Manipulação de strings

## Como executar

### Requisitos

É necessário possuir um compilador C++ instalado, como o GCC/G++.

### Compilação

Abra o terminal na pasta do projeto e execute:

```bash
g++ -std=c++17 main.cpp -o controle_financeiro
```

### Windows

```powershell
.\controle_financeiro.exe
```

### Linux ou macOS

```bash
./controle_financeiro
```

## Persistência dos dados

As movimentações são armazenadas localmente no arquivo:

```text
movimentacoes.txt
```

Cada movimentação é salva contendo informações como tipo, valor, origem e data.

Ao iniciar a aplicação, o arquivo é lido e as movimentações válidas são carregadas novamente para a memória do programa.

Caso o arquivo ainda não exista, a aplicação cria um novo arquivo para o armazenamento dos dados.

O `movimentacoes.txt` não é versionado pelo Git para evitar a publicação de informações financeiras inseridas durante o uso da aplicação.

## Estrutura atual

```text
.
├── main.cpp
├── .gitignore
└── README.md
```

Atualmente, a implementação está concentrada em `main.cpp`. A separação das responsabilidades em múltiplos arquivos faz parte das próximas etapas do projeto.

## Status do projeto

**Em desenvolvimento.**

A versão atual já permite realizar o fluxo principal de controle financeiro pelo terminal. O desenvolvimento está concentrado na melhoria da robustez antes de avançar para mudanças maiores na estrutura da aplicação.

## Próximas etapas

- Finalizar as validações e o tratamento de erros.
- Organizar o código em múltiplos arquivos.
- Separar responsabilidades da aplicação.
- Substituir a persistência em arquivo TXT por MySQL.
- Desenvolver uma interface gráfica/frontend.
- Implementar relatórios avançados por período.

Essas funcionalidades estão planejadas e ainda não fazem parte da versão atual.

## Objetivo de aprendizado

Este projeto está sendo desenvolvido de forma incremental para praticar conceitos de programação e acompanhar minha evolução no desenvolvimento de software.

A proposta é evoluir a aplicação conforme novos conceitos são estudados, partindo de uma aplicação CLI com persistência em arquivo para uma estrutura com banco de dados e interface própria.

## Autor

**Luiz Paulo Lopes Moura**

Estudante de Análise e Desenvolvimento de Sistemas  
IFSP — Campus Salto
