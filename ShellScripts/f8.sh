ls > lss
while read line
do
if [ -f $line ]
then
echo $line is a file
else
echo $line is a directory
fi
done < lss
