#include <stdio.h>

int main(int argc, char * argv[])
{
	int x[4] = {1, 2, 3, 4};

	int * ptr_x = &x[0];    /* same as next statement for the second part &x[0] */
	const int * ptr_c_x = x;    /* can also be written as int const * ptr_c_x - same as above for second part x */
	int * const ptr_x_c = x;    /* */
	const int * const ptr_c_x_c = x;    /* */

	*ptr_x = 12;    /* OK */
	ptr_x++;    /* OK */

	//*ptr_c_x = 12;    /* NOT OK */	
	ptr_c_x++;    /* OK */

	*ptr_x_c = 12;    /* OK */
	//ptr_x_c++;    /* NOT OK */

	//*ptr_c_x_c = 12;    /* NOT OK */
	//ptr_c_x_c++;    /* NOT OK */
}