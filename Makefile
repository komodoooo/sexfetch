no-bloat:
	gcc -w sexfetch.c -o sexfetch
	cp sexfetch /sexfetch
	echo "alias sexfetch='./sexfetch'" >> ~/.bashrc
	clear
	./sexfetch
