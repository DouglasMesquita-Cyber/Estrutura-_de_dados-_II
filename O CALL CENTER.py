# Cria uma fila vazia
fila = []

# Adiciona clientes na fila
fila.append("João")
fila.append("Maria")
fila.append("Carlos")
fila.append("Ana")

# Simula o atendimento dos clientes
while len(fila) > 0:

    # Retira o primeiro cliente da fila
    cliente = fila.pop(0)

    # Mostra quem esta sendo atendido
    print("Atendendo:", cliente)

print("Fila vazia.")