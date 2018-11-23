read -p "Enter two numbers: " a b
echo -n "Division of $a and $b is "
echo "scale=3;$a/$b" | bc
