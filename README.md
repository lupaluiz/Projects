# Controle Financeiro em C++

Aplicação de terminal desenvolvida individualmente em C++ para registrar e acompanhar movimentações financeiras.

O projeto já está funcional e continua em desenvolvimento, com foco atual na robustez e na organização do código.

## Funcionalidades

- Cadastro de entradas e saídas com valor, origem e data.
- Cálculo automático do saldo.
- Histórico de movimentações.
- Edição e exclusão de registros, com atualização do saldo.
- Relatório geral com total de entradas, total de saídas, saldo e quantidade de movimentações.
- Busca e filtros por tipo, origem e valor.
- Menu interativo com submenus.
- Armazenamento em arquivo TXT e carregamento automático ao iniciar a aplicação.

## Validação e tratamento de erros

- Validação de opções de menu e valores numéricos positivos.
- Verificação de origem vazia e formato básico de datas.
- Tratamento de entradas inválidas no terminal.
- Validação dos registros carregados do arquivo.
- Verificação de abertura e criação do arquivo de dados quando necessário.

## Tecnologias e conceitos utilizados

- C++
- Interface de linha de comando (CLI)
- `struct` e `vector`
- Funções, referências e estruturas de repetição
- `stringstream`
- Leitura e gravação de arquivos com `ifstream` e `ofstream`
- Tratamento de exceções e conversão de dados

## Como executar

É necessário ter um compilador C++ instalado, como o GCC/G++.

Com o terminal aberto na pasta que contém `main.cpp`, compile:

```bash
g++ main.cpp -o controle_financeiro
```

Execute no Windows:

```powershell
.\controle_financeiro.exe
```

Execute no Linux ou macOS:

```bash
./controle_financeiro
```

O programa utiliza o arquivo `movimentacoes.txt` para armazenar os dados localmente. Quando necessário, esse arquivo é criado pela aplicação.

## Estrutura atual

```text
.
├── main.cpp
├── .gitignore
└── README.md
```

O arquivo `movimentacoes.txt` e os arquivos compilados são ignorados pelo Git para evitar a publicação de dados financeiros e arquivos gerados.

## Próximas etapas

- Aprimorar a robustez e o tratamento de erros.
- Organizar o código em múltiplos arquivos.
- Migrar a persistência de dados para MySQL.
- Desenvolver um frontend.
- Implementar relatórios mais avançados por período.

Essas melhorias estão planejadas e ainda não fazem parte da versão atual.

## Autor

Luiz Paulo Lopes Moura  
Estudante de Análise e Desenvolvimento de Sistemas no IFSP Campus Salto.
