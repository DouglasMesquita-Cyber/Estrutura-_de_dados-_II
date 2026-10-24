# 📘 Caderno do Estudante

## 🌐 Projeto ConectaUDF: redes sociais com grafos

**Disciplina:** Algoritmos / Matemática Discreta / Ciência de Dados

**Integrantes:** \[Emmanuel Ferreira Gomes, João Pedro Reis Rios, Douglas Mesquita, Matheus Azevedo Novaes e Wesley Gabriel Carvalho\]

## 🧭 1. O desafio

Você faz parte da equipe que analisa a rede social fictícia ConectaUDF. Sua missão é representar as amizades em um grafo, realizar cálculos e usar Python para interpretar a estrutura da rede.

## 📚 2. Conceitos essenciais

- 🔵 **Vértice (ou nó):** representa um usuário.
- 🔗 **Aresta:** representa uma amizade entre dois usuários.
- 📊 **Grau:** quantidade de conexões diretas de um usuário.
- 🛤️ **Caminho:** sequência de usuários em que cada par consecutivo está conectado.
- 📈 **Densidade:** proporção entre as amizades existentes e todas as amizades possíveis.

Neste projeto, a amizade é recíproca. Portanto, usamos um grafo não direcionado.

## 👥 3. Conheça os usuários

| Código | Usuário |
| --- | --- |
| A | Ana |
| B | Bruno |
| C | Carla |
| D | Diego |
| E | Elisa |
| F | Felipe |

### 🔗 As amizades são:

- Ana — Bruno
- Ana — Carla
- Bruno — Carla
- Bruno — Diego
- Carla — Elisa
- Diego — Elisa
- Diego — Felipe
- Elisa — Felipe

## ✏️ 4. Passo a passo: Desenho do grafo original

 <img width="4680" height="760" alt="2  Desenho do grafo (rede original)" src="https://github.com/user-attachments/assets/b447ae50-ea37-4647-8bf6-bdd23196f5f9" />


## 📊 5. Passo a passo: calcule o grau

Conte quantas linhas chegam a cada círculo. Registre o resultado.

| Usuário | Amigos diretos | Grau |
| --- | --- | --- |
| Ana | Bruno, Carla | 2 |
| Bruno | Ana, Carla, Diego | 3 |
| Carla | Ana, Bruno, Elisa | 3 |
| Diego | Bruno, Elisa, Felipe | 3 |
| Elisa | Carla, Diego, Felipe | 3 |
| Felipe | Diego, Elisa | 2 |

**❓ Pergunta 1: quem tem mais conexões diretas?**

**Resposta:** Bruno, Carla, Diego e Elisa, com 3 amigos cada.

## 🧮 6. Passo a passo: calcule o número de amizades

Some todos os graus. Como cada amizade conecta dois usuários, cada aresta é contada duas vezes.

**📌 Fórmula:**

Número de arestas = soma dos graus ÷ 2

- Soma dos graus: 16.
- Divida por 2: 16 ÷ 2 = 8.

**Quantas amizades existem no grafo?**

Resposta: 8 amizades.

## 📈 7. Passo a passo: calcule a densidade

A densidade compara as amizades existentes com o total de amizades possíveis.

Para um grafo simples não direcionado:

**D = 2 × E / (V × (V − 1))**

Em que:

- **D** = densidade;
- **E** = número de arestas;
- **V** = número de vértices.

**Substitua os valores:**

D = 2 × 8 / (6 × (6 − 1))

Resultado decimal: 16/30 ≈ 0,5333.

Resultado percentual: 53,33%.

- Amizades existentes: 8.
- Amizades possíveis: 15.

**💭 Interprete:** a rede tem poucas ou muitas das conexões possíveis? Explique com suas palavras.

**Resposta:** Ao analisar a rede de amizades, podemos notar que ela possui mais da metade das conexões possíveis, com aproximadamente 53,33%. É uma rede moderadamente densa e relativamente bem conectada para um grupo pequeno, considerando que existem 15 conexões possíveis entre seis pessoas e oito já foram estabelecidas.

## 💻 8. Passo a passo: represente o grafo em Python

A lista de adjacência registra, para cada usuário, os nomes de seus amigos. Digite o código em Python, por exemplo, no Google Colab ou em outro ambiente disponível.

```
rede = {
    "Ana": ["Bruno", "Carla"],
    "Bruno": ["Ana", "Carla", "Diego"],
    "Carla": ["Ana", "Bruno", "Elisa"],
    "Diego": ["Bruno", "Elisa", "Felipe"],
    "Elisa": ["Carla", "Diego", "Felipe"],
    "Felipe": ["Diego", "Elisa"]
}

# Quantidade de usuários
n = len(rede)

# Calcule o grau de cada usuário
for usuario, amigos in rede.items():
    print(usuario, "tem", len(amigos), "conexões")

# A soma dos graus conta cada amizade duas vezes
soma_graus = sum(len(amigos) for amigos in rede.values())
arestas = soma_graus // 2

print("Total de usuários:", n)
print("Total de amizades:", arestas)

# Densidade do grafo
densidade = (2 * arestas) / (n * (n - 1))
print(f"Densidade: {densidade:.2%}")
```

### 🧩 8.1. Entenda o código

- `rede` guarda os usuários e suas listas de amigos.
- `len(rede)` conta os usuários.
- `len(amigos)` calcula o grau de cada usuário.
- `sum(...)` soma os graus.
- `// 2` divide a soma por dois para contar cada amizade uma única vez.
- A fórmula final calcula a densidade.

### 🔗 8.2. Código no Google Colab

📎 Acesse o projeto no Google Colab: 

GRAFO_ORIGINAL - https://colab.research.google.com/drive/1LDfvx2Ll29HT7Ynkwy4j4eKwO0f6soSh?usp=sharing

GRAFO_AMPLIADO - https://colab.research.google.com/drive/1wQ4zTRVPJWxNEd7QtZ2u7vz0EraBrR_j?usp=sharing

## 🛤️ 9. Passo a passo: encontre um caminho

Encontre um caminho de Ana até Felipe. Cada passagem por uma linha corresponde a uma aresta.

**Exemplo de caminho:**

Ana → Bruno → Diego → Felipe

**Quantas arestas há no caminho?**

Há 3 arestas.

**Você encontrou outro caminho com a mesma quantidade de arestas? Qual?**

Sim: Ana → Carla → Elisa → Felipe.

Esse caminho também possui 3 arestas.

## 🤝 10. Desafio em grupo - Desenho do grafo Ampliado

<img width="6700" height="1153" alt="7  Desafio em grupo_ rede ampliada" src="https://github.com/user-attachments/assets/54136bf2-1ea1-47bd-aa5e-c3ad13f21c85" />


### 🐍 10.1. Atualize a lista de adjacência no Python

O código abaixo representa uma rede ampliada com 10 usuários.

```
rede_ampliada = {
    "Ana": ["Bruno", "Carla"],
    "Bruno": ["Ana", "Carla", "Diego", "Gabriel"],
    "Carla": ["Ana", "Bruno", "Elisa", "Gabriel"],
    "Diego": ["Bruno", "Elisa", "Felipe"],
    "Elisa": ["Carla", "Diego", "Felipe", "Igor"],
    "Felipe": ["Diego", "Elisa", "Helena"],
    "Gabriel": ["Bruno", "Carla", "Julia"],
    "Helena": ["Felipe", "Igor"],
    "Igor": ["Elisa", "Helena"],
    "Julia": ["Gabriel"]
}

# Quantidade de usuários (V)
n = len(rede_ampliada)

print("=== GRAU DE CADA USUÁRIO (REDE AMPLIADA) ===")

for usuario, amigos in rede_ampliada.items():
    print(f"{usuario}: {len(amigos)} conexões -> {amigos}")

# Cálculo das arestas (E)
soma_graus = sum(
    len(amigos) for amigos in rede_ampliada.values()
)
arestas = soma_graus // 2

# Cálculo da densidade (D)
densidade = (2 * arestas) / (n * (n - 1))

print("\n=== RESUMO MÉTRICO ===")
print(f"Soma dos graus: {soma_graus}")
print(f"Total de usuários (V): {n}")
print(f"Total de amizades (E): {arestas}")
print(f"Densidade da rede: {densidade:.4f} ({densidade:.2%})")

# Identificação dos usuários mais conectados
maior_grau = max(
    len(amigos) for amigos in rede_ampliada.values()
)

mais_conectados = [
    usuario
    for usuario, amigos in rede_ampliada.items()
    if len(amigos) == maior_grau
]

print(
    f"Usuários mais conectados (grau {maior_grau}): "
    f"{', '.join(mais_conectados)}"
)
```

### 🧮 10.2. Recalcule os graus, o total de arestas e a densidade

- Soma dos graus: 28.
- Divisão por 2: 28 ÷ 2 = 14.
- Total de amizades: 14 amizades.

### 📈 10.3. Densidade da rede ampliada

**Fórmula:**

D = 2 × E / (V × (V − 1))

**Substituindo os valores:**

D = 2 × 14 / (10 × (10 − 1))

Resultado decimal: 28/90 ≈ 0,3111.

Resultado percentual: 31,11%.

- Amizades existentes: 14.
- Amizades possíveis: 45.

### 🔍 10.4. Compare a densidade antes e depois da ampliação

| Indicador | Rede original | Rede ampliada |
| --- | --- | --- |
| Usuários | 6 | 10 |
| Amizades existentes | 8 | 14 |
| Amizades possíveis | 15 | 45 |
| Densidade | 53,33% | 31,11% |

A densidade diminuiu de 53,33% para 31,11%. Isso ocorreu porque o número de amizades possíveis aumentou de 15 para 45, enquanto o número de amizades existentes passou de 8 para 14.

Assim, embora a rede tenha ganhado novas amizades, a proporção de conexões existentes em relação às possíveis ficou menor.

### 👥 10.5. Tabela de graus da rede ampliada

| Usuário | Amigos diretos | Grau |
| --- | --- | --- |
| Ana | Bruno, Carla | 2 |
| Bruno | Ana, Carla, Diego, Gabriel | 4 |
| Carla | Ana, Bruno, Elisa, Gabriel | 4 |
| Diego | Bruno, Elisa, Felipe | 3 |
| Elisa | Carla, Diego, Felipe, Igor | 4 |
| Felipe | Diego, Elisa, Helena | 3 |
| Gabriel | Bruno, Carla, Julia | 3 |
| Helena | Felipe, Igor | 2 |
| Igor | Elisa, Helena | 2 |
| Julia | Gabriel | 1 |

### ⭐ 10.6. Identifique os usuários com mais conexões

Os usuários com mais conexões são Bruno, Carla e Elisa, cada um com grau 4.

### 💡 10.7. Explique como a rede poderia recomendar uma nova amizade

Se duas pessoas não são amigas, mas têm três amigos em comum, isso pode indicar que participam de círculos sociais semelhantes. A rede pode usar essa informação para sugerir uma amizade e mostrar os amigos em comum, respeitando a privacidade e a vontade dos usuários.

## 📦 11. Entrega

Entregue:

- 🖼️ Desenho do grafo.
- 📊 Tabela com os graus.
- 🧮 Cálculos de arestas e densidade.
- 💻 Código Python executável.
- ✍️ Respostas às perguntas e breve conclusão.

## 🔐 12. Pergunta de reflexão

Duas pessoas ainda não são amigas, mas têm três amigos em comum. Como essa informação poderia ser usada para sugerir uma nova conexão? Quais cuidados de privacidade devem ser considerados ao analisar redes sociais?

**Resposta:** Se duas pessoas não são amigas, mas têm três amigos em comum, a rede pode usar essa informação para sugerir uma nova amizade e mostrar os amigos compartilhados.

Sobre a privacidade, é importante informar às pessoas como seus dados são utilizados e permitir que escolham se desejam receber esse tipo de sugestão. Também é necessário evitar expor vínculos que alguém prefira manter em sigilo, proteger os dados pessoais e respeitar a Lei Geral de Proteção de Dados (LGPD), quando aplicável.

## 🎉 13. Conclusão

Neste projeto, aprendemos como os grafos representam as relações de amizade em uma rede social. O grau permitiu identificar os usuários com mais conexões, a soma dos graus dividida por dois possibilitou calcular o número de amizades, e a densidade mostrou a proporção entre as conexões existentes e as possíveis.

Com a ampliação da rede de seis para dez usuários, o número de amizades aumentou de oito para quatorze, mas a densidade diminuiu de 53,33% para 31,11%. O uso de Python facilitou os cálculos e a análise das conexões.

Por fim, o projeto demonstrou que os grafos podem ajudar a compreender redes sociais e recomendar novas amizades, desde que a privacidade dos usuários seja respeitada.
