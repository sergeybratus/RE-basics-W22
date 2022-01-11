#include <stdio.h>

void print_string(char *string) {
	if ( string == NULL ) {
		return;
	}

	printf("String: %s\n", string);

	return;
}

int main(int argc, char **argv) {

	if ( argc > 1 ) {
		print_string( argv[1] );
	} else {
		print_string( "Hello World!");
	}

	return 0;
}
