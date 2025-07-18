# Sistema de Registro de Vendas - Restaurante a Quilo

Este projeto consiste em um programa em linguagem C para registrar e gerenciar as vendas diárias, mensais e anuais de um restaurante a quilo. O sistema permite registrar diferentes tipos de itens vendidos (refeições por peso, quentinhas e bebidas) para geração de relatórios.

---

## 📚 Alunos responsáveis:

- Itallo Vidal [Matrícula: 1230114462]
- Maria Eduarda B Ferreira [Matrícula: 1240107648]
- Gabriel Silva Franciscone [Matrícula: 1240117399]
- Rayanne Da Silva [Matrícula: 1240201001]

---

## ✅ Objetivos do Programa

- Registrar vendas diárias de refeições, quentinhas e bebidas.
- Calcular valores com base no peso, preço fixo e quantidade.
- Gerar relatório diário com o total de vendas.
- Gerar relatório mensal com o total vendido no mês.
- Ordenar e exibir os totais mensais em ordem decrescente.
- Simular uma média de 100 refeições por dia.

---

## ✅ Requisitos Obrigatórios

- [x] Utilizar `struct` para representar vendas e registros.
- [x] Utilizar `array` para armazenar os dados das vendas.
- [x] Utilizar `enum` para diferenciar os tipos de itens (refeição, quentinha, bebida).
- [x] Utilizar funções para modularizar o código.
- [x] Implementar algoritmo de ordenação (ex: bubble sort, insertion sort).
- [x] Código-fonte em linguagem C.

---

## ✅ Tipos de Itens

- **Refeição por peso**: valor calculado com base no peso e no preço por kg.
- **Quentinha**: valor fixo de R$ 20,00 + R$ 0,50 de embalagem.
- **Bebidas**: preço unitário \* quantidade.

---

## ✅ Funcionalidades

- [x] Inserção de vendas diárias.
- [x] Cálculo automático do valor de cada venda.
- [x] Geração de relatório diário com total vendido.
- [x] Geração de relatório mensal com ordenação decrescente por valor total.

---

## Rodando o Código

```shell
gcc main.c utils/*.c operations/*.c -o main
```
