# une bibliotheque statique (libmnblas.a)
# une bibliotheque dynamique (libmnblasdyn.so)

all: libmnblas.a libmnblasdyn.so

LIB_DIR=../lib
INC_DIR=../include
OPTIM=-O2 -fopenmp

OPTIONS=-O2 -Wall -fPIC $(OPTIM) -I$(INC_DIR)
# Bibliothèque statique

OBJECTS=copy.o swap.o dot.o complexe.o asum.o iamin.o iamax.o nrm2.o axpy.o gemv.o gemm.o

libmnblas.a: $(OBJECTS)
	rm -f libmnblas.a $(LIB_DIR)/libmnblas.a
	ar -r libmnblas.a $^
	cp libmnblas.a $(LIB_DIR)

# Bibliothèque dynamique

libmnblasdyn.so:$(OBJECTS)
	rm -f libmnblasdyn.so $(LIB_DIR)/libmnblasdyn.so
	gcc -shared -o libmnblasdyn.so $^
	cp libmnblasdyn.so $(LIB_DIR)

complexe.o: $(INC_DIR)/complexe.h complexe.c
	gcc $(OPTIONS) -c complexe.c

# BLAS 1

copy.o : copy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c copy.c

swap.o : swap.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c swap.c

dot.o : dot.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c dot.c

asum.o : asum.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c asum.c

iamin.o : asum.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c iamin.c

iamax.o : asum.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c iamax.c

nrm2.o : asum.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c nrm2.c

axpy.o : axpy.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c axpy.c

gemv.o : gemv.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c gemv.c

gemm.o : gemm.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c gemm.c

# BLAS 2

# BLAS 3

clean:
	rm -f *.o *.a *.so *~  $(INC_DIR)/*~ $(LIB_DIR)/libmnblasdyn.so  $(LIB_DIR)/libmnblas.a ../lib/libmnblas.a ../lib/libmnblasdyn.so



