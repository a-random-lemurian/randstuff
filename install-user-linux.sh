echo
echo "User-only install for Linux."
echo "Binaries ---> /home/$(whoami)/.local/bin"
echo
echo "Binaries that match rand:"
echo
ls ~/.local/bin | grep 'rand'
echo
echo "Type y to install, Ctrl+Z to cancel."
read CONFIRM

if [ $CONFIRM = "Y" ] || [ $CONFIRM = "y" ]
then
	for file in randascii randfromargs randhex randquote
	do
		cp ./bin/$file ~/.local/bin/$file
	done
else
	echo "Abort."
fi
