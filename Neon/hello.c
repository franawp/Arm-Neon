#include <arm_neon.h>
#include <stdio.h>

int main() {

  /* Initialize the two argument vectors */
  float32x4_t evens = {2.0, 4.0, 6.0, 8.0};
  float32x4_t odds = {1.0, 3.0, 5.0, 7.0};

  /* Compute the difference between the two vectors */
  float32x4_t result = vsubq_f32(evens, odds);

  /* Displays the vector's elements */
  float32_t* par = (float32_t*)&evens;
  float32_t* impar = (float32_t*)&odds;
  printf("%f ,  %f , %f , %f\n", par[0], par[1], par[2], par[3]);
  printf("%f ,  %f , %f , %f\n", impar[0], impar[1], impar[2], impar[3]);

  /* Display the elements of the result vector */
  float32_t* f = (float32_t*)&result;
  printf("%f ,  %f , %f , %f\n", f[0], f[1], f[2], f[3]);

  return 0;
}
