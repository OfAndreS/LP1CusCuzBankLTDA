# 💰 CusCuzBankLTDA

CusCuzBankLTDA é um sistema bancário simples desenvolvido em C++ com persistência em arquivos `.txt`, menus interativos e foco educacional. Ele simula operações bancárias como criação de clientes e contas, depósitos, saques e transferências — tudo via terminal.

---

## 🧠 Visão Geral

* Linguagem: C++17
* Interface: Terminal
* Persistência: Arquivos TXT
* Build System: CMake
* Plataforma alvo: Linux, Windows (via MSVC)

---

## ⚙️ Como Construir e Executar

1. Pré-requisitos:

* CMake >= 3.13
* Compilador C++ com suporte a C++17

2. Passos:

```bash
# Clonar o repositório
git clone <url-do-repo>
cd CusCuzBankLTDA

# Criar diretório de build
mkdir build && cd build

# Gerar Makefiles e compilar
cmake ..
make

# Executar o programa
./CusCuzBankLTDA
```

Ao compilar, os arquivos de recurso serão automaticamente criados em resources/, se não existirem.

---

## 🗂️ Estrutura de Diretórios

```
.
├── CMakeLists.txt
├── resources/
│   ├── clientDataBase.txt      # Armazena CPF e nome dos clientes
│   └── accountDataBase.txt     # Armazena CPF, ID da conta e saldo
├── src/
│   ├── account.cpp             # Lógica de contas bancárias
│   ├── client.cpp              # Lógica de clientes
│   ├── dataFlow.cpp            # Fluxo de criação/acesso de dados
│   ├── ioStreamData.cpp        # Leitura, escrita, atualização e exclusão nos arquivos
│   ├── main.cpp                # Ponto de entrada do programa
│   ├── menu.cpp                # Menus interativos
│   └── utility.cpp             # Utilitários diversos
└── include/                    # Arquivos .h
```

---

## 🖥️ Funcionalidades

### 1. Cliente

* Criar cliente com nome e CPF válido
* Validar formato de CPF (11 ou 14 caracteres)
* Armazenar dados em clientDataBase.txt
* Visualizar lista de clientes
* Excluir cliente por CPF

### 2. Conta Bancária

* Criar conta vinculada a um cliente
* Gerar ID aleatório
* Armazenar dados em accountDataBase.txt
* Acessar conta por ID
* Exibir todas as contas de um CPF
* Excluir conta por ID

### 3. Operações Bancárias

* Depositar valores
* Sacar (com verificação de saldo)
* Transferir entre contas diferentes
* Transferir para duas contas ao mesmo tempo (valor dividido)
* Impede transferências para a própria conta

---

## 🧪 Fluxos

Normal:
* O fluxo normal é a maneira interativa de se executar o programa

Predefinido:
* Executa uma ordem pré-estabelecida pelo professor
* Cria três clientes fictícios
* Gera contas para cada um
* Efetua uma transferência do cliente Ana para Bruno e Carla
* Exibe o saldo atualizado de cada conta

---
## 🔁 Navegação por Fluxos

### 1. Menu Principal (startMenu)

Ao iniciar o programa, o usuário vê o menu principal:

```
| MENU PRINCIPAL
|
| ( 1 ) Fluxo Normal
| ( 2 ) Fluxo Predefinido
| ( 0 ) Encerrar
| Escolha:
```

Opções:

* (1) Fluxo Normal: leva ao menu de gerenciamento de clientes (primeira camada funcional do sistema)
* (2) Fluxo Predefinido: executa um exemplo automático (sem entrada manual)
* (0) Encerra o programa

### 2. Fluxo Normal → Menu de Clientes (firstFlowMenu)

Após escolher “Fluxo Normal”, o usuário é levado ao menu de clientes:

```
| CENTRAL DE ALTERNATIVAS
|
| ( 1 ) Acessar Cliente
|
| ( 2 ) Criar Cliente
| ( 3 ) Exibir Clientes
| ( 4 ) Excluir Cliente
| ( 0 ) Voltar
| Escolha:
```

#### Opções:

* Acessar Cliente: digite um CPF válido e vá para o menu do cliente
* Criar Cliente: digite nome e CPF; o sistema valida e salva no arquivo
* Exibir Clientes: imprime todos os clientes registrados
* Excluir Cliente: remove um cliente por CPF
* Voltar: retorna ao menu principal

### 3. Menu do Cliente (clientMenu)

Após acessar ou criar um cliente, você acessa o menu de operações desse cliente:

```
| CENTRAL DO CLIENTE: <NOME>
|
| ( 1 ) Acessar Conta
|
| ( 2 ) Criar Conta
| ( 3 ) Exibir Contas
| ( 4 ) Excluir Conta
| ( 0 ) Voltar
| Escolha:
```

#### Opções:

* Acessar Conta: digite o ID de uma conta existente (vinculada ao CPF do cliente)
* Criar Conta: gera conta com ID aleatório, saldo 0.0 e vincula ao CPF
* Exibir Contas: mostra todas as contas desse CPF
* Excluir Conta: deleta conta via ID
* Voltar: retorna ao menu de clientes

### 4. Menu da Conta (accountMenu)

Depois de acessar uma conta, você pode fazer transações:

```
| CENTRAL DA CONTA: <ID>
|
| ( 1 ) Sacar
| ( 2 ) Depositar
| ( 3 ) Transferir
| ( 4 ) Transferir para duas contas
| ( 0 ) Voltar
| Escolha:
```

### Opções:

* Sacar: informa o valor, sistema verifica saldo e atualiza arquivo
* Depositar: adiciona valor ao saldo
* Transferir: transfere valor para outra conta (ID diferente)
* Transferir para duas contas: valor é dividido e enviado para dois IDs distintos
* Voltar: retorna ao menu do cliente

📌 Importante

* Cada opção exige entrada válida (CPF, nome, ID, valor etc.)
* O programa imprime cabeçalhos decorativos (printHead) para clareza
* Mensagens de erro e sucesso aparecem imediatamente após cada ação
* Você pode sempre retornar ao menu anterior com a opção (0)

🔄 Ciclo de Navegação

Você pode navegar de forma fluida entre os menus, criando clientes → acessando → gerenciando contas → voltando ao menu inicial. O sistema é projetado para ciclos curtos.

---

## 📋 Formato dos Arquivos

clientDataBase.txt

```
<CPF> | <Nome>
Exemplo:
123.456.789-00 | João da Silva
```

accountDataBase.txt

```
<CPF> | <ID> / <Saldo>
Exemplo:
123.456.789-00 | 54321 / 250.50
```

---

## 💡 Destaques Técnicos

* Modularização com namespace ccBank
* Verificação de dados com tratamento de erros
* Geração de IDs aleatórios
* CMake automatizado com macro RESOURCES\_PATH
* Impressão estética via printLogo e printHead

---

## ✅ Validações

* CPF deve ter 11 (sem máscara) ou 14 (com pontos e hífen) caracteres
* CPF duplicado é rejeitado
* Saldo insuficiente impede saque/transferência
* Não permite transferência para mesma conta
* Linhas de arquivos são numeradas para fácil localização

---

## 📌 Observações

* O sistema não utiliza banco de dados real — usa arquivos .txt para simulação
* Ideal para projetos educacionais ou demonstrações simples de CRUD em C++
* Totalmente operado via terminal

---

## 🧑‍💻 Autor

Feito com dedicação para aprendizado de sistemas bancários simples em C++.
Para dúvidas ou sugestões, entre em contato via \[andre.soares.moreira18@gmail.com].

