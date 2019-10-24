/*-----------------------------------------------------------------------------------------
 * Author: Duy Vinh To
 * Team: DinhViSo corp.
 *
 * Created date: 7th July 2016
 *
 * Brief: process string
 ------------------------------------------------------------------------------------------*/
#ifndef STRINGLIB_H_
#define STRINGLIB_H_
/*-----------------------------------------------------------------------------------------
 * INCLUDE
 ------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------
 * TYPEDEFS
 ------------------------------------------------------------------------------------------*/
typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned long U32;
/*-----------------------------------------------------------------------------------------
 * FUNC.PROTOTYPES
 ------------------------------------------------------------------------------------------*/
/* Split a string into 2 part by a character, read in source file for more details */
extern void SL_split(const U8* str, U8 chr, U8* out_head, U16 head_length, U8* out_tail, U16 tail_length);
/* check if 's' is start with 'sStart', read in source file for more details */
extern int SL_startwith(const U8* s, const U8 *sStart);
/* Cut/remove 1st found 'sCut' from s, read in source file for more details */
extern U8 SL_cut(U8 *s, const U8 *sCut);
/* Extract 'dst' from 'src', read in source file for more details */
extern void SL_sub(U16 start, U16 length, const U8 *src, U8 *dst);
/* Convert from string to double */
extern double SL_s2double(const U8* str);
/* Search 'sTarget' in 's' */
extern int SL_search(const U8 *s, const U8 *sTarget);
/* Parse double into interger and decimal value: CAUTION ON USING */
extern void SL_parseDouble(double in, int *integer, U32 *decimal);
/* convert double to string */
extern U8 *SL_double2s(double input, U32 size, U8 *s);
/*---------------------------------------------------------------------------
 * Brief: verify is a string that satisfy filter.
 * Param: 	s			|	IN	|	input string.
 * 			len			|	IN	|	string length.
 * 			filterMark	|	IN	|	filter mask bits.
 * 			extFilter	|	IN	|	extended filter: list of characters to filter.
 * 			efLen		|	IN	|	extended filter lenght.
 * Ret:	0	|	OK
 * 		>0	|	FAIL
 * Note: Filter bit:
 *  + 0x01 (BIT 0) : alphabet characters (include capitals).
 *  + 0x02 (BIT 1) : numeric characters.
 *  + 0x04 (BIT 2) : <CR>,<LF> characters.
 *  + 0x08 (BIT 3): printable characters (from ' ' to '~').
 *  + 0x19 (BIT 4) : extended filter.
 ----------------------------------------------------------------------------*/
extern U8 SL_verify( const U8 *s, U16 len, U8 filterMask, const U8 *extFilter, U16 efLen);
/* Find 1st number string in 's' */
extern U16 SL_searchNum(const U8* s, U16 numSize, U8* num);
/* Check if 's' is hexa string */
extern U8 SL_isHexString(const U8 *s);
/* Convert hexa array to string */
extern void SL_convHexArr2string(U8 *s);
/* Check if 's' is number string */
extern U8 SL_isNumString(const U8 *s);

#endif // STRINGLIB_H_
