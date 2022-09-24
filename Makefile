no-bloat:
	gcc -w sexfetch.c -o sexfetch
	cp sexfetch /bin/sexfetch
	echo "alias sexfetch='cd /bin && ./sexfetch && cd -'" >> ~/.bashrc
	clear
	./sexfetch
