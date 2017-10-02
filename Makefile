CU_APPS=gpu
C_APPS=cpu simd

all: ${C_APPS} ${CU_APPS}

%: %.cu
	nvcc -O2 --generate-code arch=compute_50,code=compute_50 -o $@ $<
%: %.c
	gcc -O2 -mavx -o $@ $<
clean:
	rm -f ${CU_APPS} ${C_APPS}
