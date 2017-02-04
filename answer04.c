#include <stdio.h>
#include <stdbool.h>
#include "pa04.h"

// must enclose the function by #ifdef TEST_INTEGRATE 
// and #endif to enable partial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  intrg -> answer = 0;
  double reg = 0;
  reg = (intrg -> upperlimit - intrg -> lowerlimit) / (intrg -> intervals);
  for (int i = 0; i < intrg -> intervals; i++){
  	intrg -> answer += reg * intrg -> func(intrg -> lowerlimit + (i * reg));
  }
  // integrate the function stored in intrg's func
  // store the result in intrg's answer
}
 #endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable partial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  // open the input file name for reading
	FILE * inf;
	inf = fopen(infilename, "r");
	
	if (inf == NULL){
		return false;
	}

	Integration intrg;
  // if fopen fails, return false
  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

	int n;
	n = fscanf(inf, "%lf\n", &intrg.lowerlimit);
	if (n != 1){
		fclose(inf);
		return false;
	}

  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

	n = fscanf(inf, "%lf", &intrg.upperlimit);
	if (n != 1){
		fclose(inf);
		return false;
	}

  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

	n = fscanf(inf,"%d", &intrg.intervals);
	if (n != 1){
		fclose(inf);
		return false;
	}

  // close the input file

	fclose(inf);

  // open the output file for writing
  // if fopen fails, return false

	FILE * outf = fopen(outfilename, "w");
	if (outf == NULL){
		return false;
	}

  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5

	funcptr funcs[5] = {func1, func2, func3, func4, func5};

  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf
	
    for(int y = 0; y < 5; y++){
		intrg.func = funcs[y];
		integrate(&intrg);
		n = fprintf(outf, "%lf\n", intrg.answer);
	}


  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false

	if(n < 1){
		fclose(outf);
		return false;
	}


  // after going through all functions in funcs
  // close the output file
	fclose(outf);

  // if the function reaches here, return true

	return true;

}
#endif // RUN_INTEGRATE
