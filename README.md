# Sistema Simulador de Caixa Eletrônico (ATM)

## Descrição do Projeto

Este projeto consiste no desenvolvimento de um **Sistema Simulador de Caixa Eletrônico (ATM – Automated Teller Machine)** utilizando a linguagem **C**.

O sistema simula operações bancárias básicas, permitindo ao usuário interagir por meio de um menu no terminal para realizar consultas e movimentações financeiras.

O projeto foi desenvolvido com o objetivo de aplicar conceitos fundamentais de programação estruturada, lógica computacional e organização de dados.

---

## Objetivo

Desenvolver um sistema de caixa eletrônico que permita ao usuário:

- Consultar saldo
- Realizar depósitos
- Realizar saques
- Visualizar extrato de operações
- Registrar histórico de transações

---

## Funcionalidades

### Consultar Saldo
Permite ao usuário visualizar o saldo atual da conta.

### Depositar
Permite adicionar valores ao saldo da conta, desde que o valor seja válido.

### Sacar
Permite retirar valores da conta, respeitando o limite do saldo disponível.

### Extrato
Exibe o histórico de operações realizadas, incluindo:

- Tipo da operação
- Valor movimentado
- Saldo após a operação

---

## Estruturas e Conceitos Utilizados

O projeto foi desenvolvido aplicando os seguintes conceitos:

- Estruturas (`struct`)
- Vetores
- Funções
- Estruturas de decisão (`if`, `switch`)
- Estruturas de repetição (`do while`, `for`)
- Manipulação de strings
- Entrada e saída de dados
- Organização modular do código

---

## Estrutura do Código

### Struct utilizada

```c
typedef struct {
    char tipo[12];
    float valor;
    float saldoDepois;
} Operacao;
```

Responsável por armazenar:

- Tipo da operação
- Valor movimentado
- Saldo após a transação

---

## Menu do Sistema

O sistema apresenta o seguinte menu:

```text
===== MENU ATM =====
1 - Consultar saldo
2 - Depositar
3 - Sacar
4 - Extrato
0 - Sair
```

---

## Tecnologias Utilizadas

- Linguagem **C**
- **VS Code**
- **Git**
- **GitHub**

---

## Como Executar o Projeto

### 1. Clonar o repositório

```bash
git clone LINK_DO_REPOSITORIO
```

### 2. Entrar na pasta

```bash
cd nome-do-repositorio
```

### 3. Compilar o programa

```bash
gcc codigo.c -o atm
```

### 4. Executar

No Windows:

```bash
atm
```

No Linux/Mac:

```bash
./atm
```

---

## Exemplo de Funcionamento

- Saldo inicial: **R$ 1000.00**
- Usuário escolhe uma operação no menu
- O sistema atualiza o saldo
- O histórico de operações é armazenado e exibido no extrato

---

## Integrantes

- Nome do aluno 1
- Nome do aluno 2
- Nome do aluno 3

---

## Disciplina

**Data Structures and Algorithms**  
Curso: **Ciência da Computação**

---

## Observações

Projeto acadêmico desenvolvido para fins educacionais, com foco na aplicação de conceitos de programação estruturada em linguagem C.

Enzo Freitas RM-572037
Lucas Pinheiro RM-573497
