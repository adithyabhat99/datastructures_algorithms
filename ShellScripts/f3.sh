c=$( echo "scale=3;4/3" | bc )
echo $c
read -p "Enter the number: " a
(( sum = a + 10 ))
echo "Sum is $sum"
