# ================================
# Makefile para compilar practica3
# Autores: Hugo García Sánchez
#          Oscar Grimal Torres
# ================================

CXX = g++
CXXFLAGS = -std=c++11
SRCS = practica3.cpp evento.cpp
TARGET = practica3

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)