all: test_complexe3 test_complexe2 test_complexe test_dot test_dot_dyn test_copy test_asum test_iamax test_iamin test_nrm2 test_swap test_axpy

INC_DIR=../include

LIB_DIR=../lib

LIBST=-lmnblas
LIBDYN=-lmnblasdyn

OPTIONS_COMPIL  =-Wall -O2 -fPIC -I$(INC_DIR)

OPTIONS_LINK_STATIC  = -fopenmp -L$(LIB_DIR) $(LIBST)  
OPTIONS_LINK_DYN     = -fopenmp -L$(LIB_DIR) $(LIBDYN)  



flop.o: flop.c flop.h
	gcc $(OPTIONS_COMPIL) -c flop.c

utils.o: utils.c $(INC_DIR)/mnblas.h $(INC_DIR)/complexe.h utils.h
	gcc $(OPTIONS_COMPIL) -c utils.c

# DOT
test_dot: test_dot.o utils.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o test_dot test_dot.o utils.o flop.o $(OPTIONS_LINK_STATIC)

test_dot_dyn: test_dot.o flop.o utils.o
	gcc -o test_dot_dyn flop.o test_dot.o utils.o $(OPTIONS_LINK_DYN) -lm

test_dot.o: test_dot.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS_COMPIL) -c test_dot.c

# COPY
test_copy: test_copy.o utils.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o test_copy test_copy.o utils.o flop.o $(OPTIONS_LINK_STATIC)

test_copy.o : test_copy.c $(INC_DIR)/mnblas.h utils.h
	gcc $(OPTIONS_COMPIL) -c test_copy.c

#SWAP
test_swap: test_swap.o utils.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o test_swap test_swap.o flop.o utils.o $(OPTIONS_LINK_STATIC)

test_swap.o : test_swap.c $(INC_DIR)/mnblas.h utils.h
	gcc $(OPTIONS_COMPIL) -c test_swap.c

# ASUM
test_asum: test_asum.o utils.o  flop.o $(LIB_DIR)/libmnblas.a
	gcc -o test_asum test_asum.o flop.o utils.o $(OPTIONS_LINK_STATIC)

test_asum.o : test_asum.c $(INC_DIR)/mnblas.h utils.h
	gcc $(OPTIONS_COMPIL) -c test_asum.c


# IAMIN
test_iamin: test_iamin.o utils.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o test_iamin test_iamin.o  flop.o utils.o $(OPTIONS_LINK_STATIC)

test_iamin.o : test_iamin.c $(INC_DIR)/mnblas.h utils.h
	gcc $(OPTIONS_COMPIL) -c test_iamin.c


# IAMAX
test_iamax: test_iamax.o utils.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o test_iamax test_iamax.o flop.o utils.o $(OPTIONS_LINK_STATIC)

test_iamax.o : test_iamax.c $(INC_DIR)/mnblas.h utils.h
	gcc $(OPTIONS_COMPIL) -c test_iamax.c


# NRM2
test_nrm2: test_nrm2.o utils.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o test_nrm2 test_nrm2.o flop.o utils.o $(OPTIONS_LINK_STATIC) -lm

test_nrm2.o : test_nrm2.c $(INC_DIR)/mnblas.h utils.h
	gcc $(OPTIONS_COMPIL) -c test_nrm2.c

test_axpy: test_axpy.o utils.o flop.o $(LIB_DIR)/libmnblas.a
	gcc -o test_axpy test_axpy.o flop.o utils.o $(OPTIONS_LINK_STATIC) -lm

test_axpy.o : test_axpy.c $(INC_DIR)/mnblas.h utils.h
	gcc $(OPTIONS_COMPIL) -c test_axpy.c



#########
#COMPLEXE
#########
test_complexe.o: test_complexe.c  $(INC_DIR)/complexe.h
	gcc $(OPTIONS_COMPIL) -c test_complexe.c

test_complexe: test_complexe.o flop.o
	gcc -o test_complexe test_complexe.o flop.o $(OPTIONS_LINK_STATIC)

test_complexe2.o: test_complexe2.c  $(INC_DIR)/complexe2.h
	gcc $(OPTIONS_COMPIL) -c test_complexe2.c

test_complexe2: test_complexe2.o flop.o
	gcc -o test_complexe2 test_complexe2.o flop.o $(OPTIONS_LINK_STATIC)

test_complexe3.o: test_complexe3.c  $(INC_DIR)/complexe2.h
	gcc $(OPTIONS_COMPIL) -c test_complexe3.c

test_complexe3: test_complexe3.o flop.o
	gcc -o test_complexe3 test_complexe3.o flop.o $(OPTIONS_LINK_STATIC)



clean:
	rm -f *.o test_dot test_dot_dyn test_complexe test_complexe2 test_complexe3 test_complexe4 *~
