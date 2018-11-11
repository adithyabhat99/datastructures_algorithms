#!/bin/bash
read -a adi
if (( adi[1] == 10 ))
then
	echo yeah
else
	echo nope
fi