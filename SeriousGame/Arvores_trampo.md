# 🌳 Design de Jogo Educativo — Árvores Avançadas

[![Estruturas de Dados II](https://img.shields.io/badge/Disciplina-Estruturas%20de%20Dados%20II-blue?style=for-the-badge)](#-introdução)
[![Árvore Rubro-Negra](https://img.shields.io/badge/Estrutura-Árvore%20Rubro--Negra-red?style=for-the-badge)](#-inovação-proposta)
[![Status](https://img.shields.io/badge/Status-Projeto%20Acadêmico-success?style=for-the-badge)](#-conclusão)

> 🎓 Projeto desenvolvido para a disciplina de **Estruturas de Dados II**, com foco em **Engenharia Reversa, Reuso de Modelos e Design de Jogos Educativos**.

👨‍💻 **Integrantes:** Emmanuel Ferreira Gomes, João Pedro Reis Rios e Douglas Mesquita da Silva

---

## 📌 Introdução

Este projeto apresenta uma proposta de melhoria para o **The Binary Tree Traversal Simulator**, utilizado como modelo-base da atividade.

O simulador original permite criar uma árvore binária visualmente e acompanhar seus principais percursos:

- 🔵 **Pré-ordem**
- 🟢 **Em-ordem**
- 🟣 **Pós-ordem**
- 🟠 **Por nível**

A nossa proposta mantém a parte visual do modelo, mas transforma a experiência em um jogo educativo mais ativo.

🎯 **A ideia principal é fazer o aluno participar do processo**, inserindo chaves, verificando propriedades, corrigindo a estrutura e recebendo feedback durante a atividade.

---

## 🎯 Objetivos

✔️ Analisar criticamente um modelo de jogo/visualizador existente.  
✔️ Identificar limitações técnicas e pedagógicas.  
✔️ Reutilizar a estrutura visual do modelo original.  
✔️ Incorporar uma estrutura avançada de **Estruturas de Dados II**.  
✔️ Transformar conceitos teóricos em mecânicas de gameplay.  
✔️ Criar uma experiência de aprendizagem mais ativa e interativa.

---

## 🎮 Jogo-Base

### 🌳 The Binary Tree Traversal Simulator

O jogo-base apresenta uma interface visual para criação e percurso de árvores binárias.

### 🔎 Limitações identificadas

❌ Entrada muito livre para o jogador.  
❌ Não possui condição clara de vitória.  
❌ Não possui condição clara de derrota.  
❌ Não oferece um treinamento progressivo.  
❌ Possui poucas explicações teóricas durante a interação.  
❌ Não apresenta uma mecânica de balanceamento.  
❌ O jogador observa a estrutura, mas participa pouco das decisões algorítmicas.

### 💡 O que será mantido?

✅ Representação visual da árvore.  
✅ Criação e organização dos nós.  
✅ Relação entre os nós da esquerda e da direita.  
✅ Visualização dos percursos.

A proposta é **melhorar o modelo sem perder sua simplicidade**.

---

## 🚀 Inovação Proposta

A principal inovação é incorporar uma **Árvore Rubro-Negra** ao gameplay.

Em vez de a estrutura aparecer somente como conteúdo teórico, suas propriedades passam a funcionar como **regras do próprio jogo**.

### 🔴⚫ Árvore Rubro-Negra

O jogador trabalha com nós vermelhos e pretos e precisa manter a estrutura válida.

### 🧩 Mecânicas adicionadas

🔹 Inserção de novas chaves.  
🔹 Verificação automática das propriedades.  
🔹 Recoloração dos nós.  
🔹 Rotação à esquerda.  
🔹 Rotação à direita.  
🔹 Feedback visual sobre erros.  
🔹 Desafios progressivos.

### 📐 Propriedades utilizadas

- A raiz deve permanecer **preta**.
- Um nó **vermelho** não pode possuir filho vermelho.
- Os caminhos devem respeitar a propriedade de **altura preta**, conforme a convenção utilizada na implementação.
- Após uma inserção, a estrutura deve ser novamente validada.

---

## 🔄 Core Loop

O ciclo principal do jogo funciona da seguinte maneira:

```text
┌─────────────────┐
│  Receber chave  │
└────────┬────────┘
         ↓
┌─────────────────┐
│   Inserir nó    │
└────────┬────────┘
         ↓
┌─────────────────┐
│ Verificar regras│
└────────┬────────┘
         ↓
   ┌─────────────┐
   │ Está válida?│
   └──────┬──────┘
      SIM │ NÃO
          │
     ↓    ↓
┌────────┐ ┌───────────────────┐
│Próxima │ │ Rotação /         │
│ chave  │ │ Recoloração       │
└────────┘ └─────────┬─────────┘
                     ↓
              ┌──────────────┐
              │ Validar again│
              └──────────────┘
```

---

## 🏆 Condições do Jogo

### ✅ Condição de Vitória

Concluir a sequência de desafios mantendo a **Árvore Rubro-Negra válida**.

### ❌ Condição de Derrota

O jogador perde quando:

- ultrapassa a quantidade máxima de erros da fase; ou
- termina a etapa com a estrutura ainda inválida.

🎯 Dessa forma, a derrota está relacionada diretamente às regras da estrutura de dados.

---

## 🧠 Algoritmo

A implementação proposta utiliza a inserção de uma **Árvore de Busca Binária** como base e, depois, executa a correção específica da Árvore Rubro-Negra.

### ⚙️ Etapas

```text
1. Criar o novo nó
2. Marcar o novo nó como VERMELHO
3. Inserir como em uma BST
4. Verificar as propriedades da Rubro-Negra
5. Identificar possíveis violações
6. Recolorir quando necessário
7. Executar rotação quando necessário
8. Garantir que a raiz seja PRETA
9. Atualizar a interface
10. Mostrar o feedback ao jogador
```

### 📝 Pseudocódigo

```text
RB-INSERT(T, chave)

    criar novo nó z
    z.cor ← VERMELHO

    inserir z como em uma BST

    enquanto pai(z) for VERMELHO:

        identificar tio(z)

        se tio(z) for VERMELHO:
            recolorir pai, tio e avô
            subir z para o avô

        senão:
            aplicar a rotação necessária
            recolorir os nós envolvidos

    raiz(T).cor ← PRETO

    atualizar interface
    mostrar feedback
```

---

## 📚 Fontes Pesquisadas

### 🔗 VisuAlgo

Ferramenta de visualização interativa de estruturas de dados e algoritmos.

📌 **Binary Search Tree / AVL Tree**  
🔗 https://visualgo.net/en/bst

### 🎓 USP — Instituto de Matemática e Estatística

Material relacionado a **Árvores Rubro-Negras**, incluindo conceitos de inserção, rotação, inversão de cores e altura negra.

🔗 https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/st-redblack.html

### 🏫 MIT OpenCourseWare

Material complementar sobre **Red-Black Trees, rotações, inserções e deleções**.

🔗 https://ocw.mit.edu/courses/6-046j-introduction-to-algorithms-sma-5503-fall-2005/resources/lecture-10-red-black-trees-rotations-insertions-deletions/

---

## 💻 Possibilidades de Implementação

### ⚙️ C++

Boa opção para uma implementação próxima do modelo original, trabalhando diretamente com nós e ponteiros.

### 🐍 Python

Interessante para criar rapidamente um protótipo e testar as mecânicas do jogo.

### ☕ Java

Pode ser utilizado em uma aplicação desktop, separando a lógica da árvore da interface.

### 🌐 JavaScript + HTML/CSS

Permite transformar a proposta em um jogo acessível diretamente pelo navegador.

### 🎮 C#

Pode ser utilizado para uma versão mais completa, inclusive com uma engine como **Unity**.

---

## 📊 Resumo do Projeto

| Item | Proposta |
|---|---|
| 🎮 Jogo-base | The Binary Tree Traversal Simulator |
| 🔎 Limitação | Experiência predominantemente visual/passiva |
| 🌳 Estrutura | Árvore Rubro-Negra |
| 🚀 Inovação | Inserção + validação + rotação + recoloração |
| 🔄 Core Loop | Receber → Inserir → Verificar → Corrigir → Avançar |
| 🏆 Vitória | Finalizar os desafios com a árvore válida |
| ❌ Derrota | Exceder erros ou manter estrutura inválida |
| 🎯 Objetivo | Aprender por meio da interação |

---

## 🤝 Nossa Opinião

Na nossa visão, o modelo original possui uma boa base porque é simples e visual.

Porém, ele funciona mais como um **visualizador** do que como um jogo educativo.

A principal mudança seria fazer o aluno participar efetivamente do processo:

🧩 **Inserir** → 🔎 **Analisar** → ⚠️ **Identificar o problema** → 🔧 **Corrigir** → ✅ **Entender**

Não acreditamos que seja necessário transformar o projeto em um jogo extremamente complexo.

Uma primeira versão já poderia funcionar com:

✅ Nós coloridos  
✅ Validação das propriedades  
✅ Rotações  
✅ Recoloração  
✅ Desafios  
✅ Feedback

Depois, o projeto poderia evoluir com níveis, pontuação, histórico de erros e modo de treinamento.

🎯 Para nós, o mais importante é transformar o **erro em aprendizado**.

---

## 📌 Conclusão

A proposta reutiliza uma ferramenta existente e acrescenta uma nova camada de interação baseada em uma **Árvore Rubro-Negra**.

Com isso, conceitos de Estruturas de Dados II deixam de ser apresentados apenas de forma teórica e passam a ser utilizados diretamente dentro do gameplay.

> 🚀 **A ideia é simples: o aluno não apenas vê a árvore. Ele precisa entender, agir e corrigir.**

---

## 👨‍💻 Autores

**Emmanuel Ferreira Gomes**  
**João Pedro Reis Rios**  
**Douglas Mesquita da Silva**

📚 Estruturas de Dados II  
🎓 Ciência da Computação

---

⭐ **Projeto acadêmico desenvolvido para a atividade prática de Design de Jogos Educativos sobre Árvores Avançadas.**
