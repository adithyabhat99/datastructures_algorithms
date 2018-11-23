read a b
if (( a == b ))
then
echo Yes
else
echo no
fi
if [[ $a == $b ]]
then echo yes
fi
if [[ $a -eq $b ]]
then echo Yes
fi
