out=$( tty )
if [[ $out = '/dev/pts/0' ]]
then echo "Yes,you can access $out"
else echo  "No,you can access only $out"
fi
