#!/bin/bash
user=$(whoami)
echo $user is the user, date is  $(date)
echo sum of variables $1 and $2 are 
echo $1 '+' $2 | bc 
sum=`expr $1 + $2` #another method
echo $sum