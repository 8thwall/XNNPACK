// Auto-generated file. Do not edit!
//   Template: src/f32-dwconv/up-avx.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include <xnnpack/dwconv.h>


static const int32_t mask_table[14] = {-1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0};

void xnn_f32_dwconv_ukernel_up16x25__avx(
    size_t channels,
    size_t output_width,
    const float** input,
    const float* weights,
    float* output,
    size_t input_stride,
    size_t output_increment,
    const union xnn_f32_output_params params[restrict static 1])
{
  assert(channels != 0);
  assert(output_width != 0);

  const __m256 vmax = _mm256_broadcast_ps((const __m128*) params->sse.max);
  const __m256 vmin = _mm256_broadcast_ps((const __m128*) params->sse.min);
  do {
    const float* i0 = input[0];
    const float* i1 = input[1];
    const float* i2 = input[2];
    const float* i3 = input[3];
    const float* i4 = input[4];
    const float* i5 = input[5];
    const float* i6 = input[6];
    const float* i7 = input[7];
    const float* i8 = input[8];
    const float* i9 = input[9];
    const float* i10 = input[10];
    const float* i11 = input[11];
    const float* i12 = input[12];
    const float* i13 = input[13];
    const float* i14 = input[14];
    const float* i15 = input[15];
    const float* i16 = input[16];
    const float* i17 = input[17];
    const float* i18 = input[18];
    const float* i19 = input[19];
    const float* i20 = input[20];
    const float* i21 = input[21];
    const float* i22 = input[22];
    const float* i23 = input[23];
    const float* i24 = input[24];
    input = (const float**) ((uintptr_t) input + input_stride);

    size_t c = channels;
    const float* w = weights;
    for (; c >= 16; c -= 16) {
      __m256 vacc01234567p0 = _mm256_load_ps(w);
      __m256 vacc89ABCDEFp0 = _mm256_load_ps(w + 8);


      const __m256 vi0x01234567 = _mm256_loadu_ps(i0);
      const __m256 vi0x89ABCDEF = _mm256_loadu_ps(i0 + 8);
      i0 += 16;

      const __m256 vk0x01234567 = _mm256_load_ps(w + 16);
      const __m256 vk0x89ABCDEF = _mm256_load_ps(w + 24);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi0x01234567, vk0x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi0x89ABCDEF, vk0x89ABCDEF));

      const __m256 vi1x01234567 = _mm256_loadu_ps(i1);
      const __m256 vi1x89ABCDEF = _mm256_loadu_ps(i1 + 8);
      i1 += 16;

      const __m256 vk1x01234567 = _mm256_load_ps(w + 32);
      const __m256 vk1x89ABCDEF = _mm256_load_ps(w + 40);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi1x01234567, vk1x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi1x89ABCDEF, vk1x89ABCDEF));

      const __m256 vi2x01234567 = _mm256_loadu_ps(i2);
      const __m256 vi2x89ABCDEF = _mm256_loadu_ps(i2 + 8);
      i2 += 16;

      const __m256 vk2x01234567 = _mm256_load_ps(w + 48);
      const __m256 vk2x89ABCDEF = _mm256_load_ps(w + 56);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi2x01234567, vk2x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi2x89ABCDEF, vk2x89ABCDEF));

      const __m256 vi3x01234567 = _mm256_loadu_ps(i3);
      const __m256 vi3x89ABCDEF = _mm256_loadu_ps(i3 + 8);
      i3 += 16;

      const __m256 vk3x01234567 = _mm256_load_ps(w + 64);
      const __m256 vk3x89ABCDEF = _mm256_load_ps(w + 72);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi3x01234567, vk3x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi3x89ABCDEF, vk3x89ABCDEF));

      const __m256 vi4x01234567 = _mm256_loadu_ps(i4);
      const __m256 vi4x89ABCDEF = _mm256_loadu_ps(i4 + 8);
      i4 += 16;

      const __m256 vk4x01234567 = _mm256_load_ps(w + 80);
      const __m256 vk4x89ABCDEF = _mm256_load_ps(w + 88);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi4x01234567, vk4x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi4x89ABCDEF, vk4x89ABCDEF));

      const __m256 vi5x01234567 = _mm256_loadu_ps(i5);
      const __m256 vi5x89ABCDEF = _mm256_loadu_ps(i5 + 8);
      i5 += 16;

      const __m256 vk5x01234567 = _mm256_load_ps(w + 96);
      const __m256 vk5x89ABCDEF = _mm256_load_ps(w + 104);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi5x01234567, vk5x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi5x89ABCDEF, vk5x89ABCDEF));

      const __m256 vi6x01234567 = _mm256_loadu_ps(i6);
      const __m256 vi6x89ABCDEF = _mm256_loadu_ps(i6 + 8);
      i6 += 16;

      const __m256 vk6x01234567 = _mm256_load_ps(w + 112);
      const __m256 vk6x89ABCDEF = _mm256_load_ps(w + 120);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi6x01234567, vk6x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi6x89ABCDEF, vk6x89ABCDEF));

      const __m256 vi7x01234567 = _mm256_loadu_ps(i7);
      const __m256 vi7x89ABCDEF = _mm256_loadu_ps(i7 + 8);
      i7 += 16;

      const __m256 vk7x01234567 = _mm256_load_ps(w + 128);
      const __m256 vk7x89ABCDEF = _mm256_load_ps(w + 136);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi7x01234567, vk7x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi7x89ABCDEF, vk7x89ABCDEF));

      const __m256 vi8x01234567 = _mm256_loadu_ps(i8);
      const __m256 vi8x89ABCDEF = _mm256_loadu_ps(i8 + 8);
      i8 += 16;

      const __m256 vk8x01234567 = _mm256_load_ps(w + 144);
      const __m256 vk8x89ABCDEF = _mm256_load_ps(w + 152);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi8x01234567, vk8x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi8x89ABCDEF, vk8x89ABCDEF));

      const __m256 vi9x01234567 = _mm256_loadu_ps(i9);
      const __m256 vi9x89ABCDEF = _mm256_loadu_ps(i9 + 8);
      i9 += 16;

      const __m256 vk9x01234567 = _mm256_load_ps(w + 160);
      const __m256 vk9x89ABCDEF = _mm256_load_ps(w + 168);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi9x01234567, vk9x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi9x89ABCDEF, vk9x89ABCDEF));

      const __m256 vi10x01234567 = _mm256_loadu_ps(i10);
      const __m256 vi10x89ABCDEF = _mm256_loadu_ps(i10 + 8);
      i10 += 16;

      const __m256 vk10x01234567 = _mm256_load_ps(w + 176);
      const __m256 vk10x89ABCDEF = _mm256_load_ps(w + 184);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi10x01234567, vk10x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi10x89ABCDEF, vk10x89ABCDEF));

      const __m256 vi11x01234567 = _mm256_loadu_ps(i11);
      const __m256 vi11x89ABCDEF = _mm256_loadu_ps(i11 + 8);
      i11 += 16;

      const __m256 vk11x01234567 = _mm256_load_ps(w + 192);
      const __m256 vk11x89ABCDEF = _mm256_load_ps(w + 200);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi11x01234567, vk11x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi11x89ABCDEF, vk11x89ABCDEF));

      const __m256 vi12x01234567 = _mm256_loadu_ps(i12);
      const __m256 vi12x89ABCDEF = _mm256_loadu_ps(i12 + 8);
      i12 += 16;

      const __m256 vk12x01234567 = _mm256_load_ps(w + 208);
      const __m256 vk12x89ABCDEF = _mm256_load_ps(w + 216);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi12x01234567, vk12x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi12x89ABCDEF, vk12x89ABCDEF));

      const __m256 vi13x01234567 = _mm256_loadu_ps(i13);
      const __m256 vi13x89ABCDEF = _mm256_loadu_ps(i13 + 8);
      i13 += 16;

      const __m256 vk13x01234567 = _mm256_load_ps(w + 224);
      const __m256 vk13x89ABCDEF = _mm256_load_ps(w + 232);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi13x01234567, vk13x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi13x89ABCDEF, vk13x89ABCDEF));

      const __m256 vi14x01234567 = _mm256_loadu_ps(i14);
      const __m256 vi14x89ABCDEF = _mm256_loadu_ps(i14 + 8);
      i14 += 16;

      const __m256 vk14x01234567 = _mm256_load_ps(w + 240);
      const __m256 vk14x89ABCDEF = _mm256_load_ps(w + 248);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi14x01234567, vk14x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi14x89ABCDEF, vk14x89ABCDEF));

      const __m256 vi15x01234567 = _mm256_loadu_ps(i15);
      const __m256 vi15x89ABCDEF = _mm256_loadu_ps(i15 + 8);
      i15 += 16;

      const __m256 vk15x01234567 = _mm256_load_ps(w + 256);
      const __m256 vk15x89ABCDEF = _mm256_load_ps(w + 264);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi15x01234567, vk15x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi15x89ABCDEF, vk15x89ABCDEF));

      const __m256 vi16x01234567 = _mm256_loadu_ps(i16);
      const __m256 vi16x89ABCDEF = _mm256_loadu_ps(i16 + 8);
      i16 += 16;

      const __m256 vk16x01234567 = _mm256_load_ps(w + 272);
      const __m256 vk16x89ABCDEF = _mm256_load_ps(w + 280);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi16x01234567, vk16x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi16x89ABCDEF, vk16x89ABCDEF));

      const __m256 vi17x01234567 = _mm256_loadu_ps(i17);
      const __m256 vi17x89ABCDEF = _mm256_loadu_ps(i17 + 8);
      i17 += 16;

      const __m256 vk17x01234567 = _mm256_load_ps(w + 288);
      const __m256 vk17x89ABCDEF = _mm256_load_ps(w + 296);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi17x01234567, vk17x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi17x89ABCDEF, vk17x89ABCDEF));

      const __m256 vi18x01234567 = _mm256_loadu_ps(i18);
      const __m256 vi18x89ABCDEF = _mm256_loadu_ps(i18 + 8);
      i18 += 16;

      const __m256 vk18x01234567 = _mm256_load_ps(w + 304);
      const __m256 vk18x89ABCDEF = _mm256_load_ps(w + 312);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi18x01234567, vk18x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi18x89ABCDEF, vk18x89ABCDEF));

      const __m256 vi19x01234567 = _mm256_loadu_ps(i19);
      const __m256 vi19x89ABCDEF = _mm256_loadu_ps(i19 + 8);
      i19 += 16;

      const __m256 vk19x01234567 = _mm256_load_ps(w + 320);
      const __m256 vk19x89ABCDEF = _mm256_load_ps(w + 328);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi19x01234567, vk19x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi19x89ABCDEF, vk19x89ABCDEF));

      const __m256 vi20x01234567 = _mm256_loadu_ps(i20);
      const __m256 vi20x89ABCDEF = _mm256_loadu_ps(i20 + 8);
      i20 += 16;

      const __m256 vk20x01234567 = _mm256_load_ps(w + 336);
      const __m256 vk20x89ABCDEF = _mm256_load_ps(w + 344);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi20x01234567, vk20x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi20x89ABCDEF, vk20x89ABCDEF));

      const __m256 vi21x01234567 = _mm256_loadu_ps(i21);
      const __m256 vi21x89ABCDEF = _mm256_loadu_ps(i21 + 8);
      i21 += 16;

      const __m256 vk21x01234567 = _mm256_load_ps(w + 352);
      const __m256 vk21x89ABCDEF = _mm256_load_ps(w + 360);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi21x01234567, vk21x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi21x89ABCDEF, vk21x89ABCDEF));

      const __m256 vi22x01234567 = _mm256_loadu_ps(i22);
      const __m256 vi22x89ABCDEF = _mm256_loadu_ps(i22 + 8);
      i22 += 16;

      const __m256 vk22x01234567 = _mm256_load_ps(w + 368);
      const __m256 vk22x89ABCDEF = _mm256_load_ps(w + 376);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi22x01234567, vk22x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi22x89ABCDEF, vk22x89ABCDEF));

      const __m256 vi23x01234567 = _mm256_loadu_ps(i23);
      const __m256 vi23x89ABCDEF = _mm256_loadu_ps(i23 + 8);
      i23 += 16;

      const __m256 vk23x01234567 = _mm256_load_ps(w + 384);
      const __m256 vk23x89ABCDEF = _mm256_load_ps(w + 392);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi23x01234567, vk23x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi23x89ABCDEF, vk23x89ABCDEF));

      const __m256 vi24x01234567 = _mm256_loadu_ps(i24);
      const __m256 vi24x89ABCDEF = _mm256_loadu_ps(i24 + 8);
      i24 += 16;

      const __m256 vk24x01234567 = _mm256_load_ps(w + 400);
      const __m256 vk24x89ABCDEF = _mm256_load_ps(w + 408);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi24x01234567, vk24x01234567));
      vacc89ABCDEFp0 = _mm256_add_ps(vacc89ABCDEFp0, _mm256_mul_ps(vi24x89ABCDEF, vk24x89ABCDEF));

      w += 416;


      __m256 vacc01234567 = _mm256_max_ps(vacc01234567p0, vmin);
      __m256 vacc89ABCDEF = _mm256_max_ps(vacc89ABCDEFp0, vmin);
      vacc01234567 = _mm256_min_ps(vacc01234567, vmax);
      vacc89ABCDEF = _mm256_min_ps(vacc89ABCDEF, vmax);

      _mm256_storeu_ps(output, vacc01234567);
      _mm256_storeu_ps(output + 8, vacc89ABCDEF);
      output += 16;
    }
    for (; c >= 8; c -= 8) {
      __m256 vacc01234567p0 = _mm256_load_ps(w);

      const __m256 vi0x01234567 = _mm256_loadu_ps(i0);
      i0 += 8;

      const __m256 vk0x01234567 = _mm256_load_ps(w + 16);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi0x01234567, vk0x01234567));

      const __m256 vi1x01234567 = _mm256_loadu_ps(i1);
      i1 += 8;

      const __m256 vk1x01234567 = _mm256_load_ps(w + 32);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi1x01234567, vk1x01234567));

      const __m256 vi2x01234567 = _mm256_loadu_ps(i2);
      i2 += 8;

      const __m256 vk2x01234567 = _mm256_load_ps(w + 48);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi2x01234567, vk2x01234567));

      const __m256 vi3x01234567 = _mm256_loadu_ps(i3);
      i3 += 8;

      const __m256 vk3x01234567 = _mm256_load_ps(w + 64);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi3x01234567, vk3x01234567));

      const __m256 vi4x01234567 = _mm256_loadu_ps(i4);
      i4 += 8;

      const __m256 vk4x01234567 = _mm256_load_ps(w + 80);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi4x01234567, vk4x01234567));

      const __m256 vi5x01234567 = _mm256_loadu_ps(i5);
      i5 += 8;

      const __m256 vk5x01234567 = _mm256_load_ps(w + 96);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi5x01234567, vk5x01234567));

      const __m256 vi6x01234567 = _mm256_loadu_ps(i6);
      i6 += 8;

      const __m256 vk6x01234567 = _mm256_load_ps(w + 112);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi6x01234567, vk6x01234567));

      const __m256 vi7x01234567 = _mm256_loadu_ps(i7);
      i7 += 8;

      const __m256 vk7x01234567 = _mm256_load_ps(w + 128);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi7x01234567, vk7x01234567));

      const __m256 vi8x01234567 = _mm256_loadu_ps(i8);
      i8 += 8;

      const __m256 vk8x01234567 = _mm256_load_ps(w + 144);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi8x01234567, vk8x01234567));

      const __m256 vi9x01234567 = _mm256_loadu_ps(i9);
      i9 += 8;

      const __m256 vk9x01234567 = _mm256_load_ps(w + 160);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi9x01234567, vk9x01234567));

      const __m256 vi10x01234567 = _mm256_loadu_ps(i10);
      i10 += 8;

      const __m256 vk10x01234567 = _mm256_load_ps(w + 176);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi10x01234567, vk10x01234567));

      const __m256 vi11x01234567 = _mm256_loadu_ps(i11);
      i11 += 8;

      const __m256 vk11x01234567 = _mm256_load_ps(w + 192);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi11x01234567, vk11x01234567));

      const __m256 vi12x01234567 = _mm256_loadu_ps(i12);
      i12 += 8;

      const __m256 vk12x01234567 = _mm256_load_ps(w + 208);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi12x01234567, vk12x01234567));

      const __m256 vi13x01234567 = _mm256_loadu_ps(i13);
      i13 += 8;

      const __m256 vk13x01234567 = _mm256_load_ps(w + 224);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi13x01234567, vk13x01234567));

      const __m256 vi14x01234567 = _mm256_loadu_ps(i14);
      i14 += 8;

      const __m256 vk14x01234567 = _mm256_load_ps(w + 240);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi14x01234567, vk14x01234567));

      const __m256 vi15x01234567 = _mm256_loadu_ps(i15);
      i15 += 8;

      const __m256 vk15x01234567 = _mm256_load_ps(w + 256);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi15x01234567, vk15x01234567));

      const __m256 vi16x01234567 = _mm256_loadu_ps(i16);
      i16 += 8;

      const __m256 vk16x01234567 = _mm256_load_ps(w + 272);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi16x01234567, vk16x01234567));

      const __m256 vi17x01234567 = _mm256_loadu_ps(i17);
      i17 += 8;

      const __m256 vk17x01234567 = _mm256_load_ps(w + 288);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi17x01234567, vk17x01234567));

      const __m256 vi18x01234567 = _mm256_loadu_ps(i18);
      i18 += 8;

      const __m256 vk18x01234567 = _mm256_load_ps(w + 304);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi18x01234567, vk18x01234567));

      const __m256 vi19x01234567 = _mm256_loadu_ps(i19);
      i19 += 8;

      const __m256 vk19x01234567 = _mm256_load_ps(w + 320);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi19x01234567, vk19x01234567));

      const __m256 vi20x01234567 = _mm256_loadu_ps(i20);
      i20 += 8;

      const __m256 vk20x01234567 = _mm256_load_ps(w + 336);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi20x01234567, vk20x01234567));

      const __m256 vi21x01234567 = _mm256_loadu_ps(i21);
      i21 += 8;

      const __m256 vk21x01234567 = _mm256_load_ps(w + 352);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi21x01234567, vk21x01234567));

      const __m256 vi22x01234567 = _mm256_loadu_ps(i22);
      i22 += 8;

      const __m256 vk22x01234567 = _mm256_load_ps(w + 368);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi22x01234567, vk22x01234567));

      const __m256 vi23x01234567 = _mm256_loadu_ps(i23);
      i23 += 8;

      const __m256 vk23x01234567 = _mm256_load_ps(w + 384);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi23x01234567, vk23x01234567));

      const __m256 vi24x01234567 = _mm256_loadu_ps(i24);
      i24 += 8;

      const __m256 vk24x01234567 = _mm256_load_ps(w + 400);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi24x01234567, vk24x01234567));

      w += 8;


      __m256 vacc01234567 = _mm256_max_ps(vacc01234567p0, vmin);
      vacc01234567 = _mm256_min_ps(vacc01234567, vmax);

      _mm256_storeu_ps(output, vacc01234567);
      output += 8;
    }
    if XNN_UNLIKELY(c != 0) {
      assert(c >= 1);
      assert(c <= 7);
      __m256i vmask = _mm256_loadu_si256((const __m256i*) &mask_table[7 - c]);

      __m256 vacc01234567p0 = _mm256_load_ps(w);

      const __m256 vi0x01234567 = _mm256_maskload_ps(i0, vmask);
      const __m256 vk0x01234567 = _mm256_load_ps(w + 16);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi0x01234567, vk0x01234567));

      const __m256 vi1x01234567 = _mm256_maskload_ps(i1, vmask);
      const __m256 vk1x01234567 = _mm256_load_ps(w + 32);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi1x01234567, vk1x01234567));

      const __m256 vi2x01234567 = _mm256_maskload_ps(i2, vmask);
      const __m256 vk2x01234567 = _mm256_load_ps(w + 48);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi2x01234567, vk2x01234567));

      const __m256 vi3x01234567 = _mm256_maskload_ps(i3, vmask);
      const __m256 vk3x01234567 = _mm256_load_ps(w + 64);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi3x01234567, vk3x01234567));

      const __m256 vi4x01234567 = _mm256_maskload_ps(i4, vmask);
      const __m256 vk4x01234567 = _mm256_load_ps(w + 80);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi4x01234567, vk4x01234567));

      const __m256 vi5x01234567 = _mm256_maskload_ps(i5, vmask);
      const __m256 vk5x01234567 = _mm256_load_ps(w + 96);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi5x01234567, vk5x01234567));

      const __m256 vi6x01234567 = _mm256_maskload_ps(i6, vmask);
      const __m256 vk6x01234567 = _mm256_load_ps(w + 112);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi6x01234567, vk6x01234567));

      const __m256 vi7x01234567 = _mm256_maskload_ps(i7, vmask);
      const __m256 vk7x01234567 = _mm256_load_ps(w + 128);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi7x01234567, vk7x01234567));

      const __m256 vi8x01234567 = _mm256_maskload_ps(i8, vmask);
      const __m256 vk8x01234567 = _mm256_load_ps(w + 144);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi8x01234567, vk8x01234567));

      const __m256 vi9x01234567 = _mm256_maskload_ps(i9, vmask);
      const __m256 vk9x01234567 = _mm256_load_ps(w + 160);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi9x01234567, vk9x01234567));

      const __m256 vi10x01234567 = _mm256_maskload_ps(i10, vmask);
      const __m256 vk10x01234567 = _mm256_load_ps(w + 176);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi10x01234567, vk10x01234567));

      const __m256 vi11x01234567 = _mm256_maskload_ps(i11, vmask);
      const __m256 vk11x01234567 = _mm256_load_ps(w + 192);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi11x01234567, vk11x01234567));

      const __m256 vi12x01234567 = _mm256_maskload_ps(i12, vmask);
      const __m256 vk12x01234567 = _mm256_load_ps(w + 208);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi12x01234567, vk12x01234567));

      const __m256 vi13x01234567 = _mm256_maskload_ps(i13, vmask);
      const __m256 vk13x01234567 = _mm256_load_ps(w + 224);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi13x01234567, vk13x01234567));

      const __m256 vi14x01234567 = _mm256_maskload_ps(i14, vmask);
      const __m256 vk14x01234567 = _mm256_load_ps(w + 240);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi14x01234567, vk14x01234567));

      const __m256 vi15x01234567 = _mm256_maskload_ps(i15, vmask);
      const __m256 vk15x01234567 = _mm256_load_ps(w + 256);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi15x01234567, vk15x01234567));

      const __m256 vi16x01234567 = _mm256_maskload_ps(i16, vmask);
      const __m256 vk16x01234567 = _mm256_load_ps(w + 272);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi16x01234567, vk16x01234567));

      const __m256 vi17x01234567 = _mm256_maskload_ps(i17, vmask);
      const __m256 vk17x01234567 = _mm256_load_ps(w + 288);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi17x01234567, vk17x01234567));

      const __m256 vi18x01234567 = _mm256_maskload_ps(i18, vmask);
      const __m256 vk18x01234567 = _mm256_load_ps(w + 304);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi18x01234567, vk18x01234567));

      const __m256 vi19x01234567 = _mm256_maskload_ps(i19, vmask);
      const __m256 vk19x01234567 = _mm256_load_ps(w + 320);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi19x01234567, vk19x01234567));

      const __m256 vi20x01234567 = _mm256_maskload_ps(i20, vmask);
      const __m256 vk20x01234567 = _mm256_load_ps(w + 336);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi20x01234567, vk20x01234567));

      const __m256 vi21x01234567 = _mm256_maskload_ps(i21, vmask);
      const __m256 vk21x01234567 = _mm256_load_ps(w + 352);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi21x01234567, vk21x01234567));

      const __m256 vi22x01234567 = _mm256_maskload_ps(i22, vmask);
      const __m256 vk22x01234567 = _mm256_load_ps(w + 368);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi22x01234567, vk22x01234567));

      const __m256 vi23x01234567 = _mm256_maskload_ps(i23, vmask);
      const __m256 vk23x01234567 = _mm256_load_ps(w + 384);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi23x01234567, vk23x01234567));

      const __m256 vi24x01234567 = _mm256_maskload_ps(i24, vmask);
      const __m256 vk24x01234567 = _mm256_load_ps(w + 400);
      vacc01234567p0 = _mm256_add_ps(vacc01234567p0, _mm256_mul_ps(vi24x01234567, vk24x01234567));


      __m256 vacc01234567 = _mm256_max_ps(vacc01234567p0, vmin);
      vacc01234567 = _mm256_min_ps(vacc01234567, vmax);

      _mm256_maskstore_ps(output, vmask, vacc01234567);
      output += c;
    }

    output = (float*) ((uintptr_t) output + output_increment);
  } while (--output_width != 0);
}
