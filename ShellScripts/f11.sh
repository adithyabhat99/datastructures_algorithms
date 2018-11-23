#!/bin/bash
for i in {1..10}
do
echo $i
done
((i++))
while (( i<=15 ))
do
echo $i
((i++))
done
