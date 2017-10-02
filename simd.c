#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>//AVX: -mavx
#include <sys/time.h>

inline double seconds()
{
    struct timeval tp;
    struct timezone tzp;
    int i = gettimeofday(&tp, &tzp);
    return ((double)tp.tv_sec + (double)tp.tv_usec * 1.e-6);
}


void vec_add(const size_t n, float *z, const float *x, const float *y){
  static const size_t single_size = 8;
  const size_t end = n / single_size; 

  __m256 *vz = (__m256 *)z; // 32 bits (float) * 8
  __m256 *vx = (__m256 *)x;
  __m256 *vy = (__m256 *)y;

  // vx[0] == x[0]
  // vx[1] == x[8]
  // vx[2] == x[16]
  
  for(size_t i=0; i<end; ++i)
    vz[i] = _mm256_add_ps(vx[i], vy[i]);
}

int main(void){
  const size_t n = 1024 * 1024 * 10;
  float *x, *y, *z;
  printf("Vector size %d\n", (int)n);

  x = (float *)_mm_malloc(sizeof(float) * n, 32); // mm malloc aligns to 32 bytes
  y = (float *)_mm_malloc(sizeof(float) * n, 32);
  z = (float *)_mm_malloc(sizeof(float) * n, 32);

  for(size_t i=0; i<n; ++i) x[i] = i;
  for(size_t i=0; i<n; ++i) y[i] = i+1;
  for(size_t i=0; i<n; ++i) z[i] = 0.0;

  double started = seconds();
  vec_add(n, z, x, y);
  double elapsed = seconds() - started;
  printf("Elapsed %lf\n", elapsed);
  
  // for(size_t i=0; i<n; ++i) printf("%g\n", z[i]);

  _mm_free(x);
  _mm_free(y);
  _mm_free(z);

  return 0;
}
