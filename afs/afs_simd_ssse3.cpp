﻿#include <Windows.h>
#include "filter.h"
#define USE_SSSE3 1
#define USE_SSE41 0

#include "afs_analyze_simd.h"

void __stdcall afs_analyze_set_threshold_ssse3(int thre_shift, int thre_deint, int thre_Ymotion, int thre_Cmotion) {
    afs_analyze_set_threshold_simd(thre_shift, thre_deint, thre_Ymotion, thre_Cmotion);
}

void __stdcall afs_analyze_12_ssse3_plus2(BYTE *dst, PIXEL_YC *p0, PIXEL_YC *p1, int tb_order, int width, int step, int si_pitch, int h, int *motion_count, AFS_SCAN_CLIP *mc_clip) {
    afs_analyze_12_simd_plus2(dst, p0, p1, tb_order, width, step, si_pitch, h, motion_count, mc_clip);
}
void __stdcall afs_analyze_1_ssse3_plus2(BYTE *dst, PIXEL_YC *p0, PIXEL_YC *p1, int tb_order, int width, int step, int si_pitch, int h, int *motion_count, AFS_SCAN_CLIP *mc_clip) {
    afs_analyze_1_simd_plus2(dst, p0, p1, tb_order, width, step, si_pitch, h, motion_count, mc_clip);
}
void __stdcall afs_analyze_2_ssse3_plus2(BYTE *dst, PIXEL_YC *p0, PIXEL_YC *p1, int tb_order, int width, int step, int si_pitch, int h, int *motion_count, AFS_SCAN_CLIP *mc_clip) {
    afs_analyze_2_simd_plus2(dst, p0, p1, tb_order, width, step, si_pitch, h, motion_count, mc_clip);
}

#include "afs_yuy2up_simd.h"

void __stdcall afs_yuy2up_frame_ssse3(PIXEL_YC *dst, PIXEL_YC *src, int width, int pitch, int y_start, int y_fin) {
    afs_yuy2up_frame_simd(dst, src, width, pitch, y_start, y_fin);
}

#include "afs_filter_simd.h"

void __stdcall afs_analyzemap_filter_ssse3(BYTE* sip, int si_w, int w, int h) {
    afs_analyzemap_filter_simd(sip, si_w, w, h);
}

void __stdcall afs_analyzemap_filter_ssse3_plus(BYTE* sip, int si_w, int w, int h) {
    afs_analyzemap_filter_simd_plus(sip, si_w, w, h);
}
