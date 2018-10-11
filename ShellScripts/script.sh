echo 'Shell script is working'
echo ''
echo 'Your home directory contains these folders and files'
echo ''
cd
ls
echo ''
echo 'Your music files are stored in ~/music.txt file '
echo ''
cd ~/Music
ls>~/music.txt
echo 'See your command history with less'
history | less
echo ''
