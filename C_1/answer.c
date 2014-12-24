/*	
	* This is the file with your answer, and is located at ~/work/answer.c.	
	* Write your code in it, and save it before submitting your answer.	
	*/	
		
	#include "answer.h"	
		
	#include <ctype.h>	
	#include <stdio.h>	
	#include <stdlib.h>	
	#include <limits.h>	
		
	#define USE_MAIN	
		
		
	/// You can use this boolean flag if you use the main function for debugging.	
	static int debug_mode = 0;	
	static char *initial_answer = "No answer written";	
		
	// ----------------------------------------------------------------------------	
		
	struct rectangle	
	{	
	    int x; ///< X-coordinate of lower-left corner.	
	    int y; ///< Y-coordinate of lower-left corner.	
	    int w; ///< Width of rectangle in pixels.	
	    int h; ///< Height of rectangle in pixels.	
	};	
		
	// ----------------------------------------------------------------------------	
		
	/** This function populates the rectangle object with values found in the string.	
	 * @return Zero for failure, non-zero for success.	
	 */	
		
	int initialize_rectangle( struct rectangle * r, const char * s )	
	{	
	    if ( NULL == r )	
	    {	
	        return 0;	
	    }	
	    r->x = 0;	
	    r->y = 0;	
	    r->w = 0;	
	    r->h = 0;	
		
	    if ( ( NULL == s ) || ( '\0' == *s ) )	
	    {	
	        return 0;	
	    }	
		
	    int got_x = 0;	
	    int got_y = 0;	
	    int got_w = 0;	
	    int got_h = 0;	
	    while ( *s != '\0' )	
	    {	
	        const char ch = *s;	
	        switch ( ch )	
	        {	
	            case 'x':	
	            case 'X':	
	            {	
	                if ( got_x )	
	                {	
	                    return 0;	
	                }	
	                ++s;	
	                if ( *s != '=' )	
	                {	
	                    return 0;	
	                }	
	                ++s;	
	                if ( isdigit( *s ) == 0 )	
	                {	
	                    return 0;	
	                }	
	                r->x = atoi( s );	
	                if ( r->x < 0 )	
	                {	
	                    return 0;	
	                }	
	                got_x = 1;	
	                break;	
	            }	
	            case 'y':	
	            case 'Y':	
	            {	
	                if ( got_y )	
	                {	
	                    return 0;	
	                }	
	                ++s;	
	                if ( *s != '=' )	
	                {	
	                    return 0;	
	                }	
	                ++s;	
	                if ( isdigit( *s ) == 0 )	
	                {	
	                    return 0;	
	                }	
	                r->y = atoi( s );	
	                if ( r->y < 0 )	
	                {	
	                    return 0;	
	                }	
	                got_y = 1;	
	                break;	
	            }	
	            case 'h':	
	            case 'H':	
	            {	
	                if ( got_h )	
	                {	
	                    return 0;	
	                }	
	                ++s;	
	                if ( *s != '=' )	
	                {	
	                    return 0;	
	                }	
	                ++s;	
	                if ( isdigit( *s ) == 0 )	
	                {	
	                    return 0;	
	                }	
	                r->h = atoi( s );	
	                if ( r->h < 1 )	
	                {	
	                    return 0;	
	                }	
	                got_h = 1;	
	                break;	
	            }	
	            case 'w':	
	            case 'W':	
	            {	
	                if ( got_w )	
	                {	
	                    return 0;	
	                }	
	                ++s;	
	                if ( *s != '=' )	
	                {	
	                    return 0;	
	                }	
	                ++s;	
	                if ( isdigit( *s ) == 0 )	
	                {	
	                    return 0;	
	                }	
	                r->w = atoi( s );	
	                if ( r->w < 1 )	
	                {	
	                    return 0;	
	                }	
	                got_w = 1;	
	                break;	
	            }	
	            default:	
	            {	
	                return 0;	
	            }	
	        }	
	        while  ( isdigit( *s ) != 0 )	
	            ++s;	
	        if ( *s == '\0' )	
	        {	
	            break;	
	        }	
	        if ( ( *s != ' ' ) && ( *s != '|' ) )	
	        {	
	            return 0;	
	        }	
	        ++s;	
	    }	
		
	    return ( got_x && got_y && got_w && got_h );	
	}	
		
	// ----------------------------------------------------------------------------	
		
	/**	
	 * Calculates minimal rectangle that encloses all others.	
	 *	
	 * This method declaration must be kept unmodified.	
	 *	
	 * @param rectangles: Strings containing data about rectangles to check.	
	 * @param count: The number of strings in the array.	
	 * @return Returns a string encoding the enclosing rectangle.	
	 */	
	char * get_enclosing_rectangle( const char * rectangles[], unsigned int count )	
	{	
	    /// @todo Write your code here.	
	    struct rectangle * input_rect = malloc(sizeof(struct rectangle) * count);
        

	    char *answer = malloc(sizeof(char) * (strlen(initial_answer) + 1));
	    strcpy(answer, initial_answer);	
	    return answer;	

	}	
		
	// ----------------------------------------------------------------------------	
		
	#ifdef USE_MAIN	
		
	void print_enclosing_rectangle( const char * rectangles[], unsigned int count )	
	{	
	    char * answer = get_enclosing_rectangle( rectangles, count );	
	    printf( "%s\n", answer );	
	    free( answer );	
	}	
		
	// ----------------------------------------------------------------------------	
		
	/**	
	 * This test code is provided only for your convenience.	
	 */	
	int main()	
	{	
		
	    debug_mode = 1;	
	    {	
	        const char * rectangles[] = { "X=5 Y=9 W=10 H=40", "X=16 Y=9 W=10 H=40" };	
	        print_enclosing_rectangle( rectangles, sizeof(rectangles) / sizeof(rectangles[0]) );	
	    }	
		
	    {	
	        const char * rectangles[] = { "X=0 Y=0 W=1 H=5", "X=0 Y=8 W=1 H=9" };	
	        print_enclosing_rectangle( rectangles, sizeof(rectangles) / sizeof(rectangles[0]) );	
	    }	
	
	    {	
	        const char * rectangles[] = { "X=0 Y=0 W=1 H=1", "X=0 Y=2 W=1 H=1" };	
	        print_enclosing_rectangle( rectangles, sizeof(rectangles) / sizeof(rectangles[0]) );	
	    }	
		
	    {	
	        const char * rectangles[] = { "X=0 Y=0 W=12 H=1", "X=20 Y=0 W=11 H=1" };	
	        print_enclosing_rectangle( rectangles, sizeof(rectangles) / sizeof(rectangles[0]) );	
	    }	
		
	    {	
	        const char * rectangles[] = { "X=5 Y=9 W=10 H=40", "X=11 Y=79 W=10 H=40" };	
	        print_enclosing_rectangle( rectangles, sizeof(rectangles) / sizeof(rectangles[0]) );	
	    }	
		
	    {	
	        const char * rectangles[] = { "X=5 Y=9 W=10 H=40", "X=11 Y=79 W=10 H=40", "X=12 Y=17 W=10 H=40", "X=15 Y=9 W=10 H=40" };	
	        print_enclosing_rectangle( rectangles, sizeof(rectangles) / sizeof(rectangles[0]) );	
	    }	
		
	    return 0;	
	}	
		
	#endif	
		
	// ----------------------------------------------------------------------------