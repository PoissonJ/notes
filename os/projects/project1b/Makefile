all: increment consecutive safe_increment

increment:
	cc increment.c -o increment;

consecutive:
	cc consecutive.c -o consecutive;

safe_increment:
	cc safe_increment.c -o safe_increment;
	echo "1" > foo.txt;
	echo: > foo.txt;

clean:
	rm -f increment;
	rm -f consecutive;
	rm -f safe_increment;
	rm -f foo.txt;
	rm -f config;
