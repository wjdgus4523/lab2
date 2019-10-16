/* dltest.c */
#include <stdio.h>
#include <dlfcn.h>
int main()
{
void *handle;
int (*add)(int, int), (*minus)(int, int),  (*multiple)(int, int);
float (*devide)(int, int);
char *error;
handle = dlopen ("./lib/libtest.so", RTLD_LAZY);
	if (!handle) {
	fputs (dlerror(), stderr);
	exit(1);
	}

	add = dlsym(handle, "add"); 
	if ((error = dlerror()) != NULL) { 
	fprintf (stderr, "%s", error); 
	exit(1); 
	}
	minus = dlsym(handle, "minus");
	if ((error = dlerror()) != NULL) {
	fprintf (stderr, "%s", error);
	exit(1);
	}
	multiple = dlsym(handle, "multiple");
	if ((error = dlerror()) != NULL) {
	fprintf (stderr, "%s", error);
	exit(1);
	}
	 devide = dlsym(handle, "devide");
	if ((error = dlerror()) != NULL) {
	fprintf (stderr, "%s", error);
	exit(1);
	}
printf ("6 + 3 = %d\n", (*add)(6,3));
printf ("6 - 3 = %d\n", (*minus)(6,3));
printf ("6 * 3 = %d\n", (*multiple)(6,3));
printf ("6 / 3 = %f\n", (*devide)(6,3));
dlclose(handle);
}
