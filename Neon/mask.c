#include <arm_neon.h>
#include <stdio.h>

int main() {

  int i;
  
  int32_t int_array[8] = {100, 200, 300, 400, 500, 600, 700, 800};
  
  /* Initialize the mask vector */
  uint32x4_t mask_low = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  uint32x4_t mask_high = {0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000000};

  /* Selectively load data into the vector */
  int32x4_t result_low = vbslq_s32(mask_low, vld1q_s32(int_array), vdupq_n_s32(0));
  int32x4_t result_high = vbslq_s32(mask_high, vld1q_s32(int_array + 4), vdupq_n_s32(0));
  
  /* Display the elements of the result vector */
  printf("%d %d %d %d %d %d %d %d\n", 
    result_low[0], result_low[1], result_low[2], result_low[3],
    result_high[0], result_high[1], result_high[2], result_high[3]);
  
  return 0;
}
