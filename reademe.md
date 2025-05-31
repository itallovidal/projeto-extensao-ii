# Sistema de Registro de Vendas - Restaurante a Quilo

Este projeto consiste em um programa em linguagem C para registrar e gerenciar as vendas diárias, mensais e anuais de um restaurante a quilo. O sistema permite registrar diferentes tipos de itens vendidos (refeições por peso, quentinhas e bebidas) para geração de relatórios.

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

- [ ] Utilizar `struct` para representar vendas e registros.
- [ ] Utilizar `array` para armazenar os dados das vendas.
- [ ] Utilizar `enum` para diferenciar os tipos de itens (refeição, quentinha, bebida).
- [ ] Utilizar funções para modularizar o código.
- [ ] Implementar algoritmo de ordenação (ex: bubble sort, insertion sort).
- [ ] Código-fonte em linguagem C.
- [ ] Apresentar pseudocódigo antes da implementação.
- [ ] Apresentar testes realizados (entradas e saídas).

---

## ✅ Tipos de Itens

- **Refeição por peso**: valor calculado com base no peso e no preço por kg.
- **Quentinha**: valor fixo de R$ 20,00 + R$ 0,50 de embalagem.
- **Bebidas**: preço unitário * quantidade.

---

## ✅ Funcionalidades

- [ ] Inserção de vendas diárias.
- [ ] Cálculo automático do valor de cada venda.
- [ ] Geração de relatório diário com total vendido.
- [ ] Geração de relatório mensal.
- [ ] Geração de relatório anual com ordenação decrescente por valor total.

---

## Rodando o Código

```shell
gcc main.c utils/utils.c -o main
```


