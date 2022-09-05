no-bloat:
	gcc sexfetch.c -o sexfetch
	cp sexfetch /sexfetch
	echo "alias sexfetch='./sexfetch'" >> ~/.bashrc
	./sexfetch
