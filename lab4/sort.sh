#!/bin/sh

int_array=( 6 4 8 3 4 1 9 10 )

for (( i=0; i<${#int_array[*]}; i++ ))
do
   best=$i;
   for (( j=${i}+1; j<${#int_array[*]}; j++))
   do
       if (( ${int_array[j]}<${int_array[best]} )); then
           best=$j
       fi
   done
   temp=${int_array[i]}
   int_array[i]=${int_array[best]}
   int_array[best]=$temp
done

echo ${int_array[*]}
