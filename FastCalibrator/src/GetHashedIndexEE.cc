#include "GetHashedIndexEE.h"
#include "EERings.h"

const int kxf[] =  {
    41,  51,  41,  51,  41,  51,  36,  51,  36,  51,
    26,  51,  26,  51,  26,  51,  21,  51,  21,  51,
    21,  51,  21,  51,  21,  51,  16,  51,  16,  51,
    14,  51,  14,  51,  14,  51,  14,  51,  14,  51,
    9,  51,   9,  51,   9,  51,   9,  51,   9,  51,
    6,  51,   6,  51,   6,  51,   6,  51,   6,  51,
    6,  51,   6,  51,   6,  51,   6,  51,   6,  51,
    4,  51,   4,  51,   4,  51,   4,  51,   4,  56,
    1,  58,   1,  59,   1,  60,   1,  61,   1,  61,
    1,  62,   1,  62,   1,  62,   1,  62,   1,  62,
    1,  62,   1,  62,   1,  62,   1,  62,   1,  62,
    1,  61,   1,  61,   1,  60,   1,  59,   1,  58,
    4,  56,   4,  51,   4,  51,   4,  51,   4,  51,
    6,  51,   6,  51,   6,  51,   6,  51,   6,  51,
    6,  51,   6,  51,   6,  51,   6,  51,   6,  51,
    9,  51,   9,  51,   9,  51,   9,  51,   9,  51,
    14,  51,  14,  51,  14,  51,  14,  51,  14,  51,
    16,  51,  16,  51,  21,  51,  21,  51,  21,  51,
    21,  51,  21,  51,  26,  51,  26,  51,  26,  51,
    36,  51,  36,  51,  41,  51,  41,  51,  41,  51
} ;

const int kdi[] =  {
   0,   10,   20,   30,   40,   50,   60,   75,   90,  105,
   120,  145,  170,  195,  220,  245,  270,  300,  330,  360,
   390,  420,  450,  480,  510,  540,  570,  605,  640,  675,
   710,  747,  784,  821,  858,  895,  932,  969, 1006, 1043,
   1080, 1122, 1164, 1206, 1248, 1290, 1332, 1374, 1416, 1458,
   1500, 1545, 1590, 1635, 1680, 1725, 1770, 1815, 1860, 1905,
   1950, 1995, 2040, 2085, 2130, 2175, 2220, 2265, 2310, 2355,
   2400, 2447, 2494, 2541, 2588, 2635, 2682, 2729, 2776, 2818,
   2860, 2903, 2946, 2988, 3030, 3071, 3112, 3152, 3192, 3232,
   3272, 3311, 3350, 3389, 3428, 3467, 3506, 3545, 3584, 3623,
   3662, 3701, 3740, 3779, 3818, 3857, 3896, 3935, 3974, 4013,
   4052, 4092, 4132, 4172, 4212, 4253, 4294, 4336, 4378, 4421,
   4464, 4506, 4548, 4595, 4642, 4689, 4736, 4783, 4830, 4877,
   4924, 4969, 5014, 5059, 5104, 5149, 5194, 5239, 5284, 5329,
   5374, 5419, 5464, 5509, 5554, 5599, 5644, 5689, 5734, 5779,
   5824, 5866, 5908, 5950, 5992, 6034, 6076, 6118, 6160, 6202,
   6244, 6281, 6318, 6355, 6392, 6429, 6466, 6503, 6540, 6577,
   6614, 6649, 6684, 6719, 6754, 6784, 6814, 6844, 6874, 6904,
   6934, 6964, 6994, 7024, 7054, 7079, 7104, 7129, 7154, 7179,
   7204, 7219, 7234, 7249, 7264, 7274, 7284, 7294, 7304, 7314
} ;


int GetHashedIndexEE(int ix, int iy, int zside)
{
  int jx = ix ;
  int jd =  2*( iy - 1 ) + ( jx - 1 )/50  ;
  return (  ( zside < 0 ? 0 : kEEhalf ) + kdi[jd] + jx - kxf[jd] ) ;
}

int GetIxFromHashedIndex(int Index)
{
  int di = Index%kEEhalf ;
  int ii = ( std::upper_bound( kdi, kdi+(2*IY_MAX), di ) - kdi ) - 1 ;
  return ( kxf[ii] + di - kdi[ii] ) ;
}

int GetIyFromHashedIndex(int Index)
{
  int di = Index%kEEhalf ;
  int ii = ( std::upper_bound( kdi, kdi+(2*IY_MAX), di ) - kdi ) - 1 ;
  return ( 1 + ii/2 ) ;
}

int GetZsideFromHashedIndex(int Index)
{  
   
  return ( Index < kEEhalf ? -1 : 1) ;
}
