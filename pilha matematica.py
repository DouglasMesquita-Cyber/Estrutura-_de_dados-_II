pilha = []            #criando uma lista

# Coloca os números na pilha
pilha.append(10)
pilha.append(20)
pilha.append(30)
pilha.append(40)
pilha.append(50)

# Variável para guardar a soma
soma = 0

while len(pilha) > 0:   # enquato a pilha nao estiver vazia remova o topo 
    valor = pilha.pop() #remove o ultimo valor da pilha
    soma = soma + valor # soma o valor removido com o total 

# Retorna a soma total
print("Soma total:", soma)