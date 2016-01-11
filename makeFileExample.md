LIBS=libs/connectivity libs/database libs/manager
INCLUDE_PATH=libs/

cli_exec: libraries
    gcc cli/main.c $(wildcard libraries/*) -I$(INCLUDE_PATH) -o cli_exec

libraries:
    mkdir libraries/
    for dir in $(LIBS); do \
        cd $$dir; \
        gcc -c *.c -I../; \
        mv *.o ../../libraries; \
        cd -; \
    done

clean:
    rm -rf libraries cli_exec
