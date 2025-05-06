# 💳 ccBank - Simulador de Contas Bancárias

Projeto simples em C++ que simula a criação de clientes e contas bancárias, com funcionalidades de depósito, saque e transferência (individual ou múltipla). O sistema oferece dois fluxos de uso: normal (interativo) e predefinido (automático para testes).

## 📁 Estrutura do Projeto

```
...
```

## 🚀 Funcionalidades

* **Criação de Cliente** com validação de CPF.
* **Criação de Conta Bancária** com ID e saldo inicial.
* **Depósito e Saque** com verificação de valores.
* **Transferência Simples e Dupla** entre contas.
* **Gravação em arquivos** para persistência simples dos dados.
* **Fluxo Interativo (normal)** e **Fluxo Predefinido (teste automático)**.

## 🧪 Exemplo de Fluxo Predefinido

Executado ao escolher a opção `2` no menu principal:

* Cria 3 clientes: Ana, Bruno e Carla.
* Cria 3 contas:

  * Ana (1001) com R\$1000 de saldo
  * Bruno (1002) com saldo zerado
  * Carla (1003) com saldo zerado
* Realiza uma **transferência de R\$500** da conta de Ana dividida entre Bruno e Carla.

## ▶️ Como Executar

1. Compile os arquivos:

```bash
...
```

2. Execute o programa:

```bash
./ccBank
```

## ⚙️ Requisitos

* Compilador C++ compatível com C++11 ou superior.
* Sistema de arquivos com permissões de escrita para os arquivos `.txt` de banco de dados.

## 📝 Autor

Desenvolvido como exercício de lógica de programação e orientação a objetos em C++.
