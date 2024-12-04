# Variáveis
CC = gcc                  # Compilador
CFLAGS = -Wall -Wextra -g3  # Opções de compilação
OBJS = main.o menu.o orders.o reports.o  # Objetos gerados pelos arquivos .c
TARGET = SistemaPedidos    # Nome do executável

# Regra padrão
all: $(TARGET)

# Como criar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Como compilar os arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)
