# Makefile para compilar y ejecutar el programa Shannon-Fano en Ubuntu

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -std=c++11

# Nombre del ejecutable
TARGET = tarea

# Archivos fuente
SRCS = tarea.cpp

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)