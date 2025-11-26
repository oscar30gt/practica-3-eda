# ================================
# Makefile para compilar practica5
# Autores: Hugo García Sánchez
#          Oscar Grimal Torres
# ================================

CXX = g++
CXXFLAGS = -std=c++11
SRCS = *.cpp
TARGET = practica5

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)