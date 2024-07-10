# Makefile para compilar y ejecutar el programa Shannon-Fano en Ubuntu

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -std=c++11

# Nombre del ejecutable
TARGET = main

# Archivos fuente
SRCS = main.cpp distribuciones.cpp gapCandSample.cpp huffman.cpp binarySearch.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar los archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) $(OBJS)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)
