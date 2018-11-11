#!/bin/bash
read a
if [ $a -lt 10 ]
then
	echo yeah, $a is less than 10
else
	echo nope, $a is greater than 10	
fi