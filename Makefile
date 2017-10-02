CU_APPS=gpu
C_APPS=cpu

all: ${C_APPS} ${CU_APPS}

%: %.cu
	nvcc -O2 -arch=sm_20 -o $@ $<
%: %.c
	gcc -O2 -o $@ $<
clean:
	rm -f ${CU_APPS} ${C_APPS}
