# Nombre del ejecutable
TARGET = main

# Archivos fuente
SRCS = main.cpp leerInstancia.cpp funaux.cpp hillClimbing.cpp

# Archivos objeto (se genera automáticamente reemplazando .cpp por .o)
OBJS = $(SRCS:.cpp=.o)

# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# Regla por defecto
compile: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
