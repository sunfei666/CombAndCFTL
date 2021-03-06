/******************************************************
 * Author :zhoujie
 * date :09.12.2018
 * function: the interval layer(FTL) to simulation for HybridSSD
 * **************************************************/
#ifndef _HBFTL_H_
#define _HBFTL_H_
#include "type.h"
#define SELECT_MLC 2
#define SELECT_SLC 1

#define DATA_READ 1
#define DATA_WRITE 0

struct mix_opm_entry {
  _u32 free  : 1;
  int ppn   : 31;
  int  cache_status;
  int  cache_age;
  int  map_status;
  int  map_age;
  int  update;
  int  count;
};

struct mix_omap_dir{
  unsigned int ppn;
};

struct mix_opm_entry * SLC_opagemap;
int SLC_opagemap_num;
struct mix_opm_entry * MLC_opagemap;
int MLC_opagemap_num;
struct mix_omap_dir * MLC_map_dir;
int MLC_map_dir_num;

int SLC_TOTAL_MAP_ENTRIES ;
int MLC_TOTAL_MAP_ENTRIES ;

#define MLC_MAP_ENTRIES_PER_PAGE 1024

double HBFTL_Scheme(unsigned int secno,int scount,int operation);
void Write_2_SLC(unsigned int secno, int scount);
void Write_2_MLC(unsigned int secno,int scount);
#endif
