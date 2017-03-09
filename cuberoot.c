/*
 * Finding cube root of perfect cube:
 * Algorithm-->
 * Save cubes of first 10 digits(1-10)
 *  1->1
 *  2->8
 *  3->27
 *  4->64
 *  5->125
 *  6->216
 *  7->343
 *  8->512
 *  9->729
 *  10->1000
 * 
 * read a number: num say 35937
 * seperate its digits digits[0=>7,1=>3,2=>9,3=>5,4=>3]
 * select first digit  digits[0] = 7
 * if (digit == 8)
 *    result = 2
 *  else if( digit == 2)
 *    result = 8
 *  else if(digit == 7)
 *    result = 3
 *  else if(digit == 3)
 *    result = 7
 *  else
 *    result = digit
 *
 *  if (not of digits > 3)
 *    rem = 0;
 *    select remaining number
 *    for( i = last; i>3; i++)
 *        rem = rem*10 + digit
 *
 * match = none
 * for each entry in cubes
 * {
 *    m = rem - entry;
 *    if ( m < match)
 *      match = m;
 *      matched = index of entry
 * }
 *
 * result = matched*10 + result
 * */
#include<stdio.h>
  
  void main(){
    int num,tnum,digit,i=0,length,result,rem,match,m,matched=0;
    int A[10]={1,8,27,64,125,216,343,512,729,1000},b[6];
    printf("Enter a number: ");
    scanf("%d",&num);
    tnum = num;
    while(tnum != 0)
    {

      digit = tnum%10;
      tnum = tnum/10;
      b[i]= digit;
      i++;
    }
    length = i;
    //printf("%d\n",length);
    digit = b[0];
    for(i=0;i<length;i++){
      //printf("%d",b[i]);
    }
   // printf("\n");
    result = 0;
    if(digit == 8){
      result = 2;
    }else if(digit == 2){
      result = 8;
    }else if(digit == 7){
      result = 3;
    }else if(digit == 3){
      result = 7;
    }else{
      result = digit;
    }

    if(length  > 3){
      rem = 0;
      for(i = length-1;i >= 3;i--)
      {
        //printf("i=%d:%d\n",i,b[i]);
        rem = rem*10 + b[i];
      }
    }
    match = 1001; 
    for(i=0;i<10;i++){
      m = rem - A[i];
     // printf("%d\n",A[i]);
      if(m <= match & m >=0)
      {
        match = m;
        matched = i+1;
      }
    }
    //printf("\nrem=%d\nmatch:%d\nmatched:%d\n",rem,match,matched);
    result = matched*10 + result;

    printf("\n%d\n",result);
  }
