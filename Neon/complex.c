#include <arm_neon.h>
#include <stdio.h>

int main() {

  float64x2_t vec1 = vcreate_f64(((uint64_t)(4.0) << 32) | (uint64_t)(5.0));
  float64x2_t vec2 = vcreate_f64(((uint64_t)(9.0) << 32) | (uint64_t)(3.0));
  float64x2_t neg = vcreate_f64(((uint64_t)(1.0) << 32) | (uint64_t)(-1.0));
  
  /* Step 1: Multiply vec1 and vec2 */
  float64x2_t vec3 = vmulq_f64(vec1, vec2);

  /* Step 2: Switch the real and imaginary elements of vec2 */
  vec2 = vcombine_f64(vget_high_f64(vec2), vget_low_f64(vec2));
  
  /* Step 3: Negate the imaginary elements of vec2 */
  vec2 = vmulq_f64(vec2, neg);  
  
  /* Step 4: Multiply vec1 and the modified vec2 */
  float64x2_t vec4 = vmulq_f64(vec1, vec2);

  /* Horizontally subtract the elements in vec3 and vec4 */
  vec1 = vsubq_f64(vec3, vec4);
  
  /* Display the elements of the result vector */
  double res[2];
  vst1q_f64(res, vec1);
  printf("%lf %lf\n", res[0], res[1]);
  
  return 0;
}
